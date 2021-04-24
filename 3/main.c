#include <stdio.h>
#include "function.h"

int op = 0, num, aux;
int iniL1 = 0, iniL2 = 0, iniL3 = 0;
Lista L1, L2, L3;

void menu(){

    printf("[1] Criar Lista 1\n[2] Inserir Lista 1\n");
    printf("[3] Remover Lista 1\n[4] Imprimir Listas\n");
    printf("[5] Tamanho das Listas\n[6] Listas iguais?\n");
    printf("[7] Maior Elemento\n[8] Esvaziar Lista\n");
    printf("[9] Intercalar Listas\n[10] Criar Lista 2\n[11] Sair\n\nDigite o Elemento: ");

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

    while(scanf("%d", &op) && op != 11){

        if(op < 1 || op > 11){
            printf("\n### OPERACAO INVALIDA ###\n\n");
            menu();
            continue;
        }

        if(iniL1 == 0 && op != 11 && op != 1 && op != 10){
            printf("\n### LISTA NAO INICIALIZADA ###\n\n");
            menu();
            continue;
        }

        if(op == 1){
            if(iniL1 == 1){
                printf("\n### LISTA JA FOI INICIALIZADA ###\n\n");
                menu();
                continue;
            }
            L1 = cria_lista();
            if(L1 != NULL) printf("\n### FALHA ###\n\n");
            else{
                printf("\n### SUCESSO ###\n\n");
                iniL1 = 1;
            }

            menu();
        }

        if(op == 2){

            printf("\nDIGITE O ELEMENTO: ");
            scanf("%d", &num);
            if(insere_elemento(&L1, num) == 0) printf("\n### FALHA ###\n\n");
            else                               printf("\n### SUCESSO ###\n\n");

            menu();
        }

        if(op == 3){

            printf("\n### ELEMENTOS DA LISTA: ###\n");
            imprimir_lista(&L1);
            printf("DIGITE O ELEMENTO: ");
            scanf("%d", &num);
            if(remove_elem(&L1, num) == 0) printf("\n### FALHA ###\n\n");
            else                           printf("\n### SUCESSO ###\n\n");

            menu();
        }

        if(op == 4){
            printf("Lista 1:");
            imprimir_lista(&L1);
            if(iniL2 == 1){
                printf("Lista 2:");
                imprimir_lista(&L2);
            }
            else printf("Lista 2 Ainda Nao Foi Inicializada\n\n");

            menu();
        }

        if(op == 5){
            if(tamanho_lista(&L1, &num) == 0) printf("\n### ERRO ###\n\n");
            else                              printf("\n### TAMANHO LISTA 1: %d ###\n\n", num);

            if(iniL2 == 1){
                if(tamanho_lista(&L2, &num) == 0) printf("\n### ERRO ###\n\n");
                else                              printf("\n### TAMANHO LISTA 2: %d ###\n\n", num);

            }
            else printf("Lista 2 Ainda Nao Foi Inicializada\n\n");

            menu();
        }

        if(op == 6){
            if(iniL2 == 0){
                printf("\n### LISTA 2 AINDA NAO FOI CRIADA ###\n\n");
                menu();
                continue;
            }
            if(listas_iguais(&L1, &L2) == 0) printf("\n### NAO ###\n\n");
            else                             printf("\n### SIM ###\n\n");
            printf("Lista 1: ");
            imprimir_lista(&L1);
            printf("Lista 2: ");
            imprimir_lista(&L2);

            menu();
        }

        if(op == 7){
            if(maior_elemento(&L1, &num) == 0) printf("\n### FALHOU ###\n\n");
            else                               printf("\n### MAIOR ELEMENTO: %d ###\n\n", num);

            menu();
        }

        if(op == 8){
            if(esvazia_lista(&L1) == 0) printf("\n### FALHOU ###\n\n");
            else                        printf("\n### SUCESSO ###\n\n");

            menu();
        }

        if(op == 9){
            if(iniL2 == 0){
                printf("\n### LISTA 2 AINDA NAO FOI CRIADA ###\n\n");
                menu();
                continue;
            }
            if(iniL3 == 1){
                libera_lista(&L3);
            }
            L3 = cria_lista();
            iniL3 = 1;
            if(intercala_lista(&L1, &L2, &L3) == 0) printf("\n### ERRO ###\n\n");
            else{
                printf("\n### SUCESSO ###\n\n");
                printf("Lista 1: ");
                imprimir_lista(&L1);
                printf("Lista 2: ");
                imprimir_lista(&L2);
                printf("Lista 3: ");
                imprimir_lista(&L3);
            }
            menu();
        }

        if(op == 10){
            if(iniL2 == 1){
                libera_lista(&L2);
            }

            L2 = cria_lista();
            if(L2 != NULL){
                printf("\n### ERRO AO CRIAR LISTA 2 ###\n\n");
                menu();
                continue;
            }

            printf("\n### LISTA 2 CRIADA COM SUCESSO ###\n\n");
            iniL2 = 1;

            printf("DESEJA INSERIR UM ELEMENTO?\n[1] Sim\n[2] Nao\n");
            printf("Opcao: ");
            scanf("%d", &num);
            while(num != 2){
                printf("DIGITE O ELEMENTO: ");
                scanf("%d", &aux);
                insere_elemento(&L2, aux);
                printf("\n### ELEMENTO INSERIDO COM SUCESSO ###\n\n");
                printf("DESEJA INSERIR UM ELEMENTO?\n[1] Sim\n[2] Nao\n");
                printf("Opcao: ");
                scanf("%d", &num);
            }
            printf("\n### LISTA 2 CRIADA COM SUCESSO ###\n\n");
            imprimir_lista(&L2);
            menu();
        }

    }

    printf("\n FIM DO PROGRAMA! \n\n");
    libera_lista(&L1);
    libera_lista(&L2);
    libera_lista(&L3);

    return 0;
}