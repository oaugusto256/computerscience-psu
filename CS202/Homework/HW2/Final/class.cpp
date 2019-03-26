/*
    Filename: class.h
    Created by Alves Silva, Otavio Augusto
    Date: 07/20/2015    
    Class: CS 202 - Program #2
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
	delete [] a_name;
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
	delete [] desc;
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

// ----------------------------------- NODE -----------------------------------

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
node *& node::go_parent()
{
	return parent;
}

// Function to get the node value
int  node::get_data()
{
	return data;
}

// Function to set the node value
void node::set_data(int value)
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
	if(kind == 0)		// If is 0 - Prize
	{	
		cout << "You got a prize!" << endl;
		cout << "The player won: " << data << " points!" << endl;
		a_player.gain_points(data); // The player won the node' data amount of value in the points
		return 0;		// Return the kind
	}
	else if(kind == 1) 	// If is 1 - Trap
	{
		cout << "You are in a trap!" << endl;
		cout << "The player lost: " << data << " points!" << endl;
		a_player.lost_points(data); // The player lost the node' data amount of value in the points
		return 1;		// Return the kind
	}
	else if (kind == 2)	// If is 2 - Dead point
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
void node::display() const
{
	cout << "Data: " << data << endl;
	cout << "Kind: " << kind << endl;
}

// ---------------------------------- BST -------------------------------------
// Constructor
bst::bst()
{
	root = NULL;
}

// Destructor
bst::~bst()
{
	remove_all(root);
}

// Function to display the BST content
int bst::display(node * root) const
{
	if(!root)	  
		return 0;
	else
	{					
		int value = 1;	
		value += display(root->go_left());
		root->display();	
		value += display(root->go_right());  
		
		return value;
	}
}

// Recursive function to insert a new path in the BSTs
int bst::insert_path(node * & root, node * parent, int to_insert)
{
	if(!root)
	{
		root = new node;
		root->set_data(to_insert);
		root->connect_parent(parent);
		root->connect_left(NULL);
		root->connect_right(NULL);
		return 1;
	}
	else if(to_insert < root->get_data())
		return insert_path(root->go_left(),  root, to_insert);
	else
		return insert_path(root->go_right(), root, to_insert);
}

// Function to insert prizes in the BST
int bst::insert_prizes(node * & root)
{
	if(!root)	  
		return 0;
	else
	{					
		int value = 1;	
		
		value += insert_prizes(root->go_left());	
		
		if(root->get_data()%2 == 0)	// If the node has an even number
			root->set_kind(0);			// It is a prize
			
		value += insert_prizes(root->go_right());  
		
		return value;
	}
}

// Function to insert traps in the BST
int bst::insert_traps(node * & root)
{
	if(!root)	  
		return 0;
	else
	{					
		int value = 1;	
		
		value += insert_traps(root->go_left());	
		
		if(root->get_data()%2 == 1)	// If the node has an odd value
			root->set_kind(1);			// It is a trap
			
		value += insert_traps(root->go_right());  
		
		return value;
	}
}

// Function to insert dead points in the BST
int bst::insert_dead_points(node * & root)
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

// Function to insert the goal in the BST
int bst::insert_goal(node * & root)
{
	if(!root->go_right())	// If the node has the biggest data
	{
		root->set_kind(3); 	// It is the maze end
		return 1;
	}
	else
		return insert_goal(root->go_right());
}

// Function to walk with the player through the BST
int bst::walk(node * root, player & to_walk)
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
			if(root->go_parent()) // Try to come back
			{
				cout << "You walked to back!" << endl;
				root = root->go_parent();	// Come back
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
			return 0;
		}	
		
		if(kind == 3)				// Checks if the player reached the maze ends
		{
			cout << "You got the level one maze end! Congratulations!" << endl;
			cout << "Let's go to the next level!" << endl;	
			end_game = true;		// Ends the game
			return 1;
		}		
	}while(!end_game);
	
	return 0;
}

// Function to destroy the BSt
void bst::remove_all(node * & root)
{
	if(!root)
		return;
	else
	{
		remove_all(root->go_left());
		remove_all(root->go_right());
		
		delete root;
		root = NULL;
	}
}

// ---------------------------------- LEVEL ----------------------------------
//Abstract constructor
level::level(){}

// -------------------------------- LEVEL ONE --------------------------------
// Constructor
level_one::level_one()
{
	number_of_nodes = 0;
}

// Function to build the graph
void level_one::build()
{
	int number_of_paths;	// Number of paths
	int random_value;		// Auxiliary variable to hold random values
		
	cout << "Building a random level one maze..." << endl;
	
	srand(time(NULL));		// Random seeder
	number_of_paths = rand() % 20 + 10; // Random number of paths
	
	for(int i = 0; i < number_of_paths; ++i)
	{
		random_value = rand() % 100 + 1;			// Inserting random values
		bst::insert_path(root, root, random_value); // in the BST
	}
	
	bst::insert_path(root, root, 125);	// Make sure that the goal is the biggest
	
	cout << "Inserting prizes.." << endl;
	bst::insert_prizes(root);			
	cout << "Inserting traps.." << endl;
	bst::insert_traps(root);			
	cout << "Inserting dead points.." << endl;
	bst::insert_dead_points(root);		
	cout << "Inserting the goal.." << endl;
	bst::insert_goal(root);				
	cout << "Placing the player in the maze..." << endl;
	
	cout << "\nTIP -> The maze has this number of paths: " << number_of_paths << endl;
}

// Function to destroy the bst
void level_one::destroy()
{	
	bst::remove_all(root);
}

// Function to display the bst
void level_one::display() const
{
	bst::display(root);
}

// Function to walk with the player
int level_one::walk(player & a_player)
{
	return bst::walk(root, a_player);
}

// ---------------------------------- VERTEX ----------------------------------
// Vertex constructor
vertex::vertex()
{
	data = 0;
	kind = 0;
	head = NULL;
}
 
// Function to get vertex value
int vertex::get_data()
{
	return data;
}

// Function to set vertex value
void vertex::set_data(int value)
{
	data = value;
}

// Function to get the vertex value
int vertex::get_kind()
{
	return kind;
}

// Function to set the vertex kind
void vertex::set_kind(int value)
{
	kind = value;
}

// Function to go to the head 
graph_node *& vertex::go_head()
{
	return head;
}

// Function to connect the head vertex with the connection
void vertex::connect_head(graph_node * connection)
{
	head = connection;
}

// Function to executes the node' job
int vertex::execute_job(player & a_player)
{
	if(kind == 0)		// If is 0 - Prize
	{	
		cout << "You got a prize!" << endl;
		cout << "The player won: " << data << " points!" << endl;
		a_player.gain_points(data); // The player won the node' data amount 
									// of value in the points
		return 0;					// Return the kind
	}
	else if(kind == 1) 	// If is 1 - Trap
	{
		cout << "You are in a trap!" << endl;
		cout << "The player lost: " << data << " points!" << endl;
		a_player.lost_points(data); // The player lost the node' data amount 
									// of value in the points
		return 1;					// Return the kind
	}
	else if (kind == 2)	// If is 2 - Dead point
	{
		cout << "You are in a dead end!" << endl;
		cout << "The player lost a life!" << endl;
		a_player.lost_a_life();	// The player lost a life
		return 2;				// Return the kind
	}
	return 3;					// If is three, than the player 
								// reached the maze end
}

// Function to display the vertex content
void vertex::display() const
{
	cout << "Data: " << data << endl;
	cout << "Kind: " << kind << endl;
}

// -------------------------------- GRAPH NODE --------------------------------
// Graph node constructor
graph_node::graph_node()
{
	adjacent = NULL;
	next = NULL;
}

// Function to return the adjacent address
vertex *& graph_node::go_adjacent()
{
	return adjacent;
}

// Function to return the next node address
graph_node *& graph_node::go_next()
{
	return next;
}

// Function to connect the adjacent with connection
void graph_node::connect_adjacent(vertex * connection)
{
	adjacent = connection;
}

// Function to connect the next with connection
void graph_node::connect_next(graph_node * connection)
{
	next = connection;
}

// ---------------------------------- GRAPH ----------------------------------
// Graph constructor
graph::graph()
{
	adjacency_list = NULL;
	list_size = 0;
}

// Graph destructor
graph::~graph()
{
	remove_all();
}

// Function to set the graph size
void graph::set_size(int size)
{
	list_size = size;
}

// Function to insert the prizes in the graph
void graph::insert_prizes()
{
	for(int i = 0; i < list_size; i++)
	{
		if(adjacency_list[i].get_data()%2 == 0)
			adjacency_list[i].set_kind(0);
	}
}

// Function to insert the traps
void graph::insert_traps()
{
	for(int i = 0; i < list_size; i++)
	{
		if(adjacency_list[i].get_data()%2 == 1)
			adjacency_list[i].set_kind(1);
	}
}

// Function to insert the dead points
void graph::insert_dead_points()
{
	for(int i = 0; i < list_size; i++)
	{
		if(!adjacency_list[i].go_head())	// If the path doesnt have any connection
			adjacency_list[i].set_kind(2);	// It's a dead point
	}
}

// Function to insert the main goal
void graph::insert_goal()
{
	if(adjacency_list[list_size-1].get_data() == 125) // The maze final will be always 125
		adjacency_list[list_size-1].set_kind(3);
}

// Function to find the path location in the list
int graph::find_location(int to_find)
{
	bool match = false;
	int i = -1;
	
	do
	{
		++i;
		if(adjacency_list[i].get_data() == to_find)	
			match = true;			
	}while(!match && i < list_size);
	
	if(!match)
		return -1;
	else	
		return i;
}

// Function to attach the paths in the adjacency list
void graph::insert_edge(int current_vertex, int to_attach)
{
	bool condition = true;
	graph_node * aux;
	int location;
	
	// Conditition to see if current vertex isn't trying
	// to create a link with itself
	if(current_vertex == to_attach)
		condition = false;
	
	location = find_location(current_vertex);
	aux = adjacency_list[location].go_head();
	
	// Loop to make sure that it doesn't have a repetition
	while(aux)
	{
		vertex * aux_vertex = aux->go_adjacent();
	
		if(aux_vertex->get_data() == to_attach)
			condition = false;
		
		aux = aux->go_next();
	}
	
	// If the condition is OK
	if(condition)
	{
		int con1 = find_location(current_vertex);
		int con2 = find_location(to_attach);
	
		graph_node * temp = new graph_node;
	
		// Creates the connection
		temp->connect_adjacent(&adjacency_list[con2]);
		temp->connect_next(adjacency_list[con1].go_head()); 
		
		adjacency_list[con1].connect_head(temp);
	}
}

// Function to display the graph content
void graph::display() const
{
	int i = 0;
	do
	{
		cout << "Data: " << adjacency_list[i].get_data() << endl;
		cout << "Kind: " << adjacency_list[i].get_kind() << endl;
		++i;
	}while(i < list_size);
}

// Function to display a vertex content
void graph::display_adjacent(int location)
{
	if(location >= 0)
	{
		graph_node * temp = adjacency_list[location].go_head();
			
		cout << "\nYou are in the path #" << adjacency_list[location].get_data()  << " you can go to the following paths: " << endl;	
			
		while(temp)
		{
			vertex * temp_vertex = temp->go_adjacent();
			cout << "#" << temp_vertex->get_data() << endl;
			temp = temp->go_next();
		}
	}
	else
		cout << "This path doesn't exist! Please, enter a valid path!" << endl;
}

// Function to walk through the graph with the player
int graph::walk(player & to_walk)
{
	bool end_game = false;	// Loop stop
	int answer = 0;			// Player action
	int kind = 0;			// Node kind (Job) - 0 - Trap, 1 - Prize, 
						    //2 - Dead end, 3 - Maze end
	
	int path = adjacency_list[0].get_data();	// Get the first position
	int location = find_location(path);			// Set the location
	
	do
	{	
		if(kind != 3)
		{
			display_adjacent(location);		// Displays possible locations to go
			
			cout << "\nEnter the path number that the player will go: ";
			cin  >> path;
			cin.ignore(100, '\n');
			
			location = find_location(path);// Try to go to this location
			
			if(location >= 0)			   // If it exists
				kind = adjacency_list[location].execute_job(to_walk);	// Executes the job
		}
		
		// If it's the maze goal
		if(kind == 3)
		{
			cout << "End game ! You got the level two maze end! Congratulations!" << endl;
			end_game = true;		// Ends the game
			return 1;
		}
		
		// Checks if the player has any life remaining 
		if(!to_walk.check_lives())	
		{
			cout << "End game! You lost all the lives!" << endl;
			end_game = true;		// Ends the game
			return 0;
		}	
		
	}while(!end_game);
	
	return 0;
}

// Function to remove all paths 
void graph::remove_all()
{
	for(int i = 0; i < list_size; ++i)
	{
		graph_node * aux = adjacency_list[i].go_head();
		while(aux)
		{
			graph_node * next = aux->go_next();
			delete aux;
			aux = next;
		}
	}
	
	delete adjacency_list;
}

// -------------------------------- LEVEL TWO --------------------------------
// Level two constructor
level_two::level_two()
{
	number_of_paths = 0;
}

// Function to build the level two
void level_two::build()
{
	int number_of_paths;	// Number of paths
	int random_value = 0;	// Auxiliary variable to hold random values
	int edges;				// Auxiliary variable to hold number of edges
	int edge = 0;			// Hold the edge value
	int to_attach = 0;      // Hold the path value to attach
	
	cout << "Building a random level two maze..." << endl;
	
	srand(time(NULL));					// Random seeder
	number_of_paths = rand()% 20 + 10;	// Random number of paths
	graph::set_size(number_of_paths);	// Set the list size
	
	adjacency_list = new vertex[number_of_paths];	// Allocates the memory
	
	for(int i = 0; i < number_of_paths-1; ++i)
	{
		random_value =  rand()% 100 + 1;			// Inserting random values
		adjacency_list[i].set_data(random_value);	// in the graph paths
		adjacency_list[i].connect_head(NULL); 
	}
	
	// Make sure that goal is the 
	// last one in the list
	adjacency_list[number_of_paths-1].set_data(125);
	adjacency_list[number_of_paths-1].connect_head(NULL);
	
	// Make sure that goal has at least 
	// one connection
	graph::insert_edge(adjacency_list[0].get_data(), 125);
	
	// For each path in the list
	for(int x = 0; x < number_of_paths-1; ++x)
	{	
		edge  = adjacency_list[x].get_data(); // Each path
		edges = rand() % 5 + 0;				  // It has up to five connections
		
		for(int y = 0; y < edges; ++y)
		{
			// It may have a connection with a random path in the list
			to_attach = rand() % number_of_paths;	
			// Attachs in both directions
			graph::insert_edge(edge, adjacency_list[to_attach].get_data());
			graph::insert_edge(adjacency_list[to_attach].get_data(), edge);
		}
	}
	
	cout << "Inserting prizes.." << endl;
	graph::insert_prizes();			
	cout << "Inserting traps.." << endl;
	graph::insert_traps();			
	cout << "Inserting dead points.." << endl;
	graph::insert_dead_points();		
	cout << "Inserting the goal.." << endl;
	graph::insert_goal();				
	cout << "Placing the player in the maze..." << endl;
	cout << "\nTIP -> This level has this number of paths: " << number_of_paths << endl;
	cout << "\n";
}

// Function to destroy the graph
void level_two::destroy()
{	
	graph::remove_all();
}

// Function to display the graph
void level_two::display() const
{
	graph::display();
}

// Function to walk through the graph with the player
int level_two::walk(player & a_player)
{
	return graph::walk(a_player);
}
