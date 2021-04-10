#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct no
{
    float info;
    struct no *prox;
};

Lista cria_lista()
{
    return NULL;
}

int tamanho(Lista li)
{
    if (li == NULL) return 0;
    int cont = 0;
    Lista aux = li;
    while (aux != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int iguais(Lista *li, Lista *li2)
{
    if (li == NULL && li2 == NULL) return 1;
    Lista aux, aux2;
    aux = *li;
    aux2 = *li2;

    if (tamanho(aux) == tamanho(aux2))
    {
        while (aux != NULL && aux2 != NULL)
        {
            if (aux->info == aux2->info)
            {
                aux = aux->prox;
                aux2 = aux2->prox;
            }
            else return 0;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

int maior(Lista *li, float *maior)
{
    if (li == NULL)
    {
        return 0;
    }
    *maior = (*li)->info;
    Lista aux = *li;

    while (aux != NULL)
    {
        if (aux->info > *maior)
        {
            *maior = aux->info;
        }
        aux = aux->prox;
    }
    return 1;
}

int lista_cheia(Lista *li)
{
    return 0;
}

int lista_vazia(Lista li)
{
    if (li == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insere_ord(Lista *li, float elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    N->info = elem;
    if (lista_vazia(*li) || elem > (*li)->info)
    {
        N->prox = *li;
        *li = N;
        return 1;
    }
    Lista aux = *li;
    while (aux->prox != NULL && aux->prox->info > elem)
    {
        aux = aux->prox;
    }

    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

Lista intercala(Lista *li, Lista *li2)
{
    if (li == NULL || li2 == NULL)
    {
        return NULL;
    }

    Lista aux, aux2;
    aux = *li;
    aux2 = *li2;

    Lista li3;
    li3 = cria_lista();

    while (aux != NULL && aux2 != NULL)
    {
        insere_ord(&li3, aux->info);
        insere_ord(&li3, aux2->info);
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    return li3;
}

int imp(Lista li)
{
    if (li == NULL)
    {
        printf("lista vazia \n");
        return 0;
    }
    else
    {
        while (li != NULL)
        {
            printf("%f \n", li->info);
            li = li->prox;
        }
    }
}

int esvaziar(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }

    Lista aux;
    while (*li != NULL)
    {
        aux = *li;
        *li = (*li)->prox;
        free(aux);
    }
    li = NULL;
    return 1;
}

int remove_ord(Lista *li, float elem)
{
    if (lista_vazia(*li) == 1 || elem > (*li)->info)
    {
        return 0;
    }
    Lista aux = *li;
    if (elem == (*li)->info)
    {
        *li = aux->prox;
        free(aux);
        return 1;
    }
    while (aux->prox != NULL && aux->prox->info > elem)
    {
        aux = aux->prox;
    }
    if (aux->prox == NULL || aux->prox->info > elem)
    {
        return 0;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int getPos(Lista *li, int pos)
{
    int nu;

    if (lista_vazia(*li) == 1)
        return 0;

    Lista aux = *li;
    for (int i = 0; i < pos && aux->prox != NULL; i++)
        aux = aux->prox;

    nu = aux->info;
    return nu;
}
