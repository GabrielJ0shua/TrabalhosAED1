#include <stdio.h>
#include <stdlib.h>
#include "ciclico.h"
int imprime_lista(Lista lst)
{
    return 1;
}
int main()
{
    Lista lst;
    lst = cria_lista();
    char input;

    scanf("%c", &input);
    insere_final(&lst, input);
    remove_final(&lst, &input);

    scanf("%c", &input);
    insere_inicio(&lst, input);
    remove_inicio(&lst, &input);
    imprime_lista(lst);

    insere_final(&lst, 'a');
    insere_final(&lst, 'b');
    insere_final(&lst, 'c');
    insere_final(&lst, 'd');
    imprime_lista(lst);

    int tam = tamanho_lista(&lst);
    printf("O tamanho da lista e %d \n", tam);

    //Intencionalmente tentando remover elemento que não existe
    char tester = remove_pos(&lst, tam+1);
    if (tester == 0) //tester == 0 indica falha de remoção
    {
        printf("Falha ao encontrar a posicao\n");
    }
    else
    {
        printf("O elemento removido foi %c \n", tester);
    }

    tester = remove_pos(&lst, tam-2);
    if (tester == 0) //tester == 0 indica falha de remoção
    {
        printf("Falha ao encontrar a posicao\n");
    }
    else
    {
        printf("O elemento removido foi %c \n", tester);
    }
    imprime_lista(lst);

    return 0;
}
