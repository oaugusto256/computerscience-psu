/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 15/04/2015    
    Class: CS 163 - Program #1
    Description: This file tests the ADT's and show how could the program be used.
*/

#include "parts.h"

const int SIZE = 50;    

void clear();   // Clear function
int menu();     // Menu function

int main()
{
    // Variables to hold data from the text file
    int number;      
    char * desc;     
    int amount;      
    int number_step; 
    int * steps;     
    
    part a_part;     // ADT part
    DIY organizer;   // ADT organizer
        
    ifstream file;   // Variable to input the text file
    char line[SIZE]; // Variable to hold each line in the text file
    char * aux;      // Auxiliar char pointer to hold each data from the text file
    
    int opt;         // Variable to receive the option of the menu
    
    file.open("parts.txt"); // Read file
    
    if(file)                // If the file has something 
    {
        while(file.getline(line, SIZE, '\n'))   // While there is lines to read
        {
            aux = strtok(line,":");     // Split the line until ":" and take the str aux
            number = atoi(aux);         // Turn the str into a integer 
        
            aux = strtok(NULL, ":");        // Split the line until ":" and take the str aux
            desc = new char[strlen(aux)+1]; // Allocate memory
            strcpy(desc, aux);              // Copy the string to desc
    
            aux = strtok(NULL,":");     // Split the line until ":" and take the str aux
            amount = atoi(aux);         // Turn the str into a integer
    
            aux = strtok(NULL,":");     // Split the line until ":" and take the str aux
            number_step = atoi(aux);    // Turn the str into a integer
        
            steps = new int[number_step];           // Allocate memory
            for(int i = 0; i < number_step; i++)    // For each step
            {
                aux = strtok(NULL,":");    // Split the line until ":" and take the str aux
                steps[i] = atoi(aux);      // Turn the str into a integer 
            }
    
            if(a_part.create_part(number, desc, amount, number_step, steps))  // Try to create a part with these data
            {
                if(!organizer.insert_part(a_part))      // Try to insert this part in the list
                    cout << "Error to add!" << endl;    // If return is failed
            }
        }
        file.close();   // Close the file
    }
       
   do   // Loop for the menu
    {
        opt = menu(); // Shows the menu and receive the option
        
        switch(opt)
        {
            case 1:  // If option is 1
                    if(!organizer.display_parts()) // Displays all parts
                        cout << "Error!" << endl;  // If return is failed
                    break;
            case 2: // If option is 2
                    int number_to_find;                      
                    cout << "Enter a part number to find: "; // Ask and receive the part number
                    cin >> number_to_find;                   // to find in the list  
                    
                    if(!organizer.find_part(number_to_find))            // Try to find the part by the number 
                        cout << "Part number was not found!" << endl;   // If return is failed
                    break;
            default: 
                    clear();
            
        }
    }
    while(opt != 0);
    
    return 0;
}

void clear(void)
{
    cout << "\033[H\033[J";
}


int menu()
{
    int opt;
    
    cout << "============ MENU =============" << endl;
    cout << "1 - Display all parts in order." << endl;
    cout << "2 - Display part by number." << endl;
    cout << "0 - Exit." << endl;
    
    do
    {
        cout << "Enter an option: ";
        cin >> opt;
        cin.ignore(100,'\n');
    }
    while(opt < 0 && opt > 3);
    
    clear();
    
    return opt;
}

