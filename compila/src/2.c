#include "2.h"
#include "ec_imprime.h"
#include <stdio.h>

static void frase1();
static void frase2();
static void frase3();

void dois()
{
    set_cor_ID("MAGENTA");
    frase1();
    set_cor_ID("E");
    frase2();
}

static void frase1()
{
    ec_imprime("Os algoritmos podem ser complexos, mas a solução sempre está a um 'debug' de distância.\n\n");
}

static void frase2()
{
    ec_imprime("Os melhores engenheiros não são os que sabem mais,\n\tmas os que fazem as melhores perguntas, nos momentos corretos.\n\n");
}
