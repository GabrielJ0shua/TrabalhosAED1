#include "tad.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Lista circular por conta do deslocamento e inserção de elementos 
struct soldado{
    dado dados_soldado; 
    struct soldado *proxNo;
};

Batalhao* iniciaLista(void){
    Batalhao * l = (Batalhao*) malloc(sizeof(Batalhao));
    if(l != NULL) *l = NULL;
    return l;
}

void liberaLista(Batalhao* l){
    if (l != NULL && (*l) != NULL)
    {
        Batalhao aux, no = *l;
        while ((*l) != no->proxNo)
        {
            aux = no;
            no = no->proxNo;
            free(aux);
        }
        free(no);
        //free(aux);
    }
}

int insereFinal(Batalhao* l, dado valor){
    if (l == NULL) return 0;
    Batalhao aux = (Batalhao) malloc(sizeof(struct soldado));
    if (aux == NULL) return 0;
    aux->dados_soldado = valor;
    if((*l) == NULL){
        *l = aux;
        aux->proxNo = aux;
    }
    else{
        Batalhao aux2 = *l;
        while (aux2->proxNo != (*l)) aux2 = aux2->proxNo;
        aux2->proxNo = aux;
        aux->proxNo = *l;
    }
    return 1;
}
 
int removeElemento(Batalhao *l, dado soldado_sai){
    if (l == NULL || (*l) == NULL) return 0;
    Batalhao no = *l;
    if(strcmp(no->dados_soldado.nome_do_soldado,soldado_sai.nome_do_soldado) == 0){
        free(*l);
        *l = NULL;
        return 1;
    }
    else{
    Batalhao ante = no;
    no = no->proxNo;
    while (no != (*l) && strcmp(no->dados_soldado.nome_do_soldado,soldado_sai.nome_do_soldado) != 0)
    {
        ante = no;
        no = no->proxNo;
    }
    if(no == *l) return 0;
    ante->proxNo = no->proxNo;
    free(no);
    return 1;
    }
}

int listaVazia(Batalhao* l){
    if (l == NULL || (*l) == NULL) return 1;// realmente tá vazia
    else return 0;// não tá vazia...
}

int consultaPosicao(Batalhao* l, int pos, dado *dado){
    if ((l == NULL)||((*l) == NULL)) return 0;
    Batalhao aux = *l;
    int i = 0;
    while (aux->proxNo != (*l) && i < pos){
        aux = aux->proxNo;
        i++;
    }
    if(i != pos) return 0;
    else{
        *dado = aux->dados_soldado;
        return 1;
    }
}

int tamanhoLista(Batalhao* l){
    if (l == NULL || (*l) == NULL) return 0;
    int cont = 1;
    Batalhao aux = *l;
    do{ 
        aux = aux->proxNo;
        cont++;
    } while (aux != (*l));
    return cont;
}

int problemaDeJosephus(Batalhao* l,dado* soldado, int* qnt_percorrimento,int* escolha, int trigger){
    if ((l == NULL) || ((*l) == NULL) || (qnt_percorrimento <= 0)) return 0;
    Batalhao aux = *l;
    int i,j;
    
    if(*escolha == 1){
        for ( i = 1; i < (*qnt_percorrimento); i++) aux = aux->proxNo;

        *soldado = aux->dados_soldado;
        removeElemento(l,*soldado);
        return 1;
    }
    else if(*escolha == 2){
        srand(time(NULL));
        j = (rand() % (tamanhoLista(l))) + 1; // o +1 me garante que não vai ser 0
        i = 0;
        while (i < j){
        aux = aux->proxNo;
        i++;
        } // vai na pocisão sorteada

        for ( i = 0; i < (*qnt_percorrimento); i++) aux = aux->proxNo;// percorre do modo que o usuario pediu

        *soldado = aux->dados_soldado;
        *escolha = j;
        removeElemento(l,*soldado);
        return 1;
    }
    else if(*escolha == 3){
       
        if (trigger == 1){
            while ((strcmp(soldado->nome_do_soldado,aux->dados_soldado.nome_do_soldado) != 0) && (aux->proxNo != (*l))) aux = aux->proxNo;
            if(strcmp(soldado->nome_do_soldado,aux->dados_soldado.nome_do_soldado) != 0) return 0;
        }

        for ( i = 1; i < (*qnt_percorrimento); i++) aux = aux->proxNo;

        *soldado = aux->dados_soldado;
        removeElemento(l,*soldado);
        return 1;       
    }
    else return 0;
}