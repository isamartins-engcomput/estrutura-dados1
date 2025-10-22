#include <stdio.h>

int somar(int a, int b)
{
  return a + b;
}

int main()
{
  int a, b;

  printf("\nSOMA DE DOIS NUMEROS");

  printf("\nDigite um valor para a var A: ");
  scanf("%d",a);
  printf("\nDigite um valor para a var B: \n\n");
  scanf("%d",b);
  
  printf("Resultado da soma de A + B: %d",somar(a,b));
}