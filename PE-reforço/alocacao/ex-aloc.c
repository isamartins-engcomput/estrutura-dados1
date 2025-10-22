/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vint;

  vint = malloc(10000000 * sizeof(int));

  int posicao = 0;

  for(int i = 0; i < 10000000; i++)
  {
    if(vint[i] == 0)
    {
      posicao++;
    }
  }

  printf("\nQuantidade de posições não zeradas: %d\n\n",posicao);

  free(vint);

return 0;
}
*/

// CORREÇÃO - código do prof.Edson Castro

#include <stdio.h>
#include <stdlib.h>

#define TAM 10000000

int main()
{
    int *v;
    long int quant, i;

    v = malloc(TAM * sizeof(int));

    quant =0;
    for (i=0; i <TAM; i++)
    {
        if (v[i] == 0) 
            quant ++;
    }

    if (quant == TAM)
        printf("TODAS as posições zeradas!\n");
    else
        printf("quantidade de posições zeradas: %ld\n", quant);

    free(v);
    v = NULL;
}