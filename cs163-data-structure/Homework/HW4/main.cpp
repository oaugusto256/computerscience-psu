/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 05/30/2015    
    Class: CS 163 - Program #4
    Description: This file tests the ADT's and shows how the program could 
	be used by the user.
*/

#include "class.h"

void clear();   // Clear function
int menu();     // Menu function

int main()
{
	// Variables to create a new app in the system
	char name[SIZE];	
	char ** keywords;	
	char * keyword = new char[SIZE];	
	int amount_keys;		
	char desc[SIZE];	
	int rating;			
	
	table BST;		// ADT table - Binary Search Tree
	app an_app;		// ADT app
	
	int option;		// Option of the menu
	
	clear();		// Clear the system screen
	
	do					    // Loop for the menu
	{					
		option = menu();	// Shows the menu and receive the option
		
        switch(option)		// Loop for the menu
        {
            case 1:
				// If the option is 1
				// Receive data to create an new app 
				cout << "Please, enter the application name: ";
				cin.get(name, SIZE, '\n');
				cin.ignore(SIZE, '\n');
	
				do
				{
					cout << "Please, enter the number of keywords(0-5) for this application: ";
					cin  >> amount_keys; 
					cin.ignore(SIZE, '\n');
		
					if(amount_keys > 5 || amount_keys <= 0)
						cout << "ERROR! Please enter a number smaller than 6 and greater than 0!" << endl;
					
				}while(amount_keys > 5 || amount_keys <= 0);
				
				keywords = new char*[amount_keys];
				
	
				cout << "Please, enter the keywords for this application." << endl;
				for(int i = 0; i < amount_keys; i++)
				{
					keywords[i] = new char[SIZE];
					cout << "#" << i+1 << " - Keyword: ";
					cin.get(keywords[i], SIZE, '\n');
					cin.ignore(SIZE, '\n');
				}
				
				cout << "Enter a description for this application: ";
				cin.get(desc, SIZE, '\n');
				cin.ignore(SIZE, '\n');
	
				cout << "Enter a rating(0-5) for this application: ";
				cin >> rating;
				cin.ignore(SIZE, '\n');
				
				// Try to create a new app and add the new app in the system
				if(an_app.create_app(name,keywords,amount_keys,desc,rating))
				{
					// Insert the app in the BST
					if(BST.insert(keywords,amount_keys,an_app))
						cout << "\nThe app was successfully inserted!\n" << endl;
				}
				break;
			
			case 2:
				// If the option is 2
				// Display all apps in the BST
				if(!BST.display_all())
					cout << "The system doesn't has any app yet!\n" << endl;
				break;
			
			case 3:
				// If the option is 3
				// Remove all apps by a specifc keyword
				cout << "Enter the keyword to remove: ";
				cin.get(keyword, SIZE, '\n');
				cin.ignore(100, '\n');
				if(!BST.remove_by_keyword(keyword))
					cout << "The data wasn't found!\n" << endl;
				else
					cout << "The data was sucessfully removed!\n" << endl;
				
				break;
			case 4:
				// If the option is 4
				// Remove all apps
				if(!BST.remove_all())
					cout << "The tree is empty now!\n" << endl;
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
    
    cout << "----------------- SMART FIND APP ----------------" << endl;
    cout << "1 - Add an app to easily find in the future." << endl;
    cout << "2 - Display all apps in the system." << endl;
    cout << "3 - Remove an app or a group of apps by a keyword." << endl;
	cout << "4 - Remove all apps in the system." << endl;
	cout << "0 - Exit." << endl;
    
    do
    {
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore(100,'\n');
    }
    while(option < 0 && option > 4);
    
    clear();
    
    return option;
}