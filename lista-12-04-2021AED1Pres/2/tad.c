#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

struct caixa
{
    struct caixa *no;
    struct pass p;
};

lista *cria(void){
    lista *li;
    li = (lista*) malloc(sizeof(lista));
    if(li!=NULL) *li = NULL;
    return li;
}

int tamanho(lista *li){
    if (li == NULL) return 0;
    int cont = 0;
    cad* no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->no;
    }
    return cont;
}

int cheia(lista* li){ return 0;}

int vazia(lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    return 1;
}
 
int insere(lista *li, Pass *aux){
    if(li == NULL) return 0;
    cad *n = (cad*) malloc(sizeof(cad));
    if(n == NULL) return 0;
    n->p = *aux;
    if((*li) == NULL) *li = n;
    else
    {
        cad *aux = *li;
        while (aux->no != NULL) aux = aux->no;
        aux->no = n; 
    }
    return 1;
}

int rem(lista *li,unsigned int b){
    if(li == NULL) return 0;
    cad *ant,*n = *li;
    while (n != NULL && n->p.mat != b)
    {
        ant = n;
        n = n->no;
    }
    if(n == NULL) return 0;
    if(n == *li) *li = n->no;
    else ant->no = n->no;
    free(n);
    return 1;
}

int pos(lista *li,unsigned int b, Pass *aux){
    if(li == NULL) return 0;
    cad *n = *li;
    int i = 1;
    while (n != NULL && n->p.mat != b) n = n->no;
    if(n == NULL) return 0;
    else *aux = n->p;
    return 1;
}

void libera (lista *li){
    if(li != NULL){
        cad* no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->no;
            free(no);
        }
        free(li);   
    }
}

int imprime(lista *li, int i, Pass *aux){
    if((li == NULL) || (*li == 0)) return 0;
    int aux1; 
    cad *n = *li;
    for (aux1 = 0; aux1 < i; aux1++){
        if(n == NULL) return 0;
        n = n->no;
    }
    *aux = n->p;
    return 1;
}