#include "tad.h"
#include <stdio.h>
#include <string.h>
 
int main(void){
    int opc,opc1,i,j,aux2;
    dado Soldado;
    Batalhao* l = iniciaLista();
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
                    gets(Soldado.nome_do_soldado);
                    setbuf(stdin,NULL);
                    insereInicio(l,Soldado);
                }
            break;

            case(2):
                printf("\n1.Iniciar contagem a partir do primeiro soldado da lista.\n2.Iniciar contagem a partir de uma posição sorteada aleatoriamente da lista.\n3.Iniciar contagem a partir de um soldado específico\n");       
                scanf("%d",&opc1);
                switch(opc1){
                    case(1):
                        printf("\nDe quantas em quantas posições será removido os soldados? ");
                        scanf("%d",&opc);
                        for(i = tamanhoLista(l); 0 < i; i = tamanhoLista(l)){
                            j = problemaDeJosephus( l, &Soldado, opc,1);
                            if(j == 1)  printf("\n %s ",Soldado.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                    break;

                    case(2):
                        for(i = 0; i < j; i++,j = tamanhoLista(l)){
                            if(problemaDeJosephus( l, &Soldado, 0,2))  printf("\n %s ",Soldado.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                    break;

                    case(3):
                        printf("\nNome do Soldado %d: ",j+1);
                        setbuf(stdin,NULL);
                        gets(Soldado.nome_do_soldado);
                        setbuf(stdin,NULL);
                        printf("\nDe quantas em quantas posições será removido os soldados? ");
                        scanf("%d",&opc);
                        for(i = tamanhoLista(l); 0 < i; i = tamanhoLista(l)){
                            if(problemaDeJosephus( l, &Soldado, opc,3))  printf("\n %s ",Soldado.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                    break;

                    default:
                        printf("\nOpção Invalida...");
                    break;
                }   
            break;

            case(3):
                liberaLista(l);
                return 0;
            break;
            default:
                printf("\nOpção Invalida...");
            break;
        }
    }while (1);
    return 1;
}