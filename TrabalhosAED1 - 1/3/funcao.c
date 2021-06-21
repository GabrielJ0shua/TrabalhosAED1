#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct no{

    int info;
    struct no *prox;

};

Lista cria_lista(){

    return NULL;

}

int lista_vazia(Lista li){

    if(li == NULL) return 1;

    return 0;

}

int lista_cheia(Lista li){

    return 0;

}

int insere_elemento(Lista *li, int elemento){//INSERE EM ORDEM CRESCENTE

    if(li == NULL) return 0;

    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL) return 0;

    N->info = elemento;
    if(lista_vazia(*li) == 1){//LISTA VAZIA E INSERE NA PRIMEIRA POSICAO
        N->prox = *li;
        (*li) = N;

        return 1;
    }

    if((*li)->info >= elemento){//LISTA NAO VAZIA E INSERE NA PRIMEIRA POSICAO
        N->prox = *li;
        *li = N;

        return 1;
    }

    Lista aux = *li;
    while(aux->prox != NULL && aux->prox->info <= elemento){
        aux = aux->prox;
    }

    if(aux->prox == NULL){//INSERE NA ULTIMA POSICAO
        N->prox = aux->prox;
        aux->prox = N;

        return 1;
    }

    //INSERE NO MEIO DA LISTA
    N->prox = aux->prox;
    aux->prox = N;

    return 1;
}

int remove_elemento(Lista *li, int elemento){

    if(li == NULL || lista_vazia(*li) == 1) return 0;

    Lista aux = *li, ant;
    if((*li)->info == elemento){//REMOVENDO PRIMEIRO ELEMENTO
        *li = (*li)->prox;
        free(aux);

        return 1;
    }

    while(aux->prox != NULL && aux->info != elemento){//NAO VERIFICA A ULTIMA POS
        ant = aux;
        aux = aux->prox;
    }

    if(aux->prox != NULL){//ENCONTREI O ELEMENTO E ESTOU NO MEIO DA LISTA
       ant->prox = aux->prox;
       free(aux);

       return 1;
    }

    if(aux->prox == NULL && aux->info != elemento) return 0;//CHEGUEI NO FINAL DA LISTA E MEU ELEMENTO NAO ESTA ALI

    //REMOVER ULTIMO ELEMENTO DA LISTA
    ant->prox = aux->prox;
    free(aux);

    return 1;

}

int tamanho_lista(Lista *li, int *tam){

    if(li == NULL) return 0;

    int contador = 0;
    if(lista_vazia(*li) == 1){
        *tam = contador;

        return 1;
    }
    Lista aux = *li;
    while(aux->prox != NULL){
        contador++;
        aux = aux->prox;
    }

    *tam = contador + 1;

    return 1;

}

int maior_elemento(Lista *li, int *maior){

    if(li == NULL || lista_vazia(*li) == 1) return 0;

    *maior = (*li)->info;
    if((*li)->prox == NULL){//LISTA TER UM ELEMENTO SO
        return 1;
    }
    Lista aux = *li;
    while(aux->prox != NULL){//NAO VERIFICA A ULTIMA POSICAO
        if(aux->info > (*maior)) *maior = aux->info;
        aux = aux->prox;
    }

    if(aux->info > (*maior)) *maior = aux->info;//VERIFICANDO A ULTIMA POSICAO

    return 1;

}

int esvazia_lista(Lista *li){

    if(li == NULL) return 0;

    Lista aux = *li;

    while(*li != NULL){
        (*li) = (*li)->prox;
        free(aux);
        aux = *li;
    }
    free(aux);

    return 1;

}

int intercala_lista(Lista *L1, Lista *L2, Lista *L3){

    if(L1 == NULL || L2 == NULL || L3 == NULL) return 0;

    /*
    4 SITUACOES
    1) AS DUAS VAZIAS
    2) TAM L1 > TAM L2
    3) TAM L1 < TAM L2
    4) TAM L1 = TAM L2
    */

    int tamL1, tamL2;
    tamanho_lista(L1, &tamL1);
    tamanho_lista(L2, &tamL2);

    if(tamL1 == 0 && tamL2 == 0) return 1;

    int cont = 1, elemento;
    if(tamL1 > tamL2){
        while(cont <= tamL2){
            get_pos(L1, cont, &elemento);
            insere_elemento(L3, elemento);
            get_pos(L2, cont, &elemento);
            insere_elemento(L3, elemento);
            cont++;
        }
        while(cont <= tamL1){
            get_pos(L1, cont, &elemento);
            insere_elemento(L3, elemento);
            cont++;
        }
    }
    if(tamL1 < tamL2){
        while(cont <= tamL1){
            get_pos(L1, cont, &elemento);
            insere_elemento(L3, elemento);
            get_pos(L2, cont, &elemento);
            insere_elemento(L3, elemento);
            cont++;
        }
        while(cont <= tamL2){
            get_pos(L2, cont, &elemento);
            insere_elemento(L3, elemento);
            cont++;
        }
    }
    if(tamL1 == tamL2){
        while(cont <= tamL1){
            get_pos(L1, cont, &elemento);
            insere_elemento(L3, elemento);
            get_pos(L2, cont, &elemento);
            insere_elemento(L3, elemento);
            cont++;
            }
        }
        return 1;
    }

int get_pos(Lista *li, int pos, int *elemento){

    if(li == NULL || pos < 1 || lista_vazia(*li) == 1) return 0;

    if(pos == 1){
        *elemento = (*li)->info;

        return 1;
    }
    int cont = 1;
    Lista aux = *li;
    while(aux->prox != NULL && cont < pos){//NAO CONFERE A ULTIMA POSICAO
        aux = aux->prox;
        cont++;
    }

    if(aux->prox == NULL && cont == pos){//SE MINHA ULTIMA POSICAO FOR A DESEJADA
        *elemento = aux->info;

        return 1;
    }

    if(aux->prox == NULL && cont != pos) return 0; //SE MINHA ULTIMA POSICAO NAO FOR A DESEJADA

    //SE NAO ENTRAR EM NENHUM IF, QUER DIZER QUE ESTOU PEGANDO
    //ALGUM ELEMENTO DO MEIO DA LISTA
    *elemento = aux->info;

    return 1;

}

int listas_iguais(Lista *L1, Lista *L2){
    if(L1 == NULL || L2 == NULL) return 0;

    int tamL1, tamL2;
    tamanho_lista(L1, &tamL1);
    tamanho_lista(L2, &tamL2);

    if(tamL1 != tamL2) return 0;

    int cont = 1, flag = 0;
    int elem1, elem2;

    while(cont <= tamL1 && flag != 1){
        get_pos(L1, cont, &elem1);
        get_pos(L2, cont, &elem2);
        cont++;
    if(elem1 != elem2)  flag = 1;
    }

    if(flag == 0) return 1;

    return 0;

}

void libera_lista(Lista *li){

    if(li != NULL){

        Lista aux = *li;

        while(*li != NULL){
            (*li) = (*li)->prox;
            free(aux);
            aux = *li;
        }
        free(aux);
        free(li);
    }

}
