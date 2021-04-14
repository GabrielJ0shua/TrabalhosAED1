#include <stdio.h>
#include <string.h>
#include "tad.h"
  
int main(void){
    int i, aux1 =0;
    lista *l;
    Pass aux;
do
{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a posição do nome\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i)
    {
        case (1):
            l = cria();
            printf("\npronto");
        break;

        case (2):
            printf("\nQual o nome que deseja inserir? ");
            setbuf(stdin,NULL);
            gets(aux.nome);
            setbuf(stdin,NULL);
            printf("\nQual a matrícula: ");
            scanf("%u",&aux.mat);
            printf("\nQuanto de média: ");
            scanf("%f",&aux.me);
            printf("\nQuantas faltas: ");
            scanf("%d",&aux.fal);
            insere(l,&aux);
            aux1++;
        break;

        case (3):
            printf("\nQual a matricula que deseja apagar? ");
            scanf("%u",&aux.mat);
            rem(l,aux.mat);
            aux1--;
        break;

        case (4):
            printf("\nQual a matricula que deseja consultar? ");
            scanf("%u",&aux.mat);
            pos(l,aux.mat,&aux);
            printf("\n| %s | %u | %f | %d |",aux.nome,aux.mat,aux.me,aux.fal);
        break;

        case (5):
            if (aux1 == 0)
            {
                printf("\nSem dados.");
                break;
            }
            
            for ( i = 0; i < aux1; i++){
            imprime(l,i,&aux);
            printf("\n| %s | %u | %f | %d |",aux.nome,aux.mat,aux.me,aux.fal);    
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
