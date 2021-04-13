#include "ciclico.h"
struct no
{
    char info;
    struct no * prox;
};
Lista cria_lista() {    return NULL;}

int lista_vazia (Lista lst)
{
    //Lista � um ponteiro; Se o ponteiro n�o apontar para nada, a lista est� vazia.
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
    Lista aux = (*lst)->prox; // Faz aux apontar para 1o n�
    *elem = aux->info; // Retorna valor do n� a ser removido
    if (*lst == (*lst)->prox) // Trata lista com 1 �nico n�
        *lst = NULL;
    else // Trata lista com + de 1 elemento
        (*lst)->prox = aux->prox;
    free(aux);    return 1;
}
int insere_final(Lista *lst, char elem)
{    // Aloca um novo n� e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; } // Falha: n� n�o alocado
    N->info = elem; // Insere o conte�do (valor do elem)
    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo n� apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo n� (�ltimo n�)
    }
    else
    {
        N->prox = (*lst)->prox;// Faz o novo n� apontar o 1o n�
        (*lst)->prox = N; // Faz o �ltimo n� apontar para o novo n�
        *lst = N; // Faz a lista apontar para o novo n� (�ltimo n�)
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
