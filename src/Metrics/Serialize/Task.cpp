//***************************************************************************
// Copyright 2007-2024 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Ruben                                                            *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

namespace Metrics
{
  //! Insert short task description here.
  //!
  //! Insert explanation on task behaviour here.
  //! @author Ruben

  namespace Serialize
  {
    using DUNE_NAMESPACES;

    bool isStringInVector(const std::vector<std::string>& vec, const std::string& str)
    {
      return std::find(vec.begin(), vec.end(), str) != vec.end();
    }

    // Create Arguments Struct. 
    // Since each task has different arguments a new struct is always required
    struct Arguments
    {
      //! UDP Address
      Address UDP_addr;
      //! Use UDP Port
      uint16_t UDP_listen_port;
      //! UDP Port
      uint16_t UDP_port;
      //! Messages to actually save 
      std::vector<std::string> messages;  
      //! Timeout to close Task
      uint8_t timeout;

    };

    struct Task: public DUNE::Tasks::Task
    {

      //! Declare an Arguments Variable.
      Arguments m_args;  
      //! UDP socket
      Network::UDPSocket* m_UDP_sock;
      //! Parser Variables
      uint8_t m_buf[4096];
      //! Accumulated size of messages sent
      int m_msize; 
      //! UDP Timeout 
      double m_last_pkt_time;
      //! Now Time
      double now;
      //! Message maps 
      std::map<std::string, int> m_map; 
      //! File stream 
      std::ofstream outFile;
      //!


      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
       DUNE::Tasks::Task(name, ctx),
       m_UDP_sock(NULL),
       m_msize(0),
       m_last_pkt_time(0),
       now(0)
      {

        // Make the Active parameter global and visible to users (in neptus)
        paramActive(Tasks::Parameter::SCOPE_GLOBAL,
                    Tasks::Parameter::VISIBILITY_USER, true);

          param("UDP - Listen Port", m_args.UDP_listen_port)
          .defaultValue("8080")
          .description("Port for connection from Neptus Replay");

          param("UDP - Port", m_args.UDP_port)
          .defaultValue("8082")
          .description("Port for connection");

          param("UDP - Address", m_args.UDP_addr)
          .defaultValue("127.0.0.1")
          .description("Address for connection");

          param("Transports", m_args.messages)
          .defaultValue("")
          .description("List of messages to transport");

          param("Timeout", m_args.timeout)
          .minimumValue("1")
          .maximumValue("60")
          .defaultValue("10")
          .units(Units::Second)
          .description("Timeout value to close Task");

      }
      
      //! Update internal state with new parameter values.
      void
      onUpdateParameters(void)
      {
      }

      //! Reserve entity identifiers.
      void
      onEntityReservation(void)
      {
      }

      //! Resolve entity names.
      void
      onEntityResolution(void)
      {
      }

      //! Acquire resources.
      void
      onResourceAcquisition(void)
      {
      }

      //! Initialize resources.
      void
      onResourceInitialization(void)
      {
      }

      //! Release resources.
      void
      onResourceRelease(void)
      {
        Memory::clear(m_UDP_sock);
      }

      void OriginalSerialize(IMC::Message* msg_d, std::string name)
      {
        // Increment accumulated size
        m_msize += msg_d->getSerializationSize();
        inf("Message name is: %s and size is: %d", msg_d->getName(), m_msize);
            
        // If the name doesn't exist add it sx
        if (m_map.count(name) == 0) 
        { 
          m_map.insert({name, msg_d->getSerializationSize()});
        }
        else // Otherwise just increase the value associated with it
        {
          m_map[name] = m_map[name] + msg_d->getSerializationSize(); 
        }

      }

      bool
      poll(double timeout)
      {
        if (m_UDP_sock != NULL)
          return Poll::poll(*m_UDP_sock, timeout);
        return false;
      }

      void
      openConnection(void)
      {
        try
        {
          // Create a new socket with an associated port and address
          m_UDP_sock = new UDPSocket;
          m_UDP_sock->bind(m_args.UDP_listen_port, Address::Any, false);
        }
        catch (...)
        {
          Memory::clear(m_UDP_sock);
          war(DTR("Connection failed, retrying..."));
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_COM_ERROR);
        }
      }

      void receiveData(uint8_t* buf, size_t blen)
      {
        int n = 0;

          if(m_UDP_sock)
          {
            n = m_UDP_sock->read(buf, blen, &m_args.UDP_addr, &m_args.UDP_listen_port);

            // Deserialize the message now
            try
            {
              Utils::ByteBuffer bfr; 
              IMC::Message* msg_d = IMC::Packet::deserialize(buf, n);
              std::string name = msg_d->getName();
              //! Check if received message is part of the Transports.Message pack 
              //! If so then get the accumulated size we also save it 
              if(isStringInVector(m_args.messages, name))
              {
                // After this, we need to get the message deserialize again and serialize it...

                OriginalSerialize(msg_d, name);

              }
              else
              {
                //inf("Message is not in the Transports list");  
              }

            }
            catch(const std::runtime_error& e)
            {
              spew("Error ocurred when deserializing: %s",e.what());
            }
        }
      }

      void 
      handleUDPData()
      {

        while(poll(0.01))
        {
          // Retrieve the data from the buffer and update the time tracker
          receiveData(m_buf, sizeof(m_buf));
          m_last_pkt_time = Clock::get();
        }
      }

      void 
      saveMetrics()
      {
        inf("Existing messages (name, num)");

        outFile.open("opt_messages.csv", std::ios::app); 
        outFile << "Playlist caravel";
        outFile << std::endl;
        outFile << "BytesUsed " << m_msize << std::endl;

        for(const auto& message: m_map)
        {
          outFile << message.first << " " << message.second << " " << std::endl;
          inf("%s", message.first.c_str());
        }
        outFile.close();
      }

      //! Main loop.
      void
      onMain(void)
      {

        m_last_pkt_time = Clock::get();
      
        while (!stopping())
        {
          
          now = Clock::get();
          
          // If UDP socket exists, start parsing data
          // Otherwise open a connection
          if(m_UDP_sock)
          {
            handleUDPData();
          }
          else
          {
            Time::Delay::wait(0.5);
            openConnection();
          }
          consumeMessages();

          if (now - m_last_pkt_time >= m_args.timeout)
          {
            saveMetrics();
            setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_MISSING_DATA);
            requestDeactivation();
            stop();
            
          }
        }
      }
    };
  }
}

DUNE_TASK
