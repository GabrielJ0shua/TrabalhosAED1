#include "tad.h"
#include <stdlib.h>
// lista duplamente encadeada por conta do deslocamento de elementos e inserção. 
struct equacaoCompleta{
    Termo polinomio;
    Funcao proxNo;
    Funcao antNo;
};
 
Funcao* criaLista(void){
    //lembre q é ponteiro de ponteiro, isso só aloca um espaço para essa lista **l.
    Funcao *l = (Funcao*) malloc(sizeof(Funcao));
    if (l != NULL) *l = NULL;
    return l;
}

int tamanhoDalista(Funcao *l){
    if (l == NULL) return 0; //se a lista for vazia o tamanho dela é 0.
    int cont = 0;
    Funcao aux = *l;
    while (aux != NULL){
        cont++;
        aux = aux->proxNo;
    }  
    return cont;
}

int listaVazia(Funcao* l){
    //retornando 1 se a lista tiver vazia
    if ((l == NULL)||(*l == NULL)) return 1;
    return 0;
}

int inserirOrdenado(Funcao *l,Termo equacao){
    if(l == NULL) return 0;
    Funcao aux = (Funcao) malloc(sizeof(struct equacaoCompleta));
    if (aux ==NULL) return 0;
    aux->polinomio = equacao;
    if (listaVazia(l)){
        aux->proxNo = NULL;
        aux->antNo = NULL;
        *l = aux;
        return 1;
    }
    else{
        Funcao ante, atual = *l;
        while (atual != NULL && atual->polinomio.Xn <= equacao.Xn ){
            ante = atual;
            atual = atual->proxNo;
        }
        // fazer uma condição de se for == somar !!!
        if (atual == *l)
        {
            aux->antNo = NULL;
            (*l)->antNo = aux;
            aux->proxNo = (*l);
            *l = aux;
        }
        else{
            aux->proxNo = ante->proxNo;
            aux->antNo = ante;
            ante->proxNo = aux;
            if(atual != NULL) atual->antNo = aux;
        }
        return 1;
    }
}

int pegaValores(Funcao *l,Termo *equacao, int pos){
    if (l == NULL) return 0;
    Funcao aux = *l;
    int j = 1;
    while(j < pos && aux != NULL){
        aux = aux->proxNo;
        j++;
    }
    if (aux == NULL) return 0;
    else{
        *equacao = aux->polinomio;
        return 1;
    }
}

int removeElemento(Funcao *l,int x){
    if (l == NULL) return 0;
    Funcao aux = *l;
    while (aux != NULL && aux->polinomio.Xn != x) aux = aux->proxNo;

    if (aux == NULL) return 0;
    if(aux->antNo == NULL) *l = aux->proxNo;
    else aux->antNo->proxNo = aux->proxNo;
    if(aux->proxNo != NULL) aux->proxNo->antNo = aux->antNo;
    free(aux);
    return 1;
}

void limpaEquacao(Funcao *l){
    if(*l != NULL){
        Funcao aux;
        while (*l != NULL){
            aux = *l;
            *l = (*l)->proxNo;
            free(aux);
        }
    }
}

void libera(Funcao *l){
    //vai verificar se a lista não está vazia para passar de nó em nó e liberar 1 a 1 e por fim liberar a lista por completo
    if(*l != NULL){
        Funcao aux;
        while (*l != NULL){
            aux = *l;
            *l = (*l)->proxNo;
            free(aux);
        }
        free(l);
    }
} 