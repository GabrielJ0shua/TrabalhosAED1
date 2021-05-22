#include <stdlib.h>
#include "tad.h"

typedef struct no{

	aluno dados;
	struct no *prox;

}No;

struct fila{//essa struct eh meu cabeçalho

	struct no *ini;
	struct no *fim;
	int tamanho;

};

Fila cria_fp(){

	Fila f;
	f = (Fila)malloc(sizeof(struct fila));
	if(f != NULL){
		f->ini = NULL;
		f->fim = NULL;
		f->tamanho = 0;
	}

	return f;

}

int fp_vazia(Fila f){

	if(f->ini == NULL) return 1;
	else			   return 0;

}

int fp_cheia(Fila f){

	return 0;

}

int inserir(Fila *f, aluno *al){

	if(f == NULL) return 0;

	No *N;
	N = (No *)malloc(sizeof(No));
	if(N == NULL) return 0;

	N->dados = *al;
	(*f)->tamanho++;

	if((*f)->ini == NULL){//se minha fp estiver vazia
		N->prox = NULL;
		(*f)->ini = N;
		(*f)->fim = N;

		return 1;
	}

	//se n tiver vazia, devo procurar o lugar para inserir esse novo elemento
	//como estamos desenvolvendo uma FPA (dinâmica), entao preciso deixar meu elemento de menor prioridade sempre
	//no inicio, para a remoção ter complexidade O(1), minha insercao no pior caso terá complexidade O(n)

	No *aux = (*f)->ini, *ant;
	while(aux != NULL && aux->dados.ano < N->dados.ano){
		ant = aux;
		aux = aux->prox;
	}

	if((*f)->ini == aux){//inserir no inicio
		N->prox = aux;
		(*f)->ini = N;
	}

	else if(aux == NULL){//inserir no fim
		ant->prox = N;
		N->prox = NULL;
		(*f)->fim = N;
	}

	else{//inserir no meio
		ant->prox = N;
		N->prox = aux;
	}

	return 1;

}

int remover(Fila *f, aluno *al){

	if(f == NULL || fp_vazia(*f) == 1) return 0;

	*al = (*f)->ini->dados;
	No *aux = (*f)->ini;
	(*f)->ini = (*f)->ini->prox;
	free(aux);
	(*f)->tamanho--;

	if((*f)->ini == NULL) (*f)->fim = NULL;

	return 1;

}

void esvazia_fp(Fila f){

	if(f != NULL){
		No *aux;
		while(f->ini != NULL){
			aux = f->ini;
			f->ini = f->ini->prox;
			free(aux);
		}
		f->fim = NULL;
	}

}

void libera_fp(Fila f){

	if(f != NULL){
		No *aux;
		while(f->ini != NULL){
			aux = f->ini;
			f->ini = f->ini->prox;
			free(aux);
		}
		f->fim = NULL;
	}
	free(f);
	f = NULL;

}
