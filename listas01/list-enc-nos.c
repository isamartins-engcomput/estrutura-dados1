#include <stdio.h>

struct Estudante
{
  int ID;
  float nota;
  char nome[60];
};

struct No
{
  struct Estudante estudante;
  struct No *proximo;
} No;

int main()
{
  struct No no1 {29,10,"Jośe\0"};
  struct No no2 {10,7,"Pedro Lucas\0"};
  struct No no3 {8,9,"Gustavo\0"};

  no1.proximo = &no2;
  no2.proximo = &no3;
  no3.proximo = NULL;
}