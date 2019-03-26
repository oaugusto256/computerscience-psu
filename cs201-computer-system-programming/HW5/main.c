#include <stdio.h>
#include <stdlib.h>

struct lineOrg
{
    int B;          // Block size
    int validBit;   // Valid bit
    int tag;        // Tag bit
};

struct cacheOrg
{
    int S;  // Number of sets
    lineOrg E;
};



char hexToBin(char * hex);  

int main(int argc, char * argv[])
{
    int S, E, B, H, M;
    
    S = (int)(argv[1][0] - '0');    // Number of sets
    E = (int)(argv[2][0] - '0');    // Number of lines
    B = (int)(argv[3][0] - '0');    // Block size
    H = (int)(argv[4][0] - '0');    // Hit time cycle
    M = (int)(argv[5][0] - '0');    // Miss time cycle
         
    char * cache;
    
    // Declarar array multidimensional
    // Ver como carregar um endereço de memoria na cache
    // Ver como criar contadores
    // Calcular numero de hits e misses 
   
   
    cache = (char *)malloc(sizeof(char)*S*E*B);
    
    printf("%d %d %d %d %d\n", S, E, B, H, M);
}
