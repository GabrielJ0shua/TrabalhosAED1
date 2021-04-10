#include <stdio.h>
#include <stdlib.h>
#include "implementacao.h"

struct node
{
    double info;
    struct node *prox;
};

LISTA criar_lista()
{
    return NULL;
}

int lista_vazia(LISTA l)
{
    if(l == NULL)
    {
        return 1;
    }
    return 0;
}

int inserir_inicio(LISTA *l, double elem)
{
    LISTA N = (LISTA)malloc(sizeof(struct node));
    if(N == NULL)
    {
        return 0;
    }
    N->info = elem;
    if(lista_vazia(*l) == 1)
    {
        N->prox = N;
    }
    else
    {
        LISTA aux = *l;
        N->prox = aux;
        do
        {
            aux = aux->prox;
        }
        while(aux->prox != *l);
        aux->prox = N;
    }
    *l = N;
    return 1;
}

// Cara, se pá é melhor fazer leituras e verificações antes de entrar na função e depois chamar com os parametros ja definidos
int inserir_posicao(LISTA *l, double elem, int pos)
{
    LISTA N = (LISTA)malloc(sizeof(struct node));
    char caractere_aux;
    if(N == NULL)
    {
        return 0;
    }
    N->info = elem;
    LISTA aux = *l;
    int pos_aux = 1;
    if(pos > (tamanho(l) + 1))
    {
        printf("A posição informada é maior que o tamanho da lista, se a operação continuar, será inserido na posição %d, você deseja continuar?(y/n)", (pos % tamanho(l)));
        setbuf(stdin, NULL);
        scanf("%c", &caractere_aux);
        switch (caractere_aux)
        {
        case 'y':
            inserir_posicao(l, elem, (pos % tamanho(l)));
            break;

        case 'n':
            printf("Operação cancelada...\n");
            return 0;
            break;
        
        default:
            printf("Resposta inválida, insira apenas um caractere(y/n)!");
            break;
        }
        return 0;
    }
    if(tamanho(l) == 0)
    {
        // lista vazia
        N->prox = N;
        *l = N;
        return 1;
    }
    else if(pos <= 1)
    {
        N->prox = aux;
        do
        {
            // coloca aux na última posição
            aux = aux->prox;
        }
        while(aux->prox != (*l));
        aux->prox = N;
        *l = N;
        return 1;
    }
    else if(pos == (tamanho(l) + 1))
    {
        N->prox = aux;
        do
        {
            // coloca aux na última posição
            aux = aux->prox;
        }
        while(aux->prox != (*l));
        aux->prox = N;
        return 1;
    }
    else
    {
        while(pos_aux < pos - 1)
        {
            aux = aux->prox;
            pos_aux++;
        }
        N->prox = aux->prox;
        aux->prox = N;
        return 1;
    }
}

// Cara, se pá é melhor fazer leituras e verificações antes de entrar na função e depois chamar com os parametros ja definidos
int remove_posicao(LISTA *l, int pos)
{
    char caractere_aux;
    int pos_aux = 1;
    LISTA aux = *l;
    if(tamanho(l) == 0)
    {
        printf("Nenhum elemento a ser removido!\n");
        return 0;
    }
    if(tamanho(l) == 1)
    {
        *l = NULL;
        return 1;
    }
    if(pos > tamanho(l))
    {
        printf("A posição informada é maior que o tamanho da lista, se a operação continuar, será removido na posição %d, você deseja continuar?(y/n)", (pos % tamanho(l)));
        setbuf(stdin, NULL);
        scanf("%c", &caractere_aux);
        switch (caractere_aux)
        {
        case 'y':
            remove_posicao(l, (pos % tamanho(l)));
            break;

        case 'n':
            printf("Operação cancelada...\n");
            break;

        default:
            printf("Resposta inválida, insira apenas um caractere(y/n)!");
            break;
        }
        return 0;
    }
    else if(pos <= 1)
    {
        // removendo o primeiro nó
        LISTA aux2 = aux;
        do
        {
            // coloca aux na última posição
            aux = aux->prox;
        }
        while(aux->prox != (*l));
        aux->prox = (*l)->prox;
        *l = aux->prox;
        free(aux2);
        return 1;
    }
    else if(pos == tamanho(l))
    {
        // removendo o último nó
        do
        {
            // coloca aux na penúltima posição
            aux = aux->prox;
        }
        while(aux->prox->prox != (*l));
        LISTA aux2 = aux->prox;
        aux->prox = *l;
        free(aux2);
        return 1;
    }
    else
    {
        while(pos_aux < pos - 1)
        {
            aux = aux->prox;
            pos_aux++;
        }
        LISTA aux2 = aux->prox;
        aux->prox = aux->prox->prox;
        free(aux2);
        return 1;
    }
    return 0;
}

int tamanho(LISTA *l)
{

    if(lista_vazia(*l) == 1)
    {
        return 0;
    }
    LISTA aux = (*l)->prox;
    int cont = 0;
    do
    {
        cont++;
        aux = aux->prox;
    }
    while(aux != (*l)->prox);
    return cont;
}

// Função int retornando 0 e 1 em casos de falha e sucesso.
// Passa uma variavel por referencia que vai receber o valor do maior e imprime ela na main
double maior(LISTA *l) 
{
    if(lista_vazia(*l) == 1)
    {
        exit(EXIT_FAILURE);
    }
    LISTA aux = (*l)->prox;
    double num_aux = aux->info;
    do
    {
        if(num_aux < aux->prox->info)
        {
            num_aux = aux->prox->info;
        }
        aux = aux->prox;
    }
    while (aux != (*l)->prox);
    return num_aux;
}

// Eu pessoalmente prefiro deixar impressões só na main e retornar valores pra ela
int imprime_lista(LISTA l)
{
    if(lista_vazia(l) == 1)
    {
        return 0;
    }
    LISTA aux = l;
    do
    {
        printf("[ %lf ] ", aux->info);
        aux = aux->prox;
    }
    while (aux != l);
    return 1;
}


// Te falar que eu nao entendi bulhufas disso
// Eu fiz o seguinte, criei um aux que eu igualei ao ponteiro de inicio
// Avança o ponteiro de inicio, libera o auxiliar, iguala o auxiliar ao ponteiro de inicio
// E vai indo fio, vai indo
void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
