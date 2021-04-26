#include "tad.h"
#include <stdio.h>
#include <string.h>
 
int main(void){
    int opc,opc1,i,j,aux2;
    dado recruta;
    Batalhao* l = iniciaLista();
    do{
        printf("\nEscolha uma opção:\n1 - Inserir o nome dos soldados que estão cercados \n2- Uma das opções para posição inicial da contagem\n3- Sair\n");
        scanf("%d",&opc);
        switch(opc){
            case(1):
                liberaLista(l);
                printf("\nSão quantos soldados? ");
                scanf("%d",&i);
                for (j = 1; j < i+1; j++){
                    printf("\nNome do Soldado %d: ",j);
                    setbuf(stdin,NULL);
                    gets(recruta.nome_do_soldado);
                    setbuf(stdin,NULL);
                    insereFinal(l,recruta);
                }
            break;

            case(2):
                printf("\n1.Iniciar contagem a partir do primeiro soldado da lista.\n2.Iniciar contagem a partir de uma posição sorteada aleatoriamente da lista.\n3.Iniciar contagem a partir de um soldado específico\n");       
                scanf("%d",&opc1);
                switch(opc1){
                    case(1):
                        printf("\nDe quantas em quantas posições será removido os soldados? ");
                        scanf("%d",&opc);
                        opc1 = 1;
                        i = tamanhoLista(l);
                        while (i != 1){
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1))  
                                printf("\nEliminado: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            i = tamanhoLista(l);
                        }
                        while (i = 1){
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1))  
                                printf("\nGanhador: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            i = tamanhoLista(l);
                        }
                    break;

                    case(2):
                        while (i >= 2){
                            opc1 = 2;
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1))  
                                printf("\nEliminado: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            i = tamanhoLista(l);
                        }
                        printf("\nNúmero Sorteado %d",opc1);
                        while (i != 0){
                            opc1 = 1;
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1))  
                                printf("\nGanhador: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            i = tamanhoLista(l);
                        }
                    break;

                    case(3):
                        printf("\nNome do Soldado a ser procurado: ");
                        setbuf(stdin,NULL);
                        gets(recruta.nome_do_soldado);
                        setbuf(stdin,NULL);
                        printf("\nDe quantas em quantas posições será removido os soldados? ");
                        scanf("%d",&opc);
                        while (i < 2){
                            opc1 = 3;
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1))  
                                printf("\nEliminado: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            i = tamanhoLista(l);
                        }
                        while (i != 0){
                            opc1 = 1;
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1))  
                                printf("\nGanhador: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            i = tamanhoLista(l);
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