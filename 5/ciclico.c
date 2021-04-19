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
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; } // Falha: nó não alocado
    N->info = elem; // Insere o conteúdo (valor do elem)
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo nó (primeiro nó)
    }
    else
    {
        N->prox = ((*lst)->prox) // Faz o novo nó apontar para o antigo 1o nó
        (*lst)->prox= N; // Faz o último nó apontar para o novo nó
    }
    return 1;
}

int tamanho_lista(Lista * lst)
{
    int i = 1;//Se a lista não é vazia, seu tamanho é pelo menos 1
    if (lista_vazia(*lst)==1)
    {
        return 0;
    }
    else
    {
        Lista aux = (*lst)->prox; // Faz aux apontar para 1o nó
        while (aux->prox != *lst)//ENQUANTO o próximo elemento não for  último
        {
            aux = aux->prox; //Percorre a lista
            i++;//Aumenta o contador
        }
        return i;//Retorna o tamanho
    }
}

int remove_final(Lista *lst, char *elem)
{
    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
        return 0;
    if ((*lst)->prox == *lst)//Trata lista com um elemento
    {
        free(*lst);
    }
    else
    {
        Lista aux = (*lst)->prox; // Faz aux apontar para 1o nó
        while (aux->prox != *lst)
        {
            aux = aux->prox; //Percorre a lista até encontrar o penúltimo elemento
        }
        *elem = (*lst)->info; //Passa o valor por referência
        aux->prox = (*lst)->prox; //Aponta o penúltimo para o primeiro
        free(*lst); //libera o último
        *lst = aux;//Aponta a lista para o novo último
    }

    return 1;//Sucesso
}

char remove_pos(Lista *lst, int pos)
{
    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
        return 0;
    int i = 1;
    Lista aux = (*lst)->prox
    while (aux->prox != *lst && i < pos)//ENQUANTO o próximo elemento não for i-ésimo
        {
            aux = aux->prox; //Percorre a lista
            i++;//Aumenta o contador
        }
    if (pos==i+1 && aux->prox = *lst)
        {
            aux->prox = (*lst)->prox; //Aponta o penúltimo para o primeiro
            free(*lst); //libera o último
            *lst = aux;//Aponta a lista para o novo último
        }
    else if (aux->prox = *lst)
        {

        }
}

void apaga_lista(Lista *lst)
{
    Lista aux = *lst;
    while ((*lst)->prox != *lst)//ENQUANTO o próximo elemento não for  último
        {
            (*lst) = (*lst)->prox; //Percorre a lista
            free(aux);//Aumenta o contador
            aux = *lst;
        }
        free(*lst);
        lst=NULL;
}
