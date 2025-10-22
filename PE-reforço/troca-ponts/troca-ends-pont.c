#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y)
{
  int aux;
  aux = &x;
  x = &y;
  y = aux;
}

int main()
{
  int a = 10;
  int b = 5000;

  printf("Endereço de a: %p\n",&a);
  printf("Endereço de b: %p\n\n",&b);

  troca(a,b);

  printf("Endereço de a: %p\n",&a);
  printf("Endereço de b: %p\n\n",&b);

return 0;
}