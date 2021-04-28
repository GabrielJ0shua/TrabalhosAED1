#include <stdio.h>
#include "ciclico.h"

int main()
{
    char tester;
    Lista lst;
    lst = cria_lista();
    char input;
    int posicao, tam;
    int escolha = 0;
    while(escolha!=9)
    {
        printf("Manipulador de lista de chars: \n");
        printf("[1] Apagar lista \n");
        printf("[2] Inserir no inicio \n");
        printf("[3] Inserir no final \n");
        printf("[4] Remover do inicio\n");
        printf("[5] Imprimir Lista\n");
        printf("[6] Tamanho da Lista\n");
        printf("[7] Remove do final\n");
        printf("[8] Remove e printa posicao especifica\n");
        printf("[9] Sair\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
            case 1:
                if(lst == NULL)
                    printf("Lista nao existe \n");
                else
                        apaga_lista(&lst);
            break;
            case 2:
                printf("Digite o caractere a ser inserido: \n");
                fflush(stdin);
                scanf("%c", &input);
                if (insere_inicio(&lst, input)==0)
                 {
                     printf("Falha \n");
                 }
            break;

            case 3:
                 printf("Digite o elemento a ser inserido \n");
                 fflush(stdin);
                 scanf("%c", &input);
                 if (insere_final(&lst, input)==0)
                 {
                     printf("Falha \n");
                 }
            break;

            case 4:
                 if (remove_inicio(&lst, &input)==0)
                 {
                     printf("Falha \n");
                 }
                 else
                    printf("Elemento %c removido \n", input);
            break;

            case 5:
                if(lista_vazia(lst)!=1)
                {
                    char aux;
                    int i=1;
                    if (lista_vazia(lst)== 1)
                    {
                        printf("Falha\n");
                    }
                    aux = get_posicao(lst, i);
                    while (aux!=0)
                    {
                        printf("%c\n", aux);
                        aux = get_posicao(lst, i+1);
                        i++;
                    }
                }
                else
                    printf("Falha, lista vazia \n");
            break;

            case 6:
                tam = tamanho_lista(&lst);
                printf("A lista tem tamanho %d\n", tam);
            break;

            case 7:
                if (remove_final(&lst, &input)==0)
                 {
                     printf("Falha \n");
                 }
                 else
                    printf("Elemento %c removido \n", input);
            break;

            case 8:
                printf("Insira posicao a ser removida \n");
                scanf("%d", &posicao);
                tester = remove_pos(&lst, posicao);
                if (tester==0)
                 {
                     printf("Falha ao encontrar a posicao \n");
                 }
                 else
                    printf("Elemento %c removido \n", tester);
            break;

            case 9:
                apaga_lista(&lst);
            break;

            default:
                printf("Escolha invalida");
        }
    }
    return 0;
}
