#include <stdio.h>
#include "tad.h"

int main(void){
    int i,j,aux = 0;
    lista *l;
do
{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a posição do número\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i){
        case (1):
            l = cria();
            printf("\npronto\n");
        break;

        case (2):
            printf("\nQual o número que deseja inserir? ");
            scanf("%d",&j);
            ord(l,j);
            aux++;
        break;

        case (3):
            printf("\nQual o número que deseja apagar? ");
            scanf("%d",&j);
            rem(l,j);
            aux--;
        break;
 
        case (4):
            printf("\nQual o número que deseja consultar? ");
            scanf("%d",&i);
            pos(l,i,&j);
            printf("%d",j);
        break;

        case (5):
        for ( i = 0; i < aux; i++){
            imprime(l,i,&j);
            printf("\n %d\n",j);    
        }
        break;

        case (6):
            libera(l);
            l = cria();
        break;

        case (7):
            libera(l);
            return 0;
        break;

        default:
            printf("opção inválida");
        break;
    }
} while (i>0 && i<8);
return 1;
} 