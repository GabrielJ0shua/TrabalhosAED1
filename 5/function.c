#include <stdio.h>
#include <stdlib.h>
#include "function.h"

struct no{

    char info;
    struct no *prox;

};

Lista cria_lista(){

    return NULL;

}

int lista_vazia(Lista li){

    if(li == NULL) return 1;
    else           return 0;

}

int insere_elem(Lista *li, char elem){//INSERE NO INICIO

    if(li == NULL) return 0;
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL) return 0;
    N->info = elem;
    if(lista_vazia(*li) == 1){//SE FOR VAZIA, INSIRO O ELEMENTO E FACO SEU N PROX APONTAR PARA ELE MESMO
        *li = N;
        N->prox = N;
    }
    else{//SE NAO FOR VAZIA, PERCORRO A LISTA ATE CHEGAR NO FINAL (NO QUE SEU PROX EH O INICIO)
        Lista aux = *li;
        while(aux->prox != (*li)) aux = aux->prox;

        aux->prox = N;//ULTIMO ELEMENTO APONTA PARA MEU NOVO ELEMENTO
        N->prox = (*li);//MEU NOVO ELEMENTO APONTA PARA O INICIO (PASSA SER O ULTIMO AGORA)
        *li = N;
    }

    return 1;

}

int insere_pos(Lista *li, int pos, char elem){

    int tam;
    tamanho_lista(li, &tam);

    if(li == NULL || pos < 1 || pos >= tam + 2) return 0;

    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL) return 0;

    N->info = elem;
    if(pos == 1 && lista_vazia(*li) == 1){
        *li = N;
        N->prox = N;

        return 1;
    }

    Lista aux = *li;
    if(pos == 1 && lista_vazia(*li) == 0){
        while(aux->prox != (*li)) aux = aux->prox;

        aux->prox = N;
        N->prox = (*li);
        (*li) = N;

        return 1;
    }
    else if(pos == tam + 1){
        while(aux->prox != *li) aux = aux->prox;

        N->prox = aux->prox;
        aux->prox = N;

        return 1;
    }
    int posicao = 1;
    while(posicao != pos - 1){
        aux = aux->prox;
        posicao++;
    }
    N->prox = aux->prox;
    aux->prox = N;

    return 1;

}

int remove_pos(Lista *li, int pos, char *valor){

    if(li == NULL || pos < 1 || lista_vazia(*li) == 1) return 0;

    Lista aux = *li;

    if(pos == 1 && (*li)->prox == NULL){//LISTA COM UM ELEMENTO SO
        
        *valor = (*li)->info;
        *li = aux->prox;//LI APONTA PARA NULL
        
        free(aux);

        return 1;
    }

    if(pos == 1 && (*li)->prox != NULL){//LISTA COM MAIS DE UM ELEMENTO E REMOVER O PRIMEIRO
        
        *valor = (*li)->info;
        while(aux->prox != *li) aux = aux->prox;
        
        Lista aux2 = *li;

        (*li) = aux2->prox;
        aux->prox = *li;
        free(aux2);

        return 1;

    }

    int cont = 1;
    Lista ant;
    while(aux->prox != (*li) && cont < pos){
        ant = aux;
        aux = aux->prox;
        cont++;
    }

    if(cont == pos){
        *valor = aux->info;
        ant->prox = aux->prox;
        free(aux);
    
        return 1;
    }


    return 0;

}

int remove_fim(Lista *li, char *elem){

    if(li == NULL || lista_vazia(*li)) return 0;

    if((*li)->prox == *li){
        *elem = (*li)->info;
        free(*li);
        *li = NULL;
        return 1;
    }

    Lista aux = *li, ant;
    while(aux->prox != *li){
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = aux->prox;
    free(aux);

    return 1;
}

int obtem_valor(Lista *li, int pos, char *valor){

    if(li == NULL || lista_vazia(*li) == 1 || pos <= 0) return 0;

    Lista aux = *li;
    int cont = 1;
    while(aux->prox != *li && cont < pos){
        aux = aux->prox;
        cont++;
    }
    if(cont < pos) return 0;

    *valor = aux->info;

    return 1;

}

int tamanho_lista(Lista *li, int *tam){

    if(li == NULL) return 0;

    int aux = 0;
    if(lista_vazia(*li) == 1){
        *tam = aux;
        return 1;
    }
    Lista N = *li;
    while(N->prox != *li){
        N = N->prox;
        aux++;
    }
    *tam = aux + 1;

    return 1;


}

void libera_lista(Lista *li){

    if(li != NULL){
        Lista aux = *li, aux2;
        while((*li) != aux->prox){
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);
    }
}

