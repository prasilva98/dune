//***************************************************************************
// Copyright 2007-2022 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Faculdade de Engenharia da             *
// Universidade do Porto. For licensing terms, conditions, and further      *
// information contact lsts@fe.up.pt.                                       *
//                                                                          *
// Modified European Union Public Licence - EUPL v.1.1 Usage                *
// Alternatively, this file may be used under the terms of the Modified     *
// EUPL, Version 1.1 only (the "Licence"), appearing in the file LICENCE.md *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://github.com/LSTS/dune/blob/master/LICENCE.md and                  *
// http://ec.europa.eu/idabc/eupl.html.                                     *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers.
#include "Driver.hpp"

namespace Sensors
{
  //! Device driver for the Mark & Wedell %SW100 CTD.
  namespace SW100
  {
    using DUNE_NAMESPACES;

    struct Arguments
    {
      //! IO device (URI).
      std::string io_dev;
      //! Read frequency.
      double read_frequency;
      //! Depth calibration parameters.
      std::vector<double> depth_cal;
      //! Input timeout.
      double data_timeout;
    };

    enum CalibrationState
    {
      //! Unable to calibrate
      CS_UNABLE,
      //! Able to calibrate
      CS_ABLE
    };

    struct Task: public Hardware::BasicDeviceDriver
    {
      //! Device driver.
      Driver* m_driver;
      //! Serial port.
      SerialPort* m_uart;
      //! Measured depth.
      IMC::Depth m_depth;
      //! Measured salinity.
      IMC::Salinity m_salinity;
      //! Measured conductivity.
      IMC::Conductivity m_conductivity;
      //! Measured temperature.
      IMC::Temperature m_temperature;
      //! Depth Offset.
      IMC::DepthOffset m_depth_offset;
      //! Moving average to compute depth offset.
      MovingAverage<double> m_depth_avg;
      //! Vehicle is at the surface
      bool m_at_surface;
      //! Vehicle is maneuvering
      bool m_maneuvering;
      //! Calibration state
      CalibrationState m_cs;
      //! Task arguments.
      Arguments m_args;
      //! Watchdog.
      Counter<double> m_wdog;

      Task(const std::string& name, Tasks::Context& ctx):
        Hardware::BasicDeviceDriver(name, ctx),
        m_driver(NULL),
        m_uart(NULL),
        m_depth_avg(10),
        m_at_surface(false),
        m_maneuvering(false),
        m_cs(CS_UNABLE)
      {
        // Define configuration parameters.
        param("IO Port - Device", m_args.io_dev)
        .defaultValue("")
        .description("IO device URI in the form \"uart://DEVICE:BAUD\"");
        
        param(DTR_RT("Execution Frequency"), m_args.read_frequency)
        .units(Units::Hertz)
        .defaultValue("1.0")
        .description(DTR("Frequency at which task reads data"));

        param("Depth Calibration", m_args.depth_cal)
        .defaultValue("1.0, 0.0")
        .size(2)
        .description("Depth calibration values");

        param("Data Timeout", m_args.data_timeout)
        .defaultValue("2.0")
        .minimumValue("1.0")
        .units(Units::Second)
        .description("Amount of seconds to wait for data before reporting an error");

        // Register consumers.
        bind<IMC::VehicleMedium>(this);
        bind<IMC::VehicleState>(this);
      }

      void
      onUpdateParameters(void)
      {
        if (paramChanged(m_args.read_frequency))
          setReadFrequency(m_args.read_frequency);
      }

      void
      onIdle(void) override
      {
        requestActivation();
      }

      //! Try to connect to the device.
      //! @return true if connection was established, false otherwise.
      bool
      onConnect() override
      {
        try
        {
          m_uart = static_cast<SerialPort*>(openUART(m_args.io_dev));
          m_driver = new Driver(this, *m_uart);
          return true;
        }
        catch (...)
        {
          throw RestartNeeded(DTR(Status::getString(CODE_COM_ERROR)), 5);
        }

        return false;
      }

      //! Disconnect from device.
      void
      onDisconnect() override
      {
        Memory::clear(m_uart);
        Memory::clear(m_driver);
      }

      //! Device may be initialized.
      void
      onInitializeDevice() override
      {
        m_wdog.setTop(m_args.data_timeout);
      }

      void
      consume(const IMC::VehicleMedium* msg)
      {
        m_at_surface = (msg->medium == IMC::VehicleMedium::VM_WATER);
      }

      void
      consume(const IMC::VehicleState* msg)
      {
        m_maneuvering = (msg->op_mode == IMC::VehicleState::VS_MANEUVER);
      }

      bool
      ableToCalibrate(void)
      {
        return (m_at_surface && !m_maneuvering);
      }

      //! Get data from device.
      //! @return true if data was received, false otherwise.
      bool
      onReadData() override
      {
        if (m_wdog.overflow())
        {
          m_wdog.reset();
          setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_INIT);
          if (m_driver->setup())
          {
            setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
          }
          else
          {
            setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_COM_ERROR);
            return false;
          }
        }

        switch (m_cs)
        {
          case CS_UNABLE:
            if (ableToCalibrate())
            {
              m_depth_avg.clear();
              m_cs = CS_ABLE;
            }
            break;
          case CS_ABLE:
            if (!ableToCalibrate())
            {
              m_depth_offset.value = -m_depth_offset.value;
              inf(DTR("depth offset is %0.2f m"), m_depth_offset.value);
              dispatch(m_depth_offset);
              m_cs = CS_UNABLE;
            }
            break;
        }

        if (m_driver->read())
        {
          m_wdog.reset();
          const double* d = m_driver->getData();
          m_depth.value = m_args.depth_cal[0] * d[0] + m_args.depth_cal[1];
          m_temperature.value = d[1];
          m_conductivity.value = d[2] / 10.0;
          m_salinity.value = d[3];

          double now;
          now = m_depth.setTimeStamp();
          m_temperature.setTimeStamp(now);
          m_conductivity.setTimeStamp(now);
          m_salinity.setTimeStamp(now);
          dispatch(m_depth, DF_KEEP_TIME);
          dispatch(m_temperature, DF_KEEP_TIME);
          dispatch(m_salinity, DF_KEEP_TIME);
          dispatch(m_conductivity, DF_KEEP_TIME);

          // Perform depth offset calibration.
          if (m_cs == CS_ABLE)
            m_depth_offset.value = m_depth_avg.update(m_depth.value);
        }

        return true;
      }
    };
  }
}

DUNE_TASK
