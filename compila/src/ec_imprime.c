#include "ec_imprime.h"
#include "ec_rgb_colors.h"

void set_cor_ID(const char * identificador)
{
    strcpy(COR_ID, identificador);
}

void ec_imprime(const char * texto)
{
    ec_imprimirCor(texto, COR_ID);
}