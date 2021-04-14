#include <stdlib.h>
#include "tad.h"

struct numero{
    int nu;
};
struct caixa{
    struct caixa *no;
    struct numero num;
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

int ord(lista* li, int b){
    if(li == NULL) return 0;
    cad* n = (cad*) malloc(sizeof(cad));
    if(n == NULL) return 0;
    n->num.nu = b;
    if (vazia(li))
    {
        n->no = (*li);
        *li = n;
        return 1;
    }
    else
    {
        cad *ant,*atual = *li;
        while (atual != NULL && atual->num.nu < b)
        {
            ant = atual;
            atual = atual->no;
        }
        if(atual == *li){
            n->no = (*li);
            *li = n;
        }
        else{
            n->no = ant->no;
            ant->no = n;
        }
        return 1;
    }
}

int rem(lista *li,int b){
    if(li == NULL) return 0;
    cad *ant,*n = *li;
    while (n != NULL && n->num.nu != b)
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

int pos(lista *li,int b, int *aux){
    if(li == NULL) return 0;
    cad *n = *li;
    int i = 1;
    while (n != NULL && n->num.nu != b) n = n->no;
    if(n == NULL) return 0;
    else *aux = n->num.nu;
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
 
int imprime(lista *li, int i, int *aux){
    if((li == NULL) || (*li == 0)) return 0;
    int aux1; 
    cad *n = *li;
    for (aux1 = 0; aux1 < i; aux1++){
        if(n == NULL) return 0;
        n = n->no;
    }
    *aux = n->num.nu;
    return 1;
}