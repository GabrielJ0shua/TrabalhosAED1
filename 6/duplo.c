#include "duplo.h"
struct no
{
    int info;
    struct no * ant;
    struct no * prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1; // Lista vazia
    else
        return 0; // Lista N�O vazia
}
int insere_elemento(Lista *lst, int elem)
{
    // Aloca um novo n� e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
        { return 0; }
    // Falha: n� n�o alocado
    N->info = elem; // Insere o conte�do (valor do elem)
    N->ant = NULL; // N�o tem antecessor do novo n�
    N->prox = *lst; // Sucessor do novo n� recebe mesmo end. da lista
    if (lista_vazia(*lst) == 0) // Se lista N�O vazia
    (*lst)->ant = N; // Faz o antecessor do 1o n� ser o novo n�
    *lst = N; // Faz a lista apontar para o novo n�
    return 1;
}
int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst)==1) // Trata lista vazia
            return 0;
    Lista aux = *lst; // Faz aux apontar para 1o n�
    while (aux->prox != NULL && aux->info != elem)
            aux = aux->prox;
    if (aux->info != elem)
        return 0; // Elemento n�o est� na lista
    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant;
    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox;
    if (aux == *lst) *lst = aux->prox;
    free(aux);
    return 1;
}


void apaga_lista(Lista *lst)
{
    Lista aux = *lst;
    while ((*lst)->prox != NULL)//ENQUANTO o pr�ximo elemento n�o for  �ltimo
        {
            (*lst) = (*lst)->prox; //Percorre a lista
            free(aux);//Aumenta o contador
            aux = *lst;
        }
        free(*lst);
        lst=NULL;
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
        while (aux->prox != NULL)//ENQUANTO o pr�ximo elemento n�o for  �ltimo
        {
            aux = aux->prox; //Percorre a lista
            i++;//Aumenta o contador
        }
        return i;//Retorna o tamanho
    }
}

int remove_maior(Lista *lst, int *elem)
{
    Lista maior;
    if(lista_vazia(*lst)==1)
        return 0;
    if ((*lst)->prox == NULL)
    {
        free(*lst);
        return 1;
    }
    maior = *lst;
    Lista aux = (*lst)->prox;
    while (aux->prox != NULL)
    {
        if(aux->info>maior->info)
            maior = aux;
        aux=aux->prox;
    }
    if(aux->info>maior->info)
            maior = aux;
    if (maior->prox != NULL)
        (maior)->prox->ant = maior->ant;
    if (maior->ant != NULL)
        (maior)->ant->prox = maior->prox;
    if (maior == *lst) *lst = maior->prox;
    *elem = maior->info;
    free(maior);
    return 1;
}
