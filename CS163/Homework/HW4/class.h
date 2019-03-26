/* Algorithm
	Start program
		Creates variables to keep information from a app order
			App name
			Array of keywords
			Number of keywords
			App description
			Rating
		Create ADT app and table
			An app	
			BST - Binary Search Tree
		Loop - While the option isn't 0 - EXIT
			Display the menu for the user
				If the option is 1 - Add an app
					Take the app information
					Create an app
					Recursive function
						If the value is bigger go to traverse to right
							Insert the tree by the key value
						Else go to left
							Insert the tree by the key value

				If the option is 2 - Display all apps
					Recursive function
						Function is called to left
						Display app
						Function is called to right

				If the option is 3 - Remove an app by specific keyword
					Recursive function
						Find the key position with the keyword
						Try to match the keyword with app which the node is point
						If match
							Check if it has one child, two children or is leaf
							Execute the right algorithm to delete
							Delete the node
						Else
							Function is called to left and right

				If the option is 4 - Delete all
					Recursive function
						Call to left
						Function is called to left
						Delete node
						Function is called to right

				If the option is 0
					Close the application
				Else
					Clear the terminal
					Display the menu for the user
		End loop
	End program
*/

/*
    Filename: class.h
    Created by Alves Silva, Otavio Augusto
    Date: 05/30/2015    
    Class: CS 163 - Program #4
    Description: The purpose of this program is to simulate an away to storage some information
	about smartphone applications to easily find in the future. We are goind to use a BST to organize
	thse information The program will take care of some informations, which are the app name, keywords, 
	description and a rating of the app. Therefore, in this file we have the ADT (Application and Table) 
	to bring life to this program, as well as the prototypes, constructors and destructors of each class.  
*/

#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

int const SIZE = 100;

// ADT of an app
class app
{
	public:
		app();				// Constructor
		~app();				// Destructor
		
		int create_app(char * name, char ** key_words, int key_len, char * desc, int rating);
		int retrieve(char * keyword, app & to_retrieve);	// Retrieve information from the ADT
		int copy_info(const app & copy_from);				// Copy information from the ADT
		int display_info();									// Display the app information
		
	private:
		char * name;	  // App name
		char ** keywords; // List of keywords of this app
		int amount_keys;  // Amount of keywords of this app
		char * desc;	  // App description 
		int rating;		  // App rating
};

struct node
{
	app  * an_app;		  // Pointer to an app
	node * left;		  // Pointer to the left child
	node * right;		  // Pointer to the right child
	int  key;			  // Key node
};

class table
{
	public:
		table();		  // Constructor
		~table();		  // Destructor
		
		int hash_function(char * keyword) const;	// Hash function
		
		// Wrapper functions
		int insert(char ** keywords, int amount_keys, const app & to_insert);	// Insert an app in the tree
		int display_all();							// Display all apps in the tree
		int remove_by_keyword(char * keyword);		// Remove all nodes with a specifc keyword
		int find_the_minimun(char * keyword, app & to_retrieve);			  // Find the inorder successor
		int remove_all();							// Remove all nodes
	
	private:
		node * root;
		
		// Recursive functions
		int insert(node * & root, int key, app * & to_insert);
		int display_all(node * root);
		int remove_by_keyword(node * & root, char * keyword);
		int find_the_minimun(node * & root, char * keyword, app & to_retrieve);
		int remove_all(node * & root);
};