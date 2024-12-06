'''
Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1222

By Soliman Elhassanein

TC: O( n )
MC: O( n )

Date: 06-Dec-2024
'''

from datetime import datetime


import sys
input_lines = sys.stdin.read().strip().split("\n")

# Initialize variables
last_time = datetime.strptime("00:00:00", "%H:%M:%S")
current_speed = 0  # km/h
total_distance = 0.0  # km
results = []

# Process each line of input
for line in input_lines:
    if " " in line:  # Speed change line
        time_str, speed_str = line.split()
        new_time = datetime.strptime(time_str, "%H:%M:%S")
        new_speed = int(speed_str)

        # Calculate distance for the interval
        elapsed_seconds = (new_time - last_time).total_seconds()
        total_distance += (elapsed_seconds / 3600.0) * current_speed

        # Update state
        last_time = new_time
        current_speed = new_speed
    else:  # Query line
        query_time = datetime.strptime(line, "%H:%M:%S")

        # Calculate distance for the interval
        elapsed_seconds = (query_time - last_time).total_seconds()
        query_distance = total_distance + (elapsed_seconds / 3600.0) * current_speed

        # Append result
        results.append(f"{line} {query_distance:.2f} km")

# Print results
for result in results:
    print(result)
