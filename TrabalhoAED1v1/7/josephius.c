#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "josephius.h"

// Lista circular é a melhor forma de fazer isso por que toda vez que acontecer uma remoção
// eu avanço o header (ponteiro) de inicio, para poder continuar removendo a partir do prox
// soldado em volta da fogueira. Assim, continuando a contagem eu posso acabar voltando pro
// antigo começo da lista. Se não fosse circular e eu movesse o header para continuar con-
// tando do próximo, e o numero sorteado excedesse a quantidade de soldados antes do fim
// da lista (que nao mudaria ja que nao é circular), eu chegaria no NULL e não teria como
// continuar percorrendo para continuar as remoções. A não ser, é claro, que eu guardasse
// o inicio da lista num ponteiro auxiliar e fizesse verificações pra ver se eu cheguei no NULL
// reassociando o header ao antigo inicio e aí sim continuando a contagem.
// A lista circular previne essas complicações.

struct node{
    char soldierName[20];
    struct node *next;
};

list initializeList(){
    return NULL;
}

int emptyList(list *header){
    if(*header == NULL)
        return 1;
    return 0;
}

int insertSoldier(list *header, char name[]){
    list newNode = (list) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;

    strcpy(newNode->soldierName, name);
   
    if(emptyList(header) == 1){
        *header = newNode;
        (*header)->next = newNode;
    }
    else{
        newNode->next = (*header)->next;
        (*header)->next = newNode;
        *header = newNode;
    }
    return 1;
}

int qtdSoldiers(list *header){
    if(emptyList(header) == 1)
        return 0;
    int size = 1;
    list aux = (*header)->next;
    while(aux != *header){
        aux = aux->next;
        size++;
    }
    return size;
}

int startByFirst(list *header, int counter, char soldier[]){
    if(emptyList(header) == 1)
        return 0;

    int size = qtdSoldiers(header);

    if(size > 1){
        if(counter > size){
            counter = counter%size;
        }

        list aux = (*header)->next, aux2;
        if(counter == 1){
            (*header)->next = aux->next;
        }

        else{
            while(counter > 1){
                aux2 = aux;
                aux = aux->next;
                counter--;
            }
            aux2->next = aux->next;
            *header = aux2;
        }
        strcpy(soldier, aux->soldierName);
        free(aux);
        return 1;
    }

    if(size == 1){
        strcpy(soldier, (*header)->soldierName);
        return 2;
    }
}

int startByRandom(list *header, char startSoldier[], char ***outSoldier, int *startPosition){
    if(emptyList(header) == 1)
        return 0;

    int size = qtdSoldiers(header);
    *startPosition = rand();

    if(size == 1){
        *outSoldier = (char **) malloc(sizeof(char*));
        *(*outSoldier) = (char*) malloc(20*sizeof(char));
        strcpy(startSoldier, (*header)->soldierName);
        strcpy(**outSoldier, (*header)->soldierName);
        return 2;
    }

    else{
        if(*startPosition > size)
            *startPosition = (*startPosition)%size;
        
        int i = *startPosition;
        while(*startPosition > 1){
            (*header) = (*header)->next;
            *startPosition--;
        }
        strcpy(startSoldier, (*header)->next->soldierName);

        i = 0;
        *outSoldier = (char**) malloc(size*sizeof(char*));
        
        int retorno;
        int counter = rand();
        *startPosition = counter;
        do{
            *(*outSoldier+i) = (char*) malloc(20*sizeof(char));
            retorno = startByFirst(header, counter, *(*outSoldier+i));
            if(retorno == 0)
                return 0;
            else if(retorno == 1 || retorno == 2){
                i++;
            }
        }while(retorno != 2);

        return 1;
    }

}

int startByName(list *header, char startSoldier[], char ***outSoldier, int *counter){
    if(emptyList(header) == 1)
        return 0;

    int size = qtdSoldiers(header);
    if(size == 1){
        *outSoldier = (char **) malloc(sizeof(char*));
        *(*outSoldier) = (char*) malloc(20*sizeof(char));
        strcpy(**outSoldier, (*header)->soldierName);
        return 2;
    }

    list aux = (*header);
    while(strcmp(startSoldier, (*header)->next->soldierName) != 0){
        (*header) = (*header)->next;
        if(*header == aux){
            return 0;
        }
    }

    int i = 0;
    *outSoldier = (char**) malloc(size*sizeof(char*));

    int cont = rand();
    *counter = cont;
    int retorno;
    do{
        *(*outSoldier+i) = (char*) malloc(20*sizeof(char));
        retorno = startByFirst(header, cont, *(*outSoldier+i));
        if(retorno == 0)
            return 0;
        else if(retorno == 1 || retorno == 2){
            i++;
        }
    }while(retorno != 2);

    return 1;
}