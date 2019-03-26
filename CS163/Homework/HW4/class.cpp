/*
    Filename: class.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 05/30/2015    
    Class: CS 163 - Program #4
    Description: This file contains the functions of the class.h 
*/

#include "class.h"

// ------------------------------------ APP -----------------------------------

// Constructor
app::app()
{
	name = NULL;
	keywords = NULL;
	amount_keys = 0;
	desc = NULL;
	rating = 0;
}

// Destructor
app::~app()
{
	delete [] name;
	name = NULL;
	
	for(int i = 0; i < amount_keys; ++i)
	{
		delete [] keywords[i];
		keywords[i] = NULL;
	}
	
	delete keywords;
	keywords = NULL;
	
	delete [] desc;
	desc = NULL;
}

// This function create an app 
// with the provided arguments
int app::create_app(char * new_name, char ** new_keywords, int new_amount_keys, char * new_desc, int new_rating)
{
	if(!new_name)
		return 0;
	
    name = new char[strlen(new_name)+1];
    strcpy(name, new_name);
	
	amount_keys = new_amount_keys;
	
	keywords = new char*[amount_keys];
	for(int i = 0; i < amount_keys; ++i)
	{
		keywords[i] = new char[strlen(new_keywords[i])+1];
		strcpy(keywords[i], new_keywords[i]);
	}
	
    desc = new char[strlen(new_desc)+1];
    strcpy(desc, new_desc);
	
	rating = new_rating;
	
	return 1;
}

// This function takes the argument 
//and copies it into the app's data members
int app::copy_info(const app & copy_from) 
{
	// If the argument doesn't have data
	if(!copy_from.name)
		return 0;	// Return failed 

    // If the data members already have some thing, 
    // we have to deallocate any memory
    if(name)
        delete [] name;
	
	if(keywords)
	{
		for(int i = 0; i < amount_keys; ++i)
			delete [] keywords[i];
	}
	
	if(desc)
		delete [] desc;
	
	// Setting pointers to NULL for safety
	name = NULL;
	keywords = NULL;
	desc = NULL;
	
	// Starting perform a deep copy
    name = new char[strlen(copy_from.name)+1];
    strcpy(name, copy_from.name);
	
	amount_keys = copy_from.amount_keys;
	
	keywords = new char*[amount_keys];
	
	for(int i = 0; i < amount_keys; ++i)
	{
		keywords[i] = new char[strlen(copy_from.keywords[i])+1];
		strcpy(keywords[i], copy_from.keywords[i]);
	}
	
    desc = new char[strlen(copy_from.desc)+1];
    strcpy(desc, copy_from.desc);
	
	rating = copy_from.rating;
	
	return 1;	// Return success
}

// This function retrieve the information to 
// the ADT provided, but the keyword must be the same
int app::retrieve(char * keyword, app & to_retrieve)
{
	bool match = false;
	
	// Checking with the ADT has the provided key_value
	for(int i = 0; i < amount_keys; i++)
	{
		if(!strcmp(keyword, keywords[i]))
			match = true;
	}
	
	// If there is the keyword, the retrieve occurs
	if(match)
	{
	
		if(to_retrieve.name)
		{
			delete [] to_retrieve.name;
			to_retrieve.name = NULL;
		}
	
		if(to_retrieve.keywords)
		{
			for(int i = 0; i < to_retrieve.amount_keys; ++i)
				delete [] to_retrieve.keywords[i];
		}
	
		if(to_retrieve.desc)
		{
			delete [] to_retrieve.desc;
			to_retrieve.desc = NULL;
		}
	
		to_retrieve.name = new char[strlen(name)+1];
		strcpy(to_retrieve.name, name);
	
		to_retrieve.amount_keys = amount_keys;
	
		to_retrieve.keywords = new char*[amount_keys];
	
		for(int i = 0; i < to_retrieve.amount_keys; ++i)
		{
			to_retrieve.keywords[i] = new char[strlen(keywords[i])+1];
			strcpy(to_retrieve.keywords[i], keywords[i]);
		}
	
		to_retrieve.desc = new char[strlen(desc)+1];
		strcpy(to_retrieve.desc, desc);
	
		to_retrieve.rating = rating;
	}
	
	if(match)
		return 1;	// Success
	else
		return 0;	// Failed
}

// This function displays the app information
int app::display_info()
{
	if(!name)
		return 0;
	
	cout <<"App name: " << name << endl;
	cout <<"Key words: ";
	
	for(int i = 0; i < amount_keys; i++)
	{
		if(i == amount_keys-1)
			cout << "#" << i+1 << "- "<<  keywords[i] << "." << endl;
		else
			cout << "#" << i+1 << "- "<<  keywords[i] << ", ";		
	}
	
	cout <<"Description: " << desc << endl;
	cout <<"Rating: " << rating << endl;
	cout << "-------------------------------------------------" << endl;
	
	return 1;
}

// ---------------------------------- TABLE -----------------------------------

// Constructor
table::table()
{
	root = NULL;		// Root tree is NULL
}

// Destructor
table::~table()
{
	remove_all(root);   // Remove all nodes recursively 
}

// Hash function
int table::hash_function(char * keyword) const
{
	int key, len, value = 0;	// Variables to store the key
								// The len of the keyword
								// The keyword value
	                                                                                                                                                 
	len = strlen(keyword);   	// Take the len                                       
	for(int i = 0; i < len; i ++)                                                     
		value += keyword[i]; 	// Sum all ASCII values of this keyword
	
	key = value % 250;			// Modulize the value and receive the key
		  
	return key;					// Return the key
}

// ----------------------------- WRAPPER FUNCTIONS ----------------------------

// This function insert an app in the tree
int table::insert(char ** keywords, int amount_keys, const app  & to_insert)
{
	int key;						// Variable to hold key of the keywords
	
	app * new_app = new app;		// Create a new app
	new_app->copy_info(to_insert);	// Copy informations of the 
									// argument to this new app
	
	for(int i = 0; i < amount_keys; ++i)	// For each keyword
	{		
		key = hash_function(keywords[i]); 	// Take the key value
		insert(root, key, new_app);			// Inser an app in the tree
	}
	
	return 1;	// Success
}

// Calls the function to display all nodes in the tree
int table::display_all()
{
	return display_all(root);
}

// Calls the function to remove a node by a specific keyword
int table::remove_by_keyword(char * keyword)
{
	return remove_by_keyword(root, keyword);
}

// Calls the function to remove all nodes 
int table::remove_all()
{
	return remove_all(root);
}

// Calls the function to find the inorder successor and retrieve
int table::find_the_minimun(char * keyword, app & to_retrieve)
{
	return find_the_minimun(root, keyword, to_retrieve);
}

// ---------------------------- RECURSIVE FUNCTIONS ---------------------------

// This function finds the inorder successor
// And replace by node which will be deleted
int table::find_the_minimun(node * & root, char * keyword, app & to_retrieve)
{	
	if(root) // If there is something
	{
		while(root->left)		// While there is a left child
			root = root->left;	// Traverse through the left children
	}
	
	// Retrieve the inorder successor 
	to_retrieve.retrieve(keyword, *root->an_app); 
	
	delete root;	// Delete root
	root = NULL;	// Point to NULL
	
	return 1;		// Success 
}

// This function insert the an app
// And replace by node which will be deleted
int table::insert(node * & root, int key, app * & to_insert)
{
	if(!root)	// If the base case is reached
	{
		root = new node;				 // Creates a new node
		root->an_app = to_insert;		 // Point the pointer of the node to the app
		root->left = root->right = NULL; // Point the node children to NULL
		root->key  = key;				 // Receives the node key
		return 1;
	}
	// If the key is less than the root->key
	// The function goes to the left
	// Else it goes to the right 
	else if(key < root->key)
		return insert(root->left, key, to_insert);
	else
		return insert(root->right, key, to_insert);
}

// This function displays all nodes in the inorder traversal
int table::display_all(node * root)
{					
				  // If the base case is reached
	if(!root)	  // Or if the tree is empty return
		return 0;
	else
	{					// Auxiliar variable to hold a value to check
		int value = 1;	// if the tree is not empty
		
		value += display_all(root->left);	// Calls rercusively to the left
		root->an_app->display_info();		// Display the app information
		value += display_all(root->right);  // Calls rercusively to the right
		
		return value;    // Return the functions
	}
}

// This function removes all nodes 
// or a specific node in the tree
int table::remove_by_keyword(node * & root, char * keyword)
{
	if(!root)		// If the base case is reached 
		return 0;	// Return 0
	
	// Receives a key by the provided keyword
	int key = hash_function(keyword);
	
	if(key == root->key) 	// If there is a match
	{
		// Call the function recursively by all nodes
		// To find repeated nodes with a specific key
		int value = remove_by_keyword(root->left, keyword) + remove_by_keyword(root->right, keyword);
		
		// If the node is a leaf
		if(!root->left && !root->right)
		{
			delete root;	// Delete the node
			root = NULL;	// Point to NULL
			value += 1;		// Increase by onde the auxiliar variable
		}			
		// If the node has a right child
		else if(!root->left)
		{
			node * temp = root;	// Create a auxiliar varible to hold root
			root = root->right;	// Root now is the  right child 
			delete temp;	// Delete the node
			temp = NULL;	// Point to NULL
			value += 1;		// Increase by one the auxiliar variable
		}
		// If the node has a left child
		else if(!root->right)
		{
			node * temp = root;	// Create a auxiliar varible to hold root
			root = root->left;	// Root now is the left child
			delete temp;		// Delete the node
			temp = NULL;		// Point to NULL
			value += 1;			// Increase by one the auxiliar variable
		}
		// If the node has a left child and a right child
		else
		{
			app to_retrieve;	// Create an app to retrieve the
								// information from the inorder successor
										
 			// Retrieve the information from the inorder successor
			// Replace by the current app by the retrieved app		
			find_the_minimun(root->right, keyword, to_retrieve);
				
			// Replace by the current app by the retrieved app		
			root->an_app->copy_info(to_retrieve);
			value += 1;			// Increase by one the auxiliar variable
		}
		
		return value;			// Return the functions to the calling routine
	}
	else  
		// Calls the functions recursively to the calling routine
		return remove_by_keyword(root->left, keyword) + remove_by_keyword(root->right, keyword);
}

// Remove all nodes in the tree
int table::remove_all(node * & root)
{
	if(!root)		// If the base case is reached
		return 0;	// Return 0
	else
	{
		int value; // Auxiliar variable
		
		// Call the functions to the calling routine
		value = remove_all(root->right) + remove_all(root->left);
		
		delete root;  // Delete the node
		root = NULL;  // Point to null
		
		return value; // Return the functions to the calling routine
	}
}


