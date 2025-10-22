#include <stdio.h>

int main(void)
{
  int i = 77777;
  int *p;

  p = &i;

  printf("Conteúdo apontado por p: %d\n",*p);

  *p = 2873189273;

  printf("Conteúdo apontado por p: %d\n",*p);
  printf("Conteúdo da variável: %d\n",i);

return 0;
}