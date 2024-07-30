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

#ifndef DUNE_IMC_DEFOPTSER_HPP_INCLUDED_
#define DUNE_IMC_DEFOPTSER_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// DUNE headers.
#include <DUNE/Config.hpp>
#include <DUNE/IMC/Message.hpp>
#include <DUNE/IMC/InlineMessage.hpp>
#include <DUNE/IMC/MessageList.hpp>
#include <DUNE/IMC/Enumerations.hpp>
#include <DUNE/IMC/Bitfields.hpp>
#include <DUNE/IMC/SuperTypes.hpp>
#include <DUNE/IMC/JSON.hpp>
#include <DUNE/IMC/Definitions.hpp>

namespace DUNE
{
  namespace IMC
  {
    bool
    checkOptBit(uint32_t bitPosition)
    {
      return opt_id & (1 << bitPosition);
    }

    void
    setOptBit(uint32_t bitPosition)
    {
      opt_id |= (1 << bitPosition);
    }

    void
    updateOptVar(void)
    {
      opt_id = 0;
      if (state != 0) setOptBit(0);
      if (flags != 0) setOptBit(1);
      if (!description.empty()) setOptBit(2);
    }

    uint8_t*
    serializeFieldsOptional(uint8_t* bfr__) const;

    uint16_t
    deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

    unsigned
    getFixedSerializationSize(void) const
    {
      return 1;
    }

    unsigned
    getVariableSerializationSize(void) const
    {
      return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(description)*checkOptBit(2);
    }
  };

  bool
  Entity State::checkOptBit(uint32_t bitPosition) const
  {
    return opt_id & (1 << bitPosition);
  }

  void
  setOptBit(uint32_t bitPosition)
  {
    opt_id |= (1 << bitPosition);
  }

  void
  updateOptVar(void)
  {
    opt_id = 0;
    if (state != 0) setOptBit(0);
    if (flags != 0) setOptBit(1);
    if (!description.empty()) setOptBit(2);
  }

  uint8_t*
  serializeFieldsOptional(uint8_t* bfr__) const;

  uint16_t
  deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

  unsigned
  getFixedSerializationSize(void) const
  {
    return 1;
  }

  unsigned
  getVariableSerializationSize(void) const
  {
    return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(description)*checkOptBit(2);
  }
};

bool
Entity State::checkOptBit(uint32_t bitPosition) const
{
  return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
  opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
  opt_id = 0;
  if (state != 0) setOptBit(0);
  if (flags != 0) setOptBit(1);
  if (!description.empty()) setOptBit(2);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
  return 1;
}

unsigned
getVariableSerializationSize(void) const
{
  return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(description)*checkOptBit(2);
}
};

bool
Log Book Entry::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (type != 0) setOptBit(0);
if (htime != 0) setOptBit(1);
if (!context.empty()) setOptBit(2);
if (!text.empty()) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*8 + IMC::getSerializationSize(context)*checkOptBit(2) + IMC::getSerializationSize(text)*checkOptBit(3);
}
};

bool
Log Book Entry::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (type != 0) setOptBit(0);
if (htime != 0) setOptBit(1);
if (!context.empty()) setOptBit(2);
if (!text.empty()) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*8 + IMC::getSerializationSize(context)*checkOptBit(2) + IMC::getSerializationSize(text)*checkOptBit(3);
}
};

bool
Log Book Entry::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (type != 0) setOptBit(0);
if (htime != 0) setOptBit(1);
if (!context.empty()) setOptBit(2);
if (!text.empty()) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*8 + IMC::getSerializationSize(context)*checkOptBit(2) + IMC::getSerializationSize(text)*checkOptBit(3);
}
};

bool
Log Book Entry::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (type != 0) setOptBit(0);
if (htime != 0) setOptBit(1);
if (!context.empty()) setOptBit(2);
if (!text.empty()) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*8 + IMC::getSerializationSize(context)*checkOptBit(2) + IMC::getSerializationSize(text)*checkOptBit(3);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Announce::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!sys_name.empty()) setOptBit(0);
if (sys_type != 0) setOptBit(1);
if (owner != 0) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
if (height != 0) setOptBit(5);
if (!services.empty()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(sys_name)*checkOptBit(0) + checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*8 + checkOptBit(4)*8 + checkOptBit(5)*4 + IMC::getSerializationSize(services)*checkOptBit(6);
}
};

bool
Received Iridium Message::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (htime != 0) setOptBit(1);
if (lat != 0) setOptBit(2);
if (lon != 0) setOptBit(3);
if (!data.empty()) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*8 + IMC::getSerializationSize(data)*checkOptBit(4);
}
};

bool
Received Iridium Message::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (htime != 0) setOptBit(1);
if (lat != 0) setOptBit(2);
if (lon != 0) setOptBit(3);
if (!data.empty()) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*8 + IMC::getSerializationSize(data)*checkOptBit(4);
}
};

bool
Received Iridium Message::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (htime != 0) setOptBit(1);
if (lat != 0) setOptBit(2);
if (lon != 0) setOptBit(3);
if (!data.empty()) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*8 + IMC::getSerializationSize(data)*checkOptBit(4);
}
};

bool
Received Iridium Message::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (htime != 0) setOptBit(1);
if (lat != 0) setOptBit(2);
if (lon != 0) setOptBit(3);
if (!data.empty()) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*8 + IMC::getSerializationSize(data)*checkOptBit(4);
}
};

bool
Historic Data Sample::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (priority != 0) setOptBit(1);
if (x != 0) setOptBit(2);
if (y != 0) setOptBit(3);
if (z != 0) setOptBit(4);
if (t != 0) setOptBit(5);
if (!sample.isNull()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 3;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*2 + checkOptBit(4)*2 + checkOptBit(5)*2 + sample.getSerializationSize()*checkOptBit(6);
}
};

bool
Historic Data Sample::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (priority != 0) setOptBit(1);
if (x != 0) setOptBit(2);
if (y != 0) setOptBit(3);
if (z != 0) setOptBit(4);
if (t != 0) setOptBit(5);
if (!sample.isNull()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 3;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*2 + checkOptBit(4)*2 + checkOptBit(5)*2 + sample.getSerializationSize()*checkOptBit(6);
}
};

bool
Historic Data Sample::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (priority != 0) setOptBit(1);
if (x != 0) setOptBit(2);
if (y != 0) setOptBit(3);
if (z != 0) setOptBit(4);
if (t != 0) setOptBit(5);
if (!sample.isNull()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 3;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*2 + checkOptBit(4)*2 + checkOptBit(5)*2 + sample.getSerializationSize()*checkOptBit(6);
}
};

bool
Historic Data Sample::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (priority != 0) setOptBit(1);
if (x != 0) setOptBit(2);
if (y != 0) setOptBit(3);
if (z != 0) setOptBit(4);
if (t != 0) setOptBit(5);
if (!sample.isNull()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 3;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*2 + checkOptBit(4)*2 + checkOptBit(5)*2 + sample.getSerializationSize()*checkOptBit(6);
}
};

bool
Historic Data Sample::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (priority != 0) setOptBit(1);
if (x != 0) setOptBit(2);
if (y != 0) setOptBit(3);
if (z != 0) setOptBit(4);
if (t != 0) setOptBit(5);
if (!sample.isNull()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 3;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*2 + checkOptBit(4)*2 + checkOptBit(5)*2 + sample.getSerializationSize()*checkOptBit(6);
}
};

bool
Historic Data Sample::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (priority != 0) setOptBit(1);
if (x != 0) setOptBit(2);
if (y != 0) setOptBit(3);
if (z != 0) setOptBit(4);
if (t != 0) setOptBit(5);
if (!sample.isNull()) setOptBit(6);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 3;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + checkOptBit(3)*2 + checkOptBit(4)*2 + checkOptBit(5)*2 + sample.getSerializationSize()*checkOptBit(6);
}
};

bool
Device State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (x != 0) setOptBit(0);
if (y != 0) setOptBit(1);
if (z != 0) setOptBit(2);
if (phi != 0) setOptBit(3);
if (theta != 0) setOptBit(4);
if (psi != 0) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*4 + checkOptBit(1)*4 + checkOptBit(2)*4 + checkOptBit(3)*4 + checkOptBit(4)*4 + checkOptBit(5)*4;
}
};

bool
Device State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (x != 0) setOptBit(0);
if (y != 0) setOptBit(1);
if (z != 0) setOptBit(2);
if (phi != 0) setOptBit(3);
if (theta != 0) setOptBit(4);
if (psi != 0) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*4 + checkOptBit(1)*4 + checkOptBit(2)*4 + checkOptBit(3)*4 + checkOptBit(4)*4 + checkOptBit(5)*4;
}
};

bool
Device State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (x != 0) setOptBit(0);
if (y != 0) setOptBit(1);
if (z != 0) setOptBit(2);
if (phi != 0) setOptBit(3);
if (theta != 0) setOptBit(4);
if (psi != 0) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*4 + checkOptBit(1)*4 + checkOptBit(2)*4 + checkOptBit(3)*4 + checkOptBit(4)*4 + checkOptBit(5)*4;
}
};

bool
Device State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (x != 0) setOptBit(0);
if (y != 0) setOptBit(1);
if (z != 0) setOptBit(2);
if (phi != 0) setOptBit(3);
if (theta != 0) setOptBit(4);
if (psi != 0) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*4 + checkOptBit(1)*4 + checkOptBit(2)*4 + checkOptBit(3)*4 + checkOptBit(4)*4 + checkOptBit(5)*4;
}
};

bool
Device State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (x != 0) setOptBit(0);
if (y != 0) setOptBit(1);
if (z != 0) setOptBit(2);
if (phi != 0) setOptBit(3);
if (theta != 0) setOptBit(4);
if (psi != 0) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*4 + checkOptBit(1)*4 + checkOptBit(2)*4 + checkOptBit(3)*4 + checkOptBit(4)*4 + checkOptBit(5)*4;
}
};

bool
Device State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (x != 0) setOptBit(0);
if (y != 0) setOptBit(1);
if (z != 0) setOptBit(2);
if (phi != 0) setOptBit(3);
if (theta != 0) setOptBit(4);
if (psi != 0) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*4 + checkOptBit(1)*4 + checkOptBit(2)*4 + checkOptBit(3)*4 + checkOptBit(4)*4 + checkOptBit(5)*4;
}
};

bool
Distance::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (validity != 0) setOptBit(0);
if (!location.empty()) setOptBit(1);
if (!beam_config.empty()) setOptBit(2);
if (value != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + location.getSerializationSize()*checkOptBit(1) + beam_config.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*4;
}
};

bool
Distance::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (validity != 0) setOptBit(0);
if (!location.empty()) setOptBit(1);
if (!beam_config.empty()) setOptBit(2);
if (value != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + location.getSerializationSize()*checkOptBit(1) + beam_config.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*4;
}
};

bool
Distance::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (validity != 0) setOptBit(0);
if (!location.empty()) setOptBit(1);
if (!beam_config.empty()) setOptBit(2);
if (value != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + location.getSerializationSize()*checkOptBit(1) + beam_config.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*4;
}
};

bool
Distance::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (validity != 0) setOptBit(0);
if (!location.empty()) setOptBit(1);
if (!beam_config.empty()) setOptBit(2);
if (value != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + location.getSerializationSize()*checkOptBit(1) + beam_config.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*4;
}
};

bool
Estimated State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (lat != 0) setOptBit(0);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 81;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*8;
}
};

bool
External Navigation Data::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (type != 0) setOptBit(1);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1;
}
};

bool
Set PWM::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (period != 0) setOptBit(1);
if (duty_cycle != 0) setOptBit(2);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*4 + checkOptBit(2)*4;
}
};

bool
Set PWM::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (period != 0) setOptBit(1);
if (duty_cycle != 0) setOptBit(2);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*4 + checkOptBit(2)*4;
}
};

bool
Desired Speed::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (value != 0) setOptBit(0);
if (speed_units != 0) setOptBit(1);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*8 + checkOptBit(1)*1;
}
};

bool
Desired Speed::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (value != 0) setOptBit(0);
if (speed_units != 0) setOptBit(1);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*8 + checkOptBit(1)*1;
}
};

bool
Goto Maneuver::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (lat != 0) setOptBit(1);
if (lon != 0) setOptBit(2);
if (z != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 33;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*4;
}
};

bool
Goto Maneuver::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (lat != 0) setOptBit(1);
if (lon != 0) setOptBit(2);
if (z != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 33;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*4;
}
};

bool
Goto Maneuver::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (lat != 0) setOptBit(1);
if (lon != 0) setOptBit(2);
if (z != 0) setOptBit(3);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 33;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*8 + checkOptBit(2)*8 + checkOptBit(3)*4;
}
};

bool
Reference To Follow::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (flags != 0) setOptBit(0);
if (!speed.isNull()) setOptBit(1);
if (!z.isNull()) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 5;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + speed.getSerializationSize()*checkOptBit(1) + z.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*8 + checkOptBit(4)*8;
}
};

bool
Reference To Follow::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (flags != 0) setOptBit(0);
if (!speed.isNull()) setOptBit(1);
if (!z.isNull()) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 5;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + speed.getSerializationSize()*checkOptBit(1) + z.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*8 + checkOptBit(4)*8;
}
};

bool
Reference To Follow::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (flags != 0) setOptBit(0);
if (!speed.isNull()) setOptBit(1);
if (!z.isNull()) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 5;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + speed.getSerializationSize()*checkOptBit(1) + z.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*8 + checkOptBit(4)*8;
}
};

bool
Reference To Follow::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (flags != 0) setOptBit(0);
if (!speed.isNull()) setOptBit(1);
if (!z.isNull()) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 5;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + speed.getSerializationSize()*checkOptBit(1) + z.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*8 + checkOptBit(4)*8;
}
};

bool
Reference To Follow::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (flags != 0) setOptBit(0);
if (!speed.isNull()) setOptBit(1);
if (!z.isNull()) setOptBit(2);
if (lat != 0) setOptBit(3);
if (lon != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 5;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + speed.getSerializationSize()*checkOptBit(1) + z.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*8 + checkOptBit(4)*8;
}
};

bool
Follow Reference State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (control_src != 0) setOptBit(0);
if (control_ent != 0) setOptBit(1);
if (!reference.isNull()) setOptBit(2);
if (state != 0) setOptBit(3);
if (proximity != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*2 + checkOptBit(1)*1 + reference.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*1 + checkOptBit(4)*1;
}
};

bool
Follow Reference State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (control_src != 0) setOptBit(0);
if (control_ent != 0) setOptBit(1);
if (!reference.isNull()) setOptBit(2);
if (state != 0) setOptBit(3);
if (proximity != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*2 + checkOptBit(1)*1 + reference.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*1 + checkOptBit(4)*1;
}
};

bool
Follow Reference State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (control_src != 0) setOptBit(0);
if (control_ent != 0) setOptBit(1);
if (!reference.isNull()) setOptBit(2);
if (state != 0) setOptBit(3);
if (proximity != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*2 + checkOptBit(1)*1 + reference.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*1 + checkOptBit(4)*1;
}
};

bool
Follow Reference State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (control_src != 0) setOptBit(0);
if (control_ent != 0) setOptBit(1);
if (!reference.isNull()) setOptBit(2);
if (state != 0) setOptBit(3);
if (proximity != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*2 + checkOptBit(1)*1 + reference.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*1 + checkOptBit(4)*1;
}
};

bool
Follow Reference State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (control_src != 0) setOptBit(0);
if (control_ent != 0) setOptBit(1);
if (!reference.isNull()) setOptBit(2);
if (state != 0) setOptBit(3);
if (proximity != 0) setOptBit(4);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*2 + checkOptBit(1)*1 + reference.getSerializationSize()*checkOptBit(2) + checkOptBit(3)*1 + checkOptBit(4)*1;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Vehicle State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op_mode != 0) setOptBit(0);
if (error_count != 0) setOptBit(1);
if (!error_ents.empty()) setOptBit(2);
if (maneuver_type != 0) setOptBit(3);
if (maneuver_stime != 0) setOptBit(4);
if (maneuver_eta != 0) setOptBit(5);
if (control_loops != 0) setOptBit(6);
if (flags != 0) setOptBit(7);
if (!last_error.empty()) setOptBit(8);
if (last_error_time != 0) setOptBit(9);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + checkOptBit(1)*1 + IMC::getSerializationSize(error_ents)*checkOptBit(2) + checkOptBit(3)*2 + checkOptBit(4)*8 + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1 + IMC::getSerializationSize(last_error)*checkOptBit(8) + checkOptBit(9)*8;
}
};

bool
Plan DB::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op != 0) setOptBit(1);
if (request_id != 0) setOptBit(2);
if (!plan_id.empty()) setOptBit(3);
if (!arg.isNull()) setOptBit(4);
if (!info.empty()) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + IMC::getSerializationSize(plan_id)*checkOptBit(3) + arg.getSerializationSize()*checkOptBit(4) + IMC::getSerializationSize(info)*checkOptBit(5);
}
};

bool
Plan DB::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op != 0) setOptBit(1);
if (request_id != 0) setOptBit(2);
if (!plan_id.empty()) setOptBit(3);
if (!arg.isNull()) setOptBit(4);
if (!info.empty()) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + IMC::getSerializationSize(plan_id)*checkOptBit(3) + arg.getSerializationSize()*checkOptBit(4) + IMC::getSerializationSize(info)*checkOptBit(5);
}
};

bool
Plan DB::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op != 0) setOptBit(1);
if (request_id != 0) setOptBit(2);
if (!plan_id.empty()) setOptBit(3);
if (!arg.isNull()) setOptBit(4);
if (!info.empty()) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + IMC::getSerializationSize(plan_id)*checkOptBit(3) + arg.getSerializationSize()*checkOptBit(4) + IMC::getSerializationSize(info)*checkOptBit(5);
}
};

bool
Plan DB::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op != 0) setOptBit(1);
if (request_id != 0) setOptBit(2);
if (!plan_id.empty()) setOptBit(3);
if (!arg.isNull()) setOptBit(4);
if (!info.empty()) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + IMC::getSerializationSize(plan_id)*checkOptBit(3) + arg.getSerializationSize()*checkOptBit(4) + IMC::getSerializationSize(info)*checkOptBit(5);
}
};

bool
Plan DB::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (op != 0) setOptBit(1);
if (request_id != 0) setOptBit(2);
if (!plan_id.empty()) setOptBit(3);
if (!arg.isNull()) setOptBit(4);
if (!info.empty()) setOptBit(5);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 2;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(1)*1 + checkOptBit(2)*2 + IMC::getSerializationSize(plan_id)*checkOptBit(3) + arg.getSerializationSize()*checkOptBit(4) + IMC::getSerializationSize(info)*checkOptBit(5);
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Plan Control State::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (state != 0) setOptBit(0);
if (!plan_id.empty()) setOptBit(1);
if (plan_eta != 0) setOptBit(2);
if (plan_progress != -1) setOptBit(3);
if (!man_id.empty()) setOptBit(4);
if (man_type != 65535) setOptBit(5);
if (man_eta != 0) setOptBit(6);
if (last_outcome != 0) setOptBit(7);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return checkOptBit(0)*1 + IMC::getSerializationSize(plan_id)*checkOptBit(1) + checkOptBit(2)*4 + checkOptBit(3)*4 + IMC::getSerializationSize(man_id)*checkOptBit(4) + checkOptBit(5)*2 + checkOptBit(6)*4 + checkOptBit(7)*1;
}
};

bool
Vehicle Links::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!localname.empty()) setOptBit(0);
if (!links.empty()) setOptBit(1);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(localname)*checkOptBit(0) + links.getSerializationSize()*checkOptBit(1);
}
};

bool
Vehicle Links::checkOptBit(uint32_t bitPosition) const
{
return opt_id & (1 << bitPosition);
}

void
setOptBit(uint32_t bitPosition)
{
opt_id |= (1 << bitPosition);
}

void
updateOptVar(void)
{
opt_id = 0;
if (!localname.empty()) setOptBit(0);
if (!links.empty()) setOptBit(1);
}

uint8_t*
serializeFieldsOptional(uint8_t* bfr__) const;

uint16_t
deserializeFieldsOptional(const uint8_t* bfr__, uint16_t size__);

unsigned
getFixedSerializationSize(void) const
{
return 1;
}

unsigned
getVariableSerializationSize(void) const
{
return IMC::getSerializationSize(localname)*checkOptBit(0) + links.getSerializationSize()*checkOptBit(1);
}
};
}
}

#endif
