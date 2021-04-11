#include "tad.h"
#include <stdio.h>
#include <string.h>

int main(void){
    int opc,opc1,i,j,aux2;
    char nome_do_soldado[20];
    Soldado l = iniciaLista();
    do{
        printf("\nEscolha uma opção:\n1 - Inserir o nome dos soldados que estão cercados \n2- Uma das opções para posição inicial da contagem\n3- Sair\n");
        scanf("%d",&opc);
        switch(opc){
            case(1):
                printf("\nSão quantos soldados? ");
                scanf("%d",&i);
                for (j = 0; j < i; j++){
                    printf("\nNome do Soldado %d: ",j+1);
                    setbuf(stdin,NULL);
                    gets(nome_do_soldado);
                    setbuf(stdin,NULL);
                    //inserir(l,nome_do_soldado);
                }
            break;

            case(2):
                printf("\n1.Iniciar contagem a partir do primeiro soldado da lista.\n2.Iniciar contagem a partir de uma posição sorteada aleatoriamente da lista.\n3.Iniciar contagem a partir de um soldado específico\n");       
                scanf("%d",&opc1);
                switch(opc1){
                    case(1):
                    break;

                    case(2):
                    break;

                    case(3):
                    break;

                    default:
                        printf("\nOpção Invalida...");
                    break;
                }   
            break;

            case(3):
                //libera_lista(l);
                return 0;
            break;
            default:
                printf("\nOpção Invalida...");
            break;
        }
    }while (1);
    return 1;
}
