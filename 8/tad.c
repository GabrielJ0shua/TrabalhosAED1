#include "tad.h"
#include <stdlib.h>

struct equacaoCompleta{
    Termo polinomio;
    comple proxNo;
};

comple criaLista(void){
    comple l = (comple) malloc(sizeof(struct equacaoCompleta));
    if (l == NULL) return 0;
    else return l;
}
int inserir(comple l,Termo equacao){
return 1;
}
int pegaValores(comple l,Termo *equacao){
return 1;
}
int removeElemento(comple l,float x){
return 1;
}
void limpaEquacao(comple l){

}
int calculoPolinomio(comple l,float* x){
return 1;
}
void libera(comple l){
    free(l);
}