#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50000000

int main()
{
    char *v; // v é uma variável do tipo ponteiro para caractere
    int i, vquant[26];
    
    // aloca um vetor de caracteres de tamanho TAMANHO    
    v = malloc(TAMANHO * sizeof(char) ); 
    
    for (i = 0; i<26; i++)
        vquant[i] = 0;

    for (i=0; i< TAMANHO; i++)
    {
        v[i] = 65 + rand()% 26;                
        vquant[v[i]-65] ++;
    }

    for (i = 0; i<26; i++)
        printf("%d \t %c \t %d \n",  i, 65 + i, vquant[i]);

    free(v); // libera memória previamente alocada ao ponteiro v

    return 0;
}