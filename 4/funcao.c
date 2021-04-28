#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

typedef struct no{
    double info;
    struct no *prox;

}Elem;

struct cabecalho{//CRIEI OUTRA STRUCT PARA O CABECALHO, PARA CONSEGUIR GUARDAR MAIS INFORMACOES
    struct no *inicio;
    int tamanho;
    double maior;
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

    if(li->inicio == NULL) return 1; //vai verificar se é vazio

    return 0;

}

int insere_elem_ord(Lista *li, double elem){//INSERE EM ORDEM CRESCENTE

    if(li == NULL) return 0;

    Elem* N = (Elem*) malloc(sizeof(Elem)); //aloca dinamicamente
    if(N == NULL) return 0;

    N->info = elem;
    if(lista_vazia(*li) == 1){ //se for vazia insere o primeiro elemento
        N->prox = (*li)->inicio; //o ponteiro que aponta pro prox elemento vai receber o ponteiro apontando pro começo
        (*li)->inicio = N;
        (*li)->tamanho++; //incrementa no tamanho
        (*li)->maior = elem; //o ponteiro da lista que aponta pro maior elemento vai receber o elemento digitado

        return 1;
    }
    if((*li)->inicio->info > elem){ //se tiver só um elemento na lista
        N->prox = (*li)->inicio;
        (*li)->inicio = N;
        (*li)->tamanho++;

        return 1;
    }
    Elem* aux = (*li)->inicio;
    while(aux->prox != NULL && aux->prox->info < elem) aux = aux->prox; //mais de um elemento na lista
       N->prox = aux->prox;
       aux->prox = N;

       (*li)->tamanho++;
        if((*li)->maior < elem) (*li)->maior = elem;

       return 1;

}

int remove_elem(Lista *li, double elem){

    if(li == NULL || lista_vazia(*li) == 1) return 0;

    Elem *ant, *atual = (*li)->inicio;
    while(atual->prox != NULL && atual->info != elem){
        ant = atual;
        atual = atual->prox;
    }
    if(atual->info != elem) return 0;

    if(atual->info == (*li)->maior){
        ant->prox = atual->prox;
        (*li)->maior = ant->info;
        return 1;
    }

    if(atual == (*li)->inicio) (*li)->inicio = (*li)->inicio->prox;

    else ant->prox = atual->prox;

    free(atual);
    (*li)->tamanho--;

    return 1;

}

int maior_elemento(Lista *li, double *elem){

    if(li == NULL || (*li)->inicio == NULL) return 0;

    *elem = (*li)->maior;
    return 1;

}

int tamanho_lista(Lista *li, int *tam){

    if(li == NULL) return 0;

    *tam = (*li)->tamanho;

    return 1;

}

int intercala_listas(Lista *L1, Lista *L2, Lista *L3){

    if(L1 == NULL || L2 == NULL || L3 == NULL) return 0;

    /* SITUACOES:
        01- L1 e L2 SEREM VAZIAS
        02- L1 > L2
        03- L2 > L1
        04- L1 == L2
    */
    if(lista_vazia(*L1) == 1 && lista_vazia(*L2) == 1) return 1;//SITUACAO 1

    int tam_L1, tam_L2;
    tamanho_lista(L1, &tam_L1);
    tamanho_lista(L2, &tam_L2);

    int i = 1;
    double num;
    if(tam_L1 > tam_L2){//SITUACAO 2
        while(i <= tam_L2){
            get_pos(L1, i, &num);
            insere_elem_ord(L3, num);
            get_pos(L2, i, &num);
            insere_elem_ord(L3, num);
            i++;
        }
        while(i <= tam_L1){
            get_pos(L1, i, &num);
            insere_elem_ord(L3, num);
            i++;
        }
    }

    else if(tam_L1 < tam_L2){//SITUACAO 3
        while(i <= tam_L1){
            get_pos(L1, i, &num);
            insere_elem_ord(L3, num);
            get_pos(L2, i, &num);
            insere_elem_ord(L3, num);
            i++;
        }
        while(i <= tam_L2){
            get_pos(L2, i, &num);
            insere_elem_ord(L3, num);
            i++;
        }
    }

    else{//SITUACAO 4
        while(i <= tam_L1){
            get_pos(L1, i, &num);
            insere_elem_ord(L3, num);
            get_pos(L2, i, &num);
            insere_elem_ord(L3, num);
            i++;
        }
    }

    return 1;
}

int get_pos(Lista *li, int pos, double *numero){

    if(lista_vazia(*li) == 1 || pos < 1 || pos > (*li)->tamanho) return 0;

    Elem* aux = (*li)->inicio;
    if(pos == 1){
        *numero = (*li)->inicio->info;
        return 1;
    }
    int i = 2; //contador
    while(aux->prox != NULL && i < pos){
        aux = aux->prox;
        i++;
    }

    *numero = aux->prox->info;

    return 1;

}

void esvaziar_lista(Lista li){
    if(li != NULL){
        Elem *no;
        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
    }

}

void libera_lista(Lista li){
    if(li != NULL){
        Elem *no;
        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int listas_iguais(Lista *L1, Lista *L2){
    if(L1 == NULL || L2 == NULL)
        return 0;

    int tam1,tam2;
    tamanho_lista(L1, &tam1);
    tamanho_lista(L2, &tam2);

    if(tam1 != tam2)
        return 0;

    int cont = 1;

    double aux1, aux2;

    while(1){
        if(get_pos(L1, cont, &aux1) == 0) return 1;

        get_pos(L2, cont, &aux2);
        if(aux1 != aux2) return 0;

        cont++;
    }
}
