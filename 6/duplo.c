#include "duplo.h"
#include <math.h>
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
    if (lista_vazia(*lst)==1) // Trata lista vazia
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


void apaga_lista(Lista *lst)
{
    Lista aux = *lst;
    while ((*lst)->prox != NULL)//ENQUANTO o próximo elemento não for  último
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
    int i = 1;//Se a lista não é vazia, seu tamanho é pelo menos 1
    if (lista_vazia(*lst)==1)
    {
        return 0;
    }
    else
    {
        Lista aux = (*lst)->prox; // Faz aux apontar para 1o nó
        while (aux->prox != NULL)//ENQUANTO existir prox elemento
        {
            aux = aux->prox; //Percorre a lista
            i++;//Aumenta o contador
        }
        return i+1;//Retorna o tamanho
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

int e_primo(int num)
{
    if (num<1)
        return 0;
    if (num==2)
        return 1;
    for (int i = 2; i<=sqrt(num);i++)
    {
        if (num%i==0)
            return 0;
    }
    return 1;
}

Lista primos(Lista *lst)
{
    Lista lst2, aux;
    aux = *lst;
    lst2 = cria_lista();
    while (aux->prox != NULL)
    {
        if(e_primo(aux->info)==1)
        {
                Lista N = (Lista) malloc(sizeof(struct no));
                if (N == NULL)
                    { return NULL; }
                // Falha: nó não alocado
                N->info = aux->info; // Insere o conteúdo (valor do elem)
                N->ant = NULL; // Não tem antecessor do novo nó
                N->prox = lst2; // Sucessor do novo nó recebe mesmo end. da lista
                if (lista_vazia(lst2) == 0) // Se lista NÃO vazia
                lst2->ant = N; // Faz o antecessor do 1o nó ser o novo nó
                lst2 = N; // Faz a lista apontar para o novo nó

        }
        aux=aux->prox;
    }
        if(e_primo(aux->info)==1)
        {
            Lista N = (Lista) malloc(sizeof(struct no));
            if (N == NULL)
                    { return NULL; }
            // Falha: nó não alocado
            N->info = aux->info; // Insere o conteúdo (valor do elem)
            N->ant = NULL; // Não tem antecessor do novo nó
            N->prox = lst2; // Sucessor do novo nó recebe mesmo end. da lista
            if (lista_vazia(lst2) == 0) // Se lista NÃO vazia
            lst2->ant = N; // Faz o antecessor do 1o nó ser o novo nó
            lst2 = N; // Faz a lista apontar para o novo nó
        }
    return lst2;
}

int get_posicao(Lista lst, int pos)
{
    if (lst == NULL)
        return 0;
    else
    {
        Lista aux = lst;
        for(int i = 1; i<pos; i++)
            {
                if(aux->prox != NULL)
                    aux=aux->prox;
                else
                    return 0;
            }
        return aux->info;
    }
}

Lista inverte(Lista* lst)
{
    Lista aux = *lst;
    Lista lst2 = cria_lista();
    while (aux->prox != NULL)//ENQUANTO existir prox elemento
        {
            aux = aux->prox; //Percorre a lista
        }
    while  (aux->ant!=NULL)
        {
            Lista N = (Lista) malloc(sizeof(struct no));
            if (N == NULL)
                { return NULL; }
            // Falha: nó não alocado
            N->info = aux->info; // Insere o conteúdo (valor do elem)
            N->ant = NULL; // Não tem antecessor do novo nó
            N->prox = lst2; // Sucessor do novo nó recebe mesmo end. da lista
            if (lista_vazia(lst2) == 0) // Se lista NÃO vazia
            lst2->ant = N; // Faz o antecessor do 1o nó ser o novo nó
            lst2 = N; // Faz a lista apontar para o novo nó

            aux = aux->ant; //Percorre a lista
        }

    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
        { return NULL; }
    // Falha: nó não alocado
    N->info = aux->info; // Insere o conteúdo (valor do elem)
    N->ant = NULL; // Não tem antecessor do novo nó
    N->prox = lst2; // Sucessor do novo nó recebe mesmo end. da lista
    if (lista_vazia(lst2) == 0) // Se lista NÃO vazia
    lst2->ant = N; // Faz o antecessor do 1o nó ser o novo nó
    lst2 = N; // Faz a lista apontar para o novo nó
    return lst2;
}
