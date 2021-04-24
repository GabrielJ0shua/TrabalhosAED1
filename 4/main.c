#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Lista p, p2, p3;
int op = 0, ini = 0, tam;
int iniP2 = 0;
double elem;

void menu(){

    printf("[1] Criar Lista\n[2] Inserir Elemento\n");
    printf("[3] Remover Elemento\n[4] Imprimir Lista\n");
    printf("[5] Esvaziar Lista\n");
    printf("[6] Obter Maior Elemento\n[7] Obter Tamanho da Lista\n");
    printf("[8] Intercalar Listas\n[9] Sair\n");
    printf("\nDigite a opcao desejada: ");

}

void imprimir_lista(Lista *li){

    int i = 1;
    printf("\n{ ");
    while(get_pos(li, i, &elem) != 0){
        printf("%.3lf ", elem);
        i++;
    }
    printf("}\n\n");

}

int main(){

    menu();

    while(scanf("%d", &op) && op != 9){

        if(op < 1 || op > 9){ // RECONHECE QND DIGITA UM NUMERO QUE NAO TEM FUNCAO
            printf("\n### Operacao Invalida ###\n\n");
            menu();
            continue;
        }

        if(ini == 0 && op != 1 && op != 9){ // NAO DEIXA FAZER ALGO COM A LISTA 1 SE ELA NAO EXISTIR
            printf("\n### Lista NAO Inicializada ###\n\n");
            menu();
            continue;
        }

        if(ini == 1 && op == 1){ // IMPEDIRA QUE APAGUE A LISTA 1 USANDO O CRIA LISTA, JA QUE TEM O COMANDO DE ESVAZIAR
            printf("\n### A Lista Ja Foi Inicializada ###\n");
            printf("### Caso deseje Esvaziar A Lista, Tecle 5 ###\n\n");
            menu();
            continue;
        }

        if(op == 1){
            p = cria_lista();
            if(p == 0) printf("\n### Falha ao Criar Lista ###\n\n");
            else{
                printf("\n### Lista Criada com Sucesso ###\n\n");
                ini = 1;
            }
            menu();
        }

        if(op == 2){
            printf("\n### A Lista possui os seguintes elementos: ###\n\n");
            imprimir_lista(&p);
            printf("\nDigite o Elemento: ");
            scanf("%lf", &elem);
            if(insere_elem_ord(&p, elem) == 0){
                printf("\n### Falha ao Inserir Elemento ###\n\n");
                menu();
                continue;
            }

            printf("\n### Elemento Inserido com Sucesso ###\n\n");
            menu();
        }

        if(op == 3){
            printf("\n### A Lista possui os seguintes elementos: ###\n\n");
            imprimir_lista(&p);
            printf("\nDigite o Elemento: ");
            scanf("%lf", &elem);
            if(remove_elem(&p, elem) == 0){
                printf("\n### Falha ao Remover Elemento ###\n\n");
                menu();
                continue;
            }

            printf("\n### Elemento Removido com Sucesso ###\n\n");
            menu();
        }

        if(op == 4){
            imprimir_lista(&p);
            menu();
        }

        if(op == 5){
            esvaziar_lista(p);
            printf("\n### Lista Esvaziada com Sucesso ###\n\n");
            printf("### A Nova Lista eh: ###\n");
            imprimir_lista(&p);
            menu();
        }

        if(op == 6){
            if(maior_elemento(&p, &elem) == 0){
                printf("\n### Falha ao Obter Maior Elemento ###\n\n");
                menu();
                continue;
            }
            printf("\n### O Maior Elemento da Lista eh '%.3lf' ###\n\n", elem);
            menu();
        }

        if(op == 7){
            if(tamanho_lista(&p,&tam) == 0){
                printf("\n### Falha ao Obter Tamanho da Lista ###\n\n");
                menu();
                continue;
            }
            printf("\n### O Tamanho da Lista eh de %d Elemento(s) ###\n\n", tam);
            menu();
        }

        if(op == 8){//INTERCALAR
            if(iniP2 == 1){
                libera_lista(p2);
                libera_lista(p3);
            }
            p2 = cria_lista();//INICIALIZA LISTA P2
            p3 = cria_lista();//INICIALIZA LISTA P3
            iniP2 = 1;

            tam = 0;
            printf("\n### INSIRA ELEMENTOS NA LISTA 2 ###\n\n");
            printf("Deseja Inserir um Elemento?\n[1] Sim\n[2] Nao\n");
            scanf("%d", &tam);
            while(tam != 2){//INSERIR ELEMENTOS NA LISTA P2
                printf("\nDigite o elemento desejado: ");
                scanf("%lf", &elem);
                if(insere_elem_ord(&p2, elem) == 0){
                   printf("\n### Erro ao Inserir Elemento ###\n\n");
                   continue;
                }
                printf("\n### Elemento Inserido com Sucesso ###\n\n");
                printf("Deseja Inserir um Elemento?\n[1] Sim\n[2] Nao\n");
                scanf("%d", &tam);
            }

            if(intercala_listas(&p,&p2,&p3) == 0){//INSERE OS ELEMENTOS DE P E P2 EM P3
                printf("\n### Falha ao Gerar Lista Intercalada ###\n\n");
                menu();
                continue;
            }
            printf("\n### Lista Intercalada Gerada com Sucesso ###\n\n");
            printf("\n### Lista 1 ###\n");
            imprimir_lista(&p);
            printf("\n### Lista 2 ###\n");
            imprimir_lista(&p2);
            printf("\n### Lista 3 (Intercalada) ###\n");
            imprimir_lista(&p3);
            printf("\n### Lista Intercalada Gerada com Sucesso ###\n\n");
            menu();
        }

    }

    libera_lista(p);

    printf("\n### Fim Do Programa ###\n\n");


    return 0;
}