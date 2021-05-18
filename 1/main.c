#include <stdio.h>
#include "1.h"

int numero, op;
Pilha p;

int conversao(int numero, int op){

	if(numero == 0){//se o numero para conversao for zero, so empilho o proprio zero
		if(push(p, 0) == 1) return 1;
		else				return 0;//se falhar aqui, n preciso limpar minha pilha, ja q nada foi empilhado
	}									//logo so retorno falha

	int divisor;//usuario que escolhe a 'op'
	if(op == 1) divisor = 2;//op = 1, conversao para binario
	else if(op == 2) divisor = 8;//op = 2, conversao para octal
	else if(op == 3) divisor = 16;//op = 3, conversao para hexa

	while(numero > 0){//faco divisoes sucessivas e vou empilhando o mod de cada divisao
		if(push(p, numero % divisor) == 0){//se falhar no meio da conversao, preciso tirar aquilo q 
			esvazia(p);				//ja foi empilhado e depois retornar falha (zero)
			return 0;
		}
		else numero /= divisor;
	}

	return 1;

}

void imprimir(Pilha p){

	while(pop(p, &numero) != 0){//vou desempilhando e mostrando o resultado na tela
		if(numero >= 10){//caso o numero tenha 2 digitios, preciso converte-lo para alguma letra
			numero += 55;//55 pq o 'A' na tabela ascii eh 65 e o menor numero q irei converter eh o 10, logo, 65-10 = 55
			printf("%c", numero);	//%c em uma variavel int? sim! me poupa o trabalho de criar uma variavel char			
		}
		else printf("%d", numero);//se o numero tiver um unico digito, so imprimo ele normalmente
	}
	
	printf("\n\n");

}

int main(){

	p = cria_pilha();
	if(p == NULL) printf("\nFalha ao criar pilha\n\n");
	else{

		printf("### CONVERSOES DE NUMEROS POSITIVOS ###\n\n");

		while(1){

			printf("Digite um numero: ");
			scanf("%d", &numero);
			if(numero < 0){ 
				printf("\nFim do programa\n\n");
				libera(p);
				break;
			}
			while(1){
				printf("Converter para: [1] Binario ; [2] Octal ; [3] Hexadecimal\n");
				printf("Opcao: ");
				scanf("%d", &op);
				if(op != 1 && op != 2 && op != 3) printf("\nOpcao invalida\n\n");
				else break;
			}
			if(conversao(numero, op) == 0) printf("\nErro\n\n");
			else{
				printf("Resultado: ");
				imprimir(p);
			}
		}
	}

	return 0;
}