#include <stdio.h>
#include "3.h"

int op = 0, boxe;
Estacionamento F;
Carro info;

void menu(){

	printf("### ESTACIONAMENTO ###\n");
	printf("[1] Entrada de veiculos\n[2] Saida de veiculos\n[3] Visualizacao cenario\n");
	printf("[4] Sair\nOpcao: ");

}

int imprimir(){
	/*
	devido o criterio de inserção, foi necessario ir variando cada boxe e tbm caso alguma vaga estivesse vazia,
	precisei preencher com um campo 'vazio' para dps qnd fosse colocar novamente os carros, a inserção fosse feita
	corretamente! Ou seja, meu estacionamento auxiliar sempre irá ficar cheio 
	ex.: pego o primeiro elemento do boxe 1, dps pego o primeiro do boxe 2, dps boxe 3 e assim vai...
	foi necessario fazer a retirada de todos os elementos do ESTACIONAMENTO primeiro, pra DEPOIS
	fazer a retirada dos carros da FILA DE ESPERA (ULTIMO BOXE)
	*/

	Estacionamento aux;
	aux = cria_fila();
	if(aux == 0) return 0;
	else{
		int boxe = 0, max = 0, cont = 0;
		int i;
		printf("\n");
		//foi usado esse for para caso eu queira mexer no numero de boxes, n preciso fazer a mao cada printf
		for(i = 0; i < MAX_BOXE-1; i++) printf("[BOXE %d]		", i+1);
		printf("\n");
		while(max < (MAX_BOXE*MAX_CAR)-MAX_CAR){
			
			if(get_inicio(F,boxe,&info) == 0){
				strcpy(info.placa, "Vazio");
			}
			else{
				if(remove_placa(F,&info) == 0) {return 0; libera_fila(&aux);}
			}
			if(insere_fim(aux, &info) == 0) {return 0; libera_fila(&aux);}
			printf("%s 			", info.placa);
			cont++;
			if(cont >= MAX_BOXE-1){
				printf("\n");
				cont = 0;
			}
			max++;
			boxe = (boxe+1) % (MAX_BOXE-1);
		
		}//ate aqui foi feita a retirada de todos os carros do ESTACIONAMENTO
		//agora irei retirar os carros que estavam na ESPERA, mas pelo fato de alguns criterios do exercicio
		//eles foram para o ESTACIONAMENTO assim q foi retirando os outros carros
		boxe = 0, max = 0;
		printf("\n[BOXE %d]\n", i+1);
		while(max < MAX_CAR){
			
			if(get_inicio(F,boxe,&info) == 0){
				strcpy(info.placa, "Vazio");
			}
			else{
				if(remove_placa(F,&info) == 0) {return 0; libera_fila(&aux);}
			}
			if(insere_fim(aux, &info) == 0) {return 0; libera_fila(&aux);}
			printf("%s  	", info.placa);
			
			max++;
			boxe = (boxe+1) % (MAX_BOXE-1);
		
		}//ate aqui o estaciomaneto esta vazio e tbm foi feito um print mostrando como esta o estacionamento
		//agora preciso tirar os carros do estacionamento auxiliar e voltar para o original
		/*
			novamente segue a linha de raciocionio de tirar todos que estao no ESTACIONAMENTO primeiro
			dps que vou para os que estavam na fila de espera
		*/

		max = 0, boxe = 0;
		while(max < (MAX_CAR*MAX_BOXE)-MAX_CAR){

			if(get_inicio(aux,boxe,&info) == 0){
				strcpy(info.placa, "Vazio");
			}
			else{
				if(remove_placa(aux,&info) == 0) {return 0; libera_fila(&aux);}
			}
			if(insere_fim(F,&info) == 0) {return 0; libera_fila(&aux);}
			max++;
			boxe = (boxe+1) % (MAX_BOXE-1);
		}

		max = 0, boxe = 0;
		while(max < MAX_CAR){

			if(get_inicio(aux,boxe,&info) == 0){
				strcpy(info.placa, "Vazio");
			}
			else{
				if(remove_placa(aux,&info) == 0) {return 0; libera_fila(&aux);}
			}
			if(insere_fim(F,&info) == 0) {return 0; libera_fila(&aux);}
			max++;
			boxe = (boxe+1) % (MAX_BOXE-1);
		}
		//caso o estacionamento n estiver cheio, foi feita a ocupação das vagas com a placa 'Vazio'
		//entao é feita a retirada de todas essas placas, para que o estacionamento volte como antes
		strcpy(info.placa, "Vazio");
		while(remove_placa(F,&info) != 0); 
	}

	printf("\n\n");

	libera_fila(&aux);

	return 1;

}

int main(){

	F = cria_fila();
	if(F == NULL) printf("\nNao foi possivel criar a fila\n\n");
	else{
		while(op != 4){
			menu();
			scanf("%d", &op);
			switch(op){
				case 1:
					if(cheio(F) == 1) printf("\nEstacionamento lotado!\n\n");
					else{
						printf("\nPlaca: ");
						scanf(" %[^\n]", info.placa);
						printf("Tipo de servico ([A] - avulso ; [M] - mensalista): ");
						scanf(" %[^\n]", &info.servico);
						info.entrada = time(NULL);
						if(insere_fim(F, &info) == 0) printf("\nFalha\n\n");
						else					printf("\nSucesso\n\n");
					}
					break;

				case 2:
					if(vazio(F) == 1) printf("\nEstacionamento vazio!\n\n");
					else{
						printf("\nPlaca: ");
						scanf(" %[^\n]", info.placa);
						if(remove_placa(F, &info) == 0) printf("\nErro\n\n");
						else{
							//4s = EQUIVALE A 15min, LOGO, 8s EQUIVALE A 30 minutos => 16s 60min == 1h
							time_t saida = time(NULL);
							int tempo;
							tempo = saida - info.entrada;
							int horas = tempo/16;
							int minutos = tempo%16;
							printf("\nServico: %c\nTempo: %d hora(s) e %.0f minuto(s)\n", info.servico, horas, minutos*3.75);
							
							if(info.servico == 'A' || info.servico == 'a' ){
								float valor = 10;								
								valor += 3*(horas-1);
								if(minutos >= 4) valor += 3;
								printf("Valor: R$%.2lf\n", valor);
							}
							printf("\n");
							
						}
					}
					break;

				case 3:

					if(imprimir() == 0){
						printf("\nErro! :x\n\n");
						op = 4;
					}
										
					break;

				case 4:
					printf("\nFim do programa\n\n");

					break;

				default:
					printf("\nOperacao invalida\n\n");

				
			}
		}
	}

	libera_fila(&F);

	return  0;

}