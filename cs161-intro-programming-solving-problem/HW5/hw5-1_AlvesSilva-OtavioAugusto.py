# Created by Alves Silva, Otavio Augusto
# Email address: alves2@pdx.edu
# Date: 02/28/2015
# Count word file program - A program to count the most common words in a .txt file

import string
import sys

# Function to read the file
def openFile():
    global file             # Variable to hold the .txt content
    done = False
    while not done:
            try:
                name = input("Enter the name of the file to read: ")
                if name == "ALL DONE":      # If the key word is ALL DONE the program is closed
                    sys.exit()
                file = open(name, "r")      # If not try to open the file
            except:
                    print("File", name, "unable to open.  Try another file name.")
            else:
                done = True                 # If everything occurred OK, the loop is done
                    
# Function to read each line in the file and create a dictionary with the amount of occurrences
def readLine(file):
    done = False
    global integerTotal     # Number of integer in the file
    integerTotal = 0
    global dictionary       # Dictionary
    dictionary = {}
    wordList = []

    for line in iter(file): # Loop to read each line in the file
        trans = line.maketrans(string.punctuation, " "*len(string.punctuation))  # Create a translation
        lineFormatted = line.translate(trans)                                    # Remove the punctuation of each line

        wordList = lineFormatted.split() # Create a list of the words in the line
            
        for word in wordList:              # Loop for each word in the list
            try:                           # Try to transform a word in a integer 
                integerTotal += int(word)  # If it is OK, append the integerTotal value
            except:
                try:                       # If not
                    dictionary[word] += 1  # Try to append the number of occurrences of that word
                except:
                    dictionary[word]  = 1  # If not work, create a dictionary with that word

# Function to output the results
def outputResults():
    print("\n\nThe total of integers in the file:", integerTotal)
    sortedList = sorted(dictionary, key=dictionary.get, reverse=True)  # Create a sorted list

    print("\nThe top 5 most common words in the file:")                # Print the most common words
    for i in sortedList[0:5]:
        print("   ", i, ":", dictionary[i] , "occurrences")
            
    print("\nThe 5 least common words in the file:")
    for i in sortedList[-5:]:                                          # Print the least common words
        print("   ", i,":", dictionary[i], "occurrences")
    
# Execute the program
openFile()
readLine(file)
outputResults()
file.close()
