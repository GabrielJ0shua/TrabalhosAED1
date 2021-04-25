#ifndef DUPLO_H_INCLUDED
#define DUPLO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct no * Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento (Lista *lst, int elem);
int remove_elemento (Lista *lst, int elem);
void apaga_lista(Lista *lst);
int remove_maior(Lista *lst, int *elem);
Lista primos(Lista *lst);
int get_posicao(Lista lst, int pos);
Lista inverte(Lista *lst);
int tamanho_lista(Lista *lst);
#endif // DUPLO_H_INCLUDED
