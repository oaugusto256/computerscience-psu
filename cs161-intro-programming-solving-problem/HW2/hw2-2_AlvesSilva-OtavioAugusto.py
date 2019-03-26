# Created by Alves Silva, Otavio Augusto
# Email address: alves2@pdx.edu
# Date: 01/19/2015s
# Dice Rolling - A program to simulate a dice rolling game.
 
import random # Import the random library.

totalValue = 0 # Initializes the variable which will receive the total value of the dice roll.

print ('Welcome to the dice roll simulator.') # Welcome the user to the program.

diceSides = int(input('How many sides does the dice have? ')) # Ask the user for how many sides the dice have
rollNumbers = int(input('How many times would you like to roll the dice? ')) # Ask the user for how many times the dice will roll

# Loop - While the number of roll is greater than zero, the dice will continue be rolled
while (rollNumbers > 0):
    diceRoll = random.randint(1, diceSides) # Receives a random number for 1 until the maximun number of diceSides
    if(diceRoll == 1): # Check if the diceRoll is 1 to print the right away
        print ("*" * diceRoll, ",", diceRoll, "dot.")
    else:
        print ("*" * diceRoll, ",", diceRoll, "dots.")
    rollNumbers = rollNumbers - 1
    totalValue = totalValue + diceRoll # Upload the total value

# Print the total value of all rolls    
print ('Total value of all rolls:', totalValue)

