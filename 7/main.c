#include "tad.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int opc,opc1,i,aux2;
    do
    {
        printf("\nEscolha uma opção:\n1 - Inserir o nome dos soldados que estão cercados \n2- Uma das opçõesparaa posição inicial dacontagem\n");
        scanf("%d",&opc);
        switch (opc)
        {
            case(1):
                
            break;

            case(2):
                printf("\n1.Iniciar contagem a partir do primeiro soldado da lista.\n2.Iniciar contagem a partir de uma posiçãosorteadaaleatoriamente da lista.\n3.Iniciar contagem a partir de um soldado específico");       
                scanf("%d",&opc1);
                switch (opc1)
                {
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
                
            break;
            default:
                printf("\nOpção Invalida...");
            break;
        }
    } while (1);
    return 1;
}
