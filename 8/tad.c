#include "tad.h"
#include <stdlib.h>

struct elemento
{
    struct elemento * ant;
    struct elemento * prox;
    struct dado d;
};

struct Deque
{
    struct elemento * inicio;
    struct elemento * final;
    int qnt;
};

void liberaDeque(deque* dq){
    if (dq != NULL){
        elem* no;
        while (dq->inicio != NULL)
        {
            no = dq->inicio;
            dq->inicio = dq->inicio->prox;
            free(no);
        }
        free(dq);
    }
}

deque* criaDeque(){
    deque* dq;
    dq = (deque*) malloc(sizeof(deque));

    if(dq != NULL){
        dq->final = NULL;
        dq->inicio = NULL;
        dq->qnt = 0;
    }
    return dq;
}

int deque_tamanho(deque* dq){
    if (dq == NULL) return 0;
    else return dq->qnt;
}

int deque_vazio(deque* dq){
    if (dq == NULL || dq->inicio == NULL) return 1;
    else return 0;
}

int consultaInicio(deque* dq, Dado *aux){
    if (dq == NULL || dq->inicio == NULL) return 1;
    *aux = dq->inicio->d;
    return 1;
}

int consultaFinal(deque* dq, Dado *aux){
    if (dq == NULL || dq->inicio == NULL) return 1;
    *aux = dq->final->d;
    return 1;
}

int insere_inicio(deque* dq, Dado aux){
    if (dq == NULL) return 0;
    elem *no = (elem*) malloc(sizeof(elem));
    if (no == NULL) return 0;
    no->d = aux;
    no->prox = dq->inicio;
    no->ant = NULL;
    if(dq->inicio == NULL) dq->final = no;
    else dq->inicio->ant = no;
    dq->inicio = no;
    dq->qnt++;
    return 1;
}

int insere_final(deque* dq, Dado aux){
    if (dq == NULL) return 0;
    elem *no = (elem*) malloc(sizeof(elem));
    if (no == NULL) return 0;
    no->d = aux;
    no->prox = NULL;
    if(dq->final == NULL){ 
        no->ant = NULL;
        dq->inicio = no;
    }
    else{
        no->ant = dq->final;
        dq->final->prox = no;
    }
    dq->final = no;
    dq->qnt++;
    return 1;
}

int remove_inicio(deque* dq, Dado* aux){
    if (dq == NULL || dq->inicio == NULL) return 0;
    elem*no = dq->inicio;
    *aux = dq->inicio->d;
    dq->inicio = dq->inicio->prox;
    if (dq->inicio == NULL) dq->final = NULL;
    else dq->inicio->ant = NULL;
    free(no);
    dq->qnt--;
    return 1;
} 

int remove_final(deque* dq, Dado* aux){
    if (dq == NULL || dq->inicio == NULL) return 0;
    elem *no = dq->final;
    *aux = dq->final->d;
    if (no == dq->inicio)
    {
        dq->inicio = NULL;
        dq->final = NULL;
    }
    else{
        no->ant->prox = NULL;
        dq->final = no->ant;
    }
    free(no);
    dq->qnt--;
    return 1;
}