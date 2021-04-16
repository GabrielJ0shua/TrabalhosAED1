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
    Lista L = (Lista) malloc(sizeof(struct no)); // aloca dinamicamente
    if(L == NULL) // se a lista L for nula retorna zero
        return 0;
    L->informacao = elemento; // o ponteiro que aponta pra informação vai receber o elemento digitado
    if (lista_vazia(*lista) || elemento >= (*lista)->informacao) { //faz verificação se o elemento digitado é maior ou igual o que foi digitado anteriormente
        L->prox = *lista;
        *lista = L;
        return 1;
    }
    Lista aux = *lista; //vai apontar pro primeiro no
    while (aux->prox != NULL && aux->prox->informacao > elemento) //condição que enquanto meu aux que aponta pro proximo elem. não for 0 e o aux que aponta pro prox que aponta pra inf(ponteiro de ponteiro de ponteiro) for maior que o elemento
        aux = aux->prox; // então o aux recebe o aux apontando pro proximo item
    L->prox = aux->prox;
    aux->prox = L;
    return 1;
}

//limpa a lista
int esvaziar_lista(Lista *lista){
    if (lista_vazia(*lista) == 1)
        return 0;
    while ((*lista)->prox != NULL) {
        Lista aux = *lista; //o aux da lista vai receber o ponteiro da lista
        *lista = (*lista)->prox; //
        free(aux); // libera auxiliar
    }
    free(*lista); //libera a lista
    *lista = NULL;
    return 1;
}

//vai retornar por referência o maior valor na lista
int maior_valor(Lista *lista, int *elemento){
    if (lista_vazia(*lista) == 1) // lista vazia
        return 0;

    *elemento = (*lista)->informacao; //ponteiro do elemento vai receber o elemento armazenado na informação
    return 1;
}

//vai retornar o tamanho da lista
int tamanho_lista(Lista *lista){
    int tamanho = 0;
    if (lista_vazia(*lista) == 1) //lista vazia
        return tamanho;
    Lista aux = (*lista); // auxiliar da lista vai receber o ponteiro da lista
    tamanho = 1; //tamanho começa com 1
    while ((aux)->prox != NULL) { //enquanto meu auxiliar apontar pro proximo e isso for diferente de nulo
        (aux) = (aux)->prox; // o auxiliar recebe o ponteiro apontando pro proximo
        tamanho++; //incrementa e retorna o tamanho
    }
    return tamanho;
}
//vai ter um ponteiro levando pra lista 3 que eh o resultado da lista1 e lista2
int intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3){
    int i, j; //vão percorrer as listas
    Lista aux_1 = (*lista_1);
    Lista aux_2 = (*lista_2);
    if (lista_vazia(aux_1) == 1 || lista_vazia(aux_2) == 1) //se ambas forem vazias retorna zero
        return 0;

    for  (i = 0; i < tamanho_lista(lista_1); i++) { //laço pra percorrer a lista 1
        if (insere_ord(lista_3, aux_1->informacao) == 0) //chama a função de insere com a lista3 e o aux apotando pra informação pra verificar se é 0
        if (insere_ord(&(*lista_3), aux_1->informacao) == 0) //chama dnv função de insere mas com o endereço da lista
            return 0;
        aux_1 = aux_1->prox; //o aux vai receber o aux apontando pro proximo item
    }

    for (j = 0; j < tamanho_lista(lista_2); j++) { //laço pra percorrer a lista 2
        if (insere_ord(lista_3, aux_2->informacao) == 0) //chama a função de insere com a lista3 e o aux apotando pra informação pra verificar se é 0
        if (insere_ord(&(*lista_3), aux_2->informacao) == 0) //chama dnv função de insere mas com o endereço da lista
            return 0;
        aux_2 = aux_2->prox; //o aux vai receber o aux apontando pro proximo item
    }

    return 1;
}

//retorna o elemento na posição
int obtem_valor(Lista *lista, int *elemento, int posicao){
    if(posicao < 0 || lista_vazia(*lista) == 1) //retorna 0 se a posição for menor que 0 ou lista vazia
        return 0;
    int i = 0;
    Lista aux = (*lista); //o aux recebe o ponteiro da lista

    while (i < posicao && aux->prox != NULL) { //se o i for menor que a posicao do elemento e o ponteiro q aponta pro proximo for diferente de nulo então
        aux = aux->prox; // o aux recebe o ponteiro do aux pro proximo elemento
        i++; //incrementação
    }
    if (i != posicao) //se o i for diferente da posicao retorna zero
        return 0;
    *elemento = aux->informacao; //o ponteiro do elemento vai receber o que ta na informação
    return 1;
}

//compara as listas pra ver se são iguais
// ESSA VERSÃO IMPRIME QUE É IGUAL QUANDO NÃO É E VICE VERSA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*int listas_iguais(Lista *lista_1, Lista *lista_2){
    if (lista_vazia(*lista_1) == 1 || lista_vazia(*lista_2) == 1) //verifica se as listas estão vazias
        return 0;

    Lista aux_1 = (*lista_1); //auxiliar recebe o ponteiro da lista1
    Lista aux_2 = (*lista_2); //auxiliar 2 recebe o ponteiro da lista2

    while (((aux_1)->prox != NULL && (aux_2)->prox != NULL) // se os dois auxiliares apontam pro proximo elemento e for diferente de nulo
    && ((aux_1)->informacao == (aux_2)->informacao)) { // auxiliar vai apontar pro no que tem a informação, e comparar com o auxiliar 2
        (aux_1) = (aux_1)->prox; // vai receber o elemento que ta armazenado no ponteiro de ponteiro(o ponteiro de aux apontando pro proximo)
        (aux_2) = (aux_2)->prox;
    }

    if ((aux_1)->informacao == (aux_2)->informacao && ((aux_1)->prox != NULL && (aux_2)->prox != NULL)) //
        return 1;

    return 0;
}

int listas_iguais(Lista *lista_1, Lista *lista_2){ // ESSA VERSÃO NÃO IMPRIME NADA
    Lista aux_1 = (*lista_1);
    Lista aux_2 = (*lista_2);

        while(lista_1 != NULL && lista_2 != NULL){
            if((aux_1)->informacao != (aux_2) ->informacao){
                return 0;
            }
            (aux_1) = (aux_1)->prox;
            (aux_2) = (aux_2)->prox;
        }
        return (aux_1) == NULL && (aux_2) == NULL;

}
*/
