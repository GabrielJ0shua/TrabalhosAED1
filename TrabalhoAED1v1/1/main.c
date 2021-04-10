#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tabela(){
    printf("\n\n===================\n");
    printf("[0] Reimprimir Menu\n");
    printf("[1] Criar Lista\n");
    printf("[2] Inserir elemento\n");
    printf("[3] Remover elemento\n");
    printf("[4] Remover impares\n");
    printf("[5] Imprimir Numero Em Posicao Especifica\n");
    printf("[6] Mostrar o menor elemento\n");
    printf("[7] Tamanho da lista\n");
    printf("[8] Imprimir a lista\n");
    printf("[9] Inverter lista\n");
    printf("[10] Concatenar listas\n");
    printf("[11] Esvaziar Lista\n");
    printf("[12] Encerrar Operacao\n");
}
 
int main(void){
    int i,numero,verificacao;
    int output;
    lista *li1 = NULL, *li2 = NULL, *li3 = NULL; 
    
    tabela();
    do{
        printf("\nInput de Operacao: ");
        scanf("%d",&i);
        printf("\n");
        switch (i){
            case 0:
                tabela();
            break;

            case (1):
                li1 = cria();
                printf("Criacao de Lista Requisitada\n");
            break;

            case (2):
                if(li1 == NULL){
                    printf("Lista Não Criada\nImpossivel Realizar Insercao\n");
                    break;
                    }
                else
                {
                    printf("Digite o numero que voce desejada inserir: ");
                    scanf("%d",&numero);
                    verificacao = insercao(li1, numero);
                    if (verificacao == 1)
                        printf("Inserido.\n");
                    else
                        printf("Nao inserido.\nLista Nao Alocada ou Quantidade Maxima Atingida\n");    
                }
            break;

            case (3):
                if(vazia(li1) == 1){
                    printf("Lista Vazia\nImpossivel Remover Elementos\n");
                    break;
                }
                
                printf("Digite o elemento a ser removido: ");
                scanf("%d",&numero);
                verificacao = remove_qualquer(li1,numero);
                if (verificacao == 1)
                    printf("Removido.\n");
                else printf("Nao removido.\nLista Um Vazia, Nao Alocada Ou Elemento Nao Presente\n");
            break;

            case (4):
                if(vazia(li1) == 1){
                    printf("Lista Vazia\nImpossivel Remover Elementos\n");
                    break;
                }
                verificacao = remove_impar(li1);
                if (verificacao == 1) printf("Impares Removidos\n");
                else printf("Falha Na Remocao dos Impares\nLista Nao ALocada ou Vazia\n");
            break;

            case (5):
                do{
                    printf("Digite a lista na qual voce quer consultar: ");
                    scanf("%d", &i);
                    switch(i){
                        case 1:
                            if(li1 == NULL || vazia(li1) == 1){
                                printf("Lista %d Nao Alocada ou Vazia\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            printf("Digite a posicao a ser acessada na lista: ");
                            scanf("%d", &numero);

                            verificacao = consulta_qualquer(li1, numero, &output);
                            if(verificacao == 0){
                                printf("Lista %d Nao Alocada, Vazia ou Posicao Passada Nao Existente\n", i);
                            }
                            else if(verificacao == 1){
                                printf("[%d] %d\n", numero, output);
                            } 
                        break;

                        case 2:
                            if(li2 == NULL || vazia(li2) == 1){
                                printf("Lista %d Nao Alocada ou Vazia\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            printf("Digite a posicao a ser acessada na lista: ");
                            scanf("%d", &numero);

                            verificacao = consulta_qualquer(li2, numero, &output);
                            if(verificacao == 0){
                                printf("Lista %d Nao Alocada, Vazia ou Posicao Passada Nao Existente\n", i);
                            }
                            else if(verificacao == 1){
                                printf("[%d] %d\n", numero, output);
                            } 
                        break;

                        case 3:
                            if(li3 == NULL || vazia(li3) == 1){
                                printf("Lista %d Nao Alocada ou Vazia\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            printf("Digite a posicao a ser acessada na lista: ");
                            scanf("%d", &numero);

                            verificacao = consulta_qualquer(li3, numero, &output);
                            if(verificacao == 0){
                                printf("Lista %d Nao Alocada, Vazia ou Posicao Passada Nao Existente\n", i);
                            }
                            else if(verificacao == 1){
                                printf("[%d] %d\n", numero, output);
                            } 
                        break;
                    }
                    if(i < 1 || i > 3){
                        printf("Lista Invalida\nTente Novamente\n");       
                    }
                }while(i < 1 || i > 3);
            break;

            case (6):
                do{
                    printf("Digite a lista na qual voce quer consultar o menor: ");
                    scanf("%d", &i);
                    switch(i){
                        case 1:
                            if(li1 == NULL || vazia(li1) == 1){
                                printf("Lista %d Nao Alocada ou Vazia\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            verificacao = consulta_menor(li1, &output);
                            if(verificacao == 0){
                                printf("Lista %d Nao Alocada ou Vazia\n", i);
                            }
                            else if(verificacao == 1){
                                printf("O menor numero na lista %d eh %d\n", i, output);
                            } 
                        break;

                        case 2:
                            if(li2 == NULL || vazia(li2) == 1){
                                printf("Lista %d Nao Alocada ou Vazia\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            verificacao = consulta_menor(li2, &output);
                            if(verificacao == 0){
                                printf("Lista %d Nao Alocada ou Vazia\n", i);
                            }
                            else if(verificacao == 1){
                                printf("O menor numero na lista %d eh %d\n", i, output);
                            } 
                        break;

                        case 3:
                            if(li3 == NULL || vazia(li3) == 1){
                                printf("Lista %d Nao Alocada ou Vazia\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            verificacao = consulta_menor(li3, &output);
                            if(verificacao == 0){
                                printf("Lista %d Nao Alocada ou Vazia\n", i);
                            }
                            else if(verificacao == 1){
                                printf("O menor numero na lista %d eh %d\n", i, output);
                            }
                        break;
                    }

                    if(i < 1 || i > 3){
                        printf("Lista Invalida\nTente Novamente\n");       
                    }
                }while(i < 1 || i > 3);
            break;

            case (7):
                do{
                    printf("Digite a lista da qual voce quer o tamanho: ");
                    scanf("%d", &i);
                    switch(i){
                        case 1:
                            if(li1 == NULL){
                                printf("Lista %d Nao Alocada\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            numero = tamanho(li1);
                            printf("A lista %d tem %d elementos\n", i, numero);
                        break;

                        case 2:
                            if(li2 == NULL){
                                printf("Lista %d Nao Alocada\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            numero = tamanho(li2);
                            printf("A lista %d tem %d elementos\n", i, numero);
                        break;

                        case 3:
                            if(li3 == NULL){
                                printf("Lista %d Nao Alocada\nImpossivel Realizar Consulta\n", i);
                                break;
                            }

                            numero = tamanho(li3);
                            printf("A lista %d tem %d elementos\n", i, numero);
                        break;
                    }
                    if(i < 1 || i > 3){
                        printf("Lista Invalida\nTente Novamente\n");       
                    }
                }while(i < 1 || i > 3);
            break;
            
            case (8):
                do{
                    printf("Digite a lista a ser impressa: ");
                    scanf("%d", &i);
                    int k;
                    switch(i){
                        case 1:
                            if(li1 == NULL || vazia(li1) == 1){
                                printf("Lista %d Vazia ou Nao Alocada\nImpossivel Realizar Impressao\n", i);
                                break;
                            }

                            printf(" ---- Lista %d ---- \n", i);
                            for(k = 0; k < tamanho(li1); k++){
                                consulta_qualquer(li1, k+1, &output);
                                printf("[%d] %d\n", k+1, output);
                            }
                        break;

                        case 2:
                            if(li2 == NULL || vazia(li2) == 1){
                                printf("Lista %d Vazia ou Nao Alocada\nImpossivel Realizar Impressao\n", i);
                                break;
                            }

                            printf(" ---- Lista %d ---- \n", i);
                            for(k = 0; k < tamanho(li2); k++){
                                consulta_qualquer(li2, k+1, &output);
                                printf("[%d] %d\n", k+1, output);
                            }
                        break;

                        case 3:
                            if(li3 == NULL || vazia(li3) == 1){
                                printf("Lista %d Vazia ou Nao Alocada\nImpossivel Realizar Impressao\n", i);
                                break;
                            }

                            printf(" ---- Lista %d ---- \n", i);
                            for(k = 0; k < tamanho(li3); k++){
                                consulta_qualquer(li3, k+1, &output);
                                printf("[%d] %d\n", k+1, output);
                            }
                        break;
                    }
                    if(i < 1 || i > 3){
                        printf("Lista Invalida\nTente Novamente\n");       
                    }
                }while(i < 1 || i > 3);
            break;

            case (9):
                if(li1 == NULL || vazia(li1) == 1 ){
                    printf("Lista Um Vazia ou Nao Criada\nImpossivel Inverter e Criar Lista Dois\n");
                    break;
                }

                li2 = cria();
                if(li2 == NULL){
                    printf("Falha ao Criar Lista Inversa\n");
                    break;
                }
                verificacao = inverter_lista(li1, li2);

                if(verificacao == 0)
                    printf("Falha na inversao\n");
                else if(verificacao == 1)
                    printf("Sucesso na inversao\n");
            break;

            case (10):
                if(li1 == NULL || li2 == NULL || vazia(li1) == 1 || vazia(li2) == 1){
                    printf("Lista Um e/ou Dois Vazias ou Nao Criadas\nImpossivel Concatenar\n");
                    break;
                }

                li3 = cria();
                if(li3 == NULL){
                    printf("Falha ao Criar Lista Concatenada\n");
                    break;
                }

                verificacao = concatenar(li1, li2, li3);
                if(verificacao == 0){
                    printf("Falha na concatenacao\n");
                }
                else if(verificacao == 2){
                    printf("Falha na concatenacao\nO tamanho da lista concatenada excederia o tamanho maximo\n");
                }
                else if(verificacao == 1){
                    printf("Sucesso\n");
                }
            break;

            case (11):
                
                do{
                    printf("Digite a lista a ser esvaziada: ");
                    scanf("%d", &i);
                }while(i < 1 || i > 3);

                switch(i){
                    case 1:
                        libera(li1);
                        printf("Lista um esvaziada\n");
                    break;

                    case 2:
                        libera(li2);
                        printf("Lista dois esvaziada\n");
                    break;

                    case 3:
                        libera(li3);
                        printf("Lista tres esvaziada\n");
                    break;
                }
            break;
        }
    } while (i != 12);
    return 1;
}