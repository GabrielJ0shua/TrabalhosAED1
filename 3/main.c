#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int opcao = 0, num, aux;
int iniL1 = 0, iniL2 = 0;
Lista L1, L2, L3;

void menu(){
    printf("\n");
    printf("[1] Criar Lista\n");
    printf("[2] Inserir Elemento\n");
    printf("[3] Remover Elemento\n");
    printf("[4] Imprimir Lista\n");
    printf("[5] Tamanho da Lista\n");
    printf("[6] Verificar se as listas sao iguais\n");
    printf("[7] Maior elemento\n");
    printf("[8] Esvaziar Lista\n");
    printf("[9] Intercalar Listas\n");
    printf("[10] Criar Lista 2\n");
    printf("[11] Sair\n");
    printf("\nDigite o numero correspondente a opcao desejada: ");
    printf("\n");
}

void imprimir_lista(Lista *li){

    int pos = 1;
    printf("\n{ ");
    while(get_pos(li, pos, &num) != 0){
        printf("%d ", num);
        pos++;
    }
    printf("}\n\n");

}

int main(){

    menu();

    do{
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        if(opcao < 1 || opcao > 11){
            printf("\nOperacao invalida\n");
            menu();
            continue;
        }

        if(iniL1 == 0 && opcao != 11 && opcao != 1 && opcao != 10){
            printf("\nLista nao inicializada.\n");
            menu();
            continue;
        }
    switch(opcao){
        case 1:
            if(iniL1 == 1){
                 printf("\nLista ja foi inicializada\n");
            }
            L1 = cria_lista();
            if(L1 != NULL) printf("\nFalha ao criar lista.\n");
            else{
                printf("\nLista criada com sucesso.\n");
                iniL1 = 1;
            }
                break;

        case 2:

            printf("\nDigite o elemento: \n");
            scanf("%d", &num);
            if(insere_elemento(&L1, num) == 0) printf("\nErro\n");
            else                               printf("\nElemento inserido com sucesso");

                break;

        case 3:

            printf("\nElementos da lista: \n");
            imprimir_lista(&L1);
            printf("Digite o elemento: \n");
            scanf("%d", &num);
            if(remove_elemento(&L1, num) == 0) printf("\nErro\n");
            else                           printf("\nElemento removido com sucesso");

                break;


        case 4:
            imprimir_lista(&L1);
                break;


        case 5:
            if(tamanho_lista(&L1, &num) == 0) printf("\nErro\n");
            else                              printf("\nTamanho: %d\n", num);

                break;


        case 6:
            if(iniL2 == 0){
                printf("Lista 2 ainda nao foi criada\n");
            }
            if(listas_iguais(&L1, &L2) == 0) printf("\nListas diferentes\n");
            else                             printf("\nListas  iguais\n");

            printf("Lista 1: ");
            imprimir_lista(&L1);
            printf("Lista 2: ");
            imprimir_lista(&L2);

                break;

         case 7:
            if(maior_elemento(&L1, &num) == 0) printf("\nErro\n");
            else                               printf("\nMaior elemento: %d\n", num);
                break;


          case 8:
            if(esvazia_lista(&L1) == 0) printf("\nErro ao esvaziar listas.\n");
            else                        printf("\nLista esvaziada com sucesso\n");

                break;


          case 9:
            if(iniL2 == 0){
                printf("Lista 2 ainda nao foi criada\n");
            }
            if(intercala_lista(&L1, &L2, &L3) == 0) printf("\nErro\n");
            else{
                printf("Sucesso ao intercalar listas\n");
                printf("Lista 1: ");
                imprimir_lista(&L1);
                printf("Lista 2: ");
                imprimir_lista(&L2);
                printf("Lista 3: ");
                imprimir_lista(&L3);
            }
                break;

        case 10:
            if(iniL2 == 1){
                libera_lista(&L2);
            }

            L2 = cria_lista();
            if(L2 != NULL){
                printf("Erro ao criar lista 2\n");
            }

            printf("Lista 2 criada com sucesso.\n");
            iniL2 = 1;

            printf("Deseja inserir um elemento?\n[1]Sim\n[2]Nao\n");
            printf("Opcao: ");
            scanf("%d", &num);
            while(num != 2){
                printf("\nDigite o elemento: \n");
                scanf("%d", &aux);
                insere_elemento(&L2, aux);
                printf("\nElemento inserido com sucesso.\n");
                printf("\nDeseja inserir um elemento?\n[1]Sim\n[2]Nao\n");
                printf("Opcao: ");
                scanf("%d", &num);
            }
            printf("Lista 2 criada com sucesso.\n");
            imprimir_lista(&L2);
                break;
    libera_lista(&L1);
    libera_lista(&L2);
    libera_lista(&L3);
    }

    }while(opcao != 11);



    return 0;
}
