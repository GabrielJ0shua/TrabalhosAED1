#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "josephius.h"

void tabela(){
    printf("---Tabela de Operacoes---\n");
    printf("[1] Inicializar Lista\n");
    printf("[2] Adicionar Soldado\n");
    printf("[3] Iniciar Contagem do Primeiro\n");
    printf("[4] Iniciar Contagem de Posicao Aleatoria\n");
    printf("[5] Iniciar Contagem a Partir de Soldado Especifico\n");
    printf("[6] Encerrar Operacao\n");
}

int main(){
    list firecamp;
    int operador;
    int flag = 0;
    char name[20], **lista;
    int cont;
    int retorno;


    tabela();

    do{
        printf("\nInput de Operacao: ");
        scanf("%d", &operador);
        switch(operador){
            case 1:
                if(flag == 1){
                    printf("Lista Ja Inicializada\n");
                    break;
                }
                flag = 1;
                printf("Inicializacao Requisitada\n");
                firecamp = initializeList();
            break;

            case 2:
                if(flag == 0){
                    printf("Lista Nao Inicializada\nImpossivel Inserir\n");
                    break;
                }
                printf("Digite o nome do soldado: ");
                setbuf(stdin, NULL);
                fgets(name, 21, stdin);
                name[strlen(name) - 1] = '\0';

                retorno = insertSoldier(&firecamp, name);
                if(retorno == 0)
                    printf("Falha ao alocar memoria para inserir o soldado\n");
                else if(retorno == 1)   
                    printf("Sucesso ao inserir\n");
            break;

            case 3:
                if(flag == 0 || emptyList(&firecamp) == 1){
                    printf("Lista Nao Inicializada ou Vazia\nImpossivel Iniciar Contagem\n");
                    break;
                }
                cont = rand();
                printf("Numero sorteado: %d\n", cont);
                do{
                    retorno = startByFirst(&firecamp, cont, name);
                    if(retorno == 0){
                        printf("Lista Vazia\n");
                    }
                    else if(retorno == 1){
                        printf("Soldado Retirado: %s\n", name);
                    }
                    else if(retorno == 2){
                        printf("Soldado Vencedor: %s\n", name);
                    }
                }while(retorno != 2);
            break;

            case 4:
                if(flag == 0 || emptyList(&firecamp) == 1){
                    printf("Lista Nao Inicializada ou Vazia\nImpossivel Iniciar Contagem\n");
                    break;
                }
                int size = qtdSoldiers(&firecamp);
                retorno = startByRandom(&firecamp, name, &lista, &cont);
                printf("Numero sorteado: %d\n", cont);
                cont = 0;
                printf("Soldado de Inicio: %s\n", name);
                for(cont = 0; cont < size-1; cont++){
                    printf("%do Soldado(a) Removido: %s\n", cont+1, *(lista+cont));
                }
                printf("Soldado(a) Vencedor: %s\n", lista[size-1]);
            break;

            case 5:
                if(flag == 0 || emptyList(&firecamp) == 1){
                    printf("Lista Nao Inicializada ou Vazia\nImpossivel Iniciar Contagem\n");
                    break;
                }
                size = qtdSoldiers(&firecamp);

                printf("Digite o nome do soldado a partir do qual a contagem comeca: ");
                setbuf(stdin, NULL);
                fgets(name, 21, stdin);
                name[strlen(name) - 1] = '\0';
                retorno = startByName(&firecamp, name, &lista, &cont);

                if(retorno == 0){
                    printf("Lista Vazia\n");
                    break;
                }

                printf("Numero sorteado: %d\n", cont);
                cont = 0;
                printf("Soldado de Inicio: %s\n", name);
                for(cont = 0; cont < size-1; cont++){
                    printf("%do Soldado(a) Removido: %s\n", cont+1, *(lista+cont));
                }
                printf("Soldado(a) Vencedor: %s\n", lista[size-1]);
            break;
        }
    }while(operador != 6);

    printf("Encerramento de Operacao\nFim do Programa\n");

    return 0;
}