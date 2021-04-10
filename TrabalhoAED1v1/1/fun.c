#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct numero{
    int qnt;
    int num[MAX];
};


lista *cria(){
    lista *li;
    li = (lista*) malloc(sizeof(lista));
    if(li != NULL) li->qnt = 0;
    return li;
}

void libera(lista *li){
    free(li);
    li = cria();
}

int tamanho(lista *li){
    if(li == NULL || vazia(li) == 1)
        return 0;
    else return li->qnt;
}

int vazia(lista *li){
    if(li == NULL || li->qnt == 0)
        return 1;
    return 0;
}

int insercao(lista *li, int numero){
    if (li == NULL || li->qnt >= MAX)
        return 0;
    li->num[li->qnt] = numero;
    li->qnt++;
    return 1;
}

int remove_qualquer(lista *li, int numero){
    if (li == NULL || vazia(li) == 1) 
        return 0;

    int k,i = 0;
    while (i<li->qnt && li->num[i] != numero)
        i++;

    if (i == li->qnt)
        return 0;

    for (k = i; k < li->qnt-1; k++)
        li->num[k] = li->num[k+1];

    li->qnt--;
    return 1;
}

int remove_impar(lista *li){
    if (li == NULL || vazia(li) == 1)
        return 0;

    int i = 0;
    while(i < li->qnt){
        if(li->num[i]%2 != 0)
            remove_qualquer(li, li->num[i]);

        else i++;
    }

    return 1;
}

int consulta_qualquer (lista *li, int pos, int *numero){
    if (li == NULL || vazia(li) == 1 || pos > li->qnt)
        return 0;

    *numero = li->num[pos-1];
    return 1;
}

int consulta_menor(lista *li, int *menor){
    if (li == NULL || vazia(li) == 1)
        return 0;
    
    int i = 0; *menor = li->num[i];
    while (i < li->qnt){
        if (*menor > li->num[i])
            *menor = li->num[i];

        i++;
    }
    
    return 1;
}

int inverter_lista(lista *li, lista *aux){
    if (li == NULL || vazia(li) == 1 || aux == NULL)
        return 0;

    int i;
    for (i = ((li->qnt)-1); i >= 0; i--)
        insercao(aux, li->num[i]);
    return 1;
}

int concatenar(lista *li, lista *li2, lista *li3){
    if (li == NULL || li2 == NULL || vazia(li) == 1 || vazia(li2) == 1)
        return 0;

    if(li->qnt + li2->qnt > MAX)
        return 2;

    int i;
    for (i = 0; i < (li->qnt); i++) insercao(li3, li->num[i]);
    for (i = 0; i < (li2->qnt); i++) insercao(li3, li2->num[i]);
    return 1;
}