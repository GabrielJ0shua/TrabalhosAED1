#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
int main(){
  int sair = 0, tam1, tam2;
  double elemento;
  Lista listas[3];
    listas[0] = criar_lista();
    listas[1] = criar_lista();
    listas[2] = criar_lista();
  while (sair != 1){
    int x = 0;
        printf("\n[1] Imprimir lista.");
        printf("\n[2] Inserir elemento.");
        printf("\n[3] Exibir tamanho da lista.");
        printf("\n[4] Exibir maior elemento da lista.");
        printf("\n[5] Esvaziar lista.");
        printf("\n[6] Intercala lista 1 e lista 2.");
        printf("\n[7] Verifica se listas sao iguais.");
        printf("\n[8] Sair.\n");
        scanf("%d", &x);
    switch (x){
        int lista, indice, posicao;
    case 1:
       //IMPRIMINDO LISTA
        printf("Deseja imprimir lista 1, 2 ou 3?: ");
     do {
                    scanf("%d", &lista);
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor sendo 1, 2 ou 3: ");

                } while (lista < 1 || lista > 3);
                indice = lista-1;
                if (lista_vazia(listas[indice]) == 1) {
                    printf("Esta lista esta vazia!");
                } else {
                    printf("Lista: %lf ", lista);
                    int posicao = 0;
                    while (obtem_valor(&listas[indice], &elemento, posicao) == 1) {
                        printf("%lf ", elemento);
                        posicao++;
                    }
                }
                break;

    case 2:
      // INSERINDO NA LISTA

      printf("Deseja inserir um elemento na Lista 1 ou Lista 2?: ");
      do {
                    scanf("%d", &lista);
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor sendo 1 ou 2:\n ");

                } while (lista != 1 && lista != 2);
                indice = lista-1;
                printf("Digite o elemento a ser inserido:\n ");
                scanf("%lf", &elemento);
                if(insere_ord(&listas[indice], elemento) == 0)
                    printf("Erro ao inserir elemento!\n");
                else
                    printf("Elemento inserido!\n");
                break;



    case 3:
      //TAMANHO
      printf("Deseja saber o tamanho da lista 1, 2 ou 3?: \n");
     do {

                    scanf("%d", &lista);
                    if (lista > 3 || lista < 1) //se usuario digita um numero invalido
                        printf("Insira um valor sendo 1, 2 ou 3:\n");

                } while (lista > 3 || lista < 1);
                indice = lista-1;
                int tamanho = tamanho_lista(&listas[indice]);
                if ((tamanho) == 0)
                    printf("A lista esta vazia!");
                else
                    printf("A Lista %d tem %d elementos.", lista, tamanho);
                break;

case 4:
      //MAIOR ELEMENTO
      printf("Deseja saber o maior elemento da lista 1, 2 ou 3?:\n");
      do {
                    scanf("%d", &lista);
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor sendo 1, 2 ou 3:\n");

                } while (lista < 1 || lista > 3);
                indice = lista-1;
                if(maior_valor(&listas[indice], &elemento) == 0)
                    printf("Erro ao encontrar o elemento digitado!");
                else
                    printf("O maior elemento da lista %d eh: %lf", lista, elemento);
                break;


    case 5:
    //ESVAZIAR
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

                    printf("Limpeza concluida\n");
                }
                break;


    case 6:

      //INTERCALAR
      //NAO MOSTRA O RESULTADO DA INTERCALAÇÃO
      if(intercalar_listas(&listas[0], &listas[1], &listas[2]) == 0)
                    printf("Erro ao intercalar.\n");
                else
                    printf("Listas intercaladas e o resultado obtido esta armazenado na lista 3.\n");
                break;

    case 7:
        tam1 = tamanho_lista(&listas[0]);
                tam2 = tamanho_lista(&listas[1]);
                    if(listas_iguais(&listas[0], &listas[1], tam1, tam2) == 0)
                        printf("Listas diferentes!\n");
                    else
                        printf("Listas iguais!\n\n");
                break;

    case 8:
      //SAIR
      sair = 1;
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  }
  return 0;
}
