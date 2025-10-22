#include <stdio.h>

void operar(int *x, int *y, int soma, int sub, int mult, float div)
{
  soma = *x + *y;
  sub = *x - *y;
  mult = *x * *y;
  div = *x / *y;
}

int main()
{
  int a = 20;
  int b = 5;
  int soma, sub, mult;
  float div;

  operar(&a,&b,soma,sub,mult,div);

  printf("\n===== RESULTADOS DAS OPERAÇÕES =====");
  printf("\nSoma: %d",soma);
  printf("Subtração: %d",sub);
  printf("Multiplicação: %d",mult);
  printf("Divisão: %f\n\n",div);

return 0;
}