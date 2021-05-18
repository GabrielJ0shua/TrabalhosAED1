#include <stdlib.h>
#include "1.h"

struct Inteiros{

	int num[MAX];
	int topo;

};

Pilha cria_pilha(){

	Pilha p = (Pilha)malloc(sizeof(struct Inteiros));
	if(p != NULL) p->topo = 0;

	return p;

}

int pilha_cheia(Pilha p){

	if(p != NULL && p->topo == MAX) return 1;
	else			  return 0;

}

int pilha_vazia(Pilha p){

	if(p != NULL && p->topo == 0) return 1;
	else			return 0;

}

int push(Pilha p, int numero){

	if(p == NULL || pilha_cheia(p) == 1) return 0;

	p->num[p->topo] = numero;
	p->topo++;

	return 1;

}

int pop(Pilha p, int *numero){

	if(p == NULL || pilha_vazia(p) == 1) return 0;

	*numero = p->num[p->topo - 1];
	p->topo--;

	return 1;

}

int le_topo(Pilha p, int *numero){

	if(p == NULL || pilha_vazia(p) == 1) return 0;

	*numero = p->num[p->topo - 1];

	return 1;

}

int esvazia(Pilha p){

	if(p == NULL) return 0;

	while(p->topo != 0) p->topo--;

	return 1;

}

void libera(Pilha p){

	if(p != NULL){
		free(p);
		p = NULL;
	}

}
