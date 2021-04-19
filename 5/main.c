#include <stdio.h>
#include <stdlib.h>
#include "ciclico.h"
int imprime_lista(Lista lst)
{
    return 1;
}
int main()
{
    char tester;
    Lista lst;
    lst = cria_lista();
    char input;
    int posicao, tam;
    int escolha = 0;
    while(escolha!=10)
    {
        printf("Manipulador de lista de chars: \n");
        printf("[1] Criar lista \n");
        printf("[2] Apagar lista \n");
        printf("[3] Inserir no inicio \n");
        printf("[4] Inserir no final \n");
        printf("[5] Remover do inicio\n");
        printf("[6] Imprimir Lista\n");
        printf("[7] Tamanho da Lista\n");
        printf("[8] Remove do final\n");
        printf("[9] Remove e printa posicao especifica\n");
        printf("[10] Sair\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
            case 1:
                if(lst == NULL)
                    lst = cria_lista();
                else
                    printf("Lista ja existe \n");
            break;

            case 2:
                if(lst == NULL)
                    printf("Lista nao existe \n");
                else
                        apaga_lista(&lst);
            break;
            case 3:
                printf("Digite o caractere a ser inserido: \n");
                scanf("%c", &input);
                insere_inicio(&lst, input);
            break;

            case 4:
                 printf("Digite o elemento a ser inserido \n");
                 scanf("%c", &input);
                 if (insere_final(&lst, input)==0)
                 {
                     printf("Falha \n");
                 }
            break;

            case 5:
                 if (remove_inicio(&lst, &input)==0)
                 {
                     printf("Falha \n");
                 }
                 else
                    printf("Elemento %c removido \n", input);
            break;

            case 6:
                if(lista_vazia(lst)!=1)
                {
                    imprime_lista(lst);
                }
                else
                    printf("Falha, lista vazia \n");
            break;

            case 7:
                tam = tamanho_lista(&lst);
                printf("%d", tam);
            break;
            case 8:
                if (remove_final(&lst, &input)==0)
                 {
                     printf("Falha \n");
                 }
                 else
                    printf("Elemento %c removido \n", input);
            break;
            case 9:
                scanf("%d", &posicao);
                tester = remove_pos(&lst, posicao);
                if (tester==0)
                 {
                     printf("Falha ao encontrar a posicao \n");
                 }
                 else
                    printf("Elemento %c removido \n", tester);
            break;

            case 10:
                apaga_lista(&lst);
                break;
            default:
                printf("Escolha invalida");
        }
    }
    return 0;
}
