#include "3.h"
#include "ec_imprime.h"

static void frase1();
static void frase2();
static void frase3();

void tres()
{
    set_cor_ID("Y");
    frase1();
    set_cor_ID("W");
    frase2();
    frase3();
}

static void frase1()
{
    ec_imprime("Listas são como amizades: a ordem importa,\n\tmas o importante mesmo é estar na lista certa.\n\n");    
}

static void frase2()
{
    ec_imprime("Referências são a base de conexões reais, seja em código ou na vida.\n\n");
}

static void frase3()
{
    ec_imprime("Se a vida te der listas, faça um algoritmo de ordenação.\n\n");
    ec_imprime("Somos ótimos estudantes!.\n\n");
}

