#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include <time.h>

int op = 0, iniLi = 0, operacao, contagem = 0, pos, tamanho;
Lista li;
char nome[50];

void menu(){

    printf("[1] Criar Lista\n[2] Inserir Soldado\n");
    printf("[3] Iniciar Contagem\n[4] Imprimir Lista\n");
    printf("[5] Sair\nDigite a Opcao Desejada: ");

}

void imprimir(Lista *li){

    if(li != NULL){
        pos = 1;
        printf("\nSoldados da Lista:\n\n");
        while(get_pos(li, pos, nome) != 0){ 
            printf("[%d] %s", pos, nome);
            pos++;
        }
        printf("\n");
    }

}

int main(){

    srand(time(NULL));

    while(op != 5){

        menu();
        scanf("%d", &op);

        if(iniLi == 0 && op > 1 && op < 5){
            printf("\n### LISTA NAO INICIALIZADA ###\n\n");
            continue;
        }

        switch(op){


            case 1:

                li = cria_lista();
                if(li == NULL) printf("\n### FALHA ###\n\n");
                else{
                    printf("\n### SUCESSO ###\n\n");
                    iniLi = 1;
                }

                break;

            case 2:

                printf("\nDigite o Nome do Soldado: ");
                setbuf(stdin, NULL);
                fgets(nome, 50, stdin);
                if(insere_elem(&li, nome) == 0) printf("\n### FALHA ###\n\n");
                else                            printf("\n ### SUCESSO ###\n\n");

                break;

            case 3:

                printf("\nComo Deseja Iniciar a Contagem?\n");
                printf("[1] A partir do primeiro soldado\n");
                printf("[2] A partir de uma posicao aleatoria\n");
                printf("[3] A partir de um soldado especifico\n");
                printf("Opcao: ");
                scanf("%d", &operacao);
                
                tamanho_lista(&li, &tamanho);
                contagem = (rand() % tamanho) + 1;

                if(operacao == 1){
                    pos = 1;
                    printf("\nSoldados Removidos:\n");
                    while(remove1(&li, contagem, &pos, nome) != 0){
                        printf("%s", nome);

                    }

                    printf("\nNumero Sorteado para Contagem: %d\n", contagem);
                    printf("\nSoldado Sobrevivente: %s", nome);

                    esvaziar_lista(&li);

                    printf("\nLista Esvaziada! \n\n");
                }
                if(operacao == 2){
                    pos = (rand() % tamanho) + 1;
                    get_pos(&li, pos, nome);
                    printf("\nSoldado Sorteado: %s", nome);
                    printf("\nSoldados Removidos:\n");
                    while(remove1(&li, contagem, &pos, nome) != 0){
                        printf("%s", nome);

                    }

                    printf("\nNumero Sorteado para Contagem: %d\n", contagem);
                    printf("\nSoldado Sobrevivente: %s", nome);

                    esvaziar_lista(&li);

                    printf("\nLista Esvaziada! \n\n");
                }

                if(operacao == 3){
                    imprimir(&li);
                    printf("\nNome do Soldado: ");
                    setbuf(stdin, NULL);
                    fgets(nome, 50, stdin);
                    if(get_soldado(&li, &pos, nome) == 0) printf("\n Soldado nao esta na lista\n\n");
                    else{
                        printf("\nSoldados Removidos:\n");
                    while(remove1(&li, contagem, &pos, nome) != 0){
                        printf("%s", nome);

                    }

                    printf("\nNumero Sorteado para Contagem: %d\n", contagem);
                    printf("\nSoldado Sobrevivente: %s", nome);

                    esvaziar_lista(&li);

                    printf("\nLista Esvaziada! \n\n");
                    }
                }

                break;

            case 4:

                imprimir(&li);
                break;

            case 5:

                printf("\n\n### FIM DO PROGRAMA ###\n\n");
                libera_lista(&li);
                break;

            default:

                printf("\n### OPCAO INVALIDA ###\n\n");

        }

    }

    return 0;
}