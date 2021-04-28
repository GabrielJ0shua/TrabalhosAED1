#include <stdio.h>
#include "tad.h"

Lista p, p2, p3;
int opcao = 0, ini = 0, op, tam1, tam2;
int iniP2 = 0;
double elem;

void menu(){
    printf("\n");
    printf("[1] Criar Lista\n");
    printf("[2] Inserir Elemento\n");
    printf("[3] Remover Elemento\n");
    printf("[4] Imprimir Lista\n");
    printf("[5] Esvaziar Lista\n");
    printf("[6] Obter Maior Elemento\n");
    printf("[7] Obter Tamanho da Lista\n");
    printf("[8] Intercalar Listas\n");
    printf("[9] Verifica se listas sao iguais\n");
    printf("[10] Criar Lista 2\n");
    printf("[11] Sair\n");

}

void imprimir_lista(Lista *li){
    int i = 1;
    printf("\n");
    while(get_pos(li, i, &elem) != 0){
            printf("%.3lf  ", elem);
        i++;
    }
}

int main(){

    do{

        menu();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        if(ini == 0 && opcao != 1 && opcao != 11){ // NAO DEIXA FAZER ALGO COM A LISTA 1 SE ELA NAO EXISTIR
            printf("\nLista nao inicializada!\n");
            continue;
        }

        if(ini == 1 && opcao == 1){ // IMPEDIRA QUE APAGUE A LISTA 1 USANDO O CRIA LISTA, JA QUE TEM O COMANDO DE ESVAZIAR
            printf("\nLista ja inicializada!\n");
            printf("\nAperte 5 para esvaziar lista.\n");
            continue;
        }

        switch(opcao){
            
            case 1:
            
                p = cria_lista();
                if(p == 0){
                    printf("\nErro ao criar lista.\n");
                }else{
                    printf("\nLista criada com sucesso !\n");
                    ini = 1;
                }
                
                break;

            case 2:
                printf("\nA lista tem os seguintes elementos:\n");
                imprimir_lista(&p);
                printf("\nDigite o elemento a ser inserido:\n");
                scanf("%lf", &elem);
                if(insere_elem_ord(&p, elem) == 0){
                    printf("\nErro ao inserir elemento.\n");
                }else{
                printf("\nElemento inserido com sucesso.\n");
                }
                
                break;

            case 3:
                printf("\nA lista tem os seguintes elementos:\n");
                imprimir_lista(&p);
                printf("\nDigite o Elemento: ");
                scanf("%lf", &elem);
                if(remove_elem(&p, elem) == 0){
                    printf("\nErro ao remover elemento.\n");
                }
                else printf("\nElemento removido com sucesso.\n");
                
                break;


            case 4:
                imprimir_lista(&p);
                
                break;

            case 5:
                esvaziar_lista(p);
                printf("\nLista esvaziada com sucesso.\n");
                printf("\nA nova lista eh: \n");
                imprimir_lista(&p);
                
                break;

            case 6:
                if(maior_elemento(&p, &elem) == 0){
                    printf("\nErro ao obter o maior elemento.\n");
                }
                else printf("\nO maior elemento da lista eh: %.3lf .\n", elem);
                
                break;

            case 7:
                if(tamanho_lista(&p, &op) == 0){
                    printf("\nErro ao obter o tamanho da lista.\n");
                }
                else printf("\nO tamanho da lista eh de %d elemento(s)\n", op);
                
                break;

            case 8: //INTERCALAR
                if(iniP2 == 0){
                    printf("\nLista 2 nao criada\n");
                    continue;
                }
                if(iniP2 == 1){
                    libera_lista(p3);
                }
                p3 = cria_lista();//INICIALIZA LISTA P3

                if(intercala_listas(&p,&p2,&p3) == 0){//INSERE OS ELEMENTOS DE P E P2 EM P3
                    printf("\nErro ao gerar lista intercalada.\n");
                }
                else{
                    printf("\nLista intercalada com sucesso.\n");
                    printf("\nLista 1: ");
                    imprimir_lista(&p);
                    printf("\nLista 2: ");
                    imprimir_lista(&p2);
                    printf("\nLista 3: (Intercalada)");
                    imprimir_lista(&p3);
                }

                break;

            case(9):
                if(iniP2 == 0){
                    printf("\nLista 2 nao inicializada\n");
                    continue;
                }
                if(listas_iguais(&p,&p2)){
                    printf("\nListas iguais\n");
                }else{
                    printf("\nListas diferentes\n");
                }
                imprimir_lista(&p);
                imprimir_lista(&p2);
                
                break;

            case(10):
                if(iniP2 == 1){
                    libera_lista(p2);
                    }
                printf("\nCriando Lista 2...\n");
                p2 = cria_lista();
                iniP2 = 1;
                op = 0;
                printf("\nInsira elementos na lista 2: \n");
                printf("\nDeseja inserir um elemento?\n[1] Sim\n[2]Nao\n");
                scanf("%d", &op);
                while(op != 2){//INSERIR ELEMENTOS NA LISTA P2
                    printf("\nDigite o elemento desejado: ");
                    scanf("%lf", &elem);
                    if(insere_elem_ord(&p2, elem) == 0){
                        printf("\nErro ao inserir elemento.\n");
                    }
                    else{
                        printf("\nElemento inserido com sucesso.\n");
                    }
                    printf("\nDeseja inserir um elemento?\n[1] Sim\n[2]Nao\n");
                    scanf("%d", &op);
                    if(op == 2) {
                        printf("Lista 2: \n");
                        imprimir_lista(&p2);
                    }
                }
            
                break;

            case 11:
                printf("\n Fim do Programa!\n");

                break;

            default:{

                printf("\nOperacao invalida!\n");

            }


        libera_lista(p);
        libera_lista(p2);
        libera_lista(p3);
    }

    }while(opcao != 11);


    return 0;
}
