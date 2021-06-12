#include <stdio.h>
#include "tad.h"

int opcao = 0, iniFP = 0;
Fila f;
aluno al;

void menu(){

	printf("Menu: \n");
	printf("[1] - Cria Fila de Prioridade\n[2] - Inserir\n[3] - Remover\n[4] - Esvaziar\n[5] - Imprimir\n[6] - Sair\nOpcao: ");

}

int imprimir(){

	Fila aux;
	aux = cria_fp();
	if(aux != NULL){ //se for bem sucedida a cria fila entra no codigo
		printf("\nFila de Prioridade:\n");
		while(remover(f, &al) != 0){ //enquanto o remover for bem sucedido, pega elemento da fila original e printa
			printf("[%d - %s - %.2lf - %d]\n", al.matricula, al.nome, al.cra, al.ano);
			if(inserir(aux, &al) == 0){ //insere na fila auxiliar mas se falhar
				libera_fp(&aux); // libera a fila auxiliar pra limpar tudo incluindo os que foram inseridos ja
				return 0;
			}
		}
		while(remover(aux, &al) != 0){ //se o remover não falhar, remove da fila 2
			if(inserir(f, &al) == 0){ //insere na fila 1
				libera_fp(&aux); //se no meio do caminho falha a inserção na fila original, libera a fila aux
				return 0;
			}
		}
		libera_fp(&aux); //libera a fila 2 auxiliar e retorna sucesso
		return 1;
	}
	return 0; //só ocorre se falhar o cria fila

int main(){

	int ok = 1; //flag

	while(ok){

		menu();
		scanf("%d", &opcao);

		if(iniFP == 0 && opcao > 1 && opcao < 7){ //só faz qualquer coisa se tiver inicializado a fila
			printf("\nFila nao inicializada\n\n");
			continue;
		}

		if(iniFP == 1 && opcao == 1){ //só inicializa uma unica vez
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
				scanf(" %[^\n]", al.nome); //dessa forma lê até a quebra de linha(/n), incluindo espaço
				printf("CRA: ");
				scanf(" %lf", &al.cra);
				printf("Ano: ");
				scanf(" %d", &al.ano);
				if(inserir(f, &al) == 0) printf("\nFalha\n\n");
				else					 printf("\nSucesso\n\n");

				break;

			case 3:
				if(fp_vazia(f) == 1) printf("\nFila de Prioridade vazia\n\n");
				else{
					if(remover(f, &al) == 0) printf("\nErro\n\n");
					else					  printf("\nAluno removido: %s\n\n", al.nome);
				}

				break;

			case 4:
				esvazia_fp(f);
				printf("\nSucesso\n\n");

				break;

			case 5:
				if(fp_vazia(f) == 1) printf("\nFila de Prioridade vazia\n\n");
				else{
					if(imprimir() == 0){
						printf("\nErro\n\n");
						opcao = 6; //vai pra operação 6, libera a lista e termina o programa
					}
					else printf("\n");
				}

				break;

			case 6:
				printf("\nFim do programa\n");
				libera_fp(&f);
				ok = 0;

				break;

			default:
				printf("\nOpcao invalida\n\n");


		}

	}

	return 0;
}
