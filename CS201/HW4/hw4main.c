#include <stdio.h>
#include <stdlib.h>

int foo (int, short, char, int, int);
void recover ();

int main (int argc, char ** argv) {
  int a, countDown, retVal;
  short b;
  char c;
  if (argc != 5) {
    printf ("Usage: program <int> <int> <int> <int>\n");
    exit (-1);
  }
  a = atoi (argv[1]);
  b = atoi (argv[2]);
  c = atoi (argv[3]);
  countDown = atoi (argv[4]); 
  printf ("main called with a = %d, b = %d, c = %d, countDown = %d\n", a, b, c, countDown);
  retVal = foo (a, b, c, 0, countDown);
  printf ("foo returns %d\n", retVal);
  return (0);
}

int foo (int a, short b, char c, int countUp, int countDown) {
  int x, y, z;
   
  if (!countDown) {
    recover ();
    return a;
  }
    
  if (a < 0)
    x = (a << 1) + 1;
  else
    x = a << 1;
  if (b < 0)
    y = (b << 1) + 1;
  else
    y = b << 1;
  if (c < 0)
    z = (c << 1) + 1;
  else
    z = c << 1;
  
  x ^= b;
  y ^= c;
  z ^= a;
     
  return a + foo (x,y,z, countUp+1, countDown-1);
}



