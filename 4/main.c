#include <stdio.h>
#include <stdlib.h> //usando na funcao rand() e srand()
#include <time.h> //usando na funcao time()
#include "fila.h"
#include "lista.h"

Vacinas v[N_HOSP];
int opc;
int dia, mes, ano;
int diaria = 0;

struct tm *data_hora_atual;
time_t segundos;

void menu(){

	printf(".......................................Data: %d / %d / %d\n",dia, mes, ano);
	printf("[1] Cadastro lista de espera\n[2] Geracao das filas diarias\n");
	printf("[3] Controle da vacinacao\n[4] Cenario\n");
	printf("[5] Sair\nOpcao: ");

}

int op = 0;

void tempo(){

	data_hora_atual = localtime(&segundos);

	dia = data_hora_atual->tm_mday;
	mes = data_hora_atual->tm_mon+1;
	ano = data_hora_atual->tm_year+1900;

}


int main(){

	time(&segundos);
	tempo();//pego a data atual do computador
	dados informacoes;
	
	Lista li, lista_aux, vacinados;
	Fila *fi, *fila_aux;
	li = cria_lista();
	vacinados = cria_lista();
	fi = cria_fila();

	if(li == NULL || vacinados == NULL || fi == NULL) printf("\nErro! :x\n\n");
	else{

		while(op != 5){

			menu();
			scanf("%d", &op);
			switch(op){

				case 1:
					printf("\nNome: ");
					scanf(" %[^\n]", informacoes.nome);
					printf("Idade: ");
					scanf(" %d", &informacoes.idade);
					printf("Possui comorbidade? [1] - Sim ; [2] - Nao\nOpcao: ");
					scanf(" %d", &informacoes.comorbidade);
					informacoes.vacina = 'x';
					informacoes.dia1 = 0;//igualei a zero para saber q n tem uma data ainda
					informacoes.mes1 = 0;
					informacoes.ano1 = 0;
					informacoes.dia2 = 0;
					informacoes.mes2 = 0;
					informacoes.ano2 = 0;

					//LOCAIS => 1 UTC1 ; 2 UTC2 ; 3 SABIAZINHO ; 4 PREFEITURA

					if(informacoes.comorbidade == 1) informacoes.local = 1;
					else if(informacoes.comorbidade == 2 && informacoes.idade <= 60) informacoes.local = 2;
					else if(informacoes.comorbidade == 2 && informacoes.idade > 60) informacoes.local = 4;
					
					if(insere_nao_ordenado(li, informacoes) == 0) printf("\nErro\n\n");
					else										  printf("\nCadastro feito\n\n");

					break;

				case 2:
					//chega mais vacinas para cada hospital
					for(int i = 0; i < N_HOSP; i++){
						if(i == 2){//arena sabiazinho
							v[i].A += 4;
							v[i].P += 4;
							v[i].C += 4;
						}
						else{//outros hospitais
							v[i].A += 2;
							v[i].P += 2;
							v[i].C += 2;
						}
					}

					//seleciona as pessoas da lista de espera e joga na fila do hospital correspondente a ela
					informacoes.local = 1;
					while(informacoes.local < 5){
						int n_pessoas = 6;
						int i = 0;
						if(informacoes.local == 3) n_pessoas = 12;//sabiazinho 12 pessoas
						while(i < n_pessoas){
							if(maior_idade(li, &informacoes) != 0){
								diaria++;//para dps controlar a opcao 'controle de vacinacao'
								if(informacoes.vacina != 'x') hospital = 2;//sabiazinho
								else if(informacoes.comorbidade == 1) hospital = 0;//UTC1
								else if(informacoes.comorbidade == 2 && informacoes.idade <= 60) hospital = 1;//UTC2
								else if(informacoes.comorbidade == 2 && informacoes.idade > 60) hospital = 3;//prefeitura

								int ok = 1;
								while(ok){//ira gerar uma vacina aleatoria para a pessoa, desde que 
											//possua da vacina disponivel
									srand(time(NULL));
									int tipo_vacina = rand() % 3;
									if(tipo_vacina == 0 && v[hospital].A > 0){
										informacoes.vacina = 'A';
										v[hospital].A--;
										ok = 0;
									}
									else if(tipo_vacina == 1 && v[hospital].P > 0){
										informacoes.vacina = 'P';
										v[hospital].P--;
										ok = 0;
									}
									else if(tipo_vacina == 2 && v[hospital].C > 0){
										informacoes.vacina = 'C';
										v[hospital].C--;
										ok = 0;
									}
								}

								if(push(fi, informacoes) == 0){
									printf("\nErro!\n\n");
									break;
								}
							}
							else break;

							++i;
						}
						informacoes.local++;
					}
					printf("\nGeracao filas diarias finalizado!\n\n");

					break;

				case 3:
					while(diaria > 0){//enquanto todas as pessoas que foram para alguma fila pelo processo do case 2
										//n forem vacinadas, vai ficar rodando aq
						hospital = 0;
						while(hospital < 1 || hospital > 4){
							printf("\nEscolha um local de vacinacao [NUMERO DE PESSOAS QUE FALTAM VACINAR: %d]\n", diaria);
							printf("[1] UTC1\n[2] UTC2\n[3] Sabiazinho\n[4] Prefeitura\nOpcao: ");
							scanf("%d", &hospital);
							if(hospital < 1 || hospital > 4) printf("\nOpcao invalida\n"); 
						}
						if(hospital == 1 || hospital == 2 || hospital == 4){//pessoas que vao tomar primeira dose
							hospital--;
							if(pop(fi, &informacoes) == 0) printf("\nFila vazia\n\n");
							else{
								//preencho a data da primeira dose
								informacoes.dia1 = dia;
								informacoes.mes1 = mes;
								informacoes.ano1 = ano;

								//preencho a data da segunda dose

								if(informacoes.vacina == 'A'){
									informacoes.dia2 = dia;
									informacoes.mes2 = mes + 3;
									informacoes.ano2 = ano;
								}
								else if(informacoes.vacina == 'P'){
									informacoes.dia2 = dia + 1;
									informacoes.mes2 = mes;
									informacoes.ano2 = ano;
								}
								else if(informacoes.vacina == 'C'){
									informacoes.dia2 = dia;
									informacoes.mes2 = mes + 2;
									informacoes.ano2 = ano;
								}

								if(informacoes.dia2 > 30){
									informacoes.mes2 += 1;
									informacoes.dia2 %= 30;
								}
								if(informacoes.mes2 > 12){
									informacoes.ano2 += 1;
									informacoes.mes2 %= 12;
								}
						
								//tirei a pessoa da fila e agora volta para lista de espera
								informacoes.local = 3;//proximo local eh o sabiazinho (segunda dose)
								if(insere_nao_ordenado(li, informacoes) == 0) printf("\nErro\n\n");
								else{
									printf("%s, %d anos, Tipo da vacina: %c, ", informacoes.nome, informacoes.idade, informacoes.vacina);
									printf("Vacina 1: %d / %d / %d - Vacina 2: %d / %d / %d\n", informacoes.dia1, informacoes.mes1, informacoes.ano1, informacoes.dia2, informacoes.mes2, informacoes.ano2);
								}
							
								diaria--;//digo q uma pessoa foi vacinada
							}
						}
						else{//pessoas que irao receber a segunda dose
							hospital--;

							//retiro da fila do sabiazinho e coloco na lista de vacinados
							if(pop(fi, &informacoes) == 0) printf("\nFila vazia\n\n");
							else{
								if(insere_nao_ordenado(vacinados, informacoes) == 0) printf("\nErro\n\n");
								else{
									printf("%s, %d anos, Tipo da vacina: %c, ", informacoes.nome, informacoes.idade, informacoes.vacina);
									printf("Vacina 1: %d / %d / %d - Vacina 2: %d / %d / %d\n", informacoes.dia1, informacoes.mes1, informacoes.ano1, informacoes.dia2, informacoes.mes2, informacoes.ano2);
								}
							
								diaria--;//digo q uma pessoa foi vacinada
							}
						}
					}
					printf("\nVacinacao diaria finalizada\n\n");
					dia++;
					if(dia > 30){
						mes += 1;
						dia %= 30;
					}
					if(mes > 12){
						ano += 1;
						mes %= 12;
					}

					break;

				case 4:
					//ira mostrar primeiro numero de vacinas em cada hospital
					printf("\n### Numero de vacinas em cada hospital ###\n");
					for(int i = 0; i < N_HOSP; i++){
						if(i == 0) printf("\nUTC1 -> ");
						else if(i == 1) printf("\nUTC2 -> ");
						else if(i == 2) printf("\nSabiazinho -> ");
						else if(i == 3) printf("\nPrefeitura -> ");
						printf("Astrazeneca [A]: %d - Pfizer [P]: %d - Coronavac [C]: %d", v[i].A, v[i].P, v[i].C);
					}
					printf("\n");

					lista_aux = cria_lista();
					if(lista_aux == NULL) printf("\nErro!\n\n");
					else{
						int cont = 1;
						//agora irá mostrar as pessoas que ja foram vacinadas
						printf("\n### LISTA DE VACINADOS ###\n\n");
						if(lista_vazia(vacinados) == 1) printf("Lista Vazia\n");
						else{
							while(remover_inicio(vacinados, &informacoes) != 0){
								printf("[%d] %s, %d anos, Tipo da vacina: %c, ", cont, informacoes.nome, informacoes.idade, informacoes.vacina);
								printf("Vacina 1: %d / %d / %d - Vacina 2: %d / %d / %d\n", informacoes.dia1, informacoes.mes1, informacoes.ano1, informacoes.dia2, informacoes.mes2, informacoes.ano2);
								insere_nao_ordenado(lista_aux, informacoes);
								cont++;
							}

							while(remover_inicio(lista_aux, &informacoes) != 0){
								insere_nao_ordenado(vacinados, informacoes);
							}
						}
						cont = 1;
						//irá mostrar as pessaos que estao na lista de espera
						printf("\n### LISTA DE ESPERA ###\n\n");
						if(lista_vazia(li) == 1) printf("Lista Vazia\n");
						else{
							while(remover_inicio(li, &informacoes) != 0){
								printf("[%d] %s, %d anos, Tipo da vacina: %c, ", cont, informacoes.nome, informacoes.idade, informacoes.vacina);
								printf("Vacina 1: %d / %d / %d - Vacina 2: %d / %d / %d\n", informacoes.dia1, informacoes.mes1, informacoes.ano1, informacoes.dia2, informacoes.mes2, informacoes.ano2);
								insere_nao_ordenado(lista_aux, informacoes);
								cont++;
							}
							while(remover_inicio(lista_aux, &informacoes) != 0){
								insere_nao_ordenado(li, informacoes);
							}
						}
					}
					libera(&lista_aux);

					fila_aux = cria_fila();
					if(fila_aux == NULL) printf("\nErro!\n\n");
					else{
						hospital = 0;
						//Fila de cada hospital
						while(hospital < N_HOSP){
							int n = 1;
							if(hospital == 0) printf("\n### UTC1 ###\n\n");
							else if(hospital == 1) printf("\n### UTC2 ###\n\n");
							else if(hospital == 2) printf("\n### Sabiazinho ###\n\n");
							else if(hospital == 3) printf("\n### Prefeitura ###\n\n");

							if(fila_vazia(fi) == 1) printf("Fila Vazia\n");
							else{
								while(pop(fi, &informacoes) != 0){
									printf("[%d] %s, %d anos, Tipo da vacina: %c, ", n, informacoes.nome, informacoes.idade, informacoes.vacina);
									printf("Vacina 1: %d / %d / %d - Vacina 2: %d / %d / %d\n", informacoes.dia1, informacoes.mes1, informacoes.ano1, informacoes.dia2, informacoes.mes2, informacoes.ano2);
									push(fila_aux, informacoes);
									n++;
								}
								while(pop(fila_aux, &informacoes) != 0){
									push(fi, informacoes);
								}
							}
							hospital++;
						}
						printf("\n");
					}
					libera_fila(fila_aux);

					break;

				case 5:
					printf("\nFim do programa\n\n");

					break;

				default:
					printf("\nOperacao invalida\n\n");

			}
		}
	}

	libera(&li);
	libera(&vacinados);
	libera_fila(fi);

	return 0;
}
