/*
    Filename: class.h
    Created by Alves Silva, Otavio Augusto
    Date: 07/13/2015    
    Class: CS 202 - Program #1
    Description: This file contains the functions of the class.h.
*/

#include "class.h"

// ----------------------------------- NAME -----------------------------------

// Default constructor
name::name():a_name(0){}

// Constructor with provided name
name::name(char * full_name)
{
	if(!full_name)
		a_name = NULL;
	else
	{
		a_name = new char[strlen(full_name)+1];
		strcpy(a_name, full_name);
	}
}

// Destructor
name::~name()
{
	delete a_name;
	a_name = NULL;
}

// Function to change name
void name::change_name(char * new_name)
{
	if(!new_name)
		return;
	else
	{
		a_name = new char[strlen(new_name)+1];
		strcpy(a_name, new_name);
	}
}

// Function to read the name
void name::read()
{
	char aux[100];
	cout << "Enter the player name: ";
	cin.get(aux, 100	, '\n'); cin.ignore(100, '\n');
	change_name(aux);
}

// Function to display the name
void name::display() const
{
	cout << "The player name is: " << a_name << endl;
}

// ------------------------------- DESCRIPTION -------------------------------

// Default constructor
description::description():desc(0){}

// Constructor with a provided description
description::description(char * new_desc)
{
	if(!new_desc)
		desc = NULL;
	else
	{
		desc = new char[strlen(new_desc)+1];
		strcpy(desc, new_desc);
	}
}

// Destructor
description::~description()
{
	delete desc;
	desc = NULL;
}

// Function to change the description
void description::change_description(char * new_desc)
{
	if(!new_desc)
		return;
	else
	{
		desc = new char[strlen(new_desc)+1];
		strcpy(desc, new_desc);
	}
}

// Function to read the description
void description::read()
{
	char aux[200];
	cout << "Enter the player description: ";
	cin.get(aux, 200, '\n'); cin.ignore(200, '\n');	
	change_description(aux);
}

// Function to display the description
void description::display() const
{
	cout << "The player description is: " << desc << endl;
}

// ---------------------------------- PERSON ----------------------------------

// Default constructor
person::person(){}

// Constructor with a initialization list
person::person(char * a_name, char * desc): name(a_name), my_desc(desc){}

// Function to read the person information
void person::read()
{
	name::read();
	my_desc.read();
}

// Function to display the person information
void person::display() const
{
	name::display();
	my_desc.display();
}

// Function to change the person name
void person::change_name(char * new_name)
{
	name::change_name(new_name);
}

// Function to change the person desc
void person::change_desc(char * new_desc)
{
	my_desc.change_description(new_desc);
}


// ---------------------------------- PLAYER ---------------------------------

// Default constructor
player::player(){}

// Player constructor with an initialization list with person and provided points
player::player(char * name, char * desc, int points): person(name, desc), my_points(points){}

// Function to set the player data members to default
void player::begins_new_game()
{
	my_lives.start_lives();
	my_points.zero_points();
}

// Function to increace the number of the player points
void player::gain_points(int amount)
{
	my_points.increase_points(amount);
}

// Function to decrease the number of the player points
void player::lost_points(int amount)
{
	my_points.decrease_points(amount);
}

// Function that executes a lost of a life by the player
void player::lost_a_life()
{
	if(my_lives.check_lives())
		my_lives.decrease_lives();
	else
		cout << "The player has no more life!" << endl;
}

// Function to read the person information of the player
void player::read()
{
	person::read();
}

// Function to display the data members information
void player::display() const
{
	cout << "-------------------- PLAYER DATA --------------------" << endl;
	person::display();
	my_lives.display();
	my_points.display();
	cout << "\n";
}

// Function to check if the player has any life remaining
bool player::check_lives()
{
	return my_lives.check_lives();
}

// ---------------------------------- LIFE -----------------------------------

// Default constructor start always with three lives
life::life():lives(3){}

// Function to set lives to three
void life::start_lives()
{
	lives = 3;
}

// Function to check if the lives are more than 0
bool life::check_lives() const
{
	if(lives > 0)
		return true;
	else
		return false;
}

// Function to decrease by one the lives
void life::decrease_lives()
{
	if(lives > 0)
		lives -= 1;
	else
		lives = 0;
}

// Function to display the amount of lives
void life::display() const
{
	cout <<"The actual amount of lives of this player is: " << lives << endl;
}

// ---------------------------------- PRIZE ----------------------------------

// Default constructor
point::point():points(0){}

// Constructor with a provided amount of points
point::point(int amount)
{
	points = amount;
}

// Function to set the points to zero
void point::zero_points()
{
	points = 0;
}

// Function to increase the points by the provided amount
void point::increase_points(int amount)
{
	points += amount;
}

// Function to decrease the points by the provided amount
void point::decrease_points(int amount)
{
	points -= amount;
}

// Function to display the amount of points
void point::display() const
{
	cout << "The amount of points of this player is: " << points << endl;
}

// ---------------------------------- NODE ----------------------------------

// Default constructor
node::node()
{
	data = 0;
	kind = 0;
	right = NULL;
	left = NULL;
	parent = NULL;
}

// Function to return the right address node
node *& node::go_right()
{
	return right;
}

// Function to return the left address node
node *& node::go_left()
{
	return left;
}

// Function to return the parent address node
node *& node::get_parent()
{
	return parent;
}

// Function to get the node value
int  node::get_value()
{
	return data;
}

// Function to set the node value
void node::set_value(int value)
{
	data = value;
}

// Function to get the node kind
int node::get_kind()
{
	return kind;
}

// Function to the set the node kkind
void node::set_kind(int value)
{
	kind = value;
}

// Function that executes a job in the player
// However, it depends of the node' kind
int node::execute_job(player & a_player)
{
	if(kind == 0)		// If is 0
	{	
		cout << "You got a prize!" << endl;
		cout << "The player won: " << data << " points!" << endl;
		a_player.gain_points(data); // The player won the node' data amount of value in the points
		return 0;		// Return the kind
	}
	else if(kind == 1) 	// If is 1
	{
		cout << "You are in a trap!" << endl;
		cout << "The player lost: " << data << " points!" << endl;
		a_player.lost_points(data); // The player lost the node' data amount of value in the points
		return 1;		// Return the kind
	}
	else if (kind == 2)	// If is 2
	{
		cout << "You are in a dead end!" << endl;
		cout << "The player lost a life!" << endl;
		a_player.lost_a_life();	// The player lost a life
		return 2;		// Return the kind
	}
	return 3;			// If is three, than the player reached the maze end
}

//Function to connect the right node with the provided connection
void node::connect_right(node * connection)
{
	right = connection;
}

//Function to connect the left node with the provided connection
void node::connect_left(node * connection)
{
	left = connection;
}

//Function to connect the parent node with the provided connection
void node::connect_parent(node * connection)
{
	parent = connection;
}

// Display the node data
void node::display()
{
	cout << data << endl;
	cout << kind << endl;
}

// ------------------------------- BINARY TREE -------------------------------
// Default constructor
binary_tree::binary_tree()
{
	root = NULL;
}

// Destructor
binary_tree::~binary_tree()
{
	delete_all(root);	// Call the delete all function
}

// Wrapper function
void binary_tree::display_all()
{
	display_all(root);
}

// Recursive function to display all nodes
int binary_tree::display_all(node * root)
{
	if(!root)	  
		return 0;
	else
	{					
		int value = 1;	
		value += display_all(root->go_left());
		root->display();	
		value += display_all(root->go_right());  
		
		return value;
	}
}

// Wrapper function
void binary_tree::delete_all()
{
	delete_all(root);
}

// Recursive function to remove all nodes
void binary_tree::delete_all(node * & root)
{
	if(!root)
		return;
	else
	{
		delete_all(root->go_left());
		delete_all(root->go_right());
		
		delete root;
		root = NULL;
	}
}

// ---------------------------------- BST ----------------------------------

// Default constructor
BST::BST():balance_factor(0){}

// Recursive function to insert a new node in the binary tree
int BST::insert_data(node * & root, node * parent, int to_insert)
{

	if(!root)
	{
		root = new node;
		root->set_value(to_insert);
		root->connect_parent(parent);
		root->connect_left(NULL);
		root->connect_right(NULL);
		return 1;
	}
	else if(to_insert < root->get_value())
		return insert_data(root->go_left(),  root, to_insert);
	else
		return insert_data(root->go_right(), root, to_insert);
		
}

// Function to insert the job (Trap) in the node
int BST::insert_traps(node * & root)
{
	if(!root)	  
		return 0;
	else
	{					
		int value = 1;	
		
		value += insert_traps(root->go_left());	
		
		if(root->get_value()%2 == 1)	// If the node has an odd value
			root->set_kind(1);			// It is a trap
			
		value += insert_traps(root->go_right());  
		
		return value;
	}
}

// Function to insert the job (Prize) in the node
int BST::insert_prizes(node * & root)
{
	if(!root)	  
		return 0;
	else
	{					
		int value = 1;	
		
		value += insert_prizes(root->go_left());	
		
		if(root->get_value()%2 == 0)	// If the node has an even number
			root->set_kind(0);			// It is a prize
			
		value += insert_prizes(root->go_right());  
		
		return value;
	}
}

// Function to insert the job(Dead point) in the node
int BST::insert_dead_points(node * & root)
{
	if(!root)
		return 0;
	else
	{
		int value = 1;	
		
		if(!root->go_right() && !root->go_left()) // If the node has no children
		{
			root->set_kind(2);	// It is a dead point
			return 1;
		}
		
		value += insert_dead_points(root->go_right()) + insert_dead_points(root->go_left()); 
		
		return value;
	}
}

// Function to insert the maze end
int BST::insert_goal(node * & root)
{
	if(!root->go_right())	// If the node has the biggest data
	{
		root->set_kind(3); 	// It is the maze end
		return 1;
	}
	else
		return insert_goal(root->go_right());
}

// Function to simulate the player walking through the maze
void BST::walk_through_the_maze(node * & root, player & to_walk)
{
	bool end_game = false;	// Loop stop
	int answer = 0;			// Player action
	int kind;				// Node kind (Job) - 0 - Trap, 1 - Prize, 2 - Dead end, 3 - Maze end
	
	cout << "\nEnter the following numbers to do the action." << endl;
	cout << "1 - Go to left" << endl;
	cout << "2 - Go to right" << endl;
	cout << "3 - Go back" << endl;
	
	do
	{		
		cout <<"\nEnter the action: ";
		cin  >> answer;
		cin.ignore(100, '\n');
		
		if(answer == 1)
		{
			if(root->go_left())	// Try to go to left
			{
				root  = root->go_left();	// Go to left
				if(root)
					kind = root->execute_job(to_walk);	// Executes the node job
			}
			else
				cout << "Sorry! Left is a WALL!" << endl;
		}
		else if(answer == 2)
		{
			if(root->go_right()) // Try to go to right
			{
				root  = root->go_right();	// Go to right
				if(root)
					kind = root->execute_job(to_walk); // Executes the node job
			}
			else
				cout << "Sorry! Right is a WALL!" << endl;
		}
		else if(answer == 3)
		{
			if(root->get_parent()) // Try to come back
			{
				cout << "You walked to back!" << endl;
				root = root->get_parent();	// Come back
			}
			else
				cout << "You are in the start pointing!" << endl; 
		}
		else
			cout << "Enter a valid answer!" << endl;
		
		if(!to_walk.check_lives())	// Checks if the player has any life remaining 
		{
			cout << "End game! You lost all the lives!" << endl;
			end_game = true;		// Ends the game
		}	
		
		if(kind == 3)				// Checks if the player reached the maze ends
		{
			cout << "End game ! You got the maze end! Congratulations!" << endl;
			end_game = true;		// Ends the game
		}		
	}while(!end_game);
	
}


// ---------------------------------- CODE ----------------------------------
//Default constructor
code::code():random_number(0){}

// Function to randomly build the maze
void code::build_the_maze()
{ 
	int number_of_paths;	// Number of paths
	int random_value;		// Random number
		
	cout << "Building a random maze..." << endl;
	
	srand(time(NULL));		// Seeder to seed the random number
	number_of_paths = rand() % 20 + 10; // Take a random number for the number of paths
										// Bigger than 10 and lease than 20
	
	// For each path
	for(int i = 0; i < number_of_paths; ++i)
	{
		random_value = rand() % 100 + 1;// A path will have a value bigger than 1 and lease than 1
		BST::insert_data(root, root, random_value); // Insert the value and the node in the maze
	}
	
	BST::insert_data(root, root, 125);	// Insert a final value to the maze ends always be in a leaf
	
	// Inser the node kinds
	cout << "Inserting prizes.." << endl;
	BST::insert_prizes(root);			// Insert prizes
	cout << "Inserting traps.." << endl;
	BST::insert_traps(root);			// Insert traps
	cout << "Inserting dead points.." << endl;
	BST::insert_dead_points(root);		// Insert dead points
	cout << "Inserting the goal.." << endl;
	BST::insert_goal(root);				// Insert goal
	cout << "Placing the player in the maze..." << endl;
	
	cout << "\nTIP -> The maze has this number of paths: " << number_of_paths << endl;
}

// Function to walk through the maze with the player
void code::put_the_player(player & to_play)
{
	BST::walk_through_the_maze(root, to_play);
}

// Function to display the maze
void code::display_the_maze()
{
	display_all();
}

// Function to destroy the maze
void code::destroy_the_maze()
{
	delete_all();
}

// ---------------------------------- MAZE ----------------------------------
// Default constructor
maze::maze()
{
	first_read = false;	
}

// Function to start a new game
void maze::start_a_game()
{
	if(first_read)	// If a player had his information read
	{
		code::destroy_the_maze();	// Destroys past mazes
		a_player.begins_new_game();	// Sets the player data members to default
		code::build_the_maze();		// Builds the maze
		cout << "The game started!" << endl;
		code::put_the_player(a_player);	// Puts the player in the maze
	} 
	else
		cout << "Please, enter the player information first!\n" << endl;
}

// Function to read the player information
void maze::read_player()
{
	a_player.read();
	first_read = true;
}

// Function to display the player information
void maze::display_player()
{
	if(first_read)
		a_player.display();
	else
		cout << "Please, enter the player information first!\n" << endl;
}













