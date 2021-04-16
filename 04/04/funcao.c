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

}

double listas_iguais(Lista *lista_1, Lista *lista_2, int tam1, int tam2){
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
