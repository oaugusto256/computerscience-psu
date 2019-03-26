/* Algorithm
	Start program
		Creates variables to keep information from a task
			Task name
			Task description
		Create ADT task and table
			A task	
			A graph with provided size

		Loop - While the option isn't 0 - EXIT
			Display the menu for the user
				If the option is 1 - Add a task
					Take the task information
					Create task
					Find a empty space in the list
						If there is space
							Insert the task
						Else
							Return an error

				If the option is 2 - Link two tasks
					Take two arguments
					If the location of both are bigger than -1
						Try to find in the list and link them
					Else
						Return an error
						
				If the option is 3 - Displays the adjacents tasks
						Find the task with the name
						Try to match the name with all the tasks
						If match
							Displays all adjacents
						Else
							Return an error

				If the option is 4 - Displays all
					Loop
						Display each task

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
    Date: 06/03/2015    
    Class: CS 163 - Program #5
    Description: The purpose of this program is to simulate an away to storage some information
	about tasks to easily manage them. We are goind to use a graph to organize these information in a
	Hierarchical form. The program will take care of some informations, which are the task name and description.
	Therefore, in this file we have the ADT (Task and Table) to bring life to this program, as well as the prototypes, 
	constructors and destructors of each class.  
*/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int const SIZE = 100;

// ADT of a task
class task
{
	public:
		task();		// Constructor
		~task();	// Destructor
		
		int create_task(char * name, char * desc);	// Create a task
		int copy_info(const task & copy_from);		// Copy the task information from the argument
		int compare_info(char * to_match);			// Compare the task name
		int display_info() const;					// Display task information
		
		char * get_name();	// Return the task name
		
	private:
		char * name;		// Task name
		char * desc;		// Task description
};

// Struct of a vertex
struct vertex
{
	task * a_task;
	struct node * head;
};

// Struct of a node
struct node
{
	vertex * adjacent;
	node * next;
};

// ADT of a table
class table
{
	public:
		table(int size);	// Constructor
	
		int insert_vertex(const task & to_add);	// Insert a vertex with the provided argument
		int find_location(char * name);			// Find a task's location with the provided argument
		int insert_edge(char * current_vertex, char * to_attach);	// Create a relationship between two tasks
		int display_adjacent(char * name);		// Display the adjacents tasks
		int display_all() const;				// Display all the tasks
	private:
		vertex * adjacency_list;	// List of vertex
		int list_size;				// List size
};
