#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;

    v = malloc(50000000  * sizeof(int));

    v[0] = 1;

    free(v);
    
    return 0;
}