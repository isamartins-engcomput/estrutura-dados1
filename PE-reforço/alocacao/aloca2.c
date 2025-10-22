#include <stdio.h>
#include <stdlib.h>

struct Animal
{
    int codigo;
    char especie[50];    
};

int main()
{
    struct Animal *animais;

    animais = malloc(5  * sizeof(struct Animal));

    // operacoes com o nosso vetor de animais

    free(animais);
    
    return 0;
}