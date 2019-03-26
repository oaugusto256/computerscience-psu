/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 05/02/2015    
    Class: CS 163 - Program #2
    Description: This file tests the ADT's and shows how the program could 
	be used by a restaurant system order.
*/

#include "class.h"

void clear();   // Clear function
int menu();     // Menu function

int main()
{
    // Variables to create a new customer in the system
	char * name = new char[SIZE];
    int order_number;
	tm * order_time;
	
	int option;				// Option of the menu
    
	customer a_customer;	// ADT customer
	service food_cart;    	// ADT service - System food cart
    
	time_t currentTime;	    // Auxiliar variable to calculate the current time

    clear();				// Clear the system screen
    
    do 						// Loop for the menu
    {
        option = menu();	// Shows the menu and receive the option
        
        switch(option)
        {
            case 1:
				// If the option is 1
				// Receive data to create a new customer order
                cout << "Please, enter the customer name: ";
                cin.get(name, SIZE, '\n');
                cin.ignore(SIZE, '\n');
    
                cout << "Please, enter the order number: ";
                cin >> order_number;
				cin.ignore(SIZE, '\n');
    			
				// Take the current time
                time(&currentTime);
                order_time = localtime(&currentTime);
				
				currentTime = mktime(order_time);
				cout << "Arrival date and time: " << ctime(&currentTime);
				
				// Try to create a new customer and add the new order in the system
                if(a_customer.create_customer(name, order_number, order_time))
                    if(food_cart.add_order(a_customer))	
                        cout << "Order was successfully registered!\n" << endl;
                break;
                
            case 2:
				// If the option is 2
				// Try to deliver a order in the system
				if(food_cart.deliver_order())	
                    cout << "Order delivered!\n" << endl;
				else	// If the system has not any order
					cout << "There isn't any order to deliver!\n" << endl;
				
				break;
                
            case 3: 
				// If the option is 3
				// Display all orders
                if(food_cart.display_orders()) 
                    cout << "\n";
                else 	// If the system has not any order
                    cout << "There isn't any order in the cart to display!\n" << endl;
                break;
			
			case 4: 
				// If the option is 4
				// Display all statistic
                if(food_cart.display_statistics()) 
                    cout << "\n";
                else	// If the system has not any statistic to display
                    cout << "There isn't any statistic to display!\n" << endl;
                break;
			
            default: 
                clear();
        }
    }
    while(option != 0);
    
    return 0; 
}

void clear(void)
{
    cout << "\033[H\033[J";
}

int menu()
{
    int option;
    
    cout << "----------------- FOOD CART SYSTEM ----------------" << endl;
    cout << "1 - Add a order in the food cart" << endl;
    cout << "2 - Deliver the order in the food cart" << endl;
    cout << "3 - Display all orders in the food cart" << endl;
	cout << "4 - Display all statistic in the food cart" << endl;
    cout << "0 - Exit" << endl;
    
    do
    {
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore(100,'\n');
    }
    while(option < 0 && option > 5);
    
    clear();
    
    return option;
}

