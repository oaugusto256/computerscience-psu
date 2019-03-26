/*
    Algorithm
    Start program
        Creates variables necessary to keep information form the .txt file
            Part number
            Description
            Amount
            Number of steps
            Steps
        Creates a variable to hold data from the stream
            File
        Create the ADT part and DIY(Organizer)
            A part
            Organizer
            
        Open the file called - parts.txt
        
        Loop - While has lines in the file
            Read and hold data until the ":" character 
            Turn to a integer and hold data
            Pass this data to the variable Part number
            
            Read and hold data until the ":" character 
            Pass this data to the variable Description
            
            Read and hold data until the ":" character 
            Turn to a integer and hold data
            Pass this data to the variable Amount
            
            Read and hold data until the ":" character 
            Turn to a integer and hold data
            Pass this data to the variable number of steps
            
            Loop - While the number of steps was not reached
                Read and hold data until the ":" character 
                Turn to a integer and hold data
                Pass this data to the variable steps[i]
            End Loop
            
            Try to create a part with these variables
                Try to insert this part in the list
                    Insert the part in the sorted crescent order
                
         End Loop
         
         Loop - While the option isn't 0 - EXIT
            Display the menu for the user
            If the user enter 1
                Display the list in order
            If the user enter 2
                Ask for the part number that he is looking for
                    If the list has the part
                        Display information
                    Else
                        Display that there hasn't the part
            Else
                Clear the terminal
                Display the menu for the user
         End Loop  
              
    End program
*/

/*
    Filename: parts.h
    Created by Alves Silva, Otavio Augusto
    Date: 15/04/2015    
    Class: CS 163 - Program #1
    Description: The purpose of this program is to auxiliar the organization of a 
    furniture parts. The program will read, organize and show the order of by number
    of each part. Therefore, we have the class part, which is an ADT of a furniture 
    part, and the DIY class, which is an ADT of a furniture organizer, as well as the
    prototypes, constructors and destructors of each class.  
*/

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

// ADT of a furniture part
class part
{   
    public:
        part();     // Constructor
        ~part();    // Destructor
        
        int create_part(int number, char * desc, int amount, int num_step, int * steps); // Creates a part with the provided arguments
        int display();                          //  Display part information
		int copy_part(const part & copy_from);  //  Copy information from the 
        int get_number();                       //  Get the part number for DIY organizes the order
        
    private:   
        int number;     //  Part number
        char * desc;    //  Description
        int amount;     //  Amount
        int num_step;   //  Number of step
        int * steps;    //  Steps
};

// Struct of a node 
struct node 
{
    part a_part;    //  A part in the list 
    node * next;    //  Pointer to the next node
};

// ADT of a furniture organizer
class DIY
{
    public:
        DIY();      // Constructor
        ~DIY();     // Destructor
        
        int insert_part(part & to_add); // Insert a part in the list
        int display_parts();            // Display all parts in the list
        int find_part(int num);         // Find a specific part in the list by the part number
        
    private:
        node * part_head;               // Head of the part list
};
