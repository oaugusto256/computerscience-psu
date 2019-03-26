/*
    Filename: class.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 06/03/2015    
    Class: CS 163 - Program #5
    Description: This file contains the functions of the class.h 
*/

#include "class.h"

// ---------------------------------- TASK -----------------------------------

// Constructor
task::task()
{
	name = NULL;
	desc = NULL;
}

// Destructor
task::~task()
{
	delete [] name;
	delete [] desc;
	
	name = NULL;
	desc = NULL;
}

// This function create an task 
// with the provided arguments
int task::create_task(char * new_name, char * new_desc)
{
	if(!new_name)
		return 0;
	
	name = new char[strlen(new_name)+1];
	strcpy(name, new_name);
		
	desc = new char[strlen(new_desc)+1];
	strcpy(desc, new_desc);
		
	return 1;
}

// This function takes the argument 
//and copies it into the task's data members
int task::copy_info(const task & copy_from)
{
	// If the argument doesn't have data
	if(!copy_from.name)
		return 0;	// Return failed 
	
    // If the data members already have some thing, 
    // we have to deallocate any memory
    if(name)
        delete [] name;
	
	if(desc)
		delete [] desc;
	
	// Setting pointers to NULL for safety
	name = NULL;
	desc = NULL;
	
	// Starting perform a deep copy
    name = new char[strlen(copy_from.name)+1];
    strcpy(name, copy_from.name);
	
    desc = new char[strlen(copy_from.desc)+1];
    strcpy(desc, copy_from.desc);
	
	return 1;	// Return success
}

// This function compares if the value
// matchs with the task name
int task::compare_info(char * to_match)
{
	if(!strcmp(to_match, name))
		return 1;
	else
		return 0;
}

// This function displays the task informations
int task::display_info() const
{
	if(!name)
		return 0;
	
	cout << "Name: " << name << endl;
	cout << "Description: " << desc << endl;
	cout << "-----------------------------------------------------" << endl;
	
	return 1;
}

// This function returns the task name
char * task::get_name()
{
	return name;
}

// ---------------------------------- TABLE -----------------------------------

// Constructor
table::table(int size)
{
	adjacency_list = new vertex[size];
	
	for(int i = 0; i < list_size; ++i)
	{
		adjacency_list[i].a_task = NULL;
		adjacency_list[i].head = NULL;
	}
	
	list_size = size;
}

// This function inserts a vertex in the list	
// with the provided task argument
int table::insert_vertex(const task & to_add)
{
	bool space = false;
	int i = 0;
	
	// Loop until find a empty space in the list
	do
	{
		if(!adjacency_list[i].a_task)
			space = true;
		else
			++i;
	}while(!space && i < list_size);
	
	// If there is space 
	if(space)
	{
		task * new_task = new task;			 // Create a new task
		new_task->copy_info(to_add);		 // Copy information
		adjacency_list[i].a_task = new_task; // Point to this new task
		
		return 1;	// Return success
	}
	else
		return 0;	// Return failed
}

// This function returns the localcation
// of a vertex in the list by checking match
int table::find_location(char * name)
{
	bool match = false;
	int i = -1;
	
	// While isn't match and i isn't bigger
	// than the list size
	do
	{
		++i;
		if(adjacency_list[i].a_task) // If the pointer isn't NULL
		{
			if(adjacency_list[i].a_task->compare_info(name))	// Check if the name is the smae
				match = true;									// Match is true
		}
	}while(!match && i < list_size);
	
	if(match)
		return i;	// Return the location
	else
		return -1;	// Return a negative value 
					// to represent a failed search
}

int table::insert_edge(char * current_vertex, char * to_attach)
{
	int connection1 = find_location(current_vertex); // Find the local 1
	int connection2 = find_location(to_attach);		 // Find the local 2
	
	if(connection1 >= 0 && connection2 >= 0)		 // Check if both are positive
	{	
		node * temp = new node;	// Create a new node
		
		temp->adjacent = &adjacency_list[connection2]; // Point the adjacent pointer to the local 2
		temp->next = adjacency_list[connection1].head; // Point the next pointer to the adjacency_list local 1
		adjacency_list[connection1].head = temp;	   // Connects the adjacency_list head with temp
		
		return 1;	// Return success
	}
	else	
		return 0;	// Return failed 	
}

// This function displays the adjacent verticies
// of a specific vertex
int table::display_adjacent(char * name)
{
	int i = 0;
	int location = find_location(name); 	// Find a list location with the provided argument
	
	if(location >= 0)				    	// If the location is valid
	{
		if(adjacency_list[location].head)	// If the head isn't pointing to NULL
		{
			node * temp = adjacency_list[location].head;	// Create a temp variable and point to head
			
			cout << "\nThe task " << adjacency_list[location].a_task->get_name()  << " has the following requisites.\n" << endl;	
			
			// Displays the edge list of this vertex
			while(temp)
			{
				cout << "---------------------- " << "#" << i+1 <<" ---------------------------" << endl;
				temp->adjacent->a_task->display_info();
				temp = temp->next;
				++i;
			}
		}
		// If the head is pointing to NULL
		else		
			cout << "\nThe task " << adjacency_list[location].a_task->get_name()  << " doesn't have any requisites yet.\n" << endl;
		
		cout << "\n";
		return 1;	// Return success
	}
	else
		return 0;	// Return failed
}

// This function displays all verticies
int table::display_all() const
{
	bool empty = true;	// Variable to check if the list is empty
	int i = 0;

	// Loop through the list size
	do
	{
		if(adjacency_list[i].a_task)
		{
			adjacency_list[i].a_task->display_info();	// Displays each vertice
			empty = false;	
		}
		++i;
	}while(i < list_size);

	cout << "\n";
	
	if(empty)
		return 0;	// Return failed
	else	
		return 1;	// Return success
}

