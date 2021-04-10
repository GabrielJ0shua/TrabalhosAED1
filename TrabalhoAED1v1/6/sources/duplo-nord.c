#include <stdlib.h>
#include "..\headers\duplo-nord.h"

struct node{
    int data;
    struct node *prev;
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

int insertNode(list *header, int data){
    list newNode = (list) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;
    
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *header;

    if(emptyList(header) == 0) 
        (*header)->prev = newNode;


    *header = newNode;
    return 1;
}

int removeNode(list *header, int data){
    if(emptyList(header) == 1)
        return 0;
    list aux = *header;
    while(aux->next != NULL && aux->data != data)
        aux = aux->next;

    if(aux->data != data)
        return 0;

    if(aux->next != NULL)
        aux->next->prev = aux->prev;

    if(aux->prev != NULL)
        aux->prev->next = aux->next;

    if(aux == *header)
        *header = aux->next;

    free(aux);
    return 1;
}

int listSize(list *header){
    if(emptyList(header) == 1){
        return 0;
    }

    int size = 1;
    list aux = *header;
    while(aux->next != NULL){
        aux = aux->next;
        size++;
    }
    return size;
}

int getValue(list *header, int *output, int position){
    int size = listSize(header);
    if(emptyList(header) == 1 || position > size)
        return 0;
    
    list aux = *header;

    while(position > 1){
        aux = aux->next;
        position--;
    }

    *output = aux->data;
    return 1;
}

int clearList(list *header){
    if(emptyList(header) == 1)
        return 0;

    list aux = *header;
    while(*header != NULL){
        *header = (*header)->next;
        free(aux);
        aux = *header;
    }
    return 1;
}

int removeAll(list *header, int data){
    if(emptyList(header) == 1)
        return 0;
    
    list aux = *header, aux2;
    while(aux != NULL){
        if(aux->data == data){
            if(aux->next != NULL)
                aux->next->prev = aux->prev;
            if(aux->prev != NULL)
                aux->prev->next = aux->next;
            if(aux == *header)
                *header = aux->next;
            aux2 = aux->next;
            free(aux);
            aux = aux2;
        }
        else aux = aux->next;
    }
    return 1;
}

int removeGreater(list *header, int *output){
    if(emptyList(header) == 1)
        return 0;
    list aux = *header, greater = *header;
    while(aux != NULL){
        if(aux->data >= greater->data)
            greater = aux;
        aux = aux->next;
    }
    if(greater->next != NULL)
        greater->next->prev = greater->prev;
    if(greater->prev != NULL)
        greater->prev->next = greater->next;
    if(greater == *header)
        *header = greater->next;

    *output = greater->data;
    free(greater);
    return 1;
}

int reverseList(list *header, list *reverse){
    if(emptyList(header) == 1)
        return 0;

    list aux = *header;
    
    while(aux != NULL){
        insertNode(reverse, aux->data);
        aux = aux->next;
    }

    return 1;
}

int threeMultiList(list *header, list *threeMultiples){
    if(emptyList(header) == 1)
        return 0;

    list aux = *header;

    while(aux != NULL){
        if(aux->data % 3 == 0){
            insertNode(threeMultiples, aux->data);
        }
        aux = aux->next;
    }

    return 1;
}