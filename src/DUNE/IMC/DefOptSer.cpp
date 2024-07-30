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
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: a90d171843e43b21ae6f4deb54c977a0                            *
//***************************************************************************

// ISO C++ 98 headers.
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

// DUNE headers.
#include <DUNE/Utils/ByteCopy.hpp>
#include <DUNE/Utils/Utils.hpp>
#include <DUNE/IMC/Exceptions.hpp>
#include <DUNE/IMC/Definitions.hpp>
#include <DUNE/IMC/Factory.hpp>
#include <DUNE/IMC/Serialization.hpp>
#include <DUNE/IMC/DefOptSer.hpp>

namespace DUNE
{
  namespace IMC
  {
    uint8_t*
    EntityState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(description, ptr__);
      return ptr__;
    }

    uint16_t
    EntityState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(description, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    EntityState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(description, ptr__);
      return ptr__;
    }

    uint16_t
    EntityState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(description, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    EntityState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(description, ptr__);
      return ptr__;
    }

    uint16_t
    EntityState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(description, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    LogBookEntry::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(context, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(text, ptr__);
      return ptr__;
    }

    uint16_t
    LogBookEntry::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(context, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(text, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    LogBookEntry::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(context, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(text, ptr__);
      return ptr__;
    }

    uint16_t
    LogBookEntry::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(context, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(text, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    LogBookEntry::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(context, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(text, ptr__);
      return ptr__;
    }

    uint16_t
    LogBookEntry::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(context, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(text, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    LogBookEntry::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(context, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(text, ptr__);
      return ptr__;
    }

    uint16_t
    LogBookEntry::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(context, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(text, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Announce::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(sys_name, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(sys_type, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(owner, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(height, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(services, ptr__);
      return ptr__;
    }

    uint16_t
    Announce::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(sys_name, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(sys_type, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(owner, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(height, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(services, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    IridiumMsgRx::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(origin, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(data, ptr__);
      return ptr__;
    }

    uint16_t
    IridiumMsgRx::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(origin, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    IridiumMsgRx::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(origin, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(data, ptr__);
      return ptr__;
    }

    uint16_t
    IridiumMsgRx::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(origin, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    IridiumMsgRx::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(origin, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(data, ptr__);
      return ptr__;
    }

    uint16_t
    IridiumMsgRx::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(origin, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    IridiumMsgRx::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(origin, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(htime, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(data, ptr__);
      return ptr__;
    }

    uint16_t
    IridiumMsgRx::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(origin, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(htime, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    HistoricSample::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(sys_id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(priority, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(t, ptr__);
      if (checkOptBit(6)) ptr__ += sample.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    HistoricSample::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(sys_id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(priority, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(t, bfr__, size__);
      if (checkOptBit(6)) bfr__ += sample.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    HistoricSample::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(sys_id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(priority, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(t, ptr__);
      if (checkOptBit(6)) ptr__ += sample.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    HistoricSample::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(sys_id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(priority, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(t, bfr__, size__);
      if (checkOptBit(6)) bfr__ += sample.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    HistoricSample::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(sys_id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(priority, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(t, ptr__);
      if (checkOptBit(6)) ptr__ += sample.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    HistoricSample::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(sys_id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(priority, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(t, bfr__, size__);
      if (checkOptBit(6)) bfr__ += sample.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    HistoricSample::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(sys_id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(priority, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(t, ptr__);
      if (checkOptBit(6)) ptr__ += sample.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    HistoricSample::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(sys_id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(priority, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(t, bfr__, size__);
      if (checkOptBit(6)) bfr__ += sample.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    HistoricSample::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(sys_id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(priority, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(t, ptr__);
      if (checkOptBit(6)) ptr__ += sample.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    HistoricSample::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(sys_id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(priority, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(t, bfr__, size__);
      if (checkOptBit(6)) bfr__ += sample.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    HistoricSample::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(sys_id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(priority, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(t, ptr__);
      if (checkOptBit(6)) ptr__ += sample.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    HistoricSample::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(sys_id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(priority, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(t, bfr__, size__);
      if (checkOptBit(6)) bfr__ += sample.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DeviceState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(phi, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(theta, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(psi, ptr__);
      return ptr__;
    }

    uint16_t
    DeviceState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(phi, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(theta, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(psi, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DeviceState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(phi, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(theta, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(psi, ptr__);
      return ptr__;
    }

    uint16_t
    DeviceState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(phi, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(theta, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(psi, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DeviceState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(phi, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(theta, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(psi, ptr__);
      return ptr__;
    }

    uint16_t
    DeviceState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(phi, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(theta, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(psi, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DeviceState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(phi, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(theta, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(psi, ptr__);
      return ptr__;
    }

    uint16_t
    DeviceState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(phi, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(theta, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(psi, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DeviceState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(phi, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(theta, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(psi, ptr__);
      return ptr__;
    }

    uint16_t
    DeviceState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(phi, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(theta, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(psi, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DeviceState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(x, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(y, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(z, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(phi, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(theta, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(psi, ptr__);
      return ptr__;
    }

    uint16_t
    DeviceState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(x, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(y, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(z, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(phi, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(theta, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(psi, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Distance::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(validity, ptr__);
      if (checkOptBit(1)) ptr__ += location.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += beam_config.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(value, ptr__);
      return ptr__;
    }

    uint16_t
    Distance::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(validity, bfr__, size__);
      if (checkOptBit(1)) bfr__ += location.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += beam_config.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Distance::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(validity, ptr__);
      if (checkOptBit(1)) ptr__ += location.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += beam_config.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(value, ptr__);
      return ptr__;
    }

    uint16_t
    Distance::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(validity, bfr__, size__);
      if (checkOptBit(1)) bfr__ += location.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += beam_config.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Distance::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(validity, ptr__);
      if (checkOptBit(1)) ptr__ += location.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += beam_config.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(value, ptr__);
      return ptr__;
    }

    uint16_t
    Distance::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(validity, bfr__, size__);
      if (checkOptBit(1)) bfr__ += location.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += beam_config.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Distance::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(validity, ptr__);
      if (checkOptBit(1)) ptr__ += location.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += beam_config.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(value, ptr__);
      return ptr__;
    }

    uint16_t
    Distance::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(validity, bfr__, size__);
      if (checkOptBit(1)) bfr__ += location.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += beam_config.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    EstimatedState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(lat, ptr__);
      ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(height, ptr__);
      ptr__ += IMC::serialize(x, ptr__);
      ptr__ += IMC::serialize(y, ptr__);
      ptr__ += IMC::serialize(z, ptr__);
      ptr__ += IMC::serialize(phi, ptr__);
      ptr__ += IMC::serialize(theta, ptr__);
      ptr__ += IMC::serialize(psi, ptr__);
      ptr__ += IMC::serialize(u, ptr__);
      ptr__ += IMC::serialize(v, ptr__);
      ptr__ += IMC::serialize(w, ptr__);
      ptr__ += IMC::serialize(vx, ptr__);
      ptr__ += IMC::serialize(vy, ptr__);
      ptr__ += IMC::serialize(vz, ptr__);
      ptr__ += IMC::serialize(p, ptr__);
      ptr__ += IMC::serialize(q, ptr__);
      ptr__ += IMC::serialize(r, ptr__);
      ptr__ += IMC::serialize(depth, ptr__);
      ptr__ += IMC::serialize(alt, ptr__);
      return ptr__;
    }

    uint16_t
    EstimatedState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(height, bfr__, size__);
      bfr__ += IMC::deserialize(x, bfr__, size__);
      bfr__ += IMC::deserialize(y, bfr__, size__);
      bfr__ += IMC::deserialize(z, bfr__, size__);
      bfr__ += IMC::deserialize(phi, bfr__, size__);
      bfr__ += IMC::deserialize(theta, bfr__, size__);
      bfr__ += IMC::deserialize(psi, bfr__, size__);
      bfr__ += IMC::deserialize(u, bfr__, size__);
      bfr__ += IMC::deserialize(v, bfr__, size__);
      bfr__ += IMC::deserialize(w, bfr__, size__);
      bfr__ += IMC::deserialize(vx, bfr__, size__);
      bfr__ += IMC::deserialize(vy, bfr__, size__);
      bfr__ += IMC::deserialize(vz, bfr__, size__);
      bfr__ += IMC::deserialize(p, bfr__, size__);
      bfr__ += IMC::deserialize(q, bfr__, size__);
      bfr__ += IMC::deserialize(r, bfr__, size__);
      bfr__ += IMC::deserialize(depth, bfr__, size__);
      bfr__ += IMC::deserialize(alt, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    ExternalNavData::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += state.serialize(ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(type, ptr__);
      return ptr__;
    }

    uint16_t
    ExternalNavData::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += state.deserialize(bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(type, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    SetPWM::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(period, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(duty_cycle, ptr__);
      return ptr__;
    }

    uint16_t
    SetPWM::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(period, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(duty_cycle, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    SetPWM::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(id, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(period, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(duty_cycle, ptr__);
      return ptr__;
    }

    uint16_t
    SetPWM::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(id, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(period, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(duty_cycle, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DesiredSpeed::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(value, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(speed_units, ptr__);
      return ptr__;
    }

    uint16_t
    DesiredSpeed::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(value, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    DesiredSpeed::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(value, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(speed_units, ptr__);
      return ptr__;
    }

    uint16_t
    DesiredSpeed::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(value, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Goto::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(timeout, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(z, ptr__);
      ptr__ += IMC::serialize(z_units, ptr__);
      ptr__ += IMC::serialize(speed, ptr__);
      ptr__ += IMC::serialize(speed_units, ptr__);
      ptr__ += IMC::serialize(roll, ptr__);
      ptr__ += IMC::serialize(pitch, ptr__);
      ptr__ += IMC::serialize(yaw, ptr__);
      ptr__ += IMC::serialize(custom, ptr__);
      return ptr__;
    }

    uint16_t
    Goto::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(z, bfr__, size__);
      bfr__ += IMC::deserialize(z_units, bfr__, size__);
      bfr__ += IMC::deserialize(speed, bfr__, size__);
      bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      bfr__ += IMC::deserialize(roll, bfr__, size__);
      bfr__ += IMC::deserialize(pitch, bfr__, size__);
      bfr__ += IMC::deserialize(yaw, bfr__, size__);
      bfr__ += IMC::deserialize(custom, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Goto::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(timeout, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(z, ptr__);
      ptr__ += IMC::serialize(z_units, ptr__);
      ptr__ += IMC::serialize(speed, ptr__);
      ptr__ += IMC::serialize(speed_units, ptr__);
      ptr__ += IMC::serialize(roll, ptr__);
      ptr__ += IMC::serialize(pitch, ptr__);
      ptr__ += IMC::serialize(yaw, ptr__);
      ptr__ += IMC::serialize(custom, ptr__);
      return ptr__;
    }

    uint16_t
    Goto::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(z, bfr__, size__);
      bfr__ += IMC::deserialize(z_units, bfr__, size__);
      bfr__ += IMC::deserialize(speed, bfr__, size__);
      bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      bfr__ += IMC::deserialize(roll, bfr__, size__);
      bfr__ += IMC::deserialize(pitch, bfr__, size__);
      bfr__ += IMC::deserialize(yaw, bfr__, size__);
      bfr__ += IMC::deserialize(custom, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Goto::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(timeout, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(lon, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(z, ptr__);
      ptr__ += IMC::serialize(z_units, ptr__);
      ptr__ += IMC::serialize(speed, ptr__);
      ptr__ += IMC::serialize(speed_units, ptr__);
      ptr__ += IMC::serialize(roll, ptr__);
      ptr__ += IMC::serialize(pitch, ptr__);
      ptr__ += IMC::serialize(yaw, ptr__);
      ptr__ += IMC::serialize(custom, ptr__);
      return ptr__;
    }

    uint16_t
    Goto::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(z, bfr__, size__);
      bfr__ += IMC::deserialize(z_units, bfr__, size__);
      bfr__ += IMC::deserialize(speed, bfr__, size__);
      bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      bfr__ += IMC::deserialize(roll, bfr__, size__);
      bfr__ += IMC::deserialize(pitch, bfr__, size__);
      bfr__ += IMC::deserialize(yaw, bfr__, size__);
      bfr__ += IMC::deserialize(custom, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Reference::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(1)) ptr__ += speed.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += z.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(radius, ptr__);
      return ptr__;
    }

    uint16_t
    Reference::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(1)) bfr__ += speed.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += z.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(radius, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Reference::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(1)) ptr__ += speed.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += z.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(radius, ptr__);
      return ptr__;
    }

    uint16_t
    Reference::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(1)) bfr__ += speed.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += z.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(radius, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Reference::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(1)) ptr__ += speed.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += z.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(radius, ptr__);
      return ptr__;
    }

    uint16_t
    Reference::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(1)) bfr__ += speed.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += z.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(radius, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Reference::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(1)) ptr__ += speed.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += z.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(radius, ptr__);
      return ptr__;
    }

    uint16_t
    Reference::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(1)) bfr__ += speed.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += z.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(radius, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    Reference::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(1)) ptr__ += speed.serialize(ptr__);
      if (checkOptBit(2)) ptr__ += z.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(lat, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(radius, ptr__);
      return ptr__;
    }

    uint16_t
    Reference::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(1)) bfr__ += speed.deserialize(bfr__, size__);
      if (checkOptBit(2)) bfr__ += z.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(lat, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(radius, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    FollowRefState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(control_src, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(control_ent, ptr__);
      if (checkOptBit(2)) ptr__ += reference.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(proximity, ptr__);
      return ptr__;
    }

    uint16_t
    FollowRefState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(control_src, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(control_ent, bfr__, size__);
      if (checkOptBit(2)) bfr__ += reference.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(proximity, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    FollowRefState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(control_src, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(control_ent, ptr__);
      if (checkOptBit(2)) ptr__ += reference.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(proximity, ptr__);
      return ptr__;
    }

    uint16_t
    FollowRefState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(control_src, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(control_ent, bfr__, size__);
      if (checkOptBit(2)) bfr__ += reference.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(proximity, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    FollowRefState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(control_src, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(control_ent, ptr__);
      if (checkOptBit(2)) ptr__ += reference.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(proximity, ptr__);
      return ptr__;
    }

    uint16_t
    FollowRefState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(control_src, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(control_ent, bfr__, size__);
      if (checkOptBit(2)) bfr__ += reference.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(proximity, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    FollowRefState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(control_src, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(control_ent, ptr__);
      if (checkOptBit(2)) ptr__ += reference.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(proximity, ptr__);
      return ptr__;
    }

    uint16_t
    FollowRefState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(control_src, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(control_ent, bfr__, size__);
      if (checkOptBit(2)) bfr__ += reference.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(proximity, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    FollowRefState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(control_src, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(control_ent, ptr__);
      if (checkOptBit(2)) ptr__ += reference.serialize(ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(proximity, ptr__);
      return ptr__;
    }

    uint16_t
    FollowRefState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(control_src, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(control_ent, bfr__, size__);
      if (checkOptBit(2)) bfr__ += reference.deserialize(bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(proximity, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(op_mode, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(error_count, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(error_ents, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(maneuver_type, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(maneuver_stime, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(maneuver_eta, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(control_loops, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(flags, ptr__);
      if (checkOptBit(8)) ptr__ += IMC::serialize(last_error, ptr__);
      if (checkOptBit(9)) ptr__ += IMC::serialize(last_error_time, ptr__);
      return ptr__;
    }

    uint16_t
    VehicleState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(op_mode, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(error_count, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(error_ents, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(maneuver_type, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(maneuver_stime, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(maneuver_eta, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(control_loops, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(flags, bfr__, size__);
      if (checkOptBit(8)) bfr__ += IMC::deserialize(last_error, bfr__, size__);
      if (checkOptBit(9)) bfr__ += IMC::deserialize(last_error_time, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanDB::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(op, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(request_id, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(4)) ptr__ += arg.serialize(ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(info, ptr__);
      return ptr__;
    }

    uint16_t
    PlanDB::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(op, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(request_id, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(4)) bfr__ += arg.deserialize(bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanDB::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(op, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(request_id, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(4)) ptr__ += arg.serialize(ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(info, ptr__);
      return ptr__;
    }

    uint16_t
    PlanDB::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(op, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(request_id, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(4)) bfr__ += arg.deserialize(bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanDB::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(op, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(request_id, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(4)) ptr__ += arg.serialize(ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(info, ptr__);
      return ptr__;
    }

    uint16_t
    PlanDB::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(op, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(request_id, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(4)) bfr__ += arg.deserialize(bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanDB::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(op, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(request_id, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(4)) ptr__ += arg.serialize(ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(info, ptr__);
      return ptr__;
    }

    uint16_t
    PlanDB::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(op, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(request_id, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(4)) bfr__ += arg.deserialize(bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanDB::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(op, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(request_id, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(4)) ptr__ += arg.serialize(ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(info, ptr__);
      return ptr__;
    }

    uint16_t
    PlanDB::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(op, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(request_id, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(4)) bfr__ += arg.deserialize(bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    PlanControlState::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(state, ptr__);
      if (checkOptBit(1)) ptr__ += IMC::serialize(plan_id, ptr__);
      if (checkOptBit(2)) ptr__ += IMC::serialize(plan_eta, ptr__);
      if (checkOptBit(3)) ptr__ += IMC::serialize(plan_progress, ptr__);
      if (checkOptBit(4)) ptr__ += IMC::serialize(man_id, ptr__);
      if (checkOptBit(5)) ptr__ += IMC::serialize(man_type, ptr__);
      if (checkOptBit(6)) ptr__ += IMC::serialize(man_eta, ptr__);
      if (checkOptBit(7)) ptr__ += IMC::serialize(last_outcome, ptr__);
      return ptr__;
    }

    uint16_t
    PlanControlState::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(state, bfr__, size__);
      if (checkOptBit(1)) bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      if (checkOptBit(2)) bfr__ += IMC::deserialize(plan_eta, bfr__, size__);
      if (checkOptBit(3)) bfr__ += IMC::deserialize(plan_progress, bfr__, size__);
      if (checkOptBit(4)) bfr__ += IMC::deserialize(man_id, bfr__, size__);
      if (checkOptBit(5)) bfr__ += IMC::deserialize(man_type, bfr__, size__);
      if (checkOptBit(6)) bfr__ += IMC::deserialize(man_eta, bfr__, size__);
      if (checkOptBit(7)) bfr__ += IMC::deserialize(last_outcome, bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleLinks::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(localname, ptr__);
      if (checkOptBit(1)) ptr__ += links.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    VehicleLinks::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(localname, bfr__, size__);
      if (checkOptBit(1)) bfr__ += links.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint8_t*
    VehicleLinks::serializeFieldsOptional(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(opt_id, ptr__);
      if (checkOptBit(0)) ptr__ += IMC::serialize(localname, ptr__);
      if (checkOptBit(1)) ptr__ += links.serialize(ptr__);
      return ptr__;
    }

    uint16_t
    VehicleLinks::deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(opt_id, bfr__, size__);
      if (checkOptBit(0)) bfr__ += IMC::deserialize(localname, bfr__, size__);
      if (checkOptBit(1)) bfr__ += links.deserialize(bfr__, size__);
      return bfr__ - start__;
    }
  }
}
