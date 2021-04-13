#include "duplo.h"
struct no
{
    int elem;
    struct no * ant;
    struct no * prox;
};
typedef struct no * Lista

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1; // Lista vazia
    else
        return 0; // Lista NÃO vazia
}
int insere_elemento(Lista *lst, int elem)
{
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
        { return 0; }
    // Falha: nó não alocado
    N->info = elem; // Insere o conteúdo (valor do elem)
    N->ant = NULL; // Não tem antecessor do novo nó
    N->prox = *lst; // Sucessor do novo nó recebe mesmo end. da lista
    if (lista_vazia(*lst) == 0) // Se lista NÃO vazia
    (*lst)->ant = N; // Faz o antecessor do 1o nó ser o novo nó
    *lst = N; // Faz a lista apontar para o novo nó
    return 1;
}
int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst) // Trata lista vazia
            return 0;
    Lista aux = *lst; // Faz aux apontar para 1o nó
    while (aux->prox != NULL && aux->info != elem)
            aux = aux->prox;
    if (aux->info != elem)
        return 0; // Elemento não está na lista
    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant;
    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox;
    if (aux == *lst) *lst = aux->prox;
    free(aux);
    return 1;
}
