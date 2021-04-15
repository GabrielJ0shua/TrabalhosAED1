#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define MAX 20

struct REAIS{

  float num[MAX];
  int Fim;

};

Reais cria_lista(){

    Reais p;
    p = (Reais)malloc(sizeof(struct REAIS));

    if(p != NULL) p->Fim = 0;

    return p;

}

int lista_vazia(Reais p){

    if(p == NULL || p->Fim > 0) return 0;
    else                        return 1;

}

int lista_cheia(Reais p){

    if(p == NULL || p->Fim != MAX) return 0;
    else                           return 1;

}

int insere_elem(Reais p, float N){

    if(p == NULL || lista_cheia(p) == 1) return 0;

/* SE A LISTA NAO ESTIVER CHEIA, SIMPLESMENTE VAI INSERIR O ELEMENTO NA
    POSICAO FINAL E INCREMENTARÁ 1 EM 'FIM' PARA DIZER QUE FOI ADICIONADO UM ELEMENTO */

    p->num[p->Fim] = N;
    p->Fim++;

    return 1;

}

int remove_elem(Reais p, float N){

    if(p == NULL || lista_vazia(p) == 1) return 0;


// SE O ELEMENTO QUE DESEJA SER REMOVIDO FOR O ULTIMO DA LISTA, SÓ DA UM FIM -1
// PARA DIZER QUE AQUELE ELEMENTO NAO PERTENCE MAIS A LISTA
    else if(p->num[p->Fim-1] == N){p->Fim--; return 1;}

//SE NAO FOR O ULTIMO, ELE PROCURA ATE ACHAR OU NAO O ELEMENTO
    else{
        int i;
        for(i = 0; i < p->Fim-1; i++){
            if(p->num[i] == N) break; //SE ACHOU, ENTAO PAUSA E IREMOS REMOVE-LO ADIANTE
        }

        if(i == p->Fim-1) return 0; //SE NAO ACHOU, RETORNA ZERO

        else{ //REMOVER ELEMENTO ENCONTRADO
            for(i += 1; i < p->Fim; i++){ //COMECO NA POSICAO DO ELEMENTO + 1
                p->num[i-1] = p->num[i];//PEGO ESSE ELEMENTO E COLOCO NA POSICAO ANTERIOR
            }                           //FACO ISSO ATE O FINAL
            p->Fim--;               //E DOU UM FIM - 1 PARA DIZER QUE REMOVI UM ELEMENTO
            return 1;
        }
    }

}

int get_pos(Reais p, int pos, float *elem){

    if(p == NULL || lista_vazia(p) == 1 || p->Fim <= pos || pos < 0) return 0;

    //JA FACO A VERIFICACAO ANTES SE A POSICAO SOLICITADA EH VALIDA
    //SE FOR, SO PEGO O ELEMENTO DAQUELA POSICAO E PASSO POR REFERENCIA
    *elem = p->num[pos];

    return 1;

}

int esvazia_lista(Reais p){

    if(p == NULL) return 0;

    //SIMPLESMENTE COLOCO FIM = 0 PARA DIZER QUE A LISTA ESTA VAZIA
    //O QUE FICOU LA SERA LIXO

    p->Fim = 0;

    return 1;

}

int remove_impares(Reais p){

    if(p == NULL || lista_vazia(p) == 1) return 0;

    int i;
    for(i = 0; i < p->Fim; i++){
        if((int)p->num[i] % 2 != 0){
            remove_elem(p, p->num[i]);
            i--; //COMANDO NECESSARIO, JA QUE IREI REMOVER O ELEMENTO SE FOR IMPAR, E O PROXIMO Q IREI VERIFICAR
        }       //IRA VIR PARA ESSA POSICAO. SEM ESSE COMANDO, EU NAO FARIA A VERIFICACAO DESSE PROXIMO ELEMENTO
    }

    return 1;

}

int maior_elemento(Reais p, float *elem){

    if(p == NULL || lista_vazia(p) == 1) return 0;

    int i;
    *elem = p->num[0]; //COLOCO PARA O PRIMEIRO ELEMENTO SER O MAIOR
    for(i = 1; i < p->Fim; i++){//DPS VOU FAZENDO A VERIFICACAO SE EXISTE OUTRO MAIOR
        if(p->num[i] > *elem) *elem = p->num[i];
    }
    //O MAIOR ELEMENTO EH PASSADO POR REFERENCIA

    return 1;

}

int tamanho_lista(Reais p, float *tam){

    if(p == NULL) return 0;

    *tam = p->Fim;

    return 1;

}

int lista_invertida(Reais p, Reais p2){

    if(p == NULL || p2 == NULL || lista_vazia(p) == 1) return 0;

    int i;
    for(i = p->Fim - 1; i >= 0; i--){//INCREMENTO DE TRAS PARA FRENTE A LISTA P NA LISTA P2
        p2->num[p2->Fim] = p->num[i];
        p2->Fim++;
    }

    return 1;

}

int concatena_listas(Reais p, Reais p2, Reais p3){

    if(p == NULL || p2 == NULL || p3 == NULL) return 0;

    int i;
    for(i = 0; i < p->Fim; i++){//COMECO INSERINDO OS ELEMENTOS DA LISTA P EM P3
        if(p3->Fim == 20) break;
        p3->num[p3->Fim] = p->num[i];
        p3->Fim++;
    }
    for(i = 0; i < p2->Fim; i++){//DEPOIS INSIRO OS ELEMENTOS DA LISTA P2 EM P3
        if(p3->Fim == 20) break;
        p3->num[p3->Fim] = p2->num[i];
        p3->Fim++;
    }

    return 1;

}

void libera(Reais p, Reais p2, Reais p3){

    if(p != NULL){free(p);p = NULL;}
    if(p2 != NULL){free(p2);p2 = NULL;}
    if(p3 != NULL){free(p3);p3 = NULL;}

    //LIBERO AS 3 LISTAS E APONTO PARA NULL

}
