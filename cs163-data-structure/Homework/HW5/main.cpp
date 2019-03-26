/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 06/03/2015    
    Class: CS 163 - Program #5
    Description: This file tests the ADT's and shows how the program could 
	be used by the user.
*/

#include "class.h"

void clear();   // Clear function
int menu();     // Menu function

int main()
{
	// Variables to create a new task in the system
	char name[SIZE];
	char desc[SIZE];
	
	int task_number;
	char task_to_find[SIZE];
	char current_task[SIZE];
	char requisite_task[SIZE];
	
	
	task a_task;		// ADT Task
	
	int option;			// Option of the menu	
	
	clear();			// Clear the system screen
	
	cout << "Welcome to the TASK MANAGER!\nPlease, enter the number of tasks you are going to be used: ";
	cin  >> task_number;
	cin.ignore(SIZE, '\n');
	
	while(task_number <= 0)
	{
		cout << "Please, enter a number bigger than zero: "; 
		cin  >> task_number;
		cin.ignore(SIZE, '\n');
	}
	
	table graph(task_number);	// ADT Graph with the provided size
	
	clear();					// Clear the system screen
	
	do
	{
		option = menu();
		switch(option)
		{
			case 1:
				// If the option is 1
				// Receive data to create a new task
				cout << "Please, enter the task name: ";
				cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
				
				cout << "Please, enter the task description: ";
				cin.get(desc, SIZE, '\n'); cin.ignore(SIZE, '\n');
				
				if(a_task.create_task(name, desc))
				{
					if(graph.insert_vertex(a_task))
						cout << "\nThe task was successfully inserted in the system\n" << endl;
					else
						cout << "\nThe system hasn't any space left to insert a new task.\n" << endl;
				}
				break;
			
			case 2:
				// If the option is 2
				// Receive two vertice names to create a link between them
				cout << "Please, enter the task name which has the requisite: ";
				cin.get(current_task, SIZE, '\n'); cin.ignore(SIZE, '\n');
				
				cout << "Please, enter the requisite task name: ";
				cin.get(requisite_task, SIZE, '\n'); cin.ignore(SIZE, '\n');
				
				if(!graph.insert_edge(current_task, requisite_task))
					cout << "\nOne of the tasks wasn't found in the system!\n" << endl;
				else
					cout << "\nThe link was made by the two tasks.\n" << endl;
				
				break;
			
			case 3:
				// If option is 3
				// Displays the adjacents tasks of a vertice
				cout << "Enter the task name to display: ";
				cin.get(task_to_find, 100, '\n'); cin.ignore(100, '\n');
			
				if(!graph.display_adjacent(task_to_find))
					cout << "The task wasn't found!" <<endl;
				
				break;
			
			case 4:
				// If option is 4
				// Displays all the tasks
				if(!graph.display_all())
					cout << "The system doesn't have any task yet!" << endl;

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
    
    cout << "-------------------- TASK MANAGER -------------------" << endl;
    cout << "1 - Add a task to the system." << endl;
    cout << "2 - Connect a task's requisite in the system." << endl;	
	cout << "3 - Display a specific task with the requisites." << endl;
    cout << "4 - Display all task in the system." << endl;
	cout << "0 - Exit." << endl;
    
    do
    {
        cout << "\nEnter an option: ";
        cin >> option;
        cin.ignore(100,'\n');
    }
    while(option < 0 && option > 5);
    
    clear();
    
    return option;
}
