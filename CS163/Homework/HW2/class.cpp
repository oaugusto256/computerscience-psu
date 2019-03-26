/*
    Filename: class.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 05/02/2015    
    Class: CS 163 - Program #2
    Description: This file contains the functions of the class.h  
*/

#include "class.h"

// --------------------------- CLASS Customer ----------------------------

// Constructor
customer::customer()
{
    name = NULL;
    order_number = 0;
    order_time = NULL;
}

// Destructor 
customer::~customer()
{
    delete name;
    name = NULL;
    
    delete order_time;
    order_time = NULL;
}

// Create a customer with the provided arguments
int customer::create_customer(char * new_name, int new_order_number, tm * & new_order_time)
{
    name = new char[strlen(new_name)+1];
    strcpy(name, new_name);
    
    order_number = new_order_number;
    
    order_time = new tm;
    order_time->tm_hour = new_order_time->tm_hour;
    order_time->tm_min  = new_order_time->tm_min;
    order_time->tm_sec  = new_order_time->tm_sec;
	order_time->tm_mday = new_order_time->tm_mday;
	order_time->tm_mon  = new_order_time->tm_mon;
	order_time->tm_year  = new_order_time->tm_year;
	order_time->tm_wday  = new_order_time->tm_wday;
	order_time->tm_yday  = new_order_time->tm_yday;
	order_time->tm_isdst = new_order_time->tm_isdst;
    
    return 1;
}

// This function takes the argument and copies it into the customer's data members
int customer::copy_info(const customer & copy_from)
{
	// If the argument doesn't have data
    if(!copy_from.name)
        return 0;	 // Return failed 
    
    // If the data members already have some thing, 
    // we have to deallocate any memory
    if(name)
        delete [] name;
    if(order_time)
        delete order_time;
    
	// Setting pointers to NULL for safety
    name = NULL;
    order_time = NULL;
    
	// Starting perform a deep copy
    name = new char[strlen(copy_from.name)+1];
    strcpy(name, copy_from.name);

    order_number = copy_from.order_number;
    
    order_time = new tm;
    order_time->tm_hour = copy_from.order_time->tm_hour;
    order_time->tm_min  = copy_from.order_time->tm_min;
    order_time->tm_sec  = copy_from.order_time->tm_sec;
	order_time->tm_mday = copy_from.order_time->tm_mday;
	order_time->tm_mon  = copy_from.order_time->tm_mon;
	order_time->tm_year  = copy_from.order_time->tm_year;
	order_time->tm_wday  = copy_from.order_time->tm_wday;
	order_time->tm_yday  = copy_from.order_time->tm_yday;
	order_time->tm_isdst = copy_from.order_time->tm_isdst;

    return 1;	// Return success
}

// This function displays the customer information
int customer::display_info()
{
    if(!name)
        return 0;
	
	time_t arrival;				
	arrival = mktime(order_time);	// Transform the tm struct in a time_t 
               
    cout << "Customer name: " << name << endl;
    cout << "Order number:  " << order_number << endl;
    cout << "Arrival date and time: " << ctime(&arrival) << endl;
    cout << "---------------------------------------------------" << endl;
    
    return 1;
}

// Retrieve the tm time struct
int customer::get_time(tm & to_get)const
{
	if(!order_time)
		return 0;
	
	to_get.tm_hour = order_time->tm_hour;
	to_get.tm_min = order_time->tm_min;
	to_get.tm_sec = order_time->tm_sec;
	to_get.tm_mday = order_time->tm_mday;
	to_get.tm_mon = order_time->tm_mon;
	to_get.tm_year = order_time->tm_year;
	to_get.tm_wday = order_time->tm_wday;
	to_get.tm_yday = order_time->tm_yday;
	to_get.tm_isdst = order_time->tm_isdst;
	
	return 1;
}

// ---------------------------- CLASS Queue ------------------------------

// Constructor
queue::queue()
{
    rear = NULL;
}

// Destructor
queue::~queue()
{
    while(dequeue()); // While we can dequeue, continue removing
    rear = NULL;	  // Point to null for safety
}

// Add a customer in the queue
int queue::enqueue(const customer & to_add)
{
    int success = 0; 
    
	// If the there is no customer in the queue
    if(!rear)
    {
        rear = new q_node;	// Create a rear
        rear->next = rear;	// Point to itself 
        
        success = rear->a_customer.copy_info(to_add); 	// Deep copy
    }
    else
    {
        q_node * temp = new q_node;	// Create a new node
        temp->next = rear->next;	// Point to the finish of the queue
        rear->next = temp;			// Linking the queue
        rear = temp;				// Rear is the new node
        
        success = rear->a_customer.copy_info(to_add);  // Deep copy
    }
    
    return success;	// Return the success
}

int queue::dequeue()
{
    if(!rear)		// If there isn't any customers 
        return 0;	// Return failed
    	
    if(rear == rear->next)	// If there is just one node left
    {
        delete rear;	// Delete rear
        rear = NULL;	// Point to null for safety
        
        return 1;		// Return success
    }
    else
    {
        q_node * temp = rear->next->next; // Take the penult node
        delete rear->next;				  // Delete the first node in the queue
        rear->next = temp;				  // Temp is the new rear
    
        return 1;	   // Return success
    }  
}

// Retrieve information about the first node in the queue
int queue::peek(customer & to_peek)const
{
	if(!rear)		// If there isn't any node to retrieve
		return 0;	// Return failed
	else
	{
		to_peek.copy_info((rear->next)->a_customer); // Deep copy to the argument
		return 1;	// Return success
	}
}

// Display all nodes
int queue::display_all()
{        
    if(!rear)		// If the queue is empty
        return 0;	// Return failed
    else
    {
        q_node * temp = rear->next; // Take the head
        int count = 0;				// Count of customers
    
        while(temp != rear)
        {   
            count += 1;
            cout << "-------------------- "<< count <<"# Order ---------------------"<< endl; 
            temp->a_customer.display_info();
            temp = temp->next;
        }
        
        count += 1;
        cout << "-------------------- "<< count <<"# Order ---------------------"<< endl;     
        rear->a_customer.display_info();

        return 1;	// Return success
    }
}

// Check if the queue is empty
int queue::is_empty()
{
	if(!rear)		// If there isn't any node
		return 1;   // Return true
	else
		return 0;  	// Return false
}

// --------------------------- CLASS Statistic -----------------------------

// Constructor
statistic::statistic()
{
	spent_time = 0;
	average_time = 0;
}

// Create a statistic with the provided arguments
int statistic::create_statistic(float new_spent_time, float new_average_time)
{
	spent_time = new_spent_time;
	average_time = new_average_time;
	
	return 1;	// Return success
}

// Copy the argument informations to the statistic data members
int statistic::copy_info(const statistic & copy_from)
{   
	// If the argument doesn't have data
    if(!copy_from.spent_time)
        return 0;	// Return failed 
	    
	// Starting perform a deep copy
    spent_time = copy_from.spent_time;
    average_time = copy_from.average_time;
	
	return 1;	// Return success
}

// Return the average time to deliver a order
int statistic::get_average()
{
	return average_time;
}

// Return the  time to deliver this order
int statistic::get_time()
{
	return spent_time;
}

// Display the data members of a statistic
int statistic::display_info()
{
    if(!spent_time)
        return 0;
          
	cout << "The worst time to deliver was: " << spent_time << " secs."<< endl; 
    cout << "The average time to deliver a order is: " << average_time <<" secs."<< endl;
    cout << "---------------------------------------------------" << endl;
    
    return 1;
}

// ----------------------------- CLASS Stack -------------------------------

// Constructor
stack::stack()
{
	head = NULL;
	top_index = 0;
}

// Destructor
stack::~stack()
{
	while(pop()); // While there is node to pop, continue removing
	head = NULL;  // Set head to NULL for safety
}

// Push a statistic in the stack
int stack::push(const statistic & to_push)
{
	int success = 0;
	node * current = head; 
	
	// If the stack is empty
	if(!current)
	{
		current = new node;		// Create a new node
		current->a_statistic = new statistic[MAX]; // Allocate the array for this node
		current->next = NULL;	// Point the next node to null
	
		head = current;			// Head is the new node
	
		success = current->a_statistic[top_index].copy_info(to_push); // Copy information
		++top_index;			// Increase the top index
	}
	else // If there already have more than one node
	{	
		if(top_index < MAX)		// If the array can have more elements
		{
			success = current->a_statistic[top_index].copy_info(to_push); // Copy information
			++top_index;	// Increase the top index
		}
		else
		{
			node * current = new node;	// Create a new node
			current->a_statistic = new statistic[MAX];	// Allocate the array for this node
			
			current->next = head;	// Linking the list
			head = current;			// Head is the new node
			
			top_index = 0;			// Start the top index to zero
			
			success = current->a_statistic[top_index].copy_info(to_push);	// Copy information
			++top_index;			// Increase the top index
		}
	}
	
	return success;					// Return success
}

// Pop a statistic in the stack
int stack::pop()
{
	// If the stack is empty
	if(!head)
		return 0;	// Return failed
	else
	{
		// If top index is bigger than zero
		if(top_index > 0)
		{	
			--top_index;	// Just decrease the index
			return 1;		// Return success
		}
		else				// If there is already a node with top index equal to zero
		{
			node * temp = head->next;	// Keep the next node of head
			delete head;		// Delete head
			head = NULL;		// Point to NULL
			
			head = temp;		// Temp is the new head
			
			if(head)				// If there is node
				top_index = MAX;	// Set the top index to the begginer 
			else
				top_index = 0;		// Set the top index to zero
		}
		return 1;					// Return success
	}
}

// Retrieve information of the first statistic in the list
int stack::peek(statistic & to_peek)const
{
	if(!head) 		// If there stack is empty
		return 0;	// Return failed
        
	int success = to_peek.copy_info(head->a_statistic[top_index-1]);	// Copy information of the statistic in the top
	return success; // Return success
}

// Display all nodes in the tack
int stack::display_all()
{
	if(!head)		// If there stack is empty
		return 0;	// Return failed
	else
	{
		node * current = head;
		int count = top_index;
		
		// Loop for the nodes
		while(current)
		{
			count = top_index;
			// Loop for the array
			while(count >= 0)
			{
				current->a_statistic[count].display_info();	// Display the content
				--count;									// Decrease the number of elements to display
			}
			current = current->next;	// Traverse through the list
		}
		return 1; 	// Return success
	}
}

// ---------------------------- CLASS Service ------------------------------

// Constructor
service::service()
{
    order_queue = new queue;
	statistic_stack = new stack;
    customers = 0;
}

// Destructor
service::~service()
{
    delete order_queue;
	order_queue = NULL;
	
	delete statistic_stack;
	statistic_stack = NULL;
}

// Add a order in the service system
int service::add_order(const customer & to_add)
{
    if(order_queue->enqueue(to_add))
    {	
        customers += 1;		// Increase the number of customers attended
		return 1;			// Return success
    }
    else
        return 0;			// Return failed
}

// Deliver a order in the service system
int service::deliver_order()
{
	if(!order_queue->is_empty())	// If the service queue isn't empty
	{
		customer a_customer;		// Customer ADT to retrieve
		statistic a_statistic;		// Statistic ADT to push in the stack
		
		time_t currentTime;			// Auxiliar variable to take the current time
		tm  arrival_time;			// tm structure to hold the order's arrival time
		tm * deliver_time;			// tm structure to hold the order's deliver time
		
		float average_time;			// Average time
		float last_order_time;		// Last amount of time to deliver a order
		float order_time;			// Current order time
		
		// Retrive the customer arrival order time
		order_queue->peek(a_customer);	
		a_customer.get_time(arrival_time);
		
		// Take the current time
        time(&currentTime);
        deliver_time = localtime(&currentTime);
		
		// Transform the tm structures in time_t 
		time_t deliver = mktime(deliver_time);
		time_t arrival = mktime(&arrival_time);
		
		// Calculate the amount of seconds to deliver a order
		order_time = difftime(deliver, arrival);
		
		// Retrieve the last statistic order
		statistic_stack->peek(a_statistic);
		last_order_time = a_statistic.get_time();
		average_time = a_statistic.get_average();
		
		// With these informations calculate the new average
		average_time = ((average_time * (customers-1)) + order_time)/customers;
		
		// If the last order time is bigger than the current
		if(last_order_time >= order_time)
		{
			// Pop the first statistic 
			// Create a new statistic and update the average
			// And push in the stack
			statistic_stack->pop();	
			a_statistic.create_statistic(last_order_time, average_time);
			statistic_stack->push(a_statistic);
		}
		else
		{	// Create a new statistic with the average and new time worst time
			// And push in the stack
			a_statistic.create_statistic(order_time, average_time);
			statistic_stack->push(a_statistic);
		}
		
		order_queue->dequeue();		// Remove the order in the food cart
		
		return 1;					// Return success
	}
	else
		return 0;					// Return failed
}

// Display all orders in the food cart
int service::display_orders()
{
    if(order_queue->display_all())
		return 1;
    else
        return 0;
}

// Display all statistic in the system
int service::display_statistics()
{
    if(statistic_stack->display_all())
		return 1;
	else
        return 0;
}
		