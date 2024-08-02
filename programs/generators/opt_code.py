# -*- coding: utf-8 -*-
############################################################################
# Copyright 2007-2024 Universidade do Porto - Faculdade de Engenharia      #
# Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  #
############################################################################
# This file is part of DUNE: Unified Navigation Environment.               #
#                                                                          #
# Commercial Licence Usage                                                 #
# Licencees holding valid commercial DUNE licences may use this file in    #
# accordance with the commercial licence agreement provided with the       #
# Software or, alternatively, in accordance with the terms contained in a  #
# written agreement between you and Faculdade de Engenharia da             #
# Universidade do Porto. For licensing terms, conditions, and further      #
# information contact lsts@fe.up.pt.                                       #
#                                                                          #
# Modified European Union Public Licence - EUPL v.1.1 Usage                #
# Alternatively, this file may be used under the terms of the Modified     #
# EUPL, Version 1.1 only (the "Licence"), appearing in the file LICENCE.md #
# included in the packaging of this file. You may not use this work        #
# except in compliance with the Licence. Unless required by applicable     #
# law or agreed to in writing, software distributed under the Licence is   #
# distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     #
# ANY KIND, either express or implied. See the Licence for the specific    #
# language governing permissions and limitations at                        #
# https://github.com/LSTS/dune/blob/master/LICENCE.md and                  #
# http://ec.europa.eu/idabc/eupl.html.                                     #
############################################################################
# Author: Ricardo Martins                                                  #
############################################################################

from imc.utils import *
from imc.file import *
from imc.code import *
from imc.deps import *

CONST_NULL_ID = 65535

def is_bigger_than_any(number, num_list):
    return any(num > number for num in num_list)

def get_cxx_type(field_node):
    type = field_node.get('type')
    msg_type = field_node.get('message-type', 'Message')
    if type == 'plaintext':
        return 'std::string'
    elif type == 'rawdata':
        return 'std::vector<char>'
    elif type == 'message':
        return 'InlineMessage<%s>' % msg_type
    elif type == 'message-list':
        return 'MessageList<%s>' % msg_type
    else:
        return type

def is_fixed(field_node):
    type = field_node.get('type')
    if type == 'message':
        return False
    elif type == 'plaintext':
        return False
    elif type == 'rawdata':
        return False
    elif type == 'message-list':
        return False
    return True

def get_clear(field_node):
    rv = get_name(field_node)
    if is_fixed(field_node):
        rv += ' = 0'
    else:
        rv += '.clear()'
    return rv + ';'

def get_not_equal(field_node):
    name = get_name(field_node)
    return 'if ({0} != other__.{0}) return false;'.format(name)

def get_field_names(message):
    return [get_name(field) for field in message.findall('field')]

def call_inline_message_function(name, func, args):
    return 'if (!' + name + '.isNull())\n{\n' + \
           name + '.get()->' + func + '(' + args + ');\n' + \
           '}\n'
def call_message_list_function(name, func, args):
    return name + '.' + func + '(' + args + ');\n'

class Message:
    def __init__(self, root, node, hpp, cpp, consts):
        self._root = root
        self._node = node
        self._consts = consts
        self.optVar = []
        self.optional = False
        for index, field in enumerate(node.findall('field')):

            if (field.get('optional')):
                
                self.optional = True
                self.optVar.append(index)
        
        public = []
        protected = []

        # Optional functions to be used for optional variable functionality
        if (self.optional):
             # checkOptbit
            f = Function(node.get('name') + '::checkOptBit', 'bool', [Var('bitPosition', 'uint32_t')], const = True, inline = True)
            f.body('return opt_id & (1 << bitPosition);')
            public.append(f)
            # setOptBit 
            f = Function('setOptBit', 'void', [Var('bitPosition', 'uint32_t')], const = False, inline = True)
            f.body('opt_id |= (1 << bitPosition);')
            public.append(f)
            # UpdateOptVar
            # In the case the opt_id variable exists we will save the index of said variable
            f = Function('updateOptVar', 'void', const = False, inline = True)
            f.add_body('opt_id = 0;')
            for index, field in enumerate(node.findall('field')):
                # Here we will need to know which variables we are going to have to check
                if index in self.optVar:
                    if field.get('type') == 'rawdata' or field.get('type') == 'plaintext':
                        f.add_body('if (!{}.empty()) setOptBit({});'.format(get_name(field), index))
                    elif field.get('preset'):
                        f.add_body('if ({} != {}) setOptBit({});'.format(get_name(field),
                                                                field.get('preset').strip(), index))
                    elif field.get('type') == 'message':
                        f.add_body('if (!{}.isNull()) setOptBit({});'.format(get_name(field), index))
                    elif field.get('type') == 'message-list':
                        f.add_body('if (!{}.empty()) setOptBit({});'.format(get_name(field), index))
                    else:
                        f.add_body('if ({} != 0) setOptBit({});'.format(get_name(field), index))
            public.append(f)

        # serializeFieldsOptional()
        if (self.optional):
            f = Function('serializeFieldsOptional', 'uint8_t*', [Var('bfr__', 'uint8_t*')], const = True)
            f.add_body('uint8_t* ptr__ = bfr__;')
            # If add the optional identifier exists then serialize the optional id variable 
            f.add_body('ptr__ += IMC::serialize(opt_id, ptr__);')
            for index, field in enumerate(node.findall('field')):
                if field.get('type').startswith('message'):
                    f.add_body('if (checkOptBit({})) ptr__ += {}.serialize(ptr__);'.format(index, get_name(field)))
                elif index in self.optVar:
                    f.add_body('if (checkOptBit({})) ptr__ += IMC::serialize({}, ptr__);'
                                                        .format(index, get_name(field)) )
                else:
                    f.add_body('ptr__ += IMC::serialize(%s, ptr__);' % get_name(field))

            f.add_body('return ptr__;')
            public.append(f)

        # deserializeFieldsOptional()
        if(self.optional):
            f = Function('deserializeFieldsOptional', 'uint16_t', [Var('bfr__', 'const uint8_t*'), Var('size__', 'uint16_t')])
            f.add_body('const uint8_t* start__ = bfr__;')
            f.add_body('bfr__ += IMC::deserialize(opt_id, bfr__, size__);')
            for index,field in enumerate(node.findall('field')):
                if field.get('type').startswith('message'):
                    f.add_body('if (checkOptBit({})) bfr__ += {}.deserialize(bfr__, size__);'.format(index, get_name(field)))
                elif index in self.optVar:
                    f.add_body('if (checkOptBit({})) bfr__ += IMC::deserialize({}, bfr__, size__);'
                                        .format(index, get_name(field)) )
                else:
                    f.add_body('bfr__ += IMC::deserialize(%s, bfr__, size__);' % get_name(field))
            f.add_body('return bfr__ - start__;')
            public.append(f)        

        # getFixedSerializationSize()
        f = Function('getFixedSerializationSize', 'unsigned', const = True, inline = True)
        f.body('return ' + str(self.get_fixed_size()) + ';')
        public.append(f)

        # getVariableSerializationSize()
        var_size = str(self.get_variable_size())
        if var_size != '':
            f = Function('getVariableSerializationSize', 'unsigned', const = True, inline = True)
            f.body('return ' + var_size + ';')
            public.append(f)

        for function in public:
            if function.is_inline():
                hpp.append(function)
            else:
                hpp.append(function.decl())

        if len(protected) > 0:
            hpp.append('protected:')
            for function in protected:
                if function.is_inline():
                    hpp.append(function)
                else:
                    hpp.append(function.decl())

        hpp.append('};\n')

        # CPP.
        for function in public + protected:
            if not function.is_inline():
                function.set_class(node.get('abbrev'))
                cpp.append(function)

    def fields_to_json(self):
        lines = []
        for field in self._node.findall('field'):
            if field.get('type').startswith('message'):
                lines.append('{0}.toJSON(os__, "{0}", nindent__);'.format(get_name(field)))
            else:
                lines.append('IMC::toJSON(os__, "{0}", {0}, nindent__);'.format(get_name(field)))
        return '\n'.join(lines)

    def validate(field):
        min_value = field.get('min', None)
        cond = ''
        if min_value is not None:
            cond += '({0} < {1})'.format(get_name(field), min_value)

        max_value = field.get('max', None)
        if max_value is not None:
            cond += '({0} > {1})'.format(get_name(field), max_value)

    def get_fixed_size(self):

        size = 0

        if(self.optional):
            if is_bigger_than_any(15,self.optVar):
                size += 4
            elif is_bigger_than_any(7,self.optVar):
                size += 2
            else:
                size += 1 
            for index, field in enumerate(self._node.findall('field')):
                if index in self.optVar:
                    # This should be counted on the variable size method
                    size += 0
                else:
                    size += self._consts['sizes'][field.get('type')]
          
        return size

    def get_variable_size(self):
        size = []
        if (self.optional):
            for index, field in enumerate(self._node.findall('field')):
                type = field.get('type')
                abbrev = get_name(field)
                if index in self.optVar:
                    if type == 'plaintext' or type == 'rawdata':
                        size.append('IMC::getSerializationSize(%s)*checkOptBit(%d)' % (abbrev, index))
                    elif type == 'message' or type == 'message-list':
                        size.append(abbrev + '.getSerializationSize()*checkOptBit({})'.format(index))
                    else:
                        size.append("checkOptBit({})*{}".format(index, 
                                                self._consts['sizes'][field.get('type')]))

        return ' + '.join(size)

    # Retrieve a list of abbreviations of variable length fields.
    def get_variable_fields(self):
        ret = []
        for field in self._node.findall('field'):
            if field.get('type') in consts['variable_types']:
                ret.append(get_name(field))
        return ret

    def has_fields(self):
        return len(self._node.findall('field')) > 0

    def count_nested(self):
        return len(self._node.findall("field[@type='message']")) + \
               len(self._node.findall("field[@type='message-list']"))

# Parse command line arguments.
import argparse
parser = argparse.ArgumentParser(
    description="Strip, compress and generate IMC.xml blob.")
parser.add_argument('dest_folder', metavar='DEST_FOLDER',
                    help="destination folder")
parser.add_argument('-x', '--xml', metavar='IMC_XML',
                    help="IMC XML file")
parser.add_argument('-f', '--force', action='store_true', required=False,
                    help="Force creation of blob file")
args = parser.parse_args()

xml_md5 = compute_md5(args.xml)
dest_folder = args.dest_folder

# Parse XML specification.
import xml.etree.ElementTree as ET
tree = ET.parse(args.xml)
root = tree.getroot()

# Initialize constant values.
consts = {}

# Retrieve Git info.
import os
import subprocess
git_dir = os.path.dirname(args.xml)
consts['git_info'] = 'unknown'
cwd_old = os.getcwd()
os.chdir(git_dir)
try:
    consts['git_info'] = subprocess.check_output(['git',
                                                  'log',
                                                  "--pretty=format:%ad %h %d",
                                                  '--abbrev-commit',
                                                  '--date=short', '-1'],
                                                 universal_newlines = True).strip()
except:
    pass

os.chdir(cwd_old)

# Set MD5 sum.
consts['md5'] = xml_md5

# Retrieve synchronization number.
sync = root.find("header/field/[@fixed='true']").get('value')
consts['sync'] = sync
consts['sync_rev'] = sync[0:2] + sync[4:6] + sync[2:4]

# Retrieve version string.
consts['version'] = root.get('version').strip()

# Retrieve size of basic types.
consts['sizes'] = {}
consts['fixed_types'] = {}
consts['variable_types'] = {}
for t in root.findall('types/type'):
    min_size = int(t.get('size', 0))
    # Variable size types use at least 2 bytes when serialized.
    if min_size == 0:
        min_size = 0;
        consts['variable_types'][t.get('name')] = True
    else:
        consts['fixed_types'][t.get('name')] = True
    consts['sizes'][t.get('name')] = min_size

# Header size.
consts['header_size'] = 0
for f in root.findall("header/field"):
    consts['header_size'] += consts['sizes'][f.get('type')]

# Footer size.
consts['footer_size'] = 0
for f in root.findall('footer/field'):
    consts['footer_size'] += consts['sizes'][f.get('type')]



################################################################################
# Definitions.hpp                                                              #
################################################################################
hpp = File('DefOptSer.hpp', dest_folder, md5 = xml_md5)
hpp.add_isoc_headers('ostream', 'string', 'vector')
hpp.add_dune_headers('Config.hpp', 'IMC/Message.hpp',
                     'IMC/InlineMessage.hpp', 'IMC/MessageList.hpp',
                     'IMC/Enumerations.hpp', 'IMC/Bitfields.hpp',
                     'IMC/SuperTypes.hpp', 'IMC/JSON.hpp',
                     'IMC/Definitions.hpp')

################################################################################
# Definitions.cpp                                                              #
################################################################################
cpp = File('DefOptSer.cpp', dest_folder, md5 = xml_md5)
cpp.add_isoc_headers('algorithm','iostream', 'iomanip', 'string', 'cstdio')
cpp.add_dune_headers('Utils/ByteCopy.hpp', 'Utils/Utils.hpp',
                     'IMC/Exceptions.hpp', 'IMC/Definitions.hpp',
                     'IMC/Factory.hpp', 'IMC/Serialization.hpp',
                     'IMC/DefOptSer.hpp')

deps = Dependencies(root)
abbrevs = deps.get_list()

for abbrev in abbrevs:
    msg = root.find("message[@abbrev='%s']" % abbrev)

    for index, field in enumerate(msg.findall('field')):

      if (field.get('optional')):  
        Message(root, msg, hpp, cpp, consts)

      else:
          continue
        
hpp.write()
cpp.write()
