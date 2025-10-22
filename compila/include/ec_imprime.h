#ifndef EC_IMPRIME
#define EC_IMPRIME

#include "ec_rgb_colors.h"
#include <stdio.h>
#include <string.h>

static char COR_ID[50];

void set_cor_ID(const char * identificador);

void ec_imprime(const char * texto);

#endif
