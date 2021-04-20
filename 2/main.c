#include <stdio.h>
#include "function.h"

CHAR p, p2, p3;
int op = 0, ini = 0, tam;
int iniP2 = 0;
char elem;

void menu(){

    printf("[1] Criar Lista\n[2] Inserir Elemento\n");
    printf("[3] Remover Elemento\n[4] Imprimir Lista\n");
    printf("[5] Esvaziar Lista\n[6] Remover Caracteres Pares\n");
    printf("[7] Obter Menor Elemento\n[8] Obter Tamanho da Lista\n");
    printf("[9] Intercalar Listas\n[10] Sair\n");
    printf("\nDigite a opcao desejada: ");

}


void imprimir_lista(CHAR p){

    if(p != NULL){
        int i = 0;
        printf("\n{ ");
        while(get_pos(p,i,&elem) != 0){//COMECA NA POSICAO ZERO E VAI IMPRIMIR ATE O GET FALHAR
            printf("%c ", elem);
            i++;
        }
        printf("}\n\n");
    }

}

int main(){

    menu();

    while(scanf("%d", &op) && op != 10){

        setbuf(stdin, NULL);

        if(op < 1 || op > 10){ // RECONHECE QND DIGITA UM NUMERO QUE NAO TEM FUNCAO
            printf("\n### Operacao Invalida ###\n\n");
            menu();
            continue;
        }

        if(ini == 0 && op != 1 && op != 10){ // NAO DEIXA FAZER ALGO COM A LISTA 1 SE ELA NAO EXISTIR
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
            imprimir_lista(p);
            printf("\nDigite o Elemento: ");
            scanf("%c", &elem);
            if(insere_ord(p, elem) == 0){
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
            scanf("%c", &elem);
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
            if(remove_pares(p) == 0){
                printf("\n### Falha ao Remover Caracteres Pares ###\n\n");
                menu();
                continue;
            }

            printf("\n### Caracteres Pares Removidos com Sucesso ###\n\n");
            printf("### A Nova Lista eh: ###\n");
            imprimir_lista(p);
            menu();
        }

        if(op == 7){
            if(menor_elemento(p,&elem) == 0){
                printf("\n### Falha ao Obter Menor Elemento ###\n\n");
                menu();
                continue;
            }
            printf("\n### O Menor Elemento da Lista eh '%c' ###\n\n", elem);
            menu();
        }

        if(op == 8){
            if(tamanho_lista(p,&tam) == 0){
                printf("\n### Falha ao Obter Tamanho da Lista ###\n\n");
                menu();
                continue;
            }
            printf("\n### O Tamanho da Lista eh de %d Elemento(s) ###\n\n", tam);
            menu();
        }

        if(op == 9){//INTERCALAR
            if(iniP2 == 1){
                libera(p2);
                libera(p3);
            }
            p2 = cria_lista();//INICIALIZA LISTA P2
            p3 = cria_lista();//INICIALIZA LISTA P3
            iniP2 = 1;

            printf("\n### INSIRA ELEMENTOS NA LISTA 2 ###\n\n");
            printf("### Caso NAO queira Inserir Mais Elementos, Tecle SPACE e de ENTER ###\n");
            printf("\nDigite o elemento desejado: ");
            while(scanf("%c", &elem) && elem != ' '){//INSERIR ELEMENTOS NA LISTA P2
                setbuf(stdin, NULL);
                if(insere_ord(p2, elem) == 0){
                   printf("\n### Erro ao Inserir Elemento ###\n\n");
                   continue;
                }
                printf("\n### Elemento Inserido com Sucesso ###\n");
                printf("\n### Caso NAO queira Inserir Mais Elementos, Tecle SPACE e de ENTER ###\n");
                printf("\nDigite o elemento desejado: ");
            }

            if(intercala_listas(p,p2,p3) == 0){//INSERE OS ELEMENTOS DE P E P2 EM P3
                printf("\n### Falha ao Gerar Lista Intercalada ###\n\n");
                menu();
                continue;
            }
            printf("\n### Lista Intercalada Gerada com Sucesso ###\n\n");
            printf("\n### Lista 1 ###\n");
            imprimir_lista(p);
            printf("\n### Lista 2 ###\n");
            imprimir_lista(p2);
            printf("\n### Lista 3 (Intercalada) ###\n");
            imprimir_lista(p3);
            printf("\n### Lista Intercalada Gerada com Sucesso ###\n\n");
            menu();
        }

    }

    printf("\n### Fim Do Programa ###\n\n");

    libera(p);
    libera(p2); // IRA DAR FREE NAS LISTAS INICIALIZADAS E APONTAR PARA NULL
    libera(p3);

    return 0;
}
