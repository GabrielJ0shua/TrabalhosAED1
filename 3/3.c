#include <stdlib.h>
#include "3.h"

//FUNCOES PARA MANIPULAR UMA FILA

struct ESTACIONAMENTO{

	int carros_totais;//contador
	Fila Boxe[MAX_BOXE];//ultimo boxe eh a fila de espera

}; 

Estacionamento cria_fila(){

	Estacionamento F = (Estacionamento)malloc(sizeof(struct ESTACIONAMENTO));
	if(F != NULL){
		F->carros_totais = 0;
		for(int i = 0; i < MAX_BOXE; ++i){
			F->Boxe[i].ini = 0;
			F->Boxe[i].cont = 0;
			for(int j = 0; j < MAX_CAR; ++j){
				F->Boxe[i].info[j].servico = '-';
			}
		}
	}

	return F;

}

int cheio(Estacionamento F){

	if(F->carros_totais == (MAX_BOXE*MAX_CAR)) return 1;
	else	return 0;

}

int vazio(Estacionamento F){

	if(F->carros_totais == 0) return 1;
	else	return 0;

}

int insere_fim(Estacionamento F, Carro *New_info){

	if(F == NULL || cheio(F) == 1) return 0;//se tiver cheio, n tem como inserir mais carros
	
	//preciso verificar qual dos boxes tem menos carro

	if(F->carros_totais < (MAX_CAR * MAX_BOXE) - MAX_CAR){//tem vaga no estacionamento
		int menor_qntd = MAX_CAR + 100;
		int pos;
		for(int i = 0; i < MAX_BOXE-1; ++i){//vejo em qual boxe tem menos carro (n inclui fila de espera)
			if(F->Boxe[i].cont < menor_qntd){
				menor_qntd = F->Boxe[i].cont;
				pos = i;
			}
		}
		F->Boxe[pos].info[(F->Boxe[pos].ini + F->Boxe[pos].cont) % MAX_CAR] = *New_info;
		F->Boxe[pos].cont++;
	}
	else{//n tem vaga no estacionamento, logo vai pra fila de espera
		F->Boxe[MAX_BOXE-1].info[(F->Boxe[MAX_BOXE-1].ini + F->Boxe[MAX_BOXE-1].cont) % MAX_CAR] = *New_info;
		F->Boxe[MAX_BOXE-1].cont++;
	}

	F->carros_totais++;

	return 1;

}

int remove_placa(Estacionamento F, Carro *Busca_placa){

	if(F == NULL || vazio(F) == 1) return 0;

	int i, j, marcador;
	Carro aux;

/*==================================================================================================================

ESSA PRIMEIRA PARTE REFERE-SE AO Estacionamento*/

	for(i = 0; i < MAX_BOXE-1; ++i){//percorrer cada boxe
		marcador = F->Boxe[i].ini;//guardo em q posicao do meu vetor esta meu primeiro carro
		for(j = 0; j < F->Boxe[i].cont; ++j){//percorrer os elementos do meu boxe i
			if(get_inicio(F, i, &aux) != 0){//se meu get_inicio nao falhar
				if(strcmp(aux.placa, (*Busca_placa).placa) != 0){//se as placas forem diferentes
					F->Boxe[i].ini = (F->Boxe[i].ini+1) % MAX_CAR;//eu passo meu ini para o proximo carro
				}
				else{//se as placas forem iguais

					*Busca_placa = aux;//passo para meu usuario as informacoes(servico, horas)

				//tenho 2 cenarios => 1) ter carro na espera ; 2) NAO ter carro na espera

					if(F->carros_totais <= (MAX_BOXE*MAX_CAR)-MAX_CAR){//se NAO houver carro na espera (Cenario 2)

						F->Boxe[i].info[F->Boxe[i].ini].servico = '-';//colocando essa posicao como invalida
						F->Boxe[i].cont--;
						if(F->Boxe[i].cont > 0){//se houver carros validos no meu boxe (servico != v)
						//preciso passar meu ini para o proximo carro valido (servico != v)
							while(F->Boxe[i].info[F->Boxe[i].ini].servico == '-'){
								F->Boxe[i].ini = (F->Boxe[i].ini+1) % MAX_CAR;
							}
						}
					}
					else{//tem carro na espera (Cenario 1)
						if(get_inicio(F, MAX_BOXE-1, &aux) != 0){//pegando os dados do primeiro carro da espera
							F->Boxe[i].info[F->Boxe[i].ini] = aux;//colocando os dados do primeiro carro da espera na vaga do estacionamento
							F->Boxe[MAX_BOXE-1].info[F->Boxe[MAX_BOXE-1].ini].servico = '-';//colocando primeira posicao da espera como invalida
							F->Boxe[MAX_BOXE-1].cont--;
							if(F->Boxe[MAX_BOXE-1].cont > 0){//se houver carros validos na minha espera (servico != v)
							//preciso passar meu ini para o proximo carro valido (servico != v)
								while(F->Boxe[MAX_BOXE-1].info[F->Boxe[MAX_BOXE-1].ini].servico == '-'){
									F->Boxe[MAX_BOXE-1].ini = (F->Boxe[MAX_BOXE-1].ini+1) % MAX_CAR;
								}
							}
							F->Boxe[i].ini = (F->Boxe[i].ini+1) % MAX_CAR;
						}
					}

					F->carros_totais--;

					return 1;
				}
			}
		}
		//se chegar aqui, eh pq n achei a placa no boxe i, agora irei para o proximo boxe
		//entao retorno meu ini para a posicao em q estava
		F->Boxe[i].ini = marcador;
	}

/*==================================================================================================================

ESSA OUTRA PARTE, REFERE-SE A FILA DE ESPERA (ULTIMA POSICAO DO MEU VETOR 'Boxe') */

	marcador = F->Boxe[MAX_BOXE-1].ini;
	for(i = 0; i < F->Boxe[MAX_BOXE-1].cont; ++i){
		if(get_inicio(F, MAX_BOXE-1, &aux) != 0){
			if(strcmp(aux.placa, (*Busca_placa).placa) != 0){
				F->Boxe[MAX_BOXE-1].ini = (F->Boxe[MAX_BOXE-1].ini+1) % MAX_CAR;
			}
			else{

				*Busca_placa = aux;
				F->carros_totais--;
				F->Boxe[MAX_BOXE-1].info[F->Boxe[MAX_BOXE-1].ini].servico = '-';
				F->Boxe[MAX_BOXE-1].cont--;
				if(F->Boxe[MAX_BOXE-1].cont > 0){
					while(F->Boxe[MAX_BOXE-1].info[F->Boxe[MAX_BOXE-1].ini].servico == '-'){
						F->Boxe[MAX_BOXE-1].ini = (F->Boxe[MAX_BOXE-1].ini+1) % MAX_CAR;
					}
				}
				return 1;
			}
		}
	}
	//se chegar aqui eh pq nao achei a placa em nenhum lugar
	F->Boxe[MAX_BOXE-1].ini = marcador;
	return 0;
}

int tamanho(Estacionamento F, int fila, int *tam){

	if(F == NULL || fila < 0 || fila > MAX_BOXE - 1) return 0;

	*tam = F->Boxe[fila].cont;

	return 1;

}

int get_inicio(Estacionamento F, int fila, Carro *Busca_placa){

	if(F == NULL || fila < 0 || fila > MAX_BOXE - 1) return 0;

	if(F->Boxe[fila].cont == 0) return 0;

	*Busca_placa = F->Boxe[fila].info[F->Boxe[fila].ini];

	return 1;

}

void libera_fila(Estacionamento *F){

	if(*F != NULL){
		free(*F);
		*F = NULL;
	}

}