#include <stdio.h>
#include <stdlib.h>

struct No
{
  struct No *proximo;
};

struct ListaEncadeada
{
  struct No *cabeca;
  int quantidade;
};

struct ListaEncadeada **lista = malloc(sizeof(struct ListaEncadeada));