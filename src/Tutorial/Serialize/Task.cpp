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
#include <../programs/tests/Test.hpp>

namespace Tutorial
{
  //! Insert short task description here.
  //!
  //! Insert explanation on task behaviour here.
  //! @author Ruben
  namespace Serialize
  {
    using DUNE_NAMESPACES;
  
    struct Task: public DUNE::Tasks::Task
    {
      // Instantiate an object of the type Test
      Test test; 
      IMC::PlanControlState* r_planControlState; 
      IMC::GpsFix r_gpsFix;
      u_int32_t a_bytesPlanControlState = 0; 
      u_int32_t bytesPlanControlState = 0;

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        test("IMC Serialization/Deserialization")
      {
        // Make the Active parameter global and visible to users (in neptus)
        paramActive(Tasks::Parameter::SCOPE_GLOBAL,
                    Tasks::Parameter::VISIBILITY_USER, true);

        //bind<IMC::PlanControl>(this);
        //bind<IMC::PlanControlState>(this);
        //bind<IMC::GpsFix>(this); 
      }

      void 
      consume(const IMC::PlanControlState* msg)
      {

        bytesPlanControlState = msg->getSerializationSize();
        a_bytesPlanControlState += bytesPlanControlState;
        spew("New Control State received. Accumulated bytes: %d. Normal Bytes: %d \n State %d \n plan_id %s man_id %s", 
                                           a_bytesPlanControlState, bytesPlanControlState,
                                            msg->state, msg->plan_id.c_str(), msg->man_id.c_str());
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
      }

      //! Main loop.
      void
      onMain(void)
      {

       /*

        IMC::FollowRefState msg_follow; 
        msg_follow.setTimeStamp(0.8722702745793229);
        msg_follow.setSource(23415U);
        msg_follow.setSourceEntity(223U);
        msg_follow.setDestination(44630U);
        msg_follow.setDestinationEntity(60U);
        msg_follow.state = 4;
        msg_follow.proximity = 0;
        msg_follow.control_src = 5; 
        IMC::Reference msg_ref; 
        inf("Size of follow message: %d", msg_follow.getSerializationSize());
        msg_ref.flags = 1;
        msg_ref.lat = 8; 
        msg_ref.lon = 6; 
        msg_ref.radius = 0;
        IMC::DesiredSpeed iAmSpeed;
        iAmSpeed.value = 0; 
        iAmSpeed.speed_units = 3;
        iAmSpeed.updateOptVar();
        msg_ref.speed.set(iAmSpeed);
        msg_ref.updateOptVar();
        msg_follow.reference.set(msg_ref);
        inf("Size of nest: %d and opt_id %d", msg_ref.getSerializationSize(), msg_follow.reference.get()->opt_id);
        msg_follow.updateOptVar();
        inf("Final size of follow message: %d opt_id: %d", msg_follow.getSerializationSize(), msg_follow.opt_id);


       IMC::VehicleLinks msg_link; 
       msg_link.localname = "Yeah Buddy";
       IMC::Announce announce_1;
       IMC::Announce announce_2; 
       inf("size of msg_d before push back: %d", msg_link.getSerializationSize());
       announce_1.lat = 20; 
       announce_1.lon = 0;
       announce_1.height = 0;
       announce_1.updateOptVar();
       msg_link.links.push_back(announce_1);
       msg_link.updateOptVar();
       inf("size of msg_d atfter 1 push back: %d", msg_link.getSerializationSize());
       announce_2.lat = 40;
       announce_2.sys_name = "Big chungus";
       announce_2.lon = 312; 
       announce_2.height = 0;
       announce_2.updateOptVar();
       msg_link.links.push_back(announce_2);
       msg_link.updateOptVar();
       inf("size of msg_d after all is set: %d", msg_link.getSerializationSize());

       */

      IMC::PlanDB msg;
      msg.setTimeStamp(0.8722702745793229);
      msg.setSource(23415U);
      msg.setSourceEntity(223U);
      msg.setDestination(44630U);
      msg.setDestinationEntity(60U);
      msg.type = 52U;
      msg.op = 205U;
      msg.request_id = 15818U;
      msg.plan_id.assign("pimba");
      IMC::PlanDBInformation tmp_msg_0;
      tmp_msg_0.change_sname = "pimba";
      msg.arg.set(tmp_msg_0);
      msg.info.assign("pumba");

      IMC::Distance msg_dist;
      msg_dist.value = 30; 
      IMC::DeviceState n_dev;
      n_dev.x = 20; 
      IMC::DeviceState n_dev2;
      n_dev2.y = 10; 
      msg_dist.location.push_back(n_dev); 
      msg_dist.location.push_back(n_dev2);

        try
          {
            Utils::ByteBuffer bfr;
            IMC::Packet::serializeOptional(&msg_dist, bfr);
            inf("Size of message: %d", msg_dist.getSerializationSize());
            IMC::Message* msg_d = IMC::Packet::deserializeOptional(bfr.getBuffer(), bfr.getSize());
            test.boolean("PlanDB", msg_dist == *msg_d);
            delete msg_d;
          }
          catch (IMC::InvalidMessageSize& e)
          {
            (void)e;
            test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
            stop();
            requestDeactivation();
          }
            
          while (!stopping())
          {
            waitForMessages(1.0);

          }   
        }
      };
  }
}
DUNE_TASK


