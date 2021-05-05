#include "tad.h"
#include <stdio.h>
#include <math.h>
 
int main(void)
{
    //variáveis auxiliares e lista apontando para NULL.
    int opc,i,j,qnt = 0;
    float x;
    Termo equacao;
    Funcao *l;
    //Menu
    do
    {
        printf("\nEscolha uma opcao:\n1 - Inicializar um polinomio\n2-Inserir um novo termo ak*x^k no polinomio existente\n3-Imprimir P(x)\n4-Eliminar o termo associado a k-esima potencia\n5-Reinicializar um polinomio\n6-Calcular o valor de P(x) para um valor de x solicitado\n7-Sair do sistema\n");
        scanf("%d",&opc);
        switch(opc){
            //Iniciando a lista
            case(1):
                //libera(l);
                l = criaLista();
                printf("\nPronto");   
            break;
            //Inserindo o valor e verificando se deu certo
            case(2):
                printf("\nValor do termo Ak: ");
                setbuf(stdin,NULL);
                scanf("%d",&equacao.An);
                printf("\nValor do termo K: ");
                setbuf(stdin,NULL);
                scanf("%d",&equacao.Xn);
                i = inserirOrdenado(l,equacao);
                if (i == 1) printf("\nPronto");
                else printf("\nNão Inserido.");                
            break;
            //verificando se tem valores antes de imprimir e imprimir
            case(3):
                qnt = tamanhoDalista(l);
                printf("\n");
                
                for(i = qnt; i > 0;i++){
                    if (pegaValores(l,&equacao,i) == 0){
                        printf("\nNão foi possível...");
                        break;
                    }
                    printf(" %dX^%d ",equacao.An,equacao.Xn);
                }
            break;
            //Verificando se o valor existe antes de deduzir do auxiliar qnt para não perder quantos elementos tem
            case(4):
                printf("\nValor do termo K que deseja apagar: ");
                scanf("%d",&equacao.Xn);
                i = removeElemento(l,equacao.Xn);
                if (i == 1) printf("\nPronto");
                else printf("\nNão Removido.");
            break;
            //Limpa a equação por completo mas não libera a lista
            case(5):
               limpaEquacao(l);
               printf("\nPronto");
            break;
            //Calcula toda a função se ela existir
            case (6):
                j = 0;
                qnt = tamanhoDalista(l);
                printf("\nValor do termo X: ");
                scanf("%f",&x);
                for(i = qnt; i > 0;i++){
                    if (pegaValores(l,&equacao,i) == 0){
                        printf("\nNão foi possível...");
                        break;
                    }
                    j += (equacao.An) * (pow(x,(equacao.Xn)));
                }
                printf("\n %d\n",j);
            break;
            //libera a lista por completo e fecha o programa
            case (7):
                libera(l);
                return 0;
            break;

            default:
                printf("\nOpção Invalida...");
            break;
        } 
    }while (1);
    libera(l);
    return 1; //programa saiu dos casos então é erro, melhor encerrar por aqui
}