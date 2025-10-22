#include <stdio.h>

int a = 2;
int b = 3;

void retorna(int *p, int *pj)
{
  p = &a;
  pj = &b;
  printf("%p   %p\n",&p,&pj); // imprime endereço de p e pj

  printf("%p   %p",&a,&b); // imprime endereço de p e pj
  printf("%p   %p\n",p,pj); // imprime endereço de p e pj
  
  // printf("%d   %d",*p,*pj); imprime endereço de a e b
}

int main()
{
  retorna(&a,&b);
return 0;
}