#include "tad.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
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
                        srand(time(NULL));
                        opc = (rand() % (tamanhoLista(l))) + 1; // o +1 me garante que não vai ser 0
                        printf("\nNúmero Sorteado para percorrimento %d",opc);
                        opc1 = 1;
                        i = tamanhoLista(l);
                        for(i = tamanhoLista(l);i > 2; i--){
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1,0))  
                                printf("\nEliminado: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                        
                        for(i = tamanhoLista(l);i <= 2; i--){
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1,0)){  
                                printf("\nGanhador: %s ",recruta.nome_do_soldado);
                                break;
                            }
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                    break;

                    case(2):
                        srand(time(NULL));
                        opc = (rand() % (tamanhoLista(l))) + 1; // o +1 me garante que não vai ser 0
                        printf("\nNúmero Sorteado para percorrimento %d",opc);
                        for(i = tamanhoLista(l);i > 2; i--){
                            opc1 = 2;
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1,0))  
                                printf("\nEliminado: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                        printf("\nNúmero Sorteado %d",opc1);
                        for(i = tamanhoLista(l);i <= 2; i--){
                            opc1 = 1;
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1,0)){  
                                printf("\nGanhador: %s ",recruta.nome_do_soldado);
                                break;
                            }
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                        }
                    break;

                    case(3):
                        srand(time(NULL));
                        opc = (rand() % (tamanhoLista(l))) + 1; // o +1 me garante que não vai ser 0
                        printf("\nNome do Soldado a ser procurado: ");
                        setbuf(stdin,NULL);
                        gets(recruta.nome_do_soldado);
                        setbuf(stdin,NULL);
                        opc1 = 3;
                        j = 1;
                        for(i = tamanhoLista(l);i > 2; i--){
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1,j))  
                                printf("\nEliminado: %s ",recruta.nome_do_soldado);
                            else{
                                printf("\nOcorreu algum problema...");
                                break;
                            }
                            j = 0;
                        }
                        opc1 = 1;
                        for(i = tamanhoLista(l);i <= 2; i--){
                            if(problemaDeJosephus( l, &recruta, &opc,&opc1,0)){  
                                printf("\nGanhador: %s ",recruta.nome_do_soldado);
                                break;
                            }
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