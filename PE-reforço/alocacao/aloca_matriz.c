#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 2

int main (void)
{
    int **p;
    int i, j;

    p = NULL;

    int matriz[LIN][COL];

    p = (int**) malloc(LIN*sizeof(int));

    for (i=LIN-1; i>=0; i--)
    {
        p[i] = (int*) malloc(COL*sizeof(int));
        for (j=0; j<COL; j++)
        {
            p[i][j] = 10*(i+1) + (j+1); matriz[i][j] = p[i][j];
        }
    }

    for (i=LIN-1; i>=0; i--)
    {
        free(p[i]);
        p[i] = NULL;
    }

    free(p);
    p = NULL;


    return 0;
}

/*
graph display matriz
graph display i
graph display j
graph display p
graph display p[i]
graph display p[j]

graph display p[0]
graph display p[1]
graph display p[2]
graph display p[3]


graph display p[0][0]
graph display p[0][1]
graph display p[0][2]


graph display p[1][0]
graph display p[1][1]
graph display p[1][2]


graph display p[2][0]
graph display p[2][1]
graph display p[2][2]


graph display p[3][0]
graph display p[3][1]
graph display p[3][2]

*/