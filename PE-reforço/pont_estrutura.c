#include <stdio.h>

struct produto
{
    int ID;
    float preco;
};

int main(void)
{
    struct produto arroz, feijao, *p1,*p2, *p3;

    p1 = &arroz;
    p2 = &feijao;
    p3 = p1;

    /*
        atraves dos ponteiros atualizar:

        ID do produto arroz para 15
        ID do produto feijão para 5000

        preco do produto associado ao ponteiro p3 para 30
        preco do produto associado ao ponteiro p2 para 20
    
    */
   //p1.ID = 15;
   //*p1.ID = 15;

   (*p1).ID = 15;
    p2->ID = 5000;
    
    p3->preco = 30;
    p2->preco = 20;


    /*
        Complete corretamente a tabela com os dados dos produtos arroz e Feijão 
        OBS: para produto imprimir os textos "Arroz" e "Feijão"
    */
    printf("PRODUTO	ID	preco\n");
    printf("=====================\n");
    printf("Arroz\t%d\t%.2f\n", arroz.ID, arroz.preco);
    printf("Feijao\t%d\t%.2f\n", feijao.ID, feijao.preco);

    printf("=====================\n");

    /*
        De maneira análoga ao anterior, faça uma tabela (corretamente formatada) 
        que exiba o endereço das variáveis ponteiros,
        os valores neles armazenados e os conteúdos apontados pelos 3 ponteiros
    */

   printf("Arroz\t%p\t\n",   &arroz);
   printf("Feijao\t%p\t\n\n", &feijao);

   printf("p1\t%p\t%p\t%d\t%.2f\n", &p1, p1, p1->ID, p1->preco);
   printf("p2\t%p\t%p\t%d\t%.2f\n", &p2, p2, p2->ID, p2->preco);
   printf("p3\t%p\t%p\t%d\t%.2f\n", &p3, p3, p3->ID, p3->preco);

    return 0;
}