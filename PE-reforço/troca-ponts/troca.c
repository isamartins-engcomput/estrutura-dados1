#include <stdio.h>

void trocarAeB(int v[])
{
  v[0] = 5000;
  v[1] = 10;
}

int main()
{
  int v[2] = {10,5000};

  trocarAeB(v);

  printf("\nValor atual de A: %d",v[0]);
  printf("\nValor atual de B: %d\n\n",v[1]);

return 0;
}