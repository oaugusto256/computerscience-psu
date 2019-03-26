/*
    Filename: class.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 07/13/2015    
    Class: CS 202 - Program #1
    Description: The purpose of this program is to simulate a maze game, which is
	created randomly by an algorithm, where a player will be placing through the path
	until find the end. The player will find prizes, traps and dead points that will
	change the story of the game. The OOP design was used to create this code.
*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

// ----------------------------------- NAME -----------------------------------
// Object name of a person
class name
{
	public:
		name();
		name(char * full_name);
		~name();
		
		void change_name(char * new_name);	// Change the name
		void read();			// Read the data members
		void display() const;	// Display the data members
		
	protected:
		char * a_name;
};

// ----------------------------------- DESC -----------------------------------
// Object description of a person
class description
{
	public:
		description();
		description(char * new_desc);
		~description();
		
		void change_description(char * new_desc);	// Change the description
		void read();			// Read the data members
		void display() const;	// Display the data members

	protected:
		char * desc;
};

// --------------------------------- PERSON -----------------------------------
// Object person is a name and has a description
class person: public name
{
    public:
		person();
        person(char * a_name, char * desc);
  	  
		void change_name(char * new_name);	// Change the name
        void change_desc(char * new_desc);	// Change the description
	  	void read();			// Read the data members 
        void display() const;	// Display the data members
		
	protected:
        description my_desc;
};

// ---------------------------------- POINT -----------------------------------
// Object point that the object player will have
class point
{
	public:
		point();
		point(int amount);
		
		void zero_points();		// Change the points to zero
		void increase_points(int amount); // Increase the points
		void decrease_points(int amount); // Decrease the points 
		void display() const;   // Display the points

	protected:
		int points;
};

// ----------------------------------- LIFE -----------------------------------
// Object life that the object player will have
class life
{
	public:
		life();
		
		bool check_lives() const;	// Check if is bigger than 0
		void start_lives();			// Change the lives to 3
		void decrease_lives();	// Decrease one life
		void display() const;	// Display the lives
		
	protected:
		int lives;	
};

// --------------------------------- PLAYER -----------------------------------
// Object player is a person and has points and lives
class player: public person
{
	public:
		player();
		player(char * name, char * desc, int points);
		

		bool check_lives();		// Check if the player has any life remaining
		void begins_new_game();	// Set the points and lives to default value
		void gain_points(int amount);	// Gain points 
		void lost_points(int amount);	// Lost points
		void lost_a_life();		// Lost a life
		void read();			// Read player information
		void display() const; 	// Display player information
			
	protected:
		point my_points;
		life  my_lives;
};

// ----------------------------------- NODE -----------------------------------
// Object node
class node
{
	public:
		node();
		
		node *& go_right();		// Go to the right
		node *& go_left();		// Go to the left
		node *& get_parent();	// Go to the parent
		
		int  get_value();			// Get node value
		void set_value(int value);	// Set node value
		
		int  get_kind();			// Get the node kind
		void set_kind(int value);	// Set the node kind
		 
		void connect_right(node * connection);	// Connect the left pointer
		void connect_left(node * connection);	// Connect the right pointer
		void connect_parent(node * connection);	// Conenct the parent pointer
		
		int execute_job(player & a_player);		// Execute the node job
		void display();				// Display the node values
	
	protected:
		int data;	// This data will be used by traps ou prizes
		int kind;	// This will be the kind of the node, each kind has a job
		
		node * parent;	// Will hold the parent node to come back
		node * left;	// Will hold the left address
		node * right;	// Will hold the right address
};

// -------------------------------- BINARY TREE -------------------------------
// Object binary tree
class binary_tree
{
	public:
		binary_tree();
		~binary_tree();
		
		void display_all();		// Wrapper function
		void delete_all();		// Wrapper function
	
	protected:
		void delete_all(node * & root); // Display all nodes
		int display_all(node * root);	// Remove all nodes
		node * root;
};

// ----------------------------------- BST ------------------------------------
// Object BST is a binary tree
class BST: public binary_tree
{
	public:
		BST();
		
		// Walk through the maze with the player
		void walk_through_the_maze(node * & root, player & to_walk);
		
		// Insert the paths in the BST 
		int insert_data(node * & root, node * parent, int data);

		int insert_traps(node * & root);	// Insert the traps in the BST
		int insert_prizes(node * & root);	// Insert the prizes in the BST
		int insert_dead_points(node * & root);	// Insert the dead points
		int insert_goal(node * & root);			// Insert the maze end

	protected:
		int balance_factor;
};

// ----------------------------------- CODE -----------------------------------
// Object code is a BST
class code: public BST
{
	public:
		code();
		
		void build_the_maze();		// Build the maze
		void destroy_the_maze();
		void put_the_player(player & to_play);	// Put the player in the maze
		void display_the_maze();	//	Display the maze
		
	protected:
		int random_number;
};

// ----------------------------------- MAZE -----------------------------------
// Object code is a maze
class maze: public code
{
	public:
		maze();
		
		void read_player();		// Read the player information
		void display_player();	// Display the player information
		void start_a_game();	// Start a game
	
	protected:
		player a_player;		
		bool first_read;		// Start the game just after the first read
};
