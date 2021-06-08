#include <stdlib.h>
#include "lista.h"

/*TAD LISTA DINAMICA DUPLAMENTE ENCADEADA E 'CIRCULAR'
circular está entre aspas, pois meu ultimo nó n aponta para o primeiro, porém,
tenho uma struct cabecalho q contem o inicio e o fim da lista, logo, sei onde está
meu inicio e fim, assim como na lista circular
*/

typedef struct no{

	dados info;
	struct no *prox;
	struct no *ant;

}No;

struct cabecalho{

	struct no *ini;
	struct no *fim;

};

Lista cria_lista(){

	Lista N = (Lista)malloc(sizeof(struct cabecalho));
	if(N != NULL){
		N->ini = NULL;
		N->fim = NULL;
	}

	return N;

}

int lista_vazia(Lista li){

	if(li->ini == NULL) return 1;
	else		   return 0;

}

int insere_nao_ordenado(Lista li, dados p){//insercao sempre feita no fim

	if(li == NULL) return 0;

	No *N = (No *)malloc(sizeof(No));
	if(N == NULL) return 0;

	N->info = p;
	N->prox = NULL;
	N->ant = li->fim;
	
	if(lista_vazia(li) == 0) li->fim->prox = N;
	else					 li->ini = N;
	
	li->fim = N;
	
	return 1;

}

int remover_inicio(Lista li, dados *p){//remove o inicio da lista

	if(li == NULL || lista_vazia(li) == 1) return 0;

	*p = li->ini->info;
	No *aux = li->ini;
	li->ini = aux->prox;

	free(aux);

	if(li->ini == NULL) li->fim = NULL;//se a lista tiver ficado vazia

	return 1;

}

int maior_idade(Lista li, dados *p){//remove a pessoa mais velha da lista

	if(li == NULL || lista_vazia(li) == 1) return 0;

	int maior = -1;
	No *aux = li->ini;
	No *remover;
	while(aux != NULL){
		if(aux->info.idade > maior && aux->info.local == (*p).local){
			maior = aux->info.idade;
			remover = aux;//deixo marcado a posicao para que eu n tenha q percorrer a lista novamente dps
		}
		aux = aux->prox;
	}
	
	if(maior == -1) return 0;

	*p = remover->info;

	if(li->ini == li->fim){//lista com um elemento
		li->ini = NULL;
		li->fim = NULL;
		

		free(remover);

		return 1;
	}

	if(remover == li->ini){//remover do inicio
		li->ini = remover->prox;
		remover->prox->ant = NULL;
	}
	else if(remover == li->fim){//remover do final
		li->fim = remover->ant;
		remover->ant->prox = NULL;
	}
	else{//remover do meio
		remover->ant->prox = remover->prox;
		remover->prox->ant = remover->ant;
	}

	free(remover);

	return 1;

}

int menor_data(Lista li, dados *p){//remove a pessoa com a menor data da segunda dose

	if(li == NULL || lista_vazia(li) == 1) return 0;

	int Diamenor = 55, Mesmenor = 55, Anomenor = 999999;
	//diamenor = 55 pois o mes vai no max 30, segue o raciocinio para as outras variaveis
	//logo, sempre a comparação com a primeira pessoa da lista, ela terá uma data menor

	No *aux = li->ini;
	No *remover;
	while(aux != NULL){
		int ok = 0;
		if(aux->info.ano2 > 0){//a pessoa precisa ter uma data valida da segunda dose
								//lembrando que a pessoa recebe data 0/0/0 no cadastro (data invalida)
			if(aux->info.ano2 < Anomenor){ remover = aux; ok = 1; }
			else if(aux->info.mes2 < Mesmenor && aux->info.ano2 <= Anomenor){ remover = aux; ok = 1; }
			else if(aux->info.dia2 < Diamenor && aux->info.mes2 <= Mesmenor && aux->info.ano2 <= Anomenor){ remover = aux; ok = 1; }
		
			/*Sei que todas as operacoes que irao realizar sao as mesma em cada condição acima,
				porem fiz assim para facilitar o entendimento*/

			if(ok){
				Diamenor = remover->info.dia2;
				Mesmenor = remover->info.mes2;
				Anomenor = remover->info.ano2;
			}
		}
		aux = aux->prox;
	}

	if(Diamenor == 55) return 0; //n tinha ngm que iria receber segunda dose (todas as datas da segunda dose eram invalidas)

	*p = remover->info;

	if(li->ini == li->fim){//lista com um elemento
		li->ini = NULL;
		li->fim = NULL;
		

		free(remover);

		return 1;
	}

	if(remover == li->ini){//remover do inicio
		li->ini = remover->prox;
		remover->prox->ant = NULL;
	}
	else if(remover == li->fim){//remover do final
		li->fim = remover->ant;
		remover->ant->prox = NULL;
	}
	else{//remover do meio
		remover->ant->prox = remover->prox;
		remover->prox->ant = remover->ant;
	}

	free(remover);

	return 1;

}

void libera(Lista *li){

	if(*li != NULL){
		while((*li)->ini != NULL){
			No *aux = (*li)->ini;
			(*li)->ini = aux->prox;
			free(aux);
		}
		free(*li);
		*li = NULL;
	}
}

