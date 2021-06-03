#include <stdlib.h>
#include "func.h"

struct Pilha{

	char info;
	struct Pilha *prox;

};

int pilha_vazia(pilha stk){

	if(stk == NULL) return 1;
	else			return 0;

}

int eh_valida(char *expressao){

	pilha stk = NULL;
	int i = 0, flag = 0;
	int parent = 0, colche = 0, chaves = 0;
	while(expressao[i] != '\0'){
		if(expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '['){
			pilha no = (pilha)malloc(sizeof(struct Pilha));
			if(no == NULL) return 0;

			if(expressao[i] == '{') chaves++;
			else if(expressao[i] == '(') parent++;
			else if(expressao[i] == '[') colche++; 

			no->info = expressao[i];
			no->prox = stk;
			stk = no;
		}
		else if(expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']'){

			if(expressao[i] == '}'){
				chaves--;
				if(chaves == 0 && parent > 0 || chaves == 0 && colche > 0){
					flag = 1;
					break;
				}
			}
			else if(expressao[i] == ']'){
				colche--;
				if(colche == 0 && parent > 0){
					flag = 1;
					break;
				}
			}

			if(pilha_vazia(stk) == 1){
				flag = 1;
				break;
			}
			if(expressao[i] - (stk)->info == 1 || expressao[i] - (stk)->info == 2){
				pilha aux = stk;
				stk = aux->prox;
				free(aux);
			}
			else{ 
				flag = 1;
				break;
			}
		}

		i++;
	}

	if(flag == 0 && pilha_vazia(stk) == 1) return 1;
	else return 0;
	
	while(stk != NULL){
		pilha aux = stk;
		stk = aux->prox;
		free(aux);
	}

}