//***************************************************************************
// Copyright 2007-2013 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Universidade do Porto. For licensing   *
// terms, conditions, and further information contact lsts@fe.up.pt.        *
//                                                                          *
// European Union Public Licence - EUPL v.1.1 Usage                         *
// Alternatively, this file may be used under the terms of the EUPL,        *
// Version 1.1 only (the "Licence"), appearing in the file LICENCE.md       *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://www.lsts.pt/dune/licence.                                        *
//***************************************************************************
// Author: Jose Pinto                                                       *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Maneuver
{
  namespace FollowReference
  {
    using DUNE_NAMESPACES;

    struct Arguments
    {
      float vertical_tolerance;
      float horizontal_tolerance;
      float loitering_radius;
    };

    struct Task : public DUNE::Maneuvers::Maneuver
    {
      //! Task arguments.
      Arguments m_args;

      //! Store maneuver specification
      IMC::FollowReference m_spec;

      //! Store latest received reference
      IMC::Reference m_cur_ref;

      //! Estimated state
      IMC::EstimatedState m_estate;

      //! Did we get a reference already?
      bool m_got_reference;

      //! Store last timestamp when reference was received
      double m_last_ref_time;

      Task(const std::string& name, Tasks::Context& ctx) :
        DUNE::Maneuvers::Maneuver(name, ctx),
        m_last_ref_time(0),
        m_got_reference(false)
      {
        bindToManeuver<Task, IMC::FollowReference>();
        bind<IMC::Reference>(this);
        bind<IMC::EstimatedState>(this);
        bind<IMC::PathControlState>(this);
      }

      void
      consume(const IMC::FollowReference* msg)
      {
        m_spec = *msg;
      }

      /**
       * \brief Consume Reference messages and generate DesiredPath messages accordingly
       *
       * Whenever a new Reference is received from a valid source, a new desired_path
       * gets commanded to the vehicle.
       * @param msg the Reference message to be processed
       */
      void
      consume(const IMC::Reference* msg)
      {

        // verify that the source is acceptable
        if (m_spec.control_src != 0xFFFF && m_spec.control_src != msg->getSource()) {
          //warn("ignoring reference from non-authorized source: %d", msg->getSource());
          return;
        }

        // verify that the source entity is acceptable
        if (m_spec.control_ent != 0xFF && m_spec.control_ent != msg->getSourceEntity()) {
          //warn("ignoring reference from non-authorized entity: %d", msg->getSource());
          return;
        }

        // start building the DesiredPath message to command
        DesiredPath desired_path;

        double curlat = m_estate.lat;
        double curlon = m_estate.lon;
        WGS84::displace(m_estate.x, m_estate.y, &curlat, &curlon);

        desired_path.start_lat = curlat;
        desired_path.start_lon = curlon;

        // set start_z according to current estimated state
        if (m_estate.depth != -1)
        {
          desired_path.start_z = m_estate.depth;
          desired_path.start_z_units = Z_DEPTH;
        }
        else if (m_estate.alt != -1)
        {
          desired_path.start_z = m_estate.alt;
          desired_path.start_z_units = Z_ALTITUDE;
        }
        else
        {
          desired_path.start_z = m_estate.height;
          desired_path.start_z_units = Z_HEIGHT;
        }

        // set end_z according to received reference
        if (msg->flags & IMC::Reference::FLAG_LOCATION)
        {
          desired_path.end_lat = msg->lat;
          desired_path.end_lon = msg->lon;
        }
        else if (m_got_reference)
        {
          desired_path.end_lat = m_cur_ref.lat;
          desired_path.end_lon = m_cur_ref.lon;
        }
        else
        {
          desired_path.end_lat = curlat;
          desired_path.end_lon = curlon;
        }

        // set speed according to received reference. If the reference does not
        // provide a desired speed, use last sent speed
        if ((msg->flags & IMC::Reference::FLAG_SPEED) && !(msg->speed.isNull()))
        {
          desired_path.speed = msg->speed->value;
          desired_path.speed_units = msg->speed->speed_units;
        }
        else if (m_got_reference && !m_cur_ref.speed.isNull())
        {
          desired_path.speed = m_cur_ref.speed->value;
          desired_path.speed_units = m_cur_ref.speed->speed_units;
        }


        if ((msg->flags & IMC::Reference::FLAG_Z) && !(msg->z.isNull()))
        {
          desired_path.end_z = msg->z->value;
          desired_path.end_z_units = msg->z->z_units;
        }
        else if (m_got_reference && !m_cur_ref.z.isNull())
        {
          desired_path.end_z = m_cur_ref.z->value;
          desired_path.end_z_units = m_cur_ref.z->z_units;
        }

        double distance_to_target = WGS84::distance(desired_path.end_lat, desired_path.end_lon, 0, curlat, curlon, 0);

        if (distance_to_target < m_args.horizontal_tolerance)
        {
          desired_path.lradius = m_args.loitering_radius;
        }

        m_cur_ref = *msg;
        m_got_reference = true;

        dispatch(desired_path);
      }

      void
      consume(const IMC::EstimatedState* msg)
      {
        m_estate = *msg;
      }

      // Function to check if the vehicle is getting near to the next waypoint
      void
      consume(const IMC::PathControlState* pcs)
      {
        //        // Verify maneuver completion
        //        double delta = Clock::get() - m_start_time - m_maneuver.duration;
        //        if (delta >= 0)
        //        {
        //          signalCompletion();
        //          return;
        //        }
        //        else
        //        {
        //          signalProgress((uint16_t)(Math::round(delta)));
        //        }

        // if we have arrived at the target, we stop moving
        if (pcs->flags & IMC::PathControlState::FL_NEAR)
        {
          debug("arrived at the center");
          // enableMovement(false);
        }
      }
    };
  }
}

DUNE_TASK
