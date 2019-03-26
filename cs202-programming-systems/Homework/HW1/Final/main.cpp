/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 07/13/2015    
    Class: CS 202 - Program #1
    Description: This file tests the ADT's and shows the game execution.
*/

#include "class.h"

void clear();   // Clear function
int menu();     // Menu function

int main()
{
	maze a_maze;	// The maze
	int option;		// Menu option
	
	clear();
	
	do					    // Loop for the menu
	{					
		option = menu();	// Shows the menu and receive the option
		
        switch(option)		// Loop for the menu
        {
            case 1:
				a_maze.read_player();	// Read the player information
				clear();
				cout << "The player information were succesuly received!" << endl;
				break;
			case 2:
				a_maze.start_a_game();		// Start the game 
				break;
			case 3:
				a_maze.display_player();	// Display the player information
				break;
			default:
				clear();
		}
	}while(option != 0);
	
	return 0;
}

void clear(void)
{
    cout << "\033[H\033[J";
}

int menu()
{
    int option;
    
    cout << "------------------- THE MAZE GAME -------------------" << endl;
    cout << "1 - Enter a player information." << endl;
    cout << "2 - Start a new game with the player." << endl;
    cout << "3 - Display player records of the last game." << endl;
	cout << "0 - Exit." << endl;
    
    do
    {
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore(100,'\n');
    }
    while(option < 0 && option > 3);
    
    clear();
    
    return option;
}