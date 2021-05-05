#include <stdlib.h>
#include <string.h>
#include "function.h"

typedef struct no{

    char info[50];
    struct no *prox;

}Elem;

struct cabecalho{

    struct no *inicio;
    struct no *final;
    int tamanho;

};

Lista cria_lista(){

    Lista N = (Lista)malloc(sizeof(struct cabecalho));
    if(N != NULL){
        N->inicio = NULL;
        N->tamanho = 0;
    }

    return N;

}

int lista_vazia(Lista li){

    if(li->inicio == NULL) return 1;
    else                      return 0;

}

int insere_elem(Lista *li, char *nome){

    if(li == NULL) return 0;

    Elem *N;
    N = (Elem*)malloc(sizeof(Elem));
    if(N == NULL) return 0;

    strcpy(N->info, nome);

    if((*li)->inicio == NULL){
        (*li)->inicio = N;
        N->prox = N;
        (*li)->final = N;
    }
    else{
        N->prox = (*li)->inicio;
        (*li)->final->prox = N;
        (*li)->final = N;        
    }

    (*li)->tamanho++;

    return 1;

}

int get_pos(Lista *li, int pos, char *nome){

    if(li == NULL || pos < 1 || lista_vazia(*li) == 1) return 0;

    int cont = 1;

    Elem *aux = (*li)->inicio;
    while(aux->prox != (*li)->inicio && cont < pos){
        aux = aux->prox;
        cont++;
    }

    if(cont != pos) return 0;

    strcpy(nome, aux->info);

    return 1;

}

int get_soldado(Lista *li, int *pos, char *nome){

    if(li == NULL || lista_vazia(*li) == 1) return 0;

    int cont = 1;

    Elem *aux = (*li)->inicio;
    while(aux->prox != (*li)->inicio && strcmp(nome, aux->info) != 0){
        aux = aux->prox;
        cont++;
    }

    if(strcmp(nome, aux->info) != 0) return 0;

    *pos = cont;

    return 1;

}

int tamanho_lista(Lista *li, int *tam){

    if(li == NULL) return 0;

    *tam = (*li)->tamanho;

    return 1;

}

int remove1(Lista *li, int contagem, int *pos, char *nome){

    if(li == NULL || contagem < 1 || lista_vazia(*li) == 1) return 0;

    if((*li)->inicio->prox == (*li)->inicio){
        strcpy(nome,(*li)->inicio->info);

        return 0;
    }

    Elem *aux = (*li)->inicio, *ant;

    int contador = 1;
    while(contador < *pos){
        ant = aux;
        aux = aux->prox;
        contador++;
    }

    contador = 1;

    while(contador < contagem){
        ant = aux;
        aux = aux->prox;
        contador++;
    }

    strcpy(nome,aux->info);

    if((*li)->inicio == aux){//REMOVER PRIMEIRA POSICAO
        (*li)->inicio = aux->prox;
        (*li)->final->prox = aux->prox;
        *pos = 1;
        free(aux);
    }

    else if((*li)->final == aux){//REMOVER ULTIMA POSICAO
        ant->prox = aux->prox;
        (*li)->final = ant;
        *pos = 1;
        free(aux);
    }

    else{//REMOVER POSICAO DO MEIO
        ant->prox = aux->prox;
        *pos = ((*pos) + contador - 1) % (*li)->tamanho;
        free(aux);
    }

    (*li)->tamanho--;

    return 1;

}

void esvaziar_lista(Lista *li){

    if(li != NULL){

        while((*li)->inicio->prox != (*li)->inicio){
            Elem *aux = (*li)->inicio;
            (*li)->inicio = aux->prox;
            free(aux);
        }
        Elem *aux = (*li)->inicio;
        (*li)->inicio = NULL;
        free(aux);
        (*li)->final = NULL;
        (*li)->tamanho = 0;

    }

}

void libera_lista(Lista *li){

    if(li != NULL && (*li) != NULL){


        Elem *aux = (*li)->inicio;
        while((*li)->final->prox != (*li)->final){
            (*li)->inicio = (*li)->inicio->prox;
            (*li)->final->prox = (*li)->inicio;
            free(aux);
            aux = (*li)->inicio;
        }
        free(aux);
    }


}