# Created by Alves Silva, Otavio Augusto
# Email address: alves2@pdx.edu
# Date: 02/07/2015
# Restaurant Order Program - A program to simulate an order system of a restaurant

# Welcome the user to the program
print("""Welcome to the Restaurant Order Program!
What would you like to order?
Use the menu selections provided.""")

menu = ("Exit", "Display Order", "Add an Item", "Delete an Item", "Increase Count of Item", "Decrease Count of Item") # Tuple of menu options
itens = []          # List of restaurant itens
amount_itens = {}   # Amount of itens in the list
choice = -1         # Loop condition

# While the options isn't '0', the program will continue
while (choice != 0):
    amount = 1;     # Amount of each item that will be increased
    
    # Loop to print the system display
    print ("-- -- -- -- -- -- -- -- -- -- -- -- -- --")
    number = 0                      # Auxiliary variable
    for option in menu:
        print (number, '-',(option)) # Print each option
        number += 1

    choice = int(input("\nEnter menu item number: "))       # Ask the user what is the option
    
    # If the options is '0', the program will close
    if choice == 0:
        print ("Good bye.")
        break
        
    # If the options is '1', the program will print the list of orders 
    if choice == 1:
        if (len(itens) == 0): # Check if the list has any item
            print ("There are no items on order.\n")
        else:                 # If not, print each item in  list with the current amount
            for item in itens:
                print(item,", quantity:",amount_itens[item])
                
    # If the options is '2', the program will add an item            
    elif choice == 2:
        item = input("Enter item name: ") # Ask the user what is the item's name
        if item in itens:                 # If item is already in the list 
            print ("Error! That item is already on order.\n")   # An error will be printed
        else:   # If not, the item is added in the list and the dictionary with the amount of one
            itens.append(item)
            amount_itens[item] = amount
            
    # If the options is '3'       
    elif choice == 3:
        if (len(itens) == 0): # Check if the list has any item
            print ("There are no items on order.")
        else:                 # If not, print each item in list
            i = 0
            for item in itens:
                print("Item", i,"-",item)
                i += 1
            number = int(input("Enter menu item number to delete: "))  # Ask the user which item will be deleted
            if ((number >= i) or (number < 0)):                        # If the number is a invalid number
                print ("Error! That is a invalid item number.\n")      # An error will be printed
            else:   
                print ("Successfully Deleted", itens[number])          # If not, the item will be deleted from the dictionary and list
                del amount_itens[itens[number]]
                itens.remove(itens[number])
    
    # If the options is '4', the program will increanse an amount of an item         
    elif choice == 4:
        if (len(itens) == 0):   # Check if the list has any item
            print ("There are no items on order.")
        else:                   # If there is any item
            i = 0
            for item in itens:  # For loop to print the itens with the current amount
                print("Item", i,"-", item, ", current quantity on order:", amount_itens[item])
                i += 1
            item = int(input("Enter menu item number to modify: "))  # Ask the user which item will be increased
            if ((item >= i) or (item < 0)):                          # If the number is a invalid number
                print ("Error! That is a invalid item number.\n")    # An error will be printed
            else:
                amount = int(input("Amount to increase the item: ")) # Ask the user what is the amount that will be increased
                amount_itens[itens[item]] = amount_itens[itens[item]] + amount  # Increase the current amount
    
    # If the options is '5', the program will increanse an amount of an item            
    elif choice == 5:
            if (len(itens) == 0):  # Check if the list has any item
                print ("There are no items on order.")
            else:                  # If there is any item
                i = 0
                for item in itens: # For loop to print the itens with the current amount
                    print("Item", i,"-",item, ", current quantity on order:",amount_itens[item])
                    i += 1
                item = int(input("Enter menu item number to modify: "))     # Ask the user which item will be decreased
                if ((item >= i) or (item < 0)):                             # If the number is a invalid number
                    print ("Error! That is a invalid item number.\n")       # An error will be printed
                else:
                    amount = int(input("Amount to increase the item: ")) # Ask the user what is the amount that will be decreased
                    if((amount > amount_itens[itens[item]]) or (amount < 0)): #Check if the amount that will be decreased is bigger than the current amount of less than 0
                        print ("Error! You cannot delete more items than are on order.\n") # An error will be printed
                    else:
                        amount_itens[itens[item]] = amount_itens[itens[item]] - amount # Decrease the current amount
                        if (amount_itens[itens[item]] == 0):            # If the current amount is 0, the item will be removed
                            del amount_itens[itens[item]]
                            itens.remove(itens[item])
                            
    # If the option is another thing, an error will be printed.
    else:
        print ("Error! That isn't a valid item number.\n")
