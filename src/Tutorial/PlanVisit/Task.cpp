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

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx)
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
        
      }

      // Keep track of the operation mode of the vehicle
      void 
      consume(const IMC::VehicleState* msg){

        op_mode = msg->op_mode;

      }

      // Keep track of the position of the vehicle
      void 
      consume(const IMC::EstimatedState* msg){

        // Convert Position WGS84 format Coordinates 
        Coordinates::toWGS84(*msg, s_lat, s_lon);
      }

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
        }
      }

      void printVectors(std::vector<double>& vec)
      {
        for (auto& value : vec)
        {
          spew("Value is: %f", value); 
        }
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
          // If it isnt start generating
          if( (this->isActive()) && (!is_plan_gen) && (op_mode == IMC::VehicleState::VS_SERVICE))
          {

            spew("Current pos (%f, %f)", s_lat, s_lon);

            // Add the current position as a point to visit in the beginning of the vector
            p_visit.push_back(s_lat);
            std::swap(p_visit.front(), p_visit.back());
            p_visit.push_back(s_lon); 
            std::swap(p_visit[1], p_visit.back());

            //! I need to calculate the distances between all the points
            for(unsigned int j = 0; j < p_visit.size();j+=2)
            {
              std::vector<double> dist_row;
              for(unsigned int i = 0; i < p_visit.size();i+=2)
              {
                dist_row.push_back(WGS84::distance(p_visit[j], p_visit[j + 1], 0,
                                            p_visit[i], p_visit[i + 1], 0));
              } 
              inf("New distance row: ");
              printVectors(dist_row);
              m_distances.push_back(dist_row); 

            }
            is_plan_gen = true; 
          }
        }
      }
    };
   }
}

DUNE_TASK
