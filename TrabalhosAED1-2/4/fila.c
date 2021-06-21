#include <stdlib.h>
#include "fila.h"

typedef struct no{

	dados info;
	struct no *prox;

}No;

struct fila{

	struct no *ini;
	struct no *fim;

};

Fila* cria_fila(){

	Fila *f = (Fila *)malloc(N_HOSP*sizeof(Fila));
	if(f != NULL){
		for(int i = 0; i < N_HOSP; ++i){
			f[i].ini = NULL;
			f[i].fim = NULL;
		}
	}
	
	return f;

}

int fila_vazia(Fila *f){

	if(f[hospital].ini == NULL) return 1;
	else				 return 0;

	/*variavel hospital eh 'global' para todos os arquivos, foi declarada lá no arquivo struct.h*/

}

int push(Fila *f, dados p){//insere sempre no final (trabalhando com fila)

	if(f == NULL) return 0;

	No *no = (No *)malloc(sizeof(No));
	if(no == NULL) return 0;

	no->info = p;
	no->prox = NULL;

	if(fila_vazia(f) == 1) f[hospital].ini = no;//se for vazia
	else 				   f[hospital].fim->prox = no;//se n for vazia

	f[hospital].fim = no;

	return 1;

}

int pop(Fila *f, dados *p){//removo sempre o inicio (trabalhando com fila)

	if(f == NULL || fila_vazia(f) == 1) return 0;

	*p = f[hospital].ini->info;

	No *aux = f[hospital].ini;
		
	if(f[hospital].ini == f[hospital].fim) f[hospital].fim = NULL;//se a fila tiver um elemento so
	
	f[hospital].ini = aux->prox;

	free(aux); 

	return 1;

}

int tamanho(Fila *f, int *tam){

	if(f == NULL) return 0;

	int t = 0;
	No *aux = f[hospital].ini;

	while(aux != NULL){
		aux = aux->prox;
		t++;
	}

	*tam = t;

	return 1;
}

int get_inicio(Fila *f, dados *p){//pego os dados de qm está no inicio da fila

	if(f == NULL || fila_vazia(f) == 1) return 0;

	*p = f[hospital].ini->info;

	return 1;

}

void libera_fila(Fila *f){

	if(f != NULL){
		for(int i = N_HOSP-1; i >= 0; --i){
			while(f[i].ini != NULL){
				No *aux = f[i].ini;
				f[i].ini = aux->prox;
				free(aux);
			}
		}
		free(f);
		f = NULL;
	}
}




