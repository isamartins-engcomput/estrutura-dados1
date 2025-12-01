#include "lista_encadeada.h"
#include "ec_rgb_colors.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h> // nanosleep

void delay_ms(unsigned int ms);

struct No
{
    struct Estudante estudante;
    struct No *proximo;
    struct No *anterior; // Permite percorrer em ambos os sentidos
};

struct ListaEnc
{
    struct No *cabeca;       // ponteiro para o primeiro nó da lista
    struct No *cauda;        // Otimização para inserção no fim O(1)
    unsigned int quantidade; // quantidade de elementos
};

// Funções estáticas (privadas ao módulo)
static struct Estudante le_GetEstudante(int i);
static struct Estudante le_criaEstudante();
static struct Estudante le_LeEstudante();
static void le_ImprimeEstudante(struct Estudante e);
static int le_InsereListaInicio2(struct ListaEnc *lista, struct Estudante e);
static int le_InsereListaFim2(struct ListaEnc *lista, struct Estudante e);
static int le_InsereListaOrdenada2(struct ListaEnc *lista, struct Estudante e);
static int le_ListaNaoInicializada(struct ListaEnc *lista);

struct ListaEnc *le_CriaLista();
int le_InsereListaInicio(struct ListaEnc *lista);
int le_InsereListaInicio2(struct ListaEnc *lista, struct Estudante e);
int le_InsereListaFim2(struct ListaEnc *lista, struct Estudante e);
int le_InsereListaOrdenada2(struct ListaEnc *lista, struct Estudante e);
void le_ImprimeLista(struct ListaEnc *lista);
void le_EstudantesArquivo(struct ListaEnc *lista);

// IMPLEMENTAÇÃO
static struct Estudante le_criaEstudante()
{
    struct Estudante e = {0, 0, ""};
    return e;
}

static struct Estudante le_LeEstudante()
{
    struct Estudante e = le_criaEstudante();

    printf("ID: ");
    scanf("%d", &e.ID);
    getchar();
    if (e.ID == 0) return e;

    printf("Nota: ");
    scanf("%f", &e.nota);

    printf("Nome: ");
    getchar();
    scanf("%[^\n]", e.nome);

    return e;
}

static void le_ImprimeEstudante(struct Estudante e)
{
    printf("%d\t", e.ID);
    printf("%4.2f\t", e.nota);
    printf("%s\n", e.nome);
    delay_ms(1000);
}

static struct Estudante le_GetEstudante(int i)
{
    struct Estudante e;

    if (i == 0)
    {
        e.ID = -1;
        e.nota = 9.0;
        strcpy(e.nome, "John von Neumann");
    }
    if (i == 1)
    {
        e.ID = -2;
        e.nota = 9.7;
        strcpy(e.nome, "Edgar Frank Codd");
    }
    if (i == 2)
    {
        e.ID = -3;
        e.nota = 9.9;
        strcpy(e.nome, "Donald Ervin Knuth");
    }

    if (i > 2)
    {
        e.ID = 0;
        e.nota = 0;
        strcpy(e.nome, "");
    }

    return e;
}

void le_InsereTestes(struct ListaEnc *lista)
{
    struct Estudante e;

    printf("Inserindo estudantes de Teste...\n");

    for (int i = 0; i < 3; i++)
    {
        e = le_GetEstudante(i);
        le_InsereListaInicio2(lista, e);
    }
}

struct ListaEnc *le_CriaLista()
{
    // aloca dinamicamente a lista, utilizando ponteiros
    // inicializa a lista
    // retorna a lista

    struct ListaEnc *lista;

    lista = (struct ListaEnc *)malloc(1 * sizeof(struct ListaEnc));

    if (lista == NULL)
    {
        ec_imprimirCor("NÃO foi possível alocar memória para a lista", "RED");
        return NULL;
    }

    lista->cabeca = NULL;
    lista->quantidade = 0;

    return lista;
}

static int le_ListaNaoInicializada(struct ListaEnc *lista)
{
    // se lista não estiver inicializada, mensagem em amarelo
    // retornar 0 ou 1 dependendo do caso 

    if (lista == NULL)
    {
        ec_imprimirCor("Lista não inicializada!", "Y");
        return 1;
    }

    return 0;
}

int le_TamanhoLista(struct ListaEnc *lista, int imprime)
{
    // retorna a quantidade de elementos da lista
    // opção para imprimir ou ão quantidade de elementos da lista
    // caso a tratar: lista não inicializada

    if (le_ListaNaoInicializada(lista))
    {
        return 0;
    }

    if (imprime == 1)
    {
        ec_imprimirCor("Quantidade de elementos da lista: %d\n","Y", lista->quantidade);
    }

    return lista->quantidade;
}

int le_ListaVazia(struct ListaEnc *lista)
{
    // SE lista vazia, imprimir mensagem em amarelo
    // retorna 1 ou 0, dependendo se a lista está ou não vazia
    // caso a tratar: lista não inicializada

    if (le_ListaNaoInicializada(lista))
    {
        ec_imprimirCor("Lista vazia!\n","Y");
        return 1;
    }
    if (lista->quantidade == 0)
    {
        ec_imprimirCor("Lista vazia!\n","Y");
        return 1;        
    }

    return 0;
}

int le_ListaCheia(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista)) return 1;

    struct No *teste;
    teste = (struct No *) malloc(1 * sizeof(struct No));
    if (teste == NULL)
    {
        ec_imprimirCor("Memória insuficiente! Lista considerada cheia.", "R");
        return 1;
    }
    
    free(teste);
    return 0;
}

static int le_InsereListaInicio2(struct ListaEnc *lista, struct Estudante e)
{
    // alocar no, e validar se conseguiu
    // armazenar dados do estudante
    // caso a tratar: lista não inicializada
    
    if (le_ListaNaoInicializada(lista))
    {
        return 0;
    }

    struct No *no = (struct No *)malloc(1 * sizeof(struct No));

    if (no == NULL)
    {
        ec_imprimirCor("Não foi possível alocar memória para o nó!", "R");
        return 0;
    }

    no->estudante = e;
    no->proximo = lista->cabeca;
    no->anterior = NULL;
    
    if (lista->cabeca != NULL)
    {
        lista->cabeca->anterior = no;
    }
    else
    {
        lista->cauda = no;
    }

    lista->cabeca = no;
    lista->quantidade++;

    return 1;
}

int le_InsereListaInicio(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista))
    {
        return 0;
    }

    ec_imprimirCor("Inserção no ínicio da lista\n", "G");
    ec_imprimirCor("Informe os dados dos estudantes:\n", "G");
    ec_imprimirCor("ID 0 para finalizar\n", "Y");

    struct Estudante e;

    do
    {
        e = le_LeEstudante();

        if (e.ID == 0)
        {
            break;
        }

        le_InsereListaInicio2(lista, e);

    } while (e.ID > 0);

    return 1;
}

static int le_InsereListaFim2(struct ListaEnc *lista, struct Estudante e)
{
    if (le_ListaNaoInicializada(lista)) return 0;

    struct No *no = (struct No *) malloc(1 * sizeof(struct No));
    if (no == NULL)
    {
        ec_imprimirCor("Não foi possível alocar memória para o nó!", "R");
        return 0;
    }

    no->estudante = e;
    no->proximo = NULL;

    if (le_ListaVazia(lista))
    {
        no->anterior = NULL;
        lista->cabeca = no;
        lista->cauda = no;
    }
    else
    {
        // Usa o ponteiro CAUDA para ir direto ao fim
        lista->cauda->proximo = no; // O antigo último aponta para o novo
        no->anterior = lista->cauda; // O novo aponta para trás (antigo último)
        lista->cauda = no; // Atualiza o ponteiro de cauda
    }

    lista->quantidade++;
    return 1;
}

int le_InsereListaFim(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista)) return 0;

    ec_imprimirCor("Inserção no fim da lista\n", "G");
    ec_imprimirCor("Informe os dados dos estudantes:\n", "G");
    ec_imprimirCor("ID 0 para finalizar\n", "Y");

    struct Estudante e;
    do
    {
        e = le_LeEstudante();
        if (e.ID == 0) break;
        
        le_InsereListaFim2(lista, e);

    } while (e.ID != 0);

    return 1;
}

static int le_InsereListaOrdenada2(struct ListaEnc *lista, struct Estudante e)
{
    if (le_ListaNaoInicializada(lista)) return 0;

    struct No *no = (struct No *) malloc(1 * sizeof(struct No));
    if (no == NULL)
    {
        ec_imprimirCor("Não foi possível alocar memória para o nó!", "R");
        return 0;
    }
    no->estudante = e;

    struct No *anterior = NULL;
    struct No *atual = lista->cabeca;

    while (atual != NULL && atual->estudante.ID < e.ID)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL)
    {
        no->proximo = lista->cabeca;
        no->anterior = NULL;
        if (lista->cabeca != NULL) lista->cabeca->anterior = no;
        else lista->cauda = no;
        lista->cabeca = no;
    }
    else if (atual == NULL)
    {
        anterior->proximo = no;
        no->anterior = anterior;
        no->proximo = NULL;
        lista->cauda = no;
    }
    else
    {
        anterior->proximo = no;
        no->anterior = anterior;
        no->proximo = atual;
        atual->anterior = no;
    }
    
    lista->quantidade++;
    return 1;
}

int le_InsereListaOrdenada(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista)) return 0;

    ec_imprimirCor("Inserção ordenada (por ID) na lista\n", "G");
    ec_imprimirCor("Informe os dados dos estudantes:\n", "G");
    ec_imprimirCor("ID 0 para finalizar\n", "Y");

    struct Estudante e;
    do
    {
        e = le_LeEstudante();
        if (e.ID == 0) break;
        
        le_InsereListaOrdenada2(lista, e);

    } while (e.ID != 0);

    return 1;
}

int le_RemoveTodos(struct ListaEnc *lista, int exige_confirmacao)
{
    if (le_ListaNaoInicializada(lista)) return 0;
    if (le_ListaVazia(lista)) return 0;

    if (exige_confirmacao)
    {
        int confirma = 0;
        ec_imprimirCor("ATENÇÃO: Isso removerá TODOS os %d elementos. \n", "R", lista->quantidade);
        ec_imprimirCor("Confirmar? (1 - Sim / 0 - Não): ", "Y");
        scanf("%d", &confirma);
        if (confirma == 0)
        {
            ec_imprimirCor("Operação cancelada.\n", "G");
            return 0;
        }
    }

    struct No *atual = lista->cabeca;
    struct No *proximo_no;

    while (atual != NULL)
    {
        proximo_no = atual->proximo; 
        free(atual);              
        atual = proximo_no;       
    }

    // Reseta a lista
    lista->cabeca = NULL;
    lista->quantidade = 0;
    
    ec_imprimirCor("Todos os elementos removidos.\n", "G");
    return 1;
}

void le_DestroiLista(struct ListaEnc **lista)
{
    if (lista == NULL || *lista == NULL)
    {
        ec_imprimirCor("Lista já destruída ou não inicializada.\n", "Y");
        return;
    }

    le_RemoveTodos(*lista, 0);
    free(*lista);
    *lista = NULL;

    ec_imprimirCor("Lista destruída com sucesso.\n", "G");
}

void le_EnderecosNos(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista)) return;
    if (le_ListaVazia(lista)) return;

    struct No *atual = lista->cabeca;
    int i = 0;
    
    ec_imprimirCor("Endereços dos Nós na Lista:\n", "C");
    ec_imprimirCor("==================================================\n", "C");
    printf("Nó\tEndereço Atual\t\tPróximo Endereço\n");
    
    while (atual != NULL)
    {
        printf("%d\t%p\t%p\n", i, (void *)atual, (void *)atual->proximo);
        atual = atual->proximo;
        i++;
    }
    ec_imprimirCor("==================================================\n", "C");
}

void le_ImprimeLista(struct ListaEnc *lista)
{
    // imprime todos os elementos da lista
    // caso a tratar: lista não inicializada
    
    if (le_ListaNaoInicializada(lista)) return;
    if (le_ListaVazia(lista)) return;

    struct No *atual = lista->cabeca;

    ec_imprimirCor("\nImprimindo lista completa:\n", "C");
    ec_imprimirCor("ID\tNOTA\tNOME\n", "C");
    ec_imprimirCor("==================================================\n", "C");
    while (atual != NULL)
    {
        le_ImprimeEstudante(atual->estudante);
        atual = atual->proximo;
    }
    ec_imprimirCor("==================================================\n", "C");
    le_TamanhoLista(lista, 1);
}

//static void le_ImprimeEstudante(struct Estudante e);

struct Estudante le_BuscaChave(struct ListaEnc *lista, char *chave)
{
    struct Estudante e_vazio = le_criaEstudante(); // Retorno padrão se não achar
    if (le_ListaNaoInicializada(lista)) return e_vazio;
    if (le_ListaVazia(lista)) return e_vazio;

    int id_busca = atoi(chave);

    struct No *atual = lista->cabeca;
    while(atual != NULL)
    {
        if ( (id_busca != 0 && atual->estudante.ID == id_busca) || 
             (strcmp(atual->estudante.nome, chave) == 0) )
        {
            ec_imprimirCor("Elemento encontrado!\n", "G");
            return atual->estudante;
        }
        atual = atual->proximo;
    }
    
    ec_imprimirCor("Elemento não encontrado.\n", "R");
    return e_vazio;
}

struct Estudante le_RemoveChave(struct ListaEnc *lista, char *chave)
{
    struct Estudante e_removido = le_criaEstudante();
    if (le_ListaNaoInicializada(lista) || lista->cabeca == NULL) return e_removido;

    int id_busca = atoi(chave);
    struct No *atual = lista->cabeca;

    while (atual != NULL)
    {
        if ((id_busca != 0 && atual->estudante.ID == id_busca) || (strcmp(atual->estudante.nome, chave) == 0))
        { break; }
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        ec_imprimirCor("Elemento não encontrado.\n", "R");
        return e_removido;
    }

    if (atual->anterior == NULL)
    { 
        lista->cabeca = atual->proximo;
        if (lista->cabeca != NULL) lista->cabeca->anterior = NULL;
        else lista->cauda = NULL; 
    }
    else
    {
        atual->anterior->proximo = atual->proximo;
        if (atual->proximo != NULL)
        {
            atual->proximo->anterior = atual->anterior;
        }
        else
        {
            lista->cauda = atual->anterior;
        }
    }

    e_removido = atual->estudante;
    free(atual);
    lista->quantidade--;
    ec_imprimirCor("Removido com sucesso!\n", "G");
    return e_removido;
}

void le_ImprimeBuscaReversa(struct ListaEnc *lista, char *chave, int n)
{
    if (le_ListaNaoInicializada(lista) || lista->cabeca == NULL)
    {
        ec_imprimirCor("Lista vazia!\n", "R");
        return;
    }

    int id_busca = atoi(chave);
    struct No *atual = lista->cabeca;
    int encontrado = 0;

    while(atual != NULL)
    {
        if ((id_busca != 0 && atual->estudante.ID == id_busca) || (strcmp(atual->estudante.nome, chave) == 0))
        {
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }
    
    if (!encontrado)
    {
        ec_imprimirCor("Estudante não encontrado.\n", "R");
        return;
    }

    ec_imprimirCor("Estudante Encontrado:\n", "G");
    ec_imprimirCor("ID\tNOTA\tNOME\n", "C");
    le_ImprimeEstudante(atual->estudante);

    if (n > 0)
    {
        ec_imprimirCor("--- %d Anteriores (Ordem Inversa) ---\n", "Y", n);
        struct No *retrovisor = atual->anterior;
        int count = 0;
        
        while (retrovisor != NULL && count < n)
        {
            le_ImprimeEstudante(retrovisor->estudante);
            retrovisor = retrovisor->anterior;
            count++;
        }
        if (count == 0) ec_imprimirCor("(Não há estudantes anteriores)\n", "Y");
    }
}

void le_EstudantesArquivo(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista)) return;

    FILE *arquivo = fopen("notas.csv", "r");
    if (arquivo == NULL)
    {
        ec_imprimirCor("Não foi possível abrir o arquivo 'notas.csv'\n", "R");
        perror("Erro");
        return;
    }

    int opcao_insere;
    ec_imprimirCor("Como deseja inserir os dados do arquivo?\n", "C");
    printf("1 - Ordenado por ID\n");
    printf("2 - No Início\n");
    printf("3 - No Fim\n");
    printf("Opção: ");
    scanf("%d", &opcao_insere);

    char buffer[100];
    struct Estudante e;
    int count = 0;

    ec_imprimirCor("Importando dados de 'notas.csv'...\n", "C");

    while(fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (sscanf(buffer, "%d,%f,%[^\n]", &e.ID, &e.nota, e.nome) == 3)
        {
            if (opcao_insere == 1) le_InsereListaOrdenada2(lista, e);
            else if (opcao_insere == 2) le_InsereListaInicio2(lista, e);
            else le_InsereListaFim2(lista, e);
            count++;
        }
    }

    fclose(arquivo);
    ec_imprimirCor("%d estudantes importados com sucesso!\n", "G", count);
}

void delay_ms(unsigned int ms)
{
    struct timespec ts;

    // Converte milissegundos em segundos e nanossegundos
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;
    
    // Faz a pausa de acordo com os valores calculados
    nanosleep(&ts, NULL);
}