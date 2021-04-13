#ifndef DUPLO_H_INCLUDED
#define DUPLO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct no * Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento (Lista *lst, int elem);
int remove_elemento (Lista *lst, int elem);


#endif // DUPLO_H_INCLUDED
