#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main(){
    int sair = 0, elemento, tam1, tam2;
    Lista listas[3];
    listas[0] = criar_lista(); //lista 1
    listas[1] = criar_lista();
    listas[2] = criar_lista(); // lista que vai receber a intercalação da lista 1 e 2
    while (sair != 1) {
        int x = 0;
        printf("\n[1] Imprimir lista.");
        printf("\n[2] Inserir elemento.");
        printf("\n[3] Exibir tamanho da lista.");
        printf("\n[4] Exibir maior elemento da lista.");
        printf("\n[5] Esvaziar lista.");
        printf("\n[6] Intercala lista 1 e lista 2.");
        printf("\n[7] Verifica se listas sao iguais.");
        printf("\n[8] Sair.\n");
        printf("\n");

        scanf("%d", &x);
        switch (x) {
            int lista, indice;
            case 1:
                printf("Deseja imprimir lista 1, 2 ou 3?: ");
                do {
                    scanf("%d", &lista);
                    if (lista < 1 || lista > 3) //se numero não for entre 1 e 3 pede outro
                        printf("Insira um valor sendo 1, 2 ou 3: ");

                } while (lista < 1 || lista > 3);
                indice = lista-1; //vai imprimindo um por um conforme o usuario pede pra imprimir
                if (lista_vazia(listas[indice]) == 1) { //verifica se a lista naquele indice for vazia
                    printf("Esta lista esta vazia!\n");
                } else {
                    printf("Lista %d: \n", lista);
                    int posicao = 0;
                    while (obtem_valor(&listas[indice], &elemento, posicao) == 1) { //vai obter o valor do elemento naquela posição da lista
                        printf("%d\n", elemento);
                        posicao++; //percorre
                    }
                }
                break;

            case 2:
                printf("Deseja inserir um elemento na Lista 1 ou Lista 2?: ");
                do {
                    scanf("%d", &lista);
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor sendo 1 ou 2:\n ");

                } while (lista != 1 && lista != 2);
                indice = lista-1; //vai percorrendo pra inserir
                printf("Digite o elemento a ser inserido:\n ");
                scanf("%d", &elemento);
                if(insere_ord(&listas[indice], elemento) == 0)
                    printf("Erro ao inserir elemento!\n");
                else
                    printf("Elemento inserido!\n");
                break;

            case 3:
                printf("Deseja saber o tamanho da lista 1, 2 ou 3?: \n");
                do {

                    scanf("%d", &lista);
                    if (lista > 3 || lista < 1) //se usuario digita um numero invalido
                        printf("Insira um valor sendo 1, 2 ou 3:\n");

                } while (lista > 3 || lista < 1);
                indice = lista-1; //o indice vai recebendo sempre um elemento anterior da lista, pra poder inserir
                int tamanho = tamanho_lista(&listas[indice]); //tamanho recebe a funcao tamanho com o indice da lista
                if ((tamanho) == 0)
                    printf("A lista esta vazia!\n");
                else
                    printf("A lista %d possui %d elementos.\n", lista, tamanho);
                break;

            case 4:
                printf("Deseja saber o maior elemento da lista 1, 2 ou 3?:\n");
                do {
                    scanf("%d", &lista);
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor sendo 1, 2 ou 3:\n");

                } while (lista < 1 || lista > 3);
                indice = lista-1; //recebe um elemento anterior da lista, pra comparar e ver qual é maior
                if(maior_valor(&listas[indice], &elemento) == 0) //vai percorrer a lista e comparar c os elementos
                    printf("Erro ao encontrar o elemento digitado!");
                else
                    printf("O maior elemento da lista %d eh: %d", lista, elemento);
                break;

            case 5:
                printf("Deseja limpar lista 1, 2 ou 3?: \n");
                do {
                    scanf("%d", &lista);
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor sendo 1, 2 ou 3:\n");

                } while (lista < 1 || lista > 3);
                indice = lista-1;

                if (esvaziar_lista(&listas[indice]) == 0) {
                    printf("Erro!\n");
                } else {

                    printf("Limpeza concluida!\n");
                }
                break;


            case 6:
                if(intercalar_listas(&listas[0], &listas[1], &listas[2]) == 0)
                    printf("Erro ao intercalar!\n");
                else
                    printf("Listas intercaladas e o resultado obtido asta armazenado na lista 3.\n");
                break;


            case 7: // imprime que são só iguais ou só distintas
                tam1 = tamanho_lista(&listas[0]);
                tam2 = tamanho_lista(&listas[1]);
                    if(listas_iguais(&listas[0], &listas[1], tam1, tam2) == 0)
                        printf("Listas diferentes!\n");
                    else
                        printf("Listas iguais!\n\n");

            case 8:
                sair = 1;
                break;
            default:
                printf("Opcao invalida!\n");
                break;

        }
    };
    return 0;
}
