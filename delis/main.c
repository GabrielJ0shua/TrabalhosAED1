#include <stdio.h>
#include "func.h"

int main(){

	char expressao[500];
	int op = 0;

	printf("Deseja inserir uma expressao?\n[1] Sim\n[2] Nao\nOpcao: ");
	scanf("%d", &op);
	while(op != 2){
		setbuf(stdin, NULL);
		printf("Digite a expressão: ");
		fgets(expressao, 500, stdin);
		if(eh_valida(expressao) == 0) printf("\nNao eh valida!\n\n");
		else						  printf("\nEh valida!\n\n");

		printf("Deseja inserir uma expressao?\n[1] Sim\n[2] Nao\nOpcao: ");
		scanf("%d", &op);
	}

	return 0;
}