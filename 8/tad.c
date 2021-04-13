#include "tad.h"
#include <stdlib.h>
// lista duplamente encadeada por conta do percorrimento. 
struct equacaoCompleta{
    Termo polinomio;
    Funcao proxNo;
    Funcao antNo;
};

Funcao* criaLista(void){
    Funcao *l = (Funcao*) malloc(sizeof(Funcao));
    if (l != NULL) *l = NULL;
    return l;
}

//usuario não precisa dessa função
int listaVazia(Funcao l){
    return 1;
}
//usuario não precisa dessa função
int tamanhoDalista(Funcao l){
    return 1;
}

int inserir(Funcao l,Termo equacao){
    return 1;    
}

int pegaValores(Funcao l,Termo *equacao){
return 1;
}

int removeElemento(Funcao l,float x){
return 1;
}

void limpaEquacao(Funcao l){
    if(l != NULL){
        Funcao aux;
        while (l != NULL){
            aux = l;
            l = l->proxNo;
            free(aux);
        }
    }
}

int calculoPolinomio(Funcao l,float* x){
return 1;
}

void libera(Funcao *l){
    if(*l != NULL){
        Funcao aux;
        while (*l != NULL){
            aux = *l;
            *l = *l;
            free(aux);
        }
        free(l);
    }
}