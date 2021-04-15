#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define MAX 20

struct CARACTER{

  char elem[MAX];
  int Fim;

};

CHAR cria_lista(){

    CHAR p;
    p = (CHAR)malloc(sizeof(struct CARACTER));

    if(p != NULL) p->Fim = 0;

    return p;

}

int lista_vazia(CHAR p){

    if(p == NULL || p->Fim > 0) return 0;
    else                        return 1;

}

int lista_cheia(CHAR p){

    if(p == NULL || p->Fim != MAX) return 0;
    else                           return 1;

}

int insere_ord(CHAR p, char N){//INSERIR EM ORDEM DECRESCENTE

    if(p == NULL || lista_cheia(p) == 1) return 0;

//SE A LISTA NAO ESTIVER CHEIA, VAI PROCURAR UM LUGAR PARA INSERIR
    if(lista_vazia(p) == 1){//SE NAO TIVER ELEMENTO, INSERE NA PRIMEIRA POSICAO E PRONTO
        p->elem[p->Fim] = N;
        p->Fim++;
        return 1;
    }
    int i, j;
    for(i = 0; i < p->Fim; i++){//SE TIVER ELEMENTOS, PROCURA UM ELEMENTO DA LISTA MENOR
        if(p->elem[i] <= N) break;//PARA PODER INSERIR EM ORDEM DECRESCENTE
    }
    for(j = p->Fim; j > i; j--){//MOVENDO TODOS OS ELEMENTOS, PARA PODER INSERIR O NOVO ELEMENTO
        p->elem[j] = p->elem[j-1];
    }
    p->elem[j] = N;//INSERCAO DO NOVO ELEMENTO
    p->Fim++;//ACRESCENTA MAIS UM EM FIM, PARA DIZER Q O ELEMENTO FOI ACRESCENTADO

    return 1;

}

int remove_elem(CHAR p, char N){

    if(p == NULL || lista_vazia(p) == 1) return 0;


// SE O ELEMENTO QUE DESEJA SER REMOVIDO FOR O ULTIMO DA LISTA, SÓ DA UM FIM -1
// PARA DIZER QUE AQUELE ELEMENTO NAO PERTENCE MAIS A LISTA
    else if(p->elem[p->Fim-1] == N){p->Fim--; return 1;}

//SE NAO FOR O ULTIMO, ELE PROCURA ATE ACHAR OU NAO O ELEMENTO
    else{
        int i;
        for(i = 0; i < p->Fim-1; i++){
            if(p->elem[i] == N) break; //SE ACHOU, ENTAO PAUSA E IREMOS REMOVE-LO ADIANTE
        }

        if(i == p->Fim-1) return 0; //SE NAO ACHOU, RETORNA ZERO

        else{ //REMOVER ELEMENTO ENCONTRADO
            for(i += 1; i < p->Fim; i++){ //COMECO NA POSICAO DO ELEMENTO + 1
                p->elem[i-1] = p->elem[i];//PEGO ESSE ELEMENTO E COLOCO NA POSICAO ANTERIOR
            }                           //FACO ISSO ATE O FINAL
            p->Fim--;               //E DOU UM FIM - 1 PARA DIZER QUE REMOVI UM ELEMENTO
            return 1;
        }
    }

}

int get_pos(CHAR p, int pos, char *elemento){

    if(p == NULL || lista_vazia(p) == 1 || pos >= p->Fim) return 0;

    //JA FACO A VERIFICACAO ANTES SE A POSICAO SOLICITADA EH VALIDA
    //SE FOR, SO PEGO O ELEMENTO DAQUELA POSICAO E PASSO POR REFERENCIA
    *elemento = p->elem[pos];

    return 1;

}

int esvazia_lista(CHAR p){

    if(p == NULL) return 0;

    //SIMPLESMENTE COLOCO FIM = 0 PARA DIZER QUE A LISTA ESTA VAZIA
    //O QUE FICOU LA SERA LIXO

    p->Fim = 0;

    return 1;

}

int remove_pares(CHAR p){

    if(p == NULL || lista_vazia(p) == 1) return 0;

    int i, j;
    for(i = 0; i < p->Fim; i++){
        if(p->elem[i] % 2 == 0){
            for(j = i+1; j < p->Fim; j++){
                p->elem[j-1] = p->elem[j];
            }
            p->Fim--;
            i--;
        }
    }

    return 1;

}

int menor_elemento(CHAR p, char *elemento){

    if(p == NULL || lista_vazia(p) == 1) return 0;

    int i;
    *elemento = p->elem[0]; //COLOCO PARA O PRIMEIRO ELEMENTO SER O MENOR
    for(i = 1; i < p->Fim; i++){//DPS VOU FAZENDO A VERIFICACAO SE EXISTE OUTRO MENOR
        if(p->elem[i] < *elemento) *elemento = p->elem[i];
    }
    //O MENOR ELEMENTO EH PASSADO POR REFERENCIA

    return 1;

}

int tamanho_lista(CHAR p, int *tam){

    if(p == NULL) return 0;

    *tam = p->Fim;

    return 1;

}

int intercala_listas(CHAR p, CHAR p2, CHAR p3){

    if(p == NULL || p2 == NULL || p3 == NULL) return 0;

    int i = 0;//contador
    while(1){
        if(p3->Fim == 20) break;
        if(p->Fim > i && p2->Fim > i){
            insere_ord(p3, p->elem[i]);
            insere_ord(p3, p2->elem[i]);
        }
        else if(p->Fim > i && p2->Fim <= i) insere_ord(p3, p->elem[i]);
        else if(p->Fim <= i && p2->Fim > i) insere_ord(p3, p2->elem[i]);
        else break;

        i++;
    }

    return 1;

}

void libera(CHAR p, CHAR p2, CHAR p3){

    if(p != NULL){free(p);p = NULL;}
    if(p2 != NULL){free(p2);p2 = NULL;}
    if(p3 != NULL){free(p3);p3 = NULL;}

    //LIBERO AS 3 LISTAS E APONTO PARA NULL

}
