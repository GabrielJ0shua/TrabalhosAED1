#include <stdio.h>
#include <stdlib.h>
#include "implementacao.h"
#define tam 20

struct lista
{
    int info[tam];
    int fim;
}; 

LISTA criar_lista()
{
    LISTA l;
    l = (LISTA)malloc(sizeof(struct lista));
    if(l != NULL)
    {
        l->fim = 0;
    }
    return l;
}

int lista_vazia(LISTA l)
{
    if(l->fim == 0) return 1;
    return 0;
}

int lista_cheia(LISTA l)
{
    if(l->fim == tam) return 1;
    return 0;
}

int inserir_ord(LISTA l, int elem)
{
    if(l == NULL || lista_cheia(l) == 1) return 0;
    if(lista_vazia(l) == 1 || elem >= l->info[l->fim - 1]) l->info[l->fim] = elem;
    else
    {
        int i;
        int aux = 0;
        while (elem >= l->info[aux]) aux++;
        for (i = l->fim; i > aux; i--) l->info[i] = l->info[i - 1];
        l->info[aux] = elem;
    }
    l->fim++;
    return 1;
}

int remover_ord(LISTA l, int elem)
{
    if(l == NULL || lista_vazia(l) == 1 || elem > l->info[l->fim - 1]) return 0;
    int i; 
    int aux = 0;
    while (aux < l->fim && l->info[aux] < elem) aux++;
    if(aux == l->fim || l->info[aux] > elem) return 0;
    for(i = aux + 1; i < l->fim; i++) l->info[i-1] = l->info[i];
    l->fim--;
    return 1;
}

int remover_pares(LISTA l)
{
    if(l == NULL) return 0;
    int aux = 0;
    while(aux < l->fim)
    {
        if(l->info[aux] % 2 == 0) remover_ord(l, l->info[aux]);
        aux++;
    }
    return 1;
}

int maior(LISTA l)
{
    int elem = l->info[0];
    int aux = 0;
    while(aux < l->fim)
    {
        if(l->info[aux] > elem) elem = l->info[aux];
        aux++;
    }
    return elem;
}

int tamanho(LISTA l)
{
    return l->fim;
}

int esvaziar(LISTA l)
{
    if(l == NULL) return 0;
    l->fim = 0;
    return 1;
}

LISTA intercalar(LISTA l1, LISTA l2)
{
    int aux = 0;
    if(l1 == NULL || l2 == NULL) return 0;
    LISTA l3 = criar_lista();
    while(aux < l1->fim)
    {
        inserir_ord(l3, l1->info[aux]);
        aux++;
    }
    aux = 0;
    while(aux < l2->fim)
    {
        inserir_ord(l3, l2->info[aux]);
        aux++;
    }
    return l3;
}

int imprimir(LISTA l)
{
    int aux = 0;
    if(l == NULL || lista_vazia(l) == 1)
    {
        printf("Lista vazia ou nula!\n");
        return 0;
    }
    while(aux < l->fim)
    {
        printf("[ %d ] ", l->info[aux]);
        aux++;
    }
    return 1;
}

void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}