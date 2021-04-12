#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

//IMPRIME NUMEROS (0.000) A MAIS

struct no{
    double informacao;
    struct no *prox;
};

Lista criar_lista(){
    Lista cabecalho;
    cabecalho = (Lista)malloc(sizeof(struct no));
    if (cabecalho != NULL){
        cabecalho->prox = NULL;
        cabecalho->informacao = 0;
    }
    return cabecalho;
}

int lista_vazia(Lista lista){
    if (lista == NULL)
        return 1; //lista vazia
    else
        return 0; //lista nao vazia
}

//vai retornar o tamanho da lista
//como tem erro na hora de imprimir(imprime a mais) ta dando um numero maior na lista
int tamanho_lista(Lista *lista){
    int tamanho = 0;
    if (lista_vazia(*lista) == 1)
        return tamanho;
    Lista aux = (*lista);
    tamanho = 1;
    while ((aux)->prox != NULL) {
        (aux) = (aux)->prox;
        tamanho++;
    }
    return tamanho;
}


//vai retornar por referência o maior valor na lista
double maior_valor(Lista *lista, double *elemento){
    if (lista_vazia(*lista) == 1)
        return 0;
    *elemento = (*lista)->informacao;
    return 1;
}


//vai inserir o elemento ordenado, se der 1 foi inserido, se der 0 não foi
double insere_ord(Lista *lista, double elemento){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->informacao = elemento;
    if (lista_vazia(*lista) || elemento >= (*lista)->informacao) {
        N->prox = *lista;
        *lista = N;
        return 1;
    }
    Lista aux = *lista; //vai apontar pro primeiro no
    while (aux->prox != NULL && aux->prox->informacao > elemento)
        aux = aux->prox;
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

//vai ter um ponteiro levando pra lista 3 que eh o resultado da lista1 e lista2
double intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3){
    int i, j;
    Lista aux_1 = (*lista_1);
    Lista aux_2 = (*lista_2);
    if (lista_vazia(aux_1) == 1 || lista_vazia(aux_2) == 1)
        return 0;

    for  (i = 0; i < tamanho_lista(lista_1); i++) {
        if (insere_ord(lista_3, aux_1->informacao) == 0)
        if (insere_ord(&(*lista_3), aux_1->informacao) == 0)
            return 0;
        aux_1 = aux_1->prox;
    }

    for (j = 0; j < tamanho_lista(lista_2); j++) {
        if (insere_ord(lista_3, aux_2->informacao) == 0)
        if (insere_ord(&(*lista_3), aux_2->informacao) == 0)
            return 0;
        aux_2 = aux_2->prox;
    }

    return 1;
}


//limpa a lista
double esvaziar_lista(Lista *lista){
    if (lista_vazia(*lista) == 1)
        return 0;
    while ((*lista)->prox != NULL) {
        Lista aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
    free(*lista);
    *lista = NULL;
    return 1;
}

//retorna o elemento na posição
double obtem_valor(Lista *lista, double *elemento, int posicao){
    if(posicao < 0 || lista_vazia(*lista) == 1)
        return 0;
    int i = 0;
    Lista aux = (*lista);

    while (i < posicao && aux->prox != NULL) {
        aux = aux->prox;
        i++;
    }
    if (i != posicao)
        return 0;
    *elemento = aux->informacao;
    return 1;
}
