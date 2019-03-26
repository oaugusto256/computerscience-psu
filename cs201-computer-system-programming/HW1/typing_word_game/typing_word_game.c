/*
    Created by Alves Silva, Otavio Augusto 
    Email address: alves2@pdx.edu
    Date: 04/13/2015
    CS 201 - Computer System Programming 
    Typing word game - How fast can you tip ?
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // timval and time to get time and generate numbers to seed
#include <string.h>   // strcmp to compare strings

int main()
{
	int i, random_number; 
	int n = 9;      // Numbers of words that will be entered 
	int count = 0;  // Auxiliary variable for output information
	
	char *words[] = {"The","quick","brown","fox","jumps","over","the","lazy","dog"}; // Array of strings with the words that will be entered
	char word[100];           // Variable to keep the user input
	
	
	struct timeval tim;     // Structure to represents an elapsed time
    struct timeval initial;  // Structure to represents an elapsed initial time
    struct timeval final;    // Structure to represents an elapsed final time
        	
    	// Welcome the user with some informations about the program and game.
	printf("This is a game that tests typing speed. \n");
    printf("Type the following words: \n");
     
    // Take the initial time in seconds and microseconds
    gettimeofday(&tim, NULL);
    initial.tv_sec = tim.tv_sec; 
    initial.tv_usec = tim.tv_usec;
      
    srand(time(NULL));  // Initialize random number generator. Seeder
    
    // Loop - While number of possibility is bigger than 0 
    do
    {
        random_number = rand()%n; // random_number receives a random number from 0 to 8.
        
        printf("  word %d# is %s: ", count+1, words[random_number]); // Print the word that must be entered 
        scanf("%s", word); // Receive the word
        
        // Checks if the word that was typed equals that was generated and while isn't the same, the program will continue asking for the correct word
        while(strcmp(word,words[random_number]) != 0) 
        {
            printf("Incorrect!  Try again.\n");
            printf("  word %d# is %s: ", count+1, words[random_number]);
            scanf("%s", word);
        }
        
        // If the word that was typed is correct. The word is removed from the array of words 
        for (i = random_number; i < n - 1 ; i++)
        {
            words[i] = words[i+1];                
        }

        n -= 1; // Decrease the number of possibles words
        count += 1; // Increase the auxiliary variable for output
    }while(n > 0);
    
    // Take the final time in seconds and microseconds
    gettimeofday(&tim, NULL);
	final.tv_sec = tim.tv_sec;
	final.tv_usec = tim.tv_usec;
	
	
	// Check if the initial time is bigger than the final to order the subtraction of time
	if (initial.tv_sec > final.tv_sec)
        timersub(&initial, &final, &tim);
    else if (initial.tv_sec < final.tv_sec)
        timersub(&final, &initial, &tim);
    else  // Check if the usec initial time is bigger than the final to order the subtraction of time
    {
        if (initial.tv_usec >= final.tv_usec)
            timersub(&initial, &final, &tim);
        else
            timersub(&final, &initial, &tim);
    }
	
	// Print the final time
    printf("\nCorrect! Your time is: %ld sec %ld usec\n\n", tim.tv_sec, tim.tv_usec);  
        
    return 0;   
}
