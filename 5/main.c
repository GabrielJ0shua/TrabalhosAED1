#include <stdio.h>
#include "function.h"

Lista li;
int op = 0, ini = 0, tam, pos;
char elem;

void menu(){

    printf("[1] Cria Lista\n[2] Inserir no Inicio\n");
    printf("[3] Inserir Por Posicao\n");
    printf("[4] Remover do Fim\n[5] Remover por Posicao\n[6] Imprimir Lista\n");
    printf("[7] Tamanho da lista\n");
    printf("[8] Sair\n\nDigite a Opcao Desejada: ");

}

void imprimir(Lista *li){

    int i = 1;
    printf("\n{ ");
    while(obtem_valor(li, i, &elem) != 0){
        printf("%c ", elem);
        i++;
    }
    printf("}\n\n");

}

int main(){

    menu();

    while(scanf("%d", &op) && op != 8){

        setbuf(stdin, NULL);

        if(op < 1 || op > 8){
            printf("\n### OPERACAO INVALIDA ###\n\n");
            menu();
            continue;
        }

        if(op != 1 && ini == 0){
            printf("\n### LISTA 1 NAO INICIALIZADA ###\n\n");
            menu();
            continue;
        }

        if(op == 1){
            if(ini == 1){
                libera_lista(&li);
                printf("\n### LISTA ANTIGA APAGADA COM SUCESSO ###\n\n");
            }
            li = cria_lista();
            if(li != NULL)printf("\n### FALHA AO CRIAR LISTA ###\n\n");
            else{
                printf("\n### LISTA 1 CRIADA COM SUCESSO ###\n\n");
                ini = 1;
            }

            menu();
        }

        if(op == 2){
            printf("\nDIGITE O ELEMENTO: ");
            scanf("%c", &elem);
            if(insere_elem(&li, elem) == 0) printf("\n### FALHA ###\n\n");
            else                              printf("\n### SUCESSO ###\n\n");

            menu();
        }

        if(op == 3){
            printf("\nDIGITE O ELEMENTO: ");
            scanf("%c", &elem);
            tamanho_lista(&li, &tam);
            printf("\n### A LISTA POSSUI %d ELEMENTOS ###\n", tam);
            printf("DIGITE A POSICAO: ");
            scanf("%d", &pos);
            if(insere_pos(&li, pos, elem) == 0) printf("\n### FALHA ###\n\n");
            else                                printf("\n### SUCESSO ###\n\n");

            menu();
        }


        if(op == 4){
            imprimir(&li);
            if(remove_fim(&li, &elem) == 0) printf("\n### FALHA ###\n\n");
            else                          printf("\n### ELEMENTO REMOVIDO: %c ###\n\n", elem);

            menu();
        }

        if(op == 5){
            imprimir(&li);
            printf("DIGITE A POSICAO: ");
            scanf("%d", &pos);
            if(remove_pos(&li, pos, &elem) == 0) printf("\n### FALHA ###\n\n");
            else                          printf("\n### ELEMENTO REMOVIDO: %c ###\n\n", elem);

            menu();
        }

        if(op == 6){
            imprimir(&li);
            menu();
        }

        if(op == 7){
            if(tamanho_lista(&li, &tam) == 0) printf("\n### ERRO ###\n\n");
            else printf("\n### TAMANHO: %d ###\n\n", tam);

            menu();
        }
    }

        libera_lista(&li);

        printf("\nFIM DO PROGRAMA!\n\n");


    return 0;
}