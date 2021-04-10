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
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));
    if (cab != NULL)
    {
        cab->prox = NULL;
        cab->info = 0;
    }
    return cab;
}

int lista_cheia(Lista lst)
{
    return 0;
}

int lista_vazia(Lista lst)
{
    if (lst->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int tamanho(Lista li)
{
    if (li == NULL)
    {
        return 0;
    }
    int cont = 0;
    Lista aux = li;
    while (aux != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont - 1;
}

int iguais(Lista li, Lista li2)
{
    if (li == NULL && li2 == NULL)
    {
        return 1;
    }
    
    Lista aux, aux2;
    aux = li->prox;
    aux2 = li2->prox;

    if (tamanho(aux) == tamanho(aux2))
    {
        while (aux != NULL && aux2 != NULL)
        {
            if (aux->info == aux2->info)
            {
                aux = aux->prox;
                aux2 = aux2->prox;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

int maior(Lista li, float *maior)
{
    if (li == NULL)
    {
        return 0;
    }
    *maior = li->info;
    Lista aux = li;
    aux = aux->prox;

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

int insere_ord(Lista lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    N->info = elem;
    Lista aux = lst;
    while (aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox;
    }

    N->prox = aux->prox;
    aux->prox = N;
    lst->info++;
    return 1;
}

Lista intercala(Lista li, Lista li2)
{
    if (li == NULL || li2 == NULL)
    {
        return 0;
    }

    Lista aux, aux2;
    aux = li;
    aux2 = li2;

    aux = aux->prox;
    aux2 = aux2->prox;

    Lista li3;
    li3 = cria_lista();

    while (aux != NULL && aux2 != NULL)
    {
        insere_ord(li3, aux->info);
        insere_ord(li3, aux2->info);
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    return li3;
}

int imp(Lista lst)
{
    if (lst == NULL)
    {
        printf("lista vazia \n");
        return 0;
    }
    else
    {
        lst = lst->prox;
        while (lst != NULL)
        {
            printf("%f \n", lst->info);

            lst = lst->prox;
        }
    }
}

int esvaziar(Lista li)
{
    if (li == NULL)
    {
        return 0;
    }

    Lista aux = li->prox;
    aux->info = 0;
    Lista aux2;
    
    while (aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    li->prox = NULL;
    return 1;
}

int remove_ord(Lista lst, int elem)
{
    if (lista_vazia(lst) == 1)
    {
        return 0;
    }
    Lista aux = lst;
    while (aux->prox != NULL && aux->prox->info < elem)
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
    lst->info--;
}


int getPos(Lista lst, int posi)
{
    int numero;
    posi++; 

    if (lista_vazia(lst) == 1)
        return 0;

    Lista aux = lst;
    for (int i = 0; i < posi && aux->prox != NULL; i++)
        aux = aux->prox;

    numero = aux->info;
    return numero;
}