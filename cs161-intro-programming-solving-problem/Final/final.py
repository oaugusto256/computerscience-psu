import string
import sys


def openFile1():
    # Variable to hold the .txt content
    done = False
    while not done:
        try:
            name = input("Enter the name of the fiel1 to read: ")
            file = open(name, "r")      # If not try to open the file
        except:
            print("File", name, "unable to open.  Try another file name.")
        else:
            done = True                 # If everything occurred OK, the loop is done
            return file


def openFile2():
    # Variable to hold the .txt content
    done = False
    while not done:
        try:
            name = input("Enter the name of the fiel2 to read: ")
            file = open(name, "r")      # If not try to open the file
        except:
            print("File", name, "unable to open.  Try another file name.")
        else:
            done = True                 # If everything occurred OK, the loop is done
            return file


def readLine(file):
    wordList = []

    for line in iter(file):  # Loop to read each line in the file
        wordList += line.split()

    return wordList


def countWords(list1, list2):
    dictionary = {}
    for word2 in list2:
        dictionary[word2] = 0

    for word1 in list1:
        for word2 in list2:
            if word1 == word2:
                try:
                    # Try to append the number of occurrences of that word
                    dictionary[word2] += 1
                except:
                    # If not work, create a dictionary with that word
                    dictionary[word2] = 1

    return dictionary


def outputResults(dictionary, list2):
    lenList2 = len(list2)
    sortedList = sorted(dictionary, key=dictionary.get, reverse=True)
    # Print the most common words
    print("\nThe amount occurs of words in file1 in file2 are:")
    for i in sortedList[0:lenList2]:
        print("   ", i, "occurs", dictionary[i], "times")


file1 = openFile1()
file2 = openFile2()

wordList1 = readLine(file1)
wordList2 = readLine(file2)

dictionaryWord = countWords(wordList1, wordList2)

outputResults(dictionaryWord, wordList2)
