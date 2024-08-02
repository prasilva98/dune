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

###
# This file takes your IMC message-types and sets all to optional
### 

message_types_pre = [
  "CpuUsage", "Current", "DesiredHeading", "DesiredZ", "DevCalibrationControl", "DevCalibrationState",
  "Distance", "EmergencyControlState", "EntityActivationState", "EntityList", "EntityParameters","EntityState",
  "EstimatedState", "FollowRefState", "FuelLevel","GpsFix","GpsFixRejection","Heartbeat",
                                          "IridiumMsgRx",
                                          "IridiumMsgTx",
                                          "IridiumTxStatus",
                                          "LblEstimate",
                                          "LblRange",
                                          "LblRangeAcceptance",
                                          "LblConfig",
                                          "LogBookEntry",
                                          "LogBookControl",
                                          "OperationalLimits",
                                          "PathControlState",
                                          "PlanControl",
                                          "PlanControlState",
                                          "PlanDB",
                                          "PlanGeneration",
                                          "PowerChannelState",
                                          "QueryEntityParameters",
                                          "RemoteActions",
                                          "RemoteActionsRequest",
                                          "Rpm",
                                          "SaveEntityParameters",
                                          "SetEntityParameters",
                                          "SimulatedState",
                                          "StorageUsage",
                                          "Temperature",
                                          "VehicleState",
                                          "Voltage"]


message_types = [ "AcousticOperation",
                                          "AcousticRequest",
                                          "AcousticStatus",
                                          "AcousticSystems",
                                          "AlignmentState",
                                          "CpuUsage",
                                          "DevCalibrationControl",
                                          "DevCalibrationState",
                                          "Distance",
                                          "EntityList",
                                          "EntityParameters",
                                          "EntityParameter",
                                          "EntityState",
                                          "EstimatedState",
                                          "FollowRefState",
                                          "FuelLevel",
                                          "Heartbeat",
                                          "IridiumMsgRx",
                                          "IridiumMsgTx",
                                          "IridiumTxStatus",
                                          "LblEstimate",
                                          "LblRangeAcceptance",
                                          "LblConfig",
                                          "LogBookEntry",
                                          "LogBookControl",
                                          "ManeuverDone",
                                          "OperationalLimits",
                                          "PathControlState",
                                          "PlanControl",
                                          "PlanStatistics",
                                          "PlanControlState",
                                          "PlanDB",
                                          "PlanDBState",
                                          "PlanDBInformation",
                                          "PlanGeneration",
                                          "PowerChannelState",
                                          "ReportControl",
                                          "RemoteActions",
                                          "RemoteActionsRequest",
                                          "Rpm",
                                          "RSSI",
                                          "SadcReadings",
                                          "Salinity",
                                          "SimulatedState",
                                          "SmsRequest",
                                          "SmsStatus",
                                          "SoiCommand",
                                          "SoiState",
                                          "SonarData",
                                          "StateReport",
                                          "StorageUsage",
                                          "TCPRequest",
                                          "TCPStatus",
                                          "Temperature",
                                          "TextMessage",
                                          "TransmissionRequest",
                                          "TransmissionStatus",
                                          "TrexObservation",
                                          "TrexOperation",
                                          "TrexToken",
                                          "TrexPlan",
                                          "Turbidity",
                                          "UamTxFrame",
                                          "UamRxFrame",
                                          "UamTxStatus",
                                          "UamRxRange",
                                          "UsblAnglesExtended",
                                          "UsblPositionExtended",
                                          "UsblFixExtended",
                                          "UsblModem",
                                          "UsblConfig",
                                          "VehicleMedium",
                                          "VehicleState",
                                          "Voltage",
                                          "DeviceState",
                                          "BeamConfig"]

message_types = ["PlanControl",
                "PlanControlState",
                "EstimatedState",
                "VehicleState",
                "StateReport",
                "FuelLevel",
                "PlanStatistics",
                "Aborted"
]

# Parse command line arguments.
import argparse
parser = argparse.ArgumentParser(
    description="Edit the IMC.xml file")
parser.add_argument('-x', '--xml', metavar='IMC_XML',
                    help="IMC XML file")

args = parser.parse_args()
xml_md5 = compute_md5(args.xml)

# Parse XML specification.
import xml.etree.ElementTree as ET
tree = ET.parse(args.xml)
root = tree.getroot()
deps = Dependencies(root)

nested_message_types = []


for abbrev in message_types:
    msg = root.find("message[@abbrev='%s']" % abbrev)
    # First I have to check if the fields are nested message   
    print(abbrev) 

    for field in msg.findall('field'):
        if field.get('message-type'):
            print("Nested message type: {}".format(field.get('message-type')))
            nested_message_types.append(field.get('message-type'))

message_types.extend(nested_message_types)

print(message_types)

for messages in message_types:
    msg = root.find("message[@abbrev='%s']" % messages)

    for field in msg.findall('field'):
        print(field.get('name'))
        field.set('optional', 'True')

tree.write('../../imc/modified.xml')



        
