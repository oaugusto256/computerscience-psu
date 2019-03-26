/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 07/20/2015    
    Class: CS 202 - Program #2
    Description: This file tests the ADT's and shows the game execution.
*/

#include "class.h"

void clear();   // Clear function
int menu();     // Menu function

int main()
{
	player a_player;		// Player object
	
	level_one stage_one;	// Maze level one
	level_two stage_two;	// Maze level two
	
	level * level1 = &stage_one;	// Level pointers
	level * level2 = &stage_two;	// Level pointers
	
	int result;
	bool player_info = false;
	int option;
	
	clear();
	
	do					    // Loop for the menu
	{					
		option = menu();	// Shows the menu and receive the option
		
        switch(option)		// Loop for the menu
        {
            case 1:
				a_player.read();	// Read the player information
				player_info = true;
				clear();
				cout << "The player information were succesuly received!" << endl;
				break;
			case 2:
				if(player_info) 	// Checks if the player infor have already been read
				{
					level1->build();// Build the level one
					result = level1->walk(a_player);	// Walk the maze with the player
				
					if(result == 1)// If the player passed the first level
					{
						level2->build();	// Walk the maze with the player
						result = level2->walk(a_player);// Walk the maze with the player
					}
					else
						cout << "You can't go to the next level of the maze! Try again!" << endl;
				}
				else
					cout << "Please, enter the player information first!" << endl;
				break;
			case 3:
				if(player_info)	// Checks if the player infor have already been read
					a_player.display();	// Display the player information
				else
					cout << "Please, enter the player information first!" << endl;
				break;
			default:
				clear();
		}
	}while(option != 0);
	
	clear();
	
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