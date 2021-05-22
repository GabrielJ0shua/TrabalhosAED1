#include "tad.h"
#include <stdlib.h>

struct Deque
{
    struct elemento ele[MAX];
    int qnt, ini, fim;
};

void liberaDeque(deque* dq){
    free(dq);
}

deque* criaDeque(){
    deque* dq;
    dq = (deque*) malloc(sizeof(deque));
    if(dq != NULL){
        dq->fim = 0;
        dq->ini = 0;
        dq->qnt = 0;
    }
    return dq;
}

int consultaInicio(deque* dq, elem *aux){
    if(dq == NULL || dq->qnt == 0) return 0;
    *aux = dq->ele[dq->ini];
    return 1;
}

int consultaFinal(deque* dq, elem *aux){
    if(dq == NULL || dq->qnt == 0) return 0;
    int pos = dq->fim -1;
    if(pos < 0) pos = MAX -1;
    *aux = dq->ele[pos];
    return 1;
}

int deque_vazio(deque* dq){
    if(dq == NULL || dq->qnt == 0) return 1;
    else return 0;
}

int deque_cheio(deque* dq){
    if(dq == NULL || dq->qnt == 0) return 0;
    else if(dq->qnt == MAX-1) return 1;
    else return 0;
}

int insere_inicio(deque* dq, elem aux){
    if(dq == NULL || dq->qnt == MAX) return 0;
    dq->ini--;
    if(dq->ini < 0) dq->ini == (MAX-1);
    dq->ele[dq->ini] = aux;
    dq->qnt++;
    return 1;
}

int insere_final(deque* dq, elem aux){
    if(dq == NULL || dq->qnt == MAX) return 0;
    dq->ele[dq->fim-1] = aux;
    dq->fim = (dq->fim+1)%MAX;
    dq->qnt++;
    return 1;
}

int remove_inicio(deque* dq, elem* aux){
    if(dq == NULL || dq->qnt == 0) return 0;
    consultaInicio(dq,aux);
    dq->ini = (dq->ini+1)%MAX;
    dq->qnt--;
    return 1;
} 

int remove_final(deque* dq, elem* aux){
    if(dq == NULL || dq->qnt == 0) return 0;
    consultaFinal(dq, aux);
    dq->fim--;
    if(dq->fim < 0) dq->fim = MAX-1;
    dq->qnt--;
    return 1;
}