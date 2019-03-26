/* - Algorithm -
    Start program
            create constants with the maximum size of a phrase, hidden word or guess
            create arrays phrase and word
            create intenger variables to keep the player points
            
            Welcome the program and rules for the user
            
            Starts player one turn
            
            Fuction - Read the player phrase 
                Do a loop while the phrase isn't valid
                    If the phrase is valid
                        The loop ends
                    If is not valid
                        Print again and ask again, until the user put a valid phrase
            
            Fuction - Read the word which the player wants hidden
                Do a loop while the word isn't valid 
                    If the word is valid
                        The loop ends
                    If the word is not valid
                        Print an error and ask again, until the user put a valid word
            
            Fuction - Uppercase phrase and word
                Uppercase the phrase
                    Do a loop to uppercase each character in the phrase
                Uppercase the word
                    Do a loop to uppercase each character in the word
            
            Clean the system screen            
                                    
            Fuction - Find the word in the phrase
                Create a pointer variable to keep the word that will be hidden
                Create a array of spaces with the same size of the word
                Find the position of the word in the phrase
                Replaces the word by the array of spaces
            
            Player two points takes the number of points calculate  by Fuction - Guessing the word in the phrase
                Create an array of characters to keep the guess word
                Create a variable to keep how many chances were used
                Create a boolean variable to control a loop
                
                While the codition is false
                    Show the phrase with the hidden word
                    Take the guess word
                    Uppercase the guess word
                    Check if the guess word is the same 
                        If is the same
                            Inform the player two that he guessed it
                            Loop condition is true and the loop ends
                            
                        If is not the same
                            Inform the player two that is not it
                            Adds by one the number of chances
                            Reduces by two the number of points
                            
                        If the number of chances if bigger or equal of 5
                            Inform that the user doesn't have more chances
                            Reduces by two the number of points
                            Loop condition is true and the loop ends
             
                Returns the player number of points
                 
            Player two turns  
            
            Fuction - Read the player phrase 
                Do a loop while the phrase isn't valid
                    If the phrase is valid
                        The loop ends
                    If is not valid
                        Print again and ask again, until the user put a valid phrase
            
            Fuction - Read the word which the player wants hidden
                Do a loop while the word isn't valid 
                    If the word is valid
                        The loop ends
                    If the word is not valid
                        Print an error and ask again, until the user put a valid word
            
            Fuction - Uppercase phrase and word
                Uppercase the phrase
                    Do a loop to uppercase each character in the phrase
                Uppercase the word
                    Do a loop to uppercase each character in the word
            
            Clean the system screen            
                                    
            Fuction - Find the word in the phrase
                Create a pointer variable to keep the word that will be hidden
                Create a array of spaces with the same size of the word
                Find the position of the word in the phrase
                Replaces the word by the array of spaces
            
            Player one points takes the number of points calculate by Fuction - Guessing the word in the phrase
                Create an array of characters to keep the guess word
                Create a variable to keep how many chances were used
                Create a boolean variable to control a loop
                
                While the codition is false
                    Show the phrase with the hidden word
                    Take the guess word
                    Uppercase the guess word
                    Check if the guess word is the same 
                        If is the same
                            Inform the player two that he guessed it
                            Loop condition is true and the loop ends
                            
                        If is not the same
                            Inform the player two that is not it
                            Adds by one the number of chances
                            Reduces by two the number of points
                            
                        If the number of chances if bigger or equal of 5
                            Inform that the user doesn't have more chances
                            Reduces by two the number of points
                            Loop condition is true and the loop ends
             
                Returns the player number of points
                
            Fuction - Results
                Calculate which is the winner
                If the player one has more points than player two
                    Print results
                If the player two has more points than player one
                    Print results
                If the player one and player two have the same amount
                    Print the results
    End program
*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

/* 
    Created by Alves Silva, Otavio Augusto
    Program #2 - Word-guessing game
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 02/01/2015
*/

// Constants
const int SIZE = 81;            // Max size of a phrase
const int WORD_SIZE = 11;       // Max size of a hidden word or guess

// Prototypes 
void intro();                   // Welcome the game and rules for the user           
void read_phrase(char []);      // Read the player's phrase
void read_word(char []);        // Read the word that will be hidden in the phrase
void uppercase(char [], char []);          // Uppercase all characters in the phrase and hidden word
void hidden_word(char [], char []);        // Hide the word in the phrase   
int guessing_word(char [],char [], int);   // Read the guessed word and return the amount of points
void results(int , int);                   // Show the results

int main()
{
    char phrase[SIZE];          //  Keep the player phrase
    char word[WORD_SIZE];       //  Keep the player word which will be hidden
    
    int playerone_points = 10;  //  Keep the player one points
    int playertwo_points = 10;  //  Keep the player two points
    
    // Welcome the program and rules for the user
    intro();
    
    // Player one turn
    cout << "=================== \n";
    cout << "= PLAYER ONE TURN = \n";
    cout << "=================== \n\n";
    
	read_phrase(phrase);        // Read the player one phrase
    read_word(word);            // Read the word which will be hidden
    uppercase(phrase,word);     // Uppercase all the characters in the phrase and word
    
    system("clear");            // Clean the terminal
    
    hidden_word(phrase,word);   // Hide the word in phrase
    playertwo_points = guessing_word(phrase,word,playertwo_points); // Player two guess the hidden word and calculate his final points
    
    // Player two turn
    cout << "=================== \n";
    cout << "= PLAYER TWO TURN = \n";
    cout << "=================== \n\n";

	read_phrase(phrase);        // Read the player two phrase
    read_word(word);            // Read the word which will be hidden
    uppercase(phrase,word);     // Uppercase all the characters in the phrase and word
        
    system("clear");            // Clean the terminal
    
    hidden_word(phrase,word);   // Hide the word in phrase
    playerone_points = guessing_word(phrase,word,playerone_points); // Player one guess the hidden word and calculate his final points
    
    // Show the results
    results(playerone_points, playertwo_points);  
}

void intro()
{
    system("clear"); // The terminal is clean
     
    cout << "==================================\n";
    cout << "=        WORD-GUESSING GAME      =\n";     
    cout << "==================================\n\n";
    
    // Welcome the game rules for the user
    cout << "========= \n";
    cout << "= RULES = \n";
    cout << "========= \n\n";

    cout << "=======================================================================================\n";
    cout << "= The first player will enter a phrase and then he will enter a word that he wants to =\n";
    cout << "= be hidden in the phrase.The second player has 5 chances to figure out what is it.   =\n";
    cout << "= For each turn, a player gets 10 points. Each time that a player incorrectly guess a =\n";  
    cout << "= word, 2 points are deducted from their score. After a player guessing correctly or  =\n";  
    cout << "= incorrectly 5 times, the players switch turns. At the final of the game, the winner =\n";
    cout << "= will be who has more points.                                                        =\n";
    cout << "=======================================================================================\n\n";
}

void read_phrase(char phrase[])
{
    bool condition = false; // Auxiliary loop condition

    do                      
    {
        cout << "Please, enter the phrase: ";   // Ask for the phrase
        cin.get(phrase, SIZE, '\n');            // Take the phrase
        if(cin.peek() == '\n')                  // If the phrase has the valid size
            condition = true;                   // The loop is finished
        else
            cout << "ERROR! You entered too many characters.\n\n"; // If isn't, an error message is printed and the loop continues
            cin.ignore(250,'\n');                                  // The buffer is clean
    }while(condition == false);
}

void read_word(char word[])
{
    bool condition = false; // Auxiliary loop condition

    do
    {
        cout << "Please, enter the word that you want to be hidden in the phrase: "; // Ask for the word that will be hidden
        cin.get(word, WORD_SIZE, '\n');     // Take the word
        if(cin.peek() == '\n')              // If the word has the valid size
            condition = true;               // The loop is finished
        else
            cout << "ERROR! You entered too many characters.\n\n"; // If isn't, an error message is printed and the loop continues
            cin.ignore(100,'\n');                                  // The buffer is clean
    }while(condition == false);
}

void uppercase(char phrase[], char word[])
{
    for(int i = 0; i < strlen(phrase); i++)  
        phrase[i] = toupper(phrase[i]);     // Uppercase all characters of the phrase
    
    for(int i = 0; i < strlen(word); i++)
        word[i] = toupper(word[i]);         // Uppercase all characters of the word
}
    
void hidden_word(char phrase[], char word[])
{    
    char * hidden;                          // Pointer to the hidden word
    char space[WORD_SIZE];                  // Array of characters of '_' which will replace the word
    
    hidden = strstr(phrase,word); 
    
    for(int i = 0; i < strlen(word); i++)   // Create a array of '_' with the same size
        space[i] = '_';
        
    strncpy(hidden,space,strlen(word));     // Replaces the word by the array of spaces
}

int guessing_word(char phrase[], char word[], int points)
{   
    char guess[WORD_SIZE];                  // Keep the word that will be guessed
    bool condition = false;                 // Auxiliary loop condition
    int chances = 0;                        // Keep how many chances were used
    
    do{
        cout << "The phrase is: " << phrase;          // Show the phrase with the hidden word
        cout << "\n\nTry to guess the hidden word: "; // Take the guess 
        cin.get(guess, WORD_SIZE, '\n');
        cin.ignore(100,'\n');
        
        for(int i = 0; i < strlen(guess); i++)        // Uppercase the guessed word
            guess[i] = toupper(guess[i]);
        
        if(strcmp(word,guess) == 0)                   // If the guess is the same
        {   
            condition = true;                         // Loop condition is true
            cout << "You guessed it!\n\n";            // Inform the player
        }
        else if(chances < 4)                          // While the number of chances are less than 4
        {
            points = points -2;                       // Reduces by 2 the number of points
            chances += 1;                             // Add by one the number of chances
            cout << "Try again! It was your "<< chances << "# chance.\n\n";     // Inform the player that the guess was wrong and number of chances
        }
        else                                          // If the player reached the #5 chance
        {
            cout << "Sorry! You don't have more chances.\n\n";  // Inform that he doesn't have more chances
            points = points -2;                       // Reduces by 2 the number of points
            condition = true;                         // Loop condition is true
        }       
    }while(condition == false);                     
    
    return points;
}

void results(int playerone_points, int playertwo_points)
{      
	cout << "=========== \n";
    cout << "= RESULTS = \n";
    cout << "=========== \n";
    
    if(playerone_points > playertwo_points) // If player one has more points than player two
        cout << "\nThe player one is the winner with "<< playerone_points << " points against " << playertwo_points <<".\n\n"; // Print the results
    else if(playertwo_points > playerone_points) // If player two has more points than player one
        cout << "\nThe player two is the winner with "<< playertwo_points << " points against " << playerone_points <<".\n\n"; // Print the results
    else if(playerone_points == playertwo_points) // If player one has the same amount of points than player two
        cout << "\nDraw ! The players have the same points.\n\n"; // Print the results
}
