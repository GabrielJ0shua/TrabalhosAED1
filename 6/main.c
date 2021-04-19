#include <stdio.h>
#include <stdlib.h>
#include "duplo.h"

int main()
{
    char tester;
    Lista lst, lst2;
    lst = cria_lista();
    char input;
    int posicao, tam;
    int escolha = 0;
    while(escolha!=11)
    {
        printf("Manipulador de lista de int: \n");
        printf("[1] Criar lista \n");
        printf("[2] Apagar lista \n");
        printf("[3] Inserir \n");
        printf("[4] Remover\n");
        printf("[5] Remover todos\n");
        printf("[6] Imprimir Lista\n");
        printf("[7] Tamanho da Lista\n");
        printf("[8] Remover maior\n");
        printf("[9] Inverter\n");
        printf("[10] Primos\n");
        printf("[11] Sair\n");
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
                scanf("%d", &input);
                insere_elemento(&lst, input);
            break;

            case 4:
                 scanf("%d", &input);
                 if (remove_elemento(&lst, input)==0)
                 {
                     printf("Falha \n");
                 }
            break;

            case 5:
                scanf("%d", &input);
                 if (remove_todos(&lst, &input)==0)
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
                if (remove_maior(&lst, &input)==0)
                 {
                     printf("Falha \n");
                 }
                 else
                    printf("Elemento %d removido \n", input);
            break;
            case 9:
                scanf("%d", &posicao);
                tester = remove_pos(&lst, posicao);
                if (tester==0)
                 {
                     printf("Falha ao encontrar a posicao \n");
                 }
                 else
                    printf("Elemento %d removido \n", tester);
            break;

            case 10:
                lst2 = primos(lst);
                break;
            case 11:
                apaga_lista(&lst);
                break;
            default:
                printf("Escolha invalida");
        }
    }
    return 0;
}

