import argparse
import os
import gzip
import shutil
import sys

def parse_seconds_from_stamp(time_str):

  if len(time_str) != 6:

    raise ValueError("Time string should be 6 digits long")

# Extract hours, minutes and seconds and return total number of seconds 

  hours = int(time_str[0:2])
  minutes = int(time_str[2:4])  
  seconds =  int(time_str[4:6])

  seconds += (hours*3600) + (minutes*60)

  return seconds
  
# Parser for command line
parser = argparse.ArgumentParser(description="Process arguments for Concatenation Script")

# Minimum time argument
parser.add_argument('-t','--min_time', type=int, default=2,
                     help="Minimum length of log (in min) to be used. Preset is 2 min")
# Path to the mission argument
parser.add_argument('-p', '--mission_path', type=str, default=os.getcwd(),
                     help="Specify path to the actual logs. Preset is your current location")
# Plan ID
parser.add_argument('-id', '--mission_planid', type=str,
                      help="Type the plan_id of the mission (-id soi_plan). If its empty all plans will be used")
# Start Time
parser.add_argument('-s', '--start_time', type=str,
                      help="Logs should be after this daytime. Specify in HHMMSS format (ex: 130599). If empty logs the whole days are used.")

# Parse the argument and save it
args = parser.parse_args()
min_time= args.min_time
logs_path = args.mission_path
plan_id = args.mission_planid
start_time = args.start_time

if start_time:
  if len(start_time) != 6:
    sys.exit()

print("Any log with less than {} minutes will NOT be used".format(min_time))
print("Logs path is: {}".format(logs_path))

logs = []
# Iterate through all the logs in the log path and save the ones relevant
for log in os.listdir(logs_path):
  # All logs should start with a time HHMMSS format 
  if str(log)[0].isdigit():
    logs.append(log)
  else: 
    print("File or folder {} NOT a log".format(log))

# Sort the logs alphabetically
logs.sort()
logs_sorted = []

# With the sorted logs we can now check the duration of each by subtracting the current and the next one
if min_time != 0: 
  print("\n ### START OF DURATION PARSER ### \n")
  for index, log in enumerate(logs[:]):

    if not (index + 1 == len(logs[:])):
      # Get the start and end time from the names of the folders
      end = parse_seconds_from_stamp(logs[index + 1].split('_')[0])
      start = parse_seconds_from_stamp(log.split('_')[0])
      dur = end - start
      
      # If the duration of the log is actually bigger than it is required then concatenate it
      if dur > min_time*60:
        logs_sorted.append(log)
      else: 
        print("Log {} DELETED. DURATION: {:.2f} min below THRESHOLD".format(log, dur/60))

  logs_sorted.sort()
  logs = logs_sorted
else: 
  print("No Duration stated. Default of 3 min will be used")

# If a mission is before the minimum daytime, remove it
if start_time:
  print(" \n ### START OF DAYTIME PARSER ### \n ")
  # Get the full seconds
  start_time_sec = parse_seconds_from_stamp(start_time)

  for log in logs[:]:
    if start_time_sec > parse_seconds_from_stamp(log.split('_')[0]):
      print("Log {} REMOVED. Daytime below {}".format(log, start_time))
      logs.remove(log)

  logs.sort()

else:
  print("\n No minimum daytime specified")

# if a mission id is specified, only use the name of it 
if plan_id:
  print(" \n ### START OF PLAN ID PARSER ### \n ")
  for log_name in logs[:]: 
    if not plan_id in str(log_name):
      logs.remove(log_name)
      print('{} log NOT included. REASON: Not part of {} plan'.format(log_name, plan_id))
else: 
  print("No plan id specified. All plan names are valid")
  
logs.sort()
print(logs)

# Possible sort the logs from a certain time
date = os.path.basename(logs_path)
vehicle = logs_path.split('/')
vehicle = vehicle[len(vehicle) - 2]
mission_name = vehicle + '_' + date + '_full.lsf' 

conc_file = os.path.join(logs_path, mission_name)
with open(conc_file, 'wb') as outfile:

  print("\n ### Concatenation Start ### \n")
  # With the sorted logs we can now check the duration of each by subtracting the current and the next one
  for log in logs:
      # Check and find data.lsf.gz inside each file
      log_path = os.path.join(logs_path,log)
      for f in os.listdir(log_path):
        if str(f) == 'Data.lsf.gz':
          zipped_log = os.path.join(log_path,f)
          unzipped_log = log_path + '/Data.lsf'
          # Unzip the log
          with gzip.open(zipped_log, 'rb') as f_in:
            with open(unzipped_log, 'wb') as f_out:
              try:
                print("Concating log {} with size: {:.2f} MB".format(log, (os.path.getsize(zipped_log) / 1024) / 1024))
                shutil.copyfileobj(f_in, f_out)
              except Exception as e:
                print("Error {} ON {} log".format(e,log))
          # Copy the contents to the new file
          with open(unzipped_log, 'rb') as f_in:
            shutil.copyfileobj(f_in, outfile)
              




  







