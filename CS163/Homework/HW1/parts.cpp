/*
    Filename: parts.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 15/04/2015    
    Class: CS 163 - Program #1
    Description: This file contains the functions of the parts.h 
*/

#include "parts.h"

// Constructor
part::part()
{
    number = 0;
    desc = NULL;
    amount = 0 ;
    num_step = 0;
    steps = NULL;
}

// Destructor 
part::~part()
{
    delete [] desc;
    desc = NULL;
    
    delete steps;
    steps = NULL;
}

// Create a part with the provided arguments
int part::create_part(int number, char * desc, int amount, int num_step, int * steps)
{
    this->number = number;
    
    this->desc = new char[strlen(desc)+1];
    strcpy(this->desc, desc);
    
    this-> amount = amount;
    
    this-> num_step = num_step;
    
    this->steps = steps;
    
    return 1;
}

// This function takes the argument and copies it into the part's data members
int part::copy_part(const part & copy_from)
{
    // If the argument doesn't have data
    if(!copy_from.number)
        return 0;       // Return failed 
    
    // If the data members already have some thing, 
    // we have to deallocate any memory
    if(number)
        number = 0;
    if(desc)
        delete [] desc;
    if(amount)
        amount = 0;
    if(num_step)
        num_step = 0;
    if(steps)
        delete steps;
    
    // Setting pointers to NULL for safety
    steps = NULL;
    desc = NULL;
    
    // Starting perform a deep copy
    if(copy_from.number)
        number = copy_from.number;
    
    if(copy_from.desc)
    {
        desc = new char[strlen(copy_from.desc)+1];
        strcpy(desc, copy_from.desc);
    }
    
    if(copy_from.amount)
        amount = copy_from.amount;
    
    if(copy_from.num_step)
        num_step = copy_from.num_step;
    
    if(copy_from.steps)
        steps = copy_from.steps;
            
    return 1;   // Return success
}

// This function displays the part information
int part::display()
{
    cout << "Part number: " << number << endl;
    cout << "Description: " << desc << endl;
    cout << "Amount: " << amount << endl;
    cout << "Amount of steps: "<< num_step << endl;
    cout << "Steps: ";

    for(int i = 0; i < num_step; i++)
    {
        cout << steps[i] << " ";
    }
    
    cout << "\n";
    cout << "-------------------------\n";
    
    return -1;
}

// This function return the part number 
int part::get_number()
{
    return number;
}


// Constructor
DIY::DIY()
{
    part_head  = NULL;
}

// Destructor
DIY::~DIY()
{
    node * temp;        // Create temp
    while(!part_head)   // While part_head isn't NULL
    { 
        temp = part_head -> next; // Take the part_head -> next
        delete part_head;         // Delete part_head
        part_head = temp;         // Part_head now is equal to temp
    }
    
    part_head = NULL;
}

// This function insert a part in the list 
// Using the part number by reference. Therefore,
// the function insert and sort the list in the same time.
int DIY::insert_part(part & to_add)
{   
    node * current = part_head;
    
    if(!current) // If the list is empty
    {
        part_head = current = new node; // Create a new node, this new node is head
        part_head->next = NULL;         // Point next to NULL;
        
        return (current->a_part).copy_part(to_add); // Return the function to copy 
                                                    // the information and add into the node 
    }
    else // The list already has some nodes
    {    
        // If the node has to be added in the begginer   
        if(to_add.get_number() <= part_head->a_part.get_number()) 
        {
            node * aux = new node; // Creates a new node
            aux->next = part_head; // Point next to head
            part_head = aux;       // This new node is head
            
            return (aux->a_part).copy_part(to_add); // Return the function to copy 
                                                    // the information and add into the node 
        }
        else // If the node has to be added in another place
        {   
            node * previous = NULL; // Auxiliar node to keep tranking of the previous node
            bool flag = true;       // Bool condition for the loop
            current = part_head;    // Take the head node
            
            do
            {
                previous = current;        // Previous is current
                current = current->next;   // Traversal
                    
                if(!current)               // If current is NULL
                    flag = false;          // End the loop
                else if(to_add.get_number() >= current->a_part.get_number()) // If the part number to add is bigger than the current
                    flag = true;                                             // The loop has to continue
                else
                    flag = false;          // End the loop
            
            }while(flag);
            
            node * aux = new node;         // Creates a new node
            previous->next = aux;          // Pointer the next previous pointer to the new node
            aux->next = current;           // Pointer the next aux pointer to current
            
            return (aux->a_part).copy_part(to_add); // Return the function to copy 
                                                    // the information and add into the node 
        }
    }           
    
    return 0;   // Return failed
}

// Display all parts in the list
int DIY::display_parts()
{                 
    node * current = part_head; // Take the head node
    int i = 0;                  // Count variable
      
    if(current)
    {
        while(current)
        {
            current->a_part.display();
            cout << "\n";
            i += 1;
            current = current->next;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int DIY::find_part(int num)
{
    node * current = part_head; // Take the head node
    bool find = false;          // Bool variable to control the loop
    
    if(current)  // If the list isn't empty
    {
        while(current && !find) // While the list has nodes or find is false
        {
            if(num == current->a_part.get_number()) // Check if the current part number is 
                                                    // the same from the argument
            {
                current->a_part.display();          // Display information
                find = true;                        // Find is true
                return 1;                           // Return success
            }
            current = current -> next;              // Traversal through the list
        }
        return 0; // Return failed 
    }
    else
    {
        return 0; // Return failed
    }
}

