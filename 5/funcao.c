#include <stdlib.h>
#include "tad.h"

typedef struct no{

	aluno dados;
	struct no *prox;

}No;

struct fila{//essa struct eh meu cabe�alho

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

	if(f->ini == NULL) return 1; //lista vazia
	else			   return 0;

}

/*Implementei essa fun��o pois est� no enunciado
Mas como se trata de uma fpa din�mica, entao comentei, pois nao existe estrutra din�mica cheia
int fp_cheia(Fila f){

	return 0;

}*/

int inserir(Fila f, aluno *al){ //passa struct aluno e o endere�o da fila por referencia

	if(f == NULL) return 0; //falha pq eh null

	No *N; //cria novo no(ponteiro)
	N = (No *)malloc(sizeof(No)); //aloca dinamicamente
	if(N == NULL) return 0; //se o endere�o for nulo falha

	N->dados = *al; //passa os dados pro novo n�
	N->prox = NULL; //o proximo elemento � null

	if(fp_vazia(f) == 1) f->ini = N; //se a fila for vazia, aponta pro inicio da fila e recebe nulo(ja que � vazia)
	else f->fim->prox = N; //se n�o, o ultimo elemento aponta pro novo elemento

	f->fim = N; //aponta pro fim

	return 1;

}

int remover(Fila f, aluno *al){
//o ans eh uma variavel pra marcar o aluno que eu quero remover, assim n�o precisa percorrer tudo, s� remove direto
	if(f == NULL || fp_vazia(f) == 1) return 0; //fila vazia

	No *aux = f->ini, *ant; //o no aux recebe o inicio da fila
	No *ans = f->ini; //ans expliquei ali em cima, aponta pro inicio da fila tb
	while(aux != NULL){
		if(aux->dados.ano < ans->dados.ano){ //procura pelo ano, se o ano for menor que o do aluno que quer deletar
			ant = ans; //o aux anterior recebe o aluno que vai deletar
			ans = aux;
		}
		aux = aux->prox; //aponta pro proximo numero
	}

	*al = ans->dados;//passando para o usuario o elemento q vai ser removido

	if(ans == f->ini) f->ini = ans->prox; //remover do inicio

	else if(ans == f->fim){//remover do final
		ant->prox = NULL;
		f->fim = ant;
	}

	else ant->prox = ans->prox; //remover no meio da fila

	if(fp_vazia(f) == 1) f->fim = NULL; //se a fila ficar vazia, seto meu fim para null

	free(ans); //libera o aluno que deletou

	return 1;

}

void esvazia_fp(Fila f){// libera todos os n�s mas n�o libera a fila

	if(f != NULL){
		No *aux; //faz um aux pra ajudar na esvazia��o
		while(f->ini != NULL){
			aux = f->ini; //aponta pro inicio da fila
			f->ini = f->ini->prox; //aponta pro proximo elemento
			free(aux); //vai esvaziar o auxiliar
		}
		f->fim = NULL; //o fim recebe nulo pq esvaziou tudo
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
	free(*f); //libera a fila
	(*f) = NULL; //fila fica null pq limpa tudo

}
