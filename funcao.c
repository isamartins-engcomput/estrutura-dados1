#include <stdio.h>
#include <stdlib.h>

int somar(int x, int y);

int somar(int x, int y)
{
  int soma;
  soma = x + y;

  return soma;
}

int main()
{
  int a = 1, b;
  int soma;

  while(a > 0)
  {
    printf("\nInforme dois números A e B: ");
    scanf("%d %d",&a,&b);

    soma = somar(a,b);
    printf("\nResultado da soma A + B: %d\n\n",soma);
  }

  return 0;
}