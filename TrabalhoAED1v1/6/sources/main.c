#include <stdio.h>
#include "..\headers\duplo-nord.h"

void tabela(){
    printf("--- Tabela de Operacoes ---\n");
    printf("[0] Reimprimir Tabela\n");
    printf("[1] Inicializar Lista\n");
    printf("[2] Inserir Dados\n");
    printf("[3] Remover Dados\n");
    printf("[4] Remover Todas as Ocorrencias\n");
    printf("[5] Remover Maior Elemento\n");
    printf("[6] Esvaziar Lista\n");
    printf("[7] Criar Lista Inversa\n");
    printf("[8] Criar Lista de Multiplos de 3\n");
    printf("[9] Imprimir Lista\n");
    printf("[10] Encerrar Operacao\n");
}

int main(){
    list fstLst, sndLst, trdLst;
    int operador;
    int flag[3] = {0,0,0};
    int input;
    int output;
    int retorno;
    int i;

    tabela();

    do{
        printf("\nInserir Operador: ");
        scanf("%d", &operador);
        switch(operador){
            case 0:
                tabela();
            break;

            case 1:
                if(flag[0] == 1){
                    printf("Lista ja inicializada\n");
                    break;
                }
                fstLst = initializeList();
                flag[0] = 1;
                printf("Lista inicializada\n");
            break;

            case 2:
                if(flag[0] == 0){
                    printf("Lista nao inicializada\nImpossivel Inserir na Lista\n");
                    break;
                }
                printf("Input de Insercao: ");
                scanf("%d", &input);
                retorno = insertNode(&fstLst, input);
                if(retorno == 0)
                    printf("Falha na alocacao do novo no\n");
                if(retorno == 1)
                    printf("Sucesso na insercao do novo no\n");
            break;

            case 3:
                if(flag[0] == 0 || emptyList(&fstLst) == 1){
                    printf("Lista nao Inicializada ou Vazia\nImpossivel Remover da Lista\n");
                    break;
                }
                printf("Input de Remocao: ");
                scanf("%d", &input);
                retorno = removeNode(&fstLst, input);
                if(retorno == 0)
                    printf("Falha na remocao do no\nLista Vazia ou Elemento nao Presente\n");
                if(retorno == 1)
                    printf("Sucesso na remocao\n");
            break;

            case 4:
                if(flag[0] == 0 || emptyList(&fstLst) == 1){
                    printf("Lista nao Inicializada ou Vazia\nImpossivel Remover da Lista\n");
                    break;
                }
                printf("Input de Remocao (Todas Ocorrencias): ");
                scanf("%d", &input);
                removeAll(&fstLst, input);
                printf("Todas as ocorrencias do elemento %d foram removidas da 1a lista\n", input);
            break;
            
            case 5:
                if(flag[0] == 0 || emptyList(&fstLst) == 1){
                    printf("Lista nao Inicializada ou Vazia\nImpossivel Remover da Lista\n");
                    break;
                }
                printf("Remocao do Maior Elemento da Lista Requisitada\n");
                removeGreater(&fstLst, &output);
                printf("\nO elemento %d era o maior da lista\nRemocao Concluida\n", output);
            break;

            case 6:
                if(flag[0] == 0 || emptyList(&fstLst) == 1){
                    printf("Lista nao Inicializada ou Vazia\nImpossivel Esvazia-la\n");
                    break;
                }
                printf("Limpeza de Lista Requisitada\n");
                clearList(&fstLst);
                printf("\nLista Limpa\n");
            break;

            case 7:
                if(flag[0] == 0 || emptyList(&fstLst)){
                    printf("Lista Um Nao Inicializada ou Vazia\nImpossivel Criar Sua Inversa\n");
                    break;
                }
                else if(flag[0] == 1 && flag[1] == 0){
                    flag[1] = 1;
                    sndLst = initializeList();
                    reverseList(&fstLst, &sndLst);
                    printf("Lista Inversa Criada\n");
                    break;
                }
                else if(flag[1] == 1){
                    printf("Lista Dois ja foi inicializada uma vez\n");
                    printf("Prosseguir com a operacao significa esvazia-la e recria-la\n");
                    printf("Caso tenha havido alguma alteracao na Lista Um desde a criacao previa da Lista Dois os dados antigos serao perdidos\n");
                    printf("Deseja prosseguir?\n");
                    printf("[1] Sim\n[2] Nao\n");
                    printf("\nInput de Confirmacao: ");
                    scanf("%d", &operador);
                    switch(operador){
                        case 1:
                            printf("Confirmada a sobrescricao\n");
                            clearList(&sndLst);
                            reverseList(&fstLst, &sndLst);
                            printf("Lista Inversa Recriada\n");
                        break;
                        
                        case 2:
                            printf("Sobrescricao Cancelada\n");
                        break;
                    }
                }
                
            break;

            case 8:
                if(flag[0] == 0 || emptyList(&fstLst)){
                    printf("Lista Um Nao Inicializada ou Vazia\nImpossivel Criar Lista Com Multiplos de Tres\n");
                    break;
                }
                else if(flag[0] == 1 && flag[2] == 0){
                    flag[2] = 1;
                    trdLst = initializeList();
                    threeMultiList(&fstLst, &trdLst);
                    printf("Lista de Multiplos de Tres Criada\n");
                    break;
                }
                else if(flag[2] == 1){
                    printf("Lista Tres ja foi inicializada uma vez\n");
                    printf("Prosseguir com a operacao significa esvazia-la e recria-la\n");
                    printf("Caso tenha havido alguma alteracao na Lista Um desde a criacao previa da Lista Tres os dados antigos serao perdidos\n");
                    printf("Deseja prosseguir?\n");
                    printf("[1] Sim\n[2] Nao\n");
                    printf("\nInput de Confirmacao: ");
                    scanf("%d", &operador);
                    switch(operador){
                        case 1:
                            printf("Confirmada a sobrescricao\n");
                            clearList(&trdLst);
                            threeMultiList(&fstLst, &trdLst);
                            printf("Lista de Multiplos de Tres Recriada\n");
                        break;
                        
                        case 2:
                            printf("Sobrescricao Cancelada\n");
                        break;
                    }
                }
            break;

            case 9:
                printf("Escolha qual lista imprimir:\n");
                printf("[1] Primeira Lista\n");
                printf("[2] Segunda Lista (Inverso da Primeira)\n");
                printf("[3] Terceira Lista (Multiplos de 3 da Primeira)\n");

                printf("\nInput de Impressao: ");
                scanf("%d", &operador);

                switch(operador){
                    case 1:
                        if(flag[0] == 0 || emptyList(&fstLst) == 1){
                            printf("Lista Nao Inicializada ou Vazia\nImpossivel Imprimir\n");
                            break;
                        }
                        i = 1;
                        printf("Lista Um:\n");
                        do{
                            retorno = getValue(&fstLst, &output, i);
                            if(retorno == 0)
                                break;
                            printf("[%d] %d\n", i, output);
                            i++;
                        }while(retorno == 1);
                    break;
                    
                    case 2:
                        if(flag[0] == 0 || emptyList(&fstLst) == 1 || flag[1] == 0){
                            printf("Lista Um Nao Inicializada, Vazia ou Lista Dois Nao Inicializada\nImpossivel Imprimir\n");
                            break;
                        }
                        i = 1;
                        printf("Lista Dois:\n");
                        do{
                            retorno = getValue(&sndLst, &output, i);
                            if(retorno == 0)
                                break;
                            printf("[%d] %d\n", i, output);
                            i++;
                        }while(retorno == 1);
                    break;

                    case 3:
                        if(flag[0] == 0 || emptyList(&fstLst) == 1 || flag[2] == 0 || emptyList(&trdLst)){
                            printf("Lista Um Nao Inicializada, Vazia, Lista Tres Nao Inicializada Ou Vazia\nImpossivel Imprimir\n");
                            break;
                        }
                        i = 1;
                        printf("Lista Tres:\n");
                        do{
                            retorno = getValue(&trdLst, &output, i);
                            if(retorno == 0)
                                break;
                            printf("[%d] %d\n", i, output);
                            i++;
                        }while(retorno == 1);
                    break;
                }
            break;
        }
    }while(operador != 10);

    printf("Encerramento de Operacao Requisitado\nFim do Programa\n");

    return 0;
}