#include <stdio.h>
#include <stdlib.h>

void recover(){
    int * x;
	int  y = 1234;
	x = &y;

	printf("The hex value of X is: %X \n", *(x+1));
	printf("The hex value of X is: %p \n", x+2);
}
 
