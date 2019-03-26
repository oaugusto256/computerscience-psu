/*
    Created by Alves Silva, Otavio Augusto 
    Email address: alves2@pdx.edu
    Date: 05/01/2015
    CS 201 - Computer System Programming 
    Decryption program
*/

#include <stdio.h>
#include <stdlib.h>

// Prototypes
void decimal_binary(int decimal, int binary[]);     // Fuction to convert a decimal number to binary.
int binary_decimal(int binary[]);                   // Fuction to convert a binary number to decimal.

int main(int argc, char *argv[])
{
    FILE *fp;           // FILE fp is the file that will be decrypted.
    int len;            // Variable len will contatin the size of file.
    int aux;            // Auxiliary variable to swap bytes and bits.
    int i;              // Auxiliary variable to count.
    int binary[8];      // Array binary which will contain the bits of each byte.

    if(fopen(argv[1],"r") == NULL)                       // Try open the program name that was passed, if we have an error.
    {
        fprintf(stderr, "HW3 can't open %s\n", argv[1]); // An error is generated and printed to the user.
        exit(1);        // The program is closed
     }
    else                // If everything occurred OK, the file is opened.
    {
        fp = fopen(argv[1],"r"); 
    }
        
    fseek(fp, 0, SEEK_END);  // Sets the file position to the end of file.
    len = ftell(fp);         // Take the file size.
    int data[len];           // Create a data array with the length size.
    
    fseek(fp, 0, SEEK_SET);  // Sets the file position to the beginning of file.
    for(i = 0; i < len; ++i) // For loop - To read each character(1 Byte - 8 bits) in decimal in file.
        data[i] = fgetc(fp); 
    
    // First step - For every 4 bytes of the file <c0,c1,c2,c3>: Swap bytes c0 and c3. 
    i = 0;
    while(i <= len)
    {
        aux = data[i];       // Take the c0 value
        data[i] = data[i+3]; // Swap c0 value and c3 value
        data[i+3] = aux;     // Swap c3 value and aux(c0) value
        i = i+4;             // Jump for the next group of 4 bytes  
    }
    
    // Second step - For every byte of the file with bits <b7,b6,b5,b4,b3,b2,b1,b0>: Swap bits b7 and b3, Swap bits b6 and b2.
    i = 0;
    while(i < len)
    {
        decimal_binary(data[i], binary); // Convert decimal data number to binary
        
        aux = binary[7];                 // Take the b7 value
        binary[7] = binary[3];           // Swap b7 value and b3 value
        binary[3] = aux;                 // Swap b3 value and aux(b7) value
        
        aux = binary[6];                 // Take the b6 value
        binary[6] = binary[2];           // Swap b6 value and b2 value
        binary[2] = aux;                 // Swap b2 value and aux(b6) value
        
        data[i] = binary_decimal(binary);// Convert binary number to decimal and put in the data array 
        i += 1;
    }
    
    // Third step - For every 4 bytes of the file <c0,c1,c2,c3>, XOR bytes c1 and c0 with k3 ('v').
    i = 0;
    while(i <= len)
    {
        data[i] = data[i] ^ 118;        // XOR with c0 and 'v'(118 is the 'v' decimal value).
        data[i+1] = data[i+1] ^ 118;    // XOR with c1 and 'v'(118 is the 'v' decimal value).
        i = i+4;                        // Jump for the next group of 4 bytes
    }
    
    for(i = 0; i < len; ++i)            
        printf("%c", data[i]);          // Print each character 
        
    fclose(fp);                         // FILE fp is closed
    return (0);       
}

void decimal_binary(int decimal, int binary[])
{   
    int i;
    for (i = 0; i <= 7; ++i) 
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
    }
}

int binary_decimal(int binary[]) 
{
    int decimal = 0; 
    int i = 0;
    int x = 1;
    
    while (i <= 7)
    {
        decimal = decimal + (binary[i]*x);
        x += x;
        ++i;
    }
    return decimal;
}
