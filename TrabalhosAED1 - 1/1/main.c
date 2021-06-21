#include <stdio.h>
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

    while(op != 11){

        menu();
        scanf("%d", &op);

        if(iniP == 0 && op != 1 && op >=2 && op < 11){ // NAO DEIXA FAZER ALGO COM A LISTA SE ELA NAO EXISTIR
            printf("\n### Lista NAO Inicializada ###\n\n");
            continue;
        }

        if(iniP == 1 && op == 1){ // IMPEDIRA QUE APAGUE A LISTA USANDO O CRIA LISTA, JA QUE TEM O COMANDO DE ESVAZIAR
            printf("\n### A Lista Ja Foi Inicializada ###\n");
            printf("### Caso deseje Esvaziar A Lista, Tecle 5 ###\n\n");
            continue;
        }

        switch(op){

            case 1:

                p = cria_lista();
                if(p == 0) printf("\n### Falha ao Criar Lista ###\n\n");
                else{
                    printf("\n### Lista Criada com Sucesso ###\n\n");
                    iniP = 1;
                }
                
                break;

            case 2:
                
                if(iniP2 == 1){//SE A LISTA INVERTIDA TIVER SIDO CRIADA E EU RESOLVO INSERIR ELEMENTO NA LISTA 1
                    libera(p2);   //ENTAO EU LIBERO A LISTA 2 QUE FOI CRIADA PARA QUANDO FOR GERAR ELA NOVAMENTE
                    iniP2 = 0;   //A LISTA ANTERIOR NAO FICAR OCUPANDO ESPACO ATOA
                }
             
                if(iniP3 == 1){//SEGUE O MESMO RACIOCINIO PARA LISTA 3, CASO ELA TENHA SIDO CRIADA E EU RESOLVO
                    libera(p3);   //INSERIR UM NOVO ELEMENTO NA LISTA 1 (LISTA 1 SERIA MEU p)
                    iniP3 = 0;
                }
                
                printf("\n### A Lista possui os seguintes elementos: ###\n\n");
                imprimir_lista(p);
                printf("\nDigite o Elemento: ");
                scanf("%f", &elem);
                if(insere_elem(p, elem) == 0) printf("\n### Falha ao Inserir Elemento ###\n\n");
                else printf("\n### Elemento Inserido com Sucesso ###\n\n");

                break;

            case 3:

                printf("\n### A Lista possui os seguintes elementos: ###\n\n");
                imprimir_lista(p);
                printf("\nDigite o Elemento: ");
                scanf("%f", &elem);
                if(remove_elem(p, elem) == 0) printf("\n### Falha ao Remover Elemento ###\n\n");
                else printf("\n### Elemento Removido com Sucesso ###\n\n");
                
                break;

            case 4:

                imprimir_lista(p);
                break;

            case 5:

                if(esvazia_lista(p) == 0) printf("\n### Falha ao Esvaziar Lista ###\n\n");
                else{
                    printf("\n### Lista Esvaziada com Sucesso ###\n\n");
                    printf("### A Nova Lista eh: ###\n");
                    imprimir_lista(p);
                }

                break;

            case 6:

                if(remove_impares(p) == 0) printf("\n### Falha ao Remover Numeros Impares ###\n\n");
                else{
                    printf("\n### Numeros Impares Removidos com Sucesso ###\n\n");
                    printf("### A Nova Lista eh: ###\n");
                    imprimir_lista(p);
                }

                break;

            case 7:

                if(maior_elemento(p,&elem) == 0) printf("\n### Falha ao Obter Maior Elemento ###\n\n");
                else                             printf("\n### O Maior Elemento da Lista eh %f ###\n\n", elem);
                
                break;

            case 8:

                if(tamanho_lista(p,&elem) == 0) printf("\n### Falha ao Obter Tamanho da Lista ###\n\n");
                else                            printf("\n### O Tamanho da Lista eh de %.f Elemento(s) ###\n\n", elem);
               
                break;

            case 9:

                p2 = cria_lista();
                if(lista_invertida(p,p2) == 0) printf("\n### Falha ao Gerar Lista Invertida ###\n\n");
                else{
                    printf("\n### Lista Invertida Gerada com Sucesso ###\n\n");
                    imprimir_lista(p2);
                    printf("\n### Lista Invertida Gerada com Sucesso ###\n\n");
                    iniP2 = 1;
                }
                
                break;

            case 10:

                p3 = cria_lista();
                if(concatena_listas(p,p2,p3) == 0) printf("\n### Falha ao concatenar Listas ###\n\n");
                else{
                    printf("\n### Listas Concatenadas com Sucesso ###\n\n");
                    imprimir_lista(p3);
                    printf("\n### Listas Concatenadas com Sucesso ###\n\n");
                    iniP3 = 1;
                }

                break;

            case 11:
                printf("\n### Fim Do Programa ###\n\n");

                break;
                
            default:

                printf("\n### Operacao Invalida ###\n\n");
        
        }
    }

    libera(p); // IRA DAR FREE NAS LISTAS INICIALIZADAS E APONTAR PARA NULL
    libera(p2);
    libera(p3);

    return 0;
}