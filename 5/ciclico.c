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
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; } // Falha: n� n�o alocado
    N->info = elem; // Insere o conte�do (valor do elem)
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo n� apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo n� (primeiro n�)
    }
    else
    {
        N->prox = ((*lst)->prox) // Faz o novo n� apontar para o antigo 1o n�
        (*lst)->prox= N; // Faz o �ltimo n� apontar para o novo n�
    }
    return 1;
}

int tamanho_lista(Lista * lst)
{
    int i = 1;//Se a lista n�o � vazia, seu tamanho � pelo menos 1
    if (lista_vazia(*lst)==1)
    {
        return 0;
    }
    else
    {
        Lista aux = (*lst)->prox; // Faz aux apontar para 1o n�
        while (aux->prox != *lst)//ENQUANTO o pr�ximo elemento n�o for  �ltimo
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
        Lista aux = (*lst)->prox; // Faz aux apontar para 1o n�
        while (aux->prox != *lst)
        {
            aux = aux->prox; //Percorre a lista at� encontrar o pen�ltimo elemento
        }
        *elem = (*lst)->info; //Passa o valor por refer�ncia
        aux->prox = (*lst)->prox; //Aponta o pen�ltimo para o primeiro
        free(*lst); //libera o �ltimo
        *lst = aux;//Aponta a lista para o novo �ltimo
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
    while (aux->prox != *lst && i < pos)//ENQUANTO o pr�ximo elemento n�o for i-�simo
        {
            aux = aux->prox; //Percorre a lista
            i++;//Aumenta o contador
        }
    if (pos==i+1 && aux->prox = *lst)
        {
            aux->prox = (*lst)->prox; //Aponta o pen�ltimo para o primeiro
            free(*lst); //libera o �ltimo
            *lst = aux;//Aponta a lista para o novo �ltimo
        }
    else if (aux->prox = *lst)
        {

        }
}

void apaga_lista(Lista *lst)
{
    Lista aux = *lst;
    while ((*lst)->prox != *lst)//ENQUANTO o pr�ximo elemento n�o for  �ltimo
        {
            (*lst) = (*lst)->prox; //Percorre a lista
            free(aux);//Aumenta o contador
            aux = *lst;
        }
        free(*lst);
        lst=NULL;
}
