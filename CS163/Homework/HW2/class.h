/* 
	Algorithm
	Start program
		Creates variables to keep information from a customer order
			Customer name
			Order number
			Arrival time
		Create ADT customer and Service(Food Cart)
			A customer
			Service
		
		Loop - While the option isn't 0 - EXIT
			Display the menu for the user
				If the option is 1 - Add a order
					Take the customer information and time
					Create a customer
					Place in the service food cart
					Increase the number of customers attended
				If the option is 2 - Deliver a order
					Peek information of the last customer
					Calculate the current time
					Calculate the time to deliver with the customer time 
					Uptaded the average time
					Calculate an average of time to deliver a order
					Create a statistic with the time order
						Worst time
						Average time to deliver
					If the time is the worst one
						Push this item in the stack
					Else
						Pop the first item
						Uptaded the average time
						Create a new stack with the last order time and uptaded average
					Deliver the customer order
				If the option is 3
					Display all orders in the queue
				If the option is 4
					Display all statistic in the stack
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
    Date: 05/02/2015    
    Class: CS 163 - Program #2
    Description: The purpose of this program is to simulate a food cart in a restaurant. 
	The program will take care of some informations, which are the name, order number and 
	arrival time, about the customers to organize a queue of orders and a list with the 
	statistics of time. Therefore, in this file we have the ADT(Queue and Stack) to bring 
	life to this program, as well as the prototypes, constructors and destructors of each class.  
*/

#include <ctime>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

const int SIZE = 100;
const int MAX = 3;

// ------------------------- ABSTRACTION OF THE QUEUE -------------------------

// ADT of a customer
class customer
{
    public:
        customer();		// Constructor
        ~customer();	// Destructor
        
        int create_customer(char * name, int order_number, tm * & order_time); // Create a customer
        int copy_info(const customer & copy_from);	// Copy information from the ADT
		int get_time(tm & to_get)const;				// Get arrival time
		int display_info();							// Display customer information
        
    private:    
        char * name;			// Customer name
        int order_number;		// Order number
        tm * order_time;		// Struct tm to hold the date and time
};

// Struct of a queue node
struct q_node
{
    customer a_customer;	// A customer
    q_node * next;			// Pointer to the next node
};

// ADT of a queue
class queue
{
	public:
        queue();	// Constructor
        ~queue();	// Destructor
    
    	int enqueue(const customer & to_add);	// Add a order in the queue
        int dequeue();							// Remove a order in the queue
		int peek(customer & to_peek)const;		// Take information about the first order
		int is_empty();				// Check if the queue is empty
        int display_all();			// Display the orders in the queue

	private:
        q_node * rear;	// Pointer to the rear of the queue
};

// ------------------------- ABSTRACTION OF THE STACK -------------------------

// ADT of a statistic
class statistic
{
    public:
        statistic();	// Constructor

		int create_statistic(float spent_time, float average_time); // Create a statistic about the last order time
		int copy_info(const statistic & copy_from);	// Copy information to the ADT
		int get_average();				// Get the average value
		int get_time();					// Get the spent time value
		int display_info();				// Display the statistic info			

    private:
		float spent_time;		// Amount of time which the order spent to be delivered
		float average_time;		// Average of time to deliver a order
};

//Struct of a stack node
struct node
{
	statistic * a_statistic;	// Dynamically allocated array of statistic
	node * next;				// Pointer to the next node
};

// ADT of Stack 
class stack
{
	public:
		stack(); 	// Constructor
		~stack();	// Destructor
		
        int push(const statistic & to_push);	// Push a statistic in the stack
        int pop();								// Pop a statistic in the stack
        int peek(statistic &)const;				// Take information about the first statistic
		int display_all();						// Display all statistic in the stack
	
	private:
        node * head;	// Stack head
        int top_index;	// Index of the stack
};

// ----------------------- ABSTRACTION OF THE SERVICE  ------------------------

class service
{
    public:
        service();		// Constructor
        ~service();		// Destructor
    
        int add_order(const customer & to_add);	// Add a order in the service system
        int deliver_order();					// Deliver a order in the food cart
        int display_orders();					// Display all orders
		int display_statistics();				// Display all statistics
        
    private:
        queue * order_queue;		// Queue of orders
		stack * statistic_stack;	// Stack of statistic
        int customers;				// Number of customers that have already been attended
};
