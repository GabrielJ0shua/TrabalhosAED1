#include <stdlib.h>
#include "tad.h"

typedef struct no{

	aluno dados;
	struct no *prox;

}No;

struct fila{//essa struct eh meu cabeçalho

	struct no *ini;
	struct no *fim;

};

Fila cria_fp(){

	Fila f;
	f = (Fila)malloc(sizeof(struct fila));
	if(f != NULL){
		f->ini = NULL;
		f->fim = NULL;
	}

	return f;

}

int fp_vazia(Fila f){

	if(f->ini == NULL) return 1;
	else			   return 0;

}

/*Implementei essa função pois está no enunciado
Mas como se trata de uma fpa dinâmica, entao comentei, pois nao existe estrutra dinâmica cheia
int fp_cheia(Fila f){

	return 0;

}*/

int inserir(Fila f, aluno *al){

	if(f == NULL) return 0;

	No *N;
	N = (No *)malloc(sizeof(No));
	if(N == NULL) return 0;

	N->dados = *al;
	N->prox = NULL;

	if(fp_vazia(f) == 1) f->ini = N;
	else f->fim->prox = N;

	f->fim = N;

	return 1;

}

int remover(Fila f, aluno *al){

	if(f == NULL || fp_vazia(f) == 1) return 0;

	No *aux = f->ini, *ant;
	No *ans = f->ini;
	while(aux != NULL){
		if(aux->dados.ano < ans->dados.ano){
			ant = ans;
			ans = aux;
		}
		aux = aux->prox;
	}

	*al = ans->dados;//passando para o usuario o elemento q vai ser removido

	if(ans == f->ini) f->ini = ans->prox; //remover do inicio

	else if(ans == f->fim){//remover do final
		ant->prox = NULL;
		f->fim = ant;
	}

	else ant->prox = ans->prox; //remover no meio da fila

	if(fp_vazia(f) == 1) f->fim = NULL; //se a fila ficar vazia, seto meu fim para null

	free(ans);

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

void libera_fp(Fila *f){

	if(*f != NULL){
		No *aux;
		while((*f)->ini != NULL){
			aux = (*f)->ini;
			(*f)->ini = (*f)->ini->prox;
			free(aux);
		}
		(*f)->fim = NULL;
	}
	free(*f);
	(*f) = NULL;

}
