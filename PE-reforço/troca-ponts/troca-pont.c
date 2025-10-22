#include <stdio.h>

void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main ()
{
    int a = 10;
    int b = 5000;

    troca(&a, &b);

    printf("a: %d\n", a);
    printf("b: %d\n\n", b);

return 0;
}