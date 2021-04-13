#include "ciclico.h"
struct no
{
    char info;
    struct no * prox;
};
Lista cria_lista() {    return NULL;}

int lista_vazia (Lista lst)
{
    //Lista é um ponteiro; Se o ponteiro não apontar para nada, a lista está vazia.
    if (lst == NULL)
        return 1;
    else
        return 0;
}
int remove_inicio(Lista *lst, char *elem)
{
    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox; // Faz aux apontar para 1o nó
    *elem = aux->info; // Retorna valor do nó a ser removido
    if (*lst == (*lst)->prox) // Trata lista com 1 único nó
        *lst = NULL;
    else // Trata lista com + de 1 elemento
        (*lst)->prox = aux->prox;
    free(aux);    return 1;
}
int insere_final(Lista *lst, char elem)
{    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; } // Falha: nó não alocado
    N->info = elem; // Insere o conteúdo (valor do elem)
    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo nó (último nó)
    }
    else
    {
        N->prox = (*lst)->prox;// Faz o novo nó apontar o 1o nó
        (*lst)->prox = N; // Faz o último nó apontar para o novo nó
        *lst = N; // Faz a lista apontar para o novo nó (último nó)
    }
    return 1;
}

int insere_inicio(Lista *lst, char elem)
{
    return 1;
}

int tamanho_lista(Lista * lst)
{
    return 1;
}

int remove_final(Lista *lst, char *elem)
{
    return 1;
}

char remove_pos(Lista *lst, int pos)
{
    return 1;
}
