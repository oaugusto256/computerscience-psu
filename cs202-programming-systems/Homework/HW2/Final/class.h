/*
    Filename: class.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 07/20/2015    
    Class: CS 202 - Program #2
    Description: The purpose of this program is to simulate a maze game, which is
	created randomly by an algorithm, where a player will be placing through the path
	until find the end. The player will find prizes, traps and dead points that will
	change the story of the game. The OOP design was used to create this code. 
	This maze has two levels, they are represented by a BST and a graph.
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
		node *& go_parent();	// Go to the parent
		
		int  get_data();			// Get node value
		void set_data(int value);	// Set node value
		
		int  get_kind();			// Get the node kind
		void set_kind(int value);	// Set the node kind

		void connect_right(node * connection);	// Connect the left pointer
		void connect_left(node * connection);	// Connect the right pointer
		void connect_parent(node * connection);	// Conenct the parent pointer
		
		int execute_job(player & a_player);		// Execute the node job
		void display() const;		// Display node contents
		
	protected:
		int data;	// This data will be used by traps ou prizes
		int kind;	// This will be the kind of the node, each kind has a job
		
		node * parent;	// Will hold the parent node to come back
		node * left;	// Will hold the left address
		node * right;	// Will hold the right address
};

// ----------------------------------- BST ------------------------------------
// Object BST is a binary tree
class bst
{
	public:
		bst();
		~bst();
		
		int display(node * root) const;					
		int insert_path(node * & root, node * parent, int data);
		int insert_prizes(node * & root);		// Insert the prizes in the BST
		int insert_traps(node * & root);		// Insert the traps in the BST
		int insert_dead_points(node * & root);	// Insert the dead points
		int insert_goal(node * & root);			// Insert the maze end	
		int walk(node * root, player & to_walk);// Walk through the maze
		void remove_all(node * & root);			// Destrou the BST
		
	protected:
		node * root;
};

class vertex; //Forward declaration

// ------------------------------- GRAPH NODE ---------------------------------
// Object graph node is a special kind of node
class graph_node
{
	public:
		graph_node();
		
		vertex  *& go_adjacent();	// Go to adjacent
		graph_node *& go_next();	// Go to next 
		
		void connect_adjacent(vertex * connection);	// Connect adjacent
		void connect_next(graph_node * connection);	// Connect next
		
	protected:
		vertex * adjacent;
		graph_node * next;
};

// ---------------------------------- VERTEX ----------------------------------
// Object vertex is vertice in the graph
class vertex
{
	public:
		vertex();
		
		int  get_data();			// Get node value
		void set_data(int value);	// Set node value
		
		int  get_kind();			// Get the node kind
		void set_kind(int value);	// Set the node kind
		
		graph_node *& go_head();	// Go to head node
		void connect_head(graph_node * connection); // Connect the head
		
		int execute_job(player & a_player);	// Execute the node job
		void display() const;				// Display node contents
		
	protected:
		int data;
		int kind;

		graph_node * head;
};

// ---------------------------------- GRAPH -----------------------------------
// Object graph
class graph
{
	public:
		graph();
		~graph();
		
		void set_size(int size);	// Set the list size
		
		void insert_prizes();		// Insert prizes in the graph
		void insert_traps();		// Insert traps in the graph
		void insert_dead_points();	// Insert dead points
		void insert_goal();			// Insert the goal
		
		int find_location(int to_find);	// Find a path location in the list
		void insert_edge(int current_vertex, int to_attach); // Insert a link between paths
		void display_adjacent(int location); // Display adjacents nodes
		void display() const;		// Display graph 
		int walk(player & to_walk); // Walk with the player
		void remove_all();			// Remove all paths

	protected:
		vertex * adjacency_list;
		int list_size;
};

// ---------------------------------- LEVEL -----------------------------------
// Abstract base class level
class level: public bst, public graph
{
	public:
		level();
		
		//These functions are totally virtuals 
		//and doesn't make sense here
		virtual void display() const = 0;
		virtual void build() = 0;
		virtual void destroy() = 0;
		virtual int walk(player & a_player) = 0;
};

// -------------------------------- LEVEL ONE ---------------------------------
// Object level_one is a level 
class level_one: public level
{
	public:
		level_one();
		
		void build();	// Build the BST
		void destroy();	// Destroy the BST
		void display() const;		// Display the BST
		int walk(player & a_player);// Walk with the player in the BST
	
	protected:
		int number_of_nodes;
};

// -------------------------------- LEVEL TWO ---------------------------------
// Object level_one is a level 
class level_two: public level
{
	public:
		level_two();
		
		void build();	// Build the graph
		void destroy();	// Destroy the graph
		void display() const;		// Display the graph
		int walk(player & a_player);// Walk with the player in the graph
	
	protected:
		int number_of_paths;
};
