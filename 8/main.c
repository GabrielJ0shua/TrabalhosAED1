#include "tad.h"
#include <stdio.h>

int main(void)
{
    //variáveis auxiliares e lista apontando para NULL.
    int opc,i,qnt = 0;
    float x;
    Termo equacao;
    Funcao *l;
    //Menu
    do
    {
        printf("\nEscolha uma opção:\n1 - Inicializar um polinômio\n2-Inserir um novo termo ak*x^k no polinômio existente\n3-Imprimir P(x)\n4-Eliminar o termo associado à k-ésima potência\n5-Reinicializar um polinômio\n6-Calcular o valor de P(x) para um valor de x solicitado\n7-Sair do sistema\n");
        scanf("%d",&opc);
        switch(opc){
            //Iniciando a lista
            case(1):
            l = criaLista();
            printf("\nPronto");   
            break;
            //Inserindo o valor e verificando se deu certo
            case(2):
                printf("\nValor do termo Ak: ");
                scanf("%d",equacao.An);
                printf("\nValor do termo K: ");
                scanf("%d",equacao.Xn);
                //i = inserirOrdenado(l,equacao);
                if (i == 1)
                {
                    printf("\nPronto");
                    qnt++;
                }
                else printf("\nNão Inserido.");                
            break;
            //verificando se tem valores antes de imprimir e imprimir
            case(3):/*
                for(i = 0; i <qnt;i++){
                    if (pegaValores(l,&equacao) == 0){
                        printf("\nNão foi possível...");
                        break;
                    }
                    printf(" %.2fX^%.2f ",equacao.aux,equacao.aux1);
                }*/
            break;
            //Verificando se o valor existe antes de deduzir do auxiliar qnt para não perder quantos elementos tem
            case(4):
                //i = removeElemento(l,x);
                if (i == 1)
                {
                    printf("\nPronto");
                    qnt--;
                }
                else printf("\nNão Removido.");
            break;
            //Limpa a equação por completo mas não libera a lista
            case(5):
               //limpaEquacao(l);
               qnt = 0;
            break;
            //Calcula toda a função se ela existir
            case (6):
                printf("\nValor do termo X: ");
                scanf("%f",x);
                //i = calculoPolinomio(l,&x);
                if (i == 1)
                {
                    printf("\nPronto");
                    qnt--;
                }
                else printf("\nNão calculado.");
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
    return 1; //programa saiu dos casos então é erro, melhor encerrar por aqui
}