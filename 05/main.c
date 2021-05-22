#include <stdio.h>
#include "tad.h"

int opcao = 0, iniFP = 0;
Fila f;
aluno al;

void menu(){

	printf("Selecione a opcao desejada:\n");
	printf("[1] Cria fila de prioridade\n[2] Inserir\n[3] Remover\n[4] Esvaziar\n[5] Imprimir\n[6] Sair\nOpcao: ");
}

int imprimir(){

	Fila aux;
	aux = cria_fp();
	if(aux != NULL){
		printf("\nFila de prioridade:\n");
		while(remover(&f, &al) != 0){
			printf("[%d - %s - %.2lf - %d]\n", al.matricula, al.nome, al.cra, al.ano);
			if(inserir(&aux, &al) == 0){
				libera_fp(aux);
				return 0;
			}
		}
		while(remover(&aux, &al) != 0){
			if(inserir(&f, &al) == 0){
				libera_fp(aux);
				return 0;
			}
		}
		libera_fp(aux);
		return 1;
	}
	return 0;
}

int main(){

	int ok = 1;

	while(ok){

		menu();
		scanf("%d", &opcao);

		if(iniFP == 0 && opcao > 1 && opcao < 7){
			printf("\nFila não inicializada\n\n");
			continue;
		}

		if(iniFP == 1 && opcao == 1){
			printf("\nFila ja inicializada\n\n");
			continue;
		}

		switch(opcao){

			case 1:
				f = cria_fp();
				if(f == NULL) printf("\nFalha\n\n");
				else{
					printf("\nSucesso\n\n");
					iniFP = 1;
				}

				break;

			case 2:
				printf("\nMatricula: ");
				scanf("%d", &al.matricula);
				printf("Nome: ");
				scanf(" %[^\n]", al.nome);
				printf("CRA: ");
				scanf("%lf", &al.cra);
				printf("Ano: ");
				scanf("%d", &al.ano);
				if(inserir(&f, &al) == 0) printf("\nFalha\n\n");
				else					 printf("\nSucesso\n\n");

				break;

			case 3:
				if(fp_vazia(f) == 1) printf("\nFila vazia\n\n");
				else{
					if(remover(&f, &al) == 0) printf("\nErro\n\n");
					else					  printf("\nAluno removido: %s\n\n", al.nome);
				}

				break;

			case 4:
				esvazia_fp(f);
				printf("\nSucesso\n\n");

				break;

			case 5:
				if(fp_vazia(f) == 1) printf("\nFila vazia\n\n");
				else{
					if(imprimir() == 0){
						printf("\nOcorreu um erro :(\n\n");
						opcao = 6;
					}
					else printf("\n");
				}

				break;

			case 6:
				printf("\nFim do programa\n");
				libera_fp(f);
				ok = 0;

				break;

			default:
				printf("\nOpcao invalida\n\n");


		}

	}

	return 0;
}
