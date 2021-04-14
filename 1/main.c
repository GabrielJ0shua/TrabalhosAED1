#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Reais p, p2, p3;
int op = 0;
int iniP = 0,iniP2 = 0, iniP3 = 0;//NENHUMA LISTA FOI INICIALIZADA AINDA
float elem;

void menu(){

    printf("[1] Criar Lista\n[2] Inserir Elemento\n");
    printf("[3] Remover Elemento\n[4] Imprimir Lista\n");
    printf("[5] Esvaziar Lista\n[6] Remover Numeros Impares\n");
    printf("[7] Obter Maior Elemento\n[8] Obter Tamanho da Lista\n");
    printf("[9] Gerar Lista Invertida\n[10] Concatenar Listas\n[11] Sair\n");
    printf("\nDigite a opcao desejada: ");

}


void imprimir_lista(Reais p){

    if(p != NULL){
        int i = 0;
        printf("\n{ ");
        while(get_pos(p,i,&elem) != 0){
            printf("%f ", elem);
            i++;
        }
        printf("}\n\n");
    }

}

int main(){

    menu();

    while(scanf("%d", &op) && op != 11){

        if(op < 1 || op > 11){ // RECONHECE QND DIGITA UM NUMERO QUE NAO TEM FUNCAO
            printf("\n### Operacao Invalida ###\n\n");
            menu();
            continue;
        }

        if(iniP == 0 && op != 1){ // NAO DEIXA FAZER ALGO COM A LISTA SE ELA NAO EXISTIR
            printf("\n### Lista NAO Inicializada ###\n\n");
            menu();
            continue;
        }

        if(iniP == 1 && op == 1){ // IMPEDIRA QUE APAGUE A LISTA USANDO O CRIA LISTA, JA QUE TEM O COMANDO DE ESVAZIAR
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
                iniP = 1;
            }
            menu();
        }

        if(op == 2){
            if(iniP2 == 1){//SE A LISTA INVERTIDA TIVER SIDO CRIADA E EU RESOLVO INSERIR ELEMENTO NA LISTA 1
                free(p2);   //ENTAO EU LIBERO A LISTA 2 QUE FOI CRIADA PARA QUANDO FOR GERAR ELA NOVAMENTE
                p2 = NULL;  //A LISTA ANTERIOR NAO FICAR OCUPANDO ESPACO ATOA
                iniP2 = 0;
            }
            if(iniP3 == 1){//SEGUE O MESMO RACIOCINIO PARA LISTA 3, CASO ELA TENHA SIDO CRIADA E EU RESOLVO
                free(p3);   //INSERIR UM NOVO ELEMENTO NA LISTA 1 (LISTA 1 SERIA MEU p)
                p3 = NULL;
                iniP3 = 0;
            }
            printf("\n### A Lista possui os seguintes elementos: ###\n\n");
            imprimir_lista(p);
            printf("\nDigite o Elemento: ");
            scanf("%f", &elem);
            if(insere_elem(p, elem) == 0){
                printf("\n### Falha ao Inserir Elemento ###\n\n");
                menu();
                continue;
            }

            printf("\n### Elemento Inserido com Sucesso ###\n\n");
            menu();
        }

        if(op == 3){
            printf("\n### A Lista possui os seguintes elementos: ###\n\n");
            imprimir_lista(p);
            printf("\nDigite o Elemento: ");
            scanf("%f", &elem);
            if(remove_elem(p, elem) == 0){
                printf("\n### Falha ao Remover Elemento ###\n\n");
                menu();
                continue;
            }

            printf("\n### Elemento Removido com Sucesso ###\n\n");
            menu();
        }

        if(op == 4){
            imprimir_lista(p);
            menu();
        }

        if(op == 5){
            if(esvazia_lista(p) == 0){
                printf("\n### Falha ao Esvaziar Lista ###\n\n");
                menu();
                continue;
            }

            printf("\n### Lista Esvaziada com Sucesso ###\n\n");
            printf("### A Nova Lista eh: ###\n");
            imprimir_lista(p);
            menu();
        }

        if(op == 6){
            if(remove_impares(p) == 0){
                printf("\n### Falha ao Remover Numeros Impares ###\n\n");
                menu();
                continue;
            }

            printf("\n### Numeros Impares Removidos com Sucesso ###\n\n");
            printf("### A Nova Lista eh: ###\n");
            imprimir_lista(p);
            menu();
        }

        if(op == 7){
            if(maior_elemento(p,&elem) == 0){
                printf("\n### Falha ao Obter Maior Elemento ###\n\n");
                menu();
                continue;
            }
            printf("\n### O Maior Elemento da Lista eh %f ###\n\n", elem);
            menu();
        }

        if(op == 8){
            if(tamanho_lista(p,&elem) == 0){
                printf("\n### Falha ao Obter Tamanho da Lista ###\n\n");
                menu();
                continue;
            }
            printf("\n### O Tamanho da Lista eh de %.f Elemento(s) ###\n\n", elem);
            menu();
        }

        if(op == 9){
            p2 = cria_lista();
            if(lista_invertida(p,p2) == 0){
                printf("\n### Falha ao Gerar Lista Invertida ###\n\n");
                menu();
                continue;
            }
            printf("\n### Lista Invertida Gerada com Sucesso ###\n\n");
            imprimir_lista(p2);
            printf("\n### Lista Invertida Gerada com Sucesso ###\n\n");
            iniP2 = 1;
            menu();
        }

        if(op == 10){
            p3 = cria_lista();
            if(concatena_listas(p,p2,p3) == 0){
                printf("\n### Falha ao concatenar Listas ###\n\n");
                menu();
                continue;
            }
            printf("\n### Listas Concatenadas com Sucesso ###\n\n");
            imprimir_lista(p3);
            printf("\n### Listas Concatenadas com Sucesso ###\n\n");
            menu();
            iniP3 = 1;
        }

    }

    printf("\n### Fim Do Programa ###\n\n");

    libera(p,p2,p3); // IRA DAR FREE NAS LISTAS INICIALIZADAS E APONTAR PARA NULL

    return 0;
}
