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
    Lista N = (Lista) malloc(sizeof(struct no)); // aloca dinamicamente
    if(N == NULL) // se a lista L for nula retorna zero
        return 0;
    N->informacao = elemento; // o ponteiro que aponta pra informação vai receber o elemento digitado
    if (lista_vazia(*lista) || elemento >= (*lista)->informacao) { //faz verificação se o elemento digitado é maior ou igual o que foi digitado anteriormente
        N->prox = *lista;
        *lista = N;
        return 1;
    }
    Lista aux = *lista; //vai apontar pro primeiro no
    while (aux->prox != NULL && aux->prox->informacao > elemento) //condição que enquanto meu aux que aponta pro proximo elem. não for 0 e o aux que aponta pro prox que aponta pra inf(ponteiro de ponteiro de ponteiro) for maior que o elemento
        aux = aux->prox; // então o aux recebe o aux apontando pro proximo item
    N->prox = aux->prox;
    aux->prox = N;
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

int listas_iguais(Lista *lista_1, Lista *lista_2, int tam1, int tam2){
    Lista aux_1 = (*lista_1); //auxiliar 1 recebe o ponteiro da lista 1
    Lista aux_2 = (*lista_2); //auxiliar 2 recebe o ponteiro da lista 2
    if(lista_vazia(*lista_1) == 1 && lista_vazia(*lista_2) == 1) //verifica se tem elemento na lista
        return 1;
    if(lista_1 == NULL || lista_2 == NULL)
        return 0; // lista vazia


    if(tam1 != tam2) //tamanhos diferentes
        return 0;
    if(tam1 == 1){
        if(aux_1->informacao != aux_2->informacao) //se o elemento que ta na informação 1 for diferente da 2
        return 0; //retorna 0
    }

    int teste = 0; //listas iguais
    while(aux_1->prox != NULL && teste == 0){ //enquanto o resultado do "apontamento" do aux pro proximo for diferente de nulo e o teste for 0
        if(aux_1->informacao != aux_2->informacao) teste = 1; // se aux1 e aux1 foram diferentes dai as listas é diferente
        aux_1 = aux_1->prox; //aux1 recebe o elemento que o ponteiro de aux1 ta apontando
        aux_2 = aux_2->prox; //aux2 recebe o elemento que o ponteiro de aux2 ta apontando
    }
    if(teste == 0)
        return 1;
    else
        return 0;

}
