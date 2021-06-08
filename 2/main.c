#include "fila.h"
#include <stdio.h>
#include <string.h>

int main(){
    Pilha* pi = cria_pilha();
    Parte aux;
    int opc, i, j = 0;
    char express[20];

    do{
        printf("\n1 - Entra com a expressão\n2 - Sair\n");
        scanf("%d",&opc);
        switch (opc){
        case (1):
            printf("\nDigite a expressão: ");
            gets(express);
            avaliaçãoDaExpressao(pi, express);
            break;

        case (2):
            liberaPilha(pi);
            return 0;
            break;

        default:
            printf("\nOpção invalida...");
            break;

        }
    } while (1);

    liberaDeque(pi);
    return 1;
}