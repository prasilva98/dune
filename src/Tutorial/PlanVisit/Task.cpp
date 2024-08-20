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
#include <limits> 

namespace Tutorial
{
  //! Insert short task description here.
  //!
  //! Insert explanation on task behaviour here.
  //! @author Ruben
  namespace PlanVisit
  {
    using DUNE_NAMESPACES;

    // Create Arguments Struct. 
    // Since each task has different arguments a new struct is always required
    struct Arguments
    {
      // Variable where points to visit will be saved
      std::vector<double> p_visit; 
    };

    struct Task: public DUNE::Tasks::Task
    {

      //! Declare an Arguments Variable.
      Arguments m_args;  
      //! Operation mode.
      int op_mode; 
      //! Plan Mode; 
      int p_mode;
      //! Position variables of our vehicle.
      //! Latitude.
      fp64_t s_lat;
      //! Longitude.
      fp64_t s_lon;
      //! Vector of points to visit 
      std::vector<double> p_visit; 
      //! Flag to check if plan has been generated
      bool is_plan_gen = false;
      //! Distance matrix 
      std::vector<std::vector<double>> m_distances; 
      //! Full Path 
      std::vector<int> m_path; 
      // Full plan specification 
      IMC::PlanSpecification p_spec;
      // Flag to check if plan has been sent 
      bool plan_sent = false; 
      // Plan control type message
      IMC::PlanControl plan_control;

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        op_mode(-1)
      {
        // Make the Active parameter global and visible to users (in neptus)
        paramActive(Tasks::Parameter::SCOPE_GLOBAL,
                    Tasks::Parameter::VISIBILITY_USER, true);

        // Declare points to visit parameter and get values from .ini file
        param("Points to Visit", m_args.p_visit)
        .defaultValue("")
        .description("Points that should be visited by lauv.")
        .visibility(Tasks::Parameter::VISIBILITY_USER)
        .scope(Tasks::Parameter::SCOPE_GLOBAL);

        // Bind to the check if vehicle is in service
        bind<IMC::VehicleState>(this);
        bind<IMC::EstimatedState>(this); 
        bind<IMC::PlanControlState>(this);
        
      }

      // Keep track of the operation mode of the vehicle.
      void 
      consume(const IMC::VehicleState* msg)
      {
        op_mode = msg->op_mode;
      }

      // Keep track of the position of the vehicle.
      void 
      consume(const IMC::EstimatedState* msg)
      {
        // Convert Position WGS84 format Coordinates 
        Coordinates::toWGS84(*msg, s_lat, s_lon);
      }

      //! Keep track of the the state of the plan 
      void consume(const IMC::PlanControlState* msg)
      {
        p_mode = msg->state; 

        if (msg->last_outcome == PlanControlState::LPO_SUCCESS)
        {
          inf("Plan is sucessfully completed");
        }

      }
      // Validate coordinates based on if the number of points is even or not.
      bool validateCoor(std::vector<double>& points)
      {
        if (points.size() % 2 == 0)
        {
          return true; 
        } 
        else
        {
          return false; 
        }
      }
      
      //! In this case new parameters will mean new points to visit! 
      void
      onUpdateParameters(void)
      {

        //! Check if points to visit parameters were changed. 
        if(paramChanged(m_args.p_visit) )
        {
          //! Check if number of points is even,
          //! If not deactivate the task
          if(!validateCoor(m_args.p_visit))
          {
            throw std::runtime_error("Number of points is not correct.");
          }

          //! Save the points in a variable
          for(auto& value : m_args.p_visit)
          {
            p_visit.push_back(Angles::radians(value));
          }

          spew("New, valid set of points inserted! New plan should be generated"); 
          is_plan_gen = false;
          plan_sent = false; 

          if(op_mode == IMC::VehicleState::VS_MANEUVER)
          {
            plan_control.op = IMC::PlanControl::PC_STOP;
            dispatch(plan_control);
          }
        }
      }

      template <typename t>
      void printVectors(t& vec)
      {
        for (auto& value : vec)
        {
          if(typeid(value) == typeid(int))
          {
            spew("Value is: %d", value); 
          }
          
          if(typeid(value) == typeid(double))
          {
            spew("Value is: %f", value);
          }
        }
      }

      void addCurrentPosition(void)
      {
        // Add the current position as a point to visit in the beginning of the vector
        p_visit.push_back(s_lat);
        std::swap(p_visit.front(), p_visit.back());
        p_visit.push_back(s_lon); 
        std::swap(p_visit[1], p_visit.back());
      }

      void calcDistMatrix(void)
      {
        //! Calculate the distances between all the points and fill the distance matrix
        for(unsigned int j = 0; j < p_visit.size();j+=2)
        {
          std::vector<double> dist_row;
          for(unsigned int i = 0; i < p_visit.size();i+=2)
          {
            dist_row.push_back(WGS84::distance(p_visit[j], p_visit[j + 1], 0,
                                               p_visit[i], p_visit[i + 1], 0));
          } 
          m_distances.push_back(dist_row); 
         }
      }

      int CalculateTotalDistance()
      { 
        int totalDistance = 0;
        // Iterate through the current path chosen and add the distances from point to point 
        for (size_t i = 0; i < m_path.size() -1; ++i)
        {
          totalDistance += m_distances[m_path[i]][m_path[i + 1]];
        }
        // Add the distance to return to origin position.
        totalDistance += m_distances[m_path.back()][m_path.front()];
        return totalDistance;
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

        while (!stopping())
        {
          waitForMessages(1.0);

          // Check if our task is Active and the path has been generated
          // If it isnt generate a distance matrix and calculate the best route

          if ( (op_mode == IMC::VehicleState::VS_SERVICE) && (this->isActive()) )
          {

            if(!is_plan_gen)
            {

              spew("Current pos (%f, %f)", s_lat, s_lon);
              
              //! Add current position to the beginning of the list of points to visit
              addCurrentPosition();
              calcDistMatrix();            
              
              // Fill the path variable based on the number of points 
              for (unsigned int i = 0; i < m_distances.size(); i++)
              {
                m_path.push_back(i);
              }

              // First minDistance is the biggest distance that fits inside a double.
              double minDistance = std::numeric_limits<double>::max();

              // Save the best path on this variable. 
              std::vector<int> bestPath; 
              do
              {
                int currentDistance = CalculateTotalDistance();
                if (currentDistance < minDistance) 
                {
                  minDistance = currentDistance;
                  bestPath = m_path; 
                }

              }while(std::next_permutation(m_path.begin() + 1, m_path.end()));

              //! Creating the various maneuvers for the plans
              for(unsigned int i = 0; i < bestPath.size(); i++)
              {
                double lat = p_visit[bestPath[i]*2]; 
                double lon = p_visit[bestPath[i]*2 + 1];

                IMC::Goto goto_maneuver; 
                goto_maneuver.lat = lat; 
                goto_maneuver.lon = lon; 
                goto_maneuver.speed = 1; 
                inf("lat to go: %f, lon to go: %f", goto_maneuver.lat, goto_maneuver.lon);
                goto_maneuver.speed_units = IMC::SpeedUnits::SUNITS_METERS_PS;
                goto_maneuver.z = 0; 
                goto_maneuver.z_units = IMC::Z_DEPTH;  

                // Set Plan Maneuver
                IMC::PlanManeuver pman;
                std::stringstream man_name; 
                man_name << "Goto " << i; 
                pman.maneuver_id = man_name.str();
                //! Start filling the actual maneuver plan
                pman.data.set(goto_maneuver);
                
                p_spec.maneuvers.push_back(pman);
                
                // The beginning maneuver
                if (i == 1)
                {
                  p_spec.start_man_id = pman.maneuver_id; 
                }
                else
                {
                // After the initial maneuver ID it is required to create transitions between maneuvers;

                  IMC::PlanTransition ptrans; 
                  std::stringstream prev_man_name; 
                  prev_man_name << "Goto " << i - 1; 
                  ptrans.source_man = prev_man_name.str(); 
                  ptrans.dest_man = man_name.str();
                  ptrans.conditions = "ManeuverIsDone";
                  p_spec.transitions.push_back(ptrans);
                  
                }
              } 

              // Plan is finally generated.
              is_plan_gen = true;
            }
            
            // If the plan has been generated but not sent
            if ( (!plan_sent) && (is_plan_gen) )
            {
              
              auto m_gen = Math::Random::Factory::create(Math::Random::Factory::c_default);

              inf("Plan control is being set");
              plan_control.type = IMC::PlanControl::PC_REQUEST;
              plan_control.op = IMC::PlanControl::PC_START;
              plan_control.request_id = m_gen->random() & 0xFFFF;
              plan_control.plan_id = p_spec.plan_id;
              plan_control.arg.set(p_spec);
              plan_control.setDestination(getSystemId());  
              dispatch(plan_control); 

              plan_sent = true;    
  
            }
          }
        }    
      }
    };
  }
}

DUNE_TASK
