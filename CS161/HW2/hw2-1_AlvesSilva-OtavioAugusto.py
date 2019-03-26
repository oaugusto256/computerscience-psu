# Created by Alves Silva, Otavio Augusto
# Email address: alves2@pdx.edu
# Date: 01/19/2015
# Jogging activity recorder - A program to record and calculate the distance, time and average pace for the user.

breakLoop = False # Condition for while statement 

print ("Welcome to the Running Activity Tracker") # Welcome the user to the program

totalDistance = float(input("Please tell me the previous total distance in miles: ")) # Ask the user for the previous total distance in miles
totalTime = float(input("Please tell me the previous total time in minutes: "))  # Ask the user for the previous total time in minutes

newDistance = float(input("Please tell me the most recent running distance in miles: ")) # Ask the user for the most recent distance in miles
newTime = float(input("Please tell me the most recent running time in minutes: ")) # Ask the user for the most recent time in minutes

totalDistance = totalDistance + newDistance # Calculate the total distance
totalTime = totalTime + newTime # Calculate the total time

print ("Average pace for this session:", round(newTime/newDistance,2) ,"minutes per mile.") # Reports the avarage pace for the user

# While the user's newDistance does not equal ALL DONE, the program continue asking for new distance and time
while(breakLoop == False):
    newDistance = input("Please tell me the most recent running distance in miles: ") # Ask the user for the most recent distance in miles
    if(newDistance == "ALL DONE"):
        breakLoop = True
    else:
        newDistance = float(newDistance)
        totalDistance = totalDistance + newDistance
        newTime = float(input("Please tell me the most recent running time in minutes: ")) # Ask the user for the most recent time in minutes
        totalTime = totalTime + newTime
        print ("Average pace for this session:", round(newTime/newDistance,2) ,"minutes per mile.") # Reports the avarage pace for the user

# Reports the total distance, total time and avarage total pace for the user
   
print ("\nNew total distance::", round(totalDistance,2), "miles.")
print ("New total time:", round(totalTime,2), "minutes.")
print ("Average Total Pace:", round(totalTime/totalDistance,2), "minutes per mile.")



