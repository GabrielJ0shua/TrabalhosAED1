#include "tad.h"
#include <stdio.h>

int main(){
    deque* dq;
    elem aux;
    int opc, i,j = 0;

    do
    {
        printf("\n1 - Criar lista\n2 - Inserir\n3 - Remover\n4 - Consultar\n5 - Sair\n");
        scanf("%d",&opc);
        switch (opc)
        {
        case (1):
            if (j == 0)
            {
                dq = criaDeque();
                printf("\nPronto");
                j = 1;
            }
            else printf("Lista já criada");
            break;
        case (2):
            printf("\nInserir no Inicio (1) ou no Final(2):");
            scanf("%d",&i);
            switch (i)
            {
            case (1):
                printf("\nNúmero a ser inserido: ");
                scanf("%d",&aux.nu);
                insere_inicio(dq, aux);
                break;
            case (2):
                printf("\nNúmero a ser inserido: ");
                scanf("%d",&aux.nu);
                insere_final(dq, aux);
                break;
            default:
                printf("\nOpção invalida...");
                break;
            }
            break;
        case (3):
            printf("\nRemover no Inicio (1) ou no Final(2):");
            scanf("%d",&i);
            switch (i)
            {
            case (1):
                if(remove_inicio(dq, &aux)) printf("\n%d",aux.nu);
                else printf("\nErro...");
                break;
            case (2):
                if(remove_final(dq, &aux)) printf("\n%d",aux.nu);
                else printf("\nErro...");
                break;
            default:
                printf("\nOpção invalida...");
                break;
            }
            break;
        case (4):
            printf("\nConsultar no Inicio (1) ou no Final(2):");
            scanf("%d",&i);
            switch (i)
            {
            case (1):
                if(consultaInicio(dq, &aux)) printf("\n%d",aux.nu);
                else printf("\nErro...");
                break;
            case (2):
                if(consultaFinal(dq, &aux)) printf("\n%d",aux.nu);
                else printf("\nErro...");
                break;
            default:
                printf("\nOpção invalida...");
                break;
            }
            break;
        case (5):
            liberaDeque(dq);
            return 0;
            break;
        default:
            printf("\nOpção invalida...");
            break;
        }
    } while (1);
    liberaDeque(dq);
    return 1;
}