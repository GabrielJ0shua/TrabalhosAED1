#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
struct no {
    int informacao; //guarda informacao do no
    struct no *prox; //endereco do proximo no
};
Lista criar_lista(){
    return NULL;
}
//vai ver se a lista ta vazia
int lista_vazia(Lista lista){
    if (lista == NULL)
        return 1; //lista vazia
    else
        return 0; //lista nao vazia
}

//vai inserir o elemento ordenado, se der 1 foi inserido, se der 0 não foi
int insere_ord(Lista *lista, int elemento){
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

//limpa a lista
int esvaziar_lista(Lista *lista){
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

//vai retornar por referência o maior valor na lista
int maior_valor(Lista *lista, int *elemento){
    if (lista_vazia(*lista) == 1)
        return 0;

    *elemento = (*lista)->informacao;
    return 1;
}

//vai retornar o tamanho da lista
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
//vai ter um ponteiro levando pra lista 3 que eh o resultado da lista1 e lista2
int intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3){
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

//retorna o elemento na posição
/*int obtem_valor(Lista *lista, int *elemento, int posicao){
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
*/
