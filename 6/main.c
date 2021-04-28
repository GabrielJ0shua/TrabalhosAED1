#include <stdio.h>
#include "duplo.h"
int imprime_lista(Lista lst)
{
    int aux;
    int i=1;
    if (lista_vazia(lst)== 1)
    {
        return 0;
    }
    aux = get_posicao(lst, i);
    while (aux!=0)
    {
        printf("%d\n", aux);
        aux = get_posicao(lst, i+1);
        i++;
    }
    return 1;
}
int main()
{
    Lista lst, lst2;
    lst = cria_lista();
    int input;
    int tam;
    int escolha = 0;
    while(escolha!=10)
    {
        printf("Manipulador de lista de int: \n");
        printf("[1] Apagar lista \n");
        printf("[2] Inserir \n");
        printf("[3] Remover\n");
        printf("[4] Remover todos\n");
        printf("[5] Imprimir Lista\n");
        printf("[6] Tamanho da Lista\n");
        printf("[7] Remover maior\n");
        printf("[8] Inverter\n");
        printf("[9] Primos\n");
        printf("[10] Sair\n");
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
                printf("Digite o numero a ser inserido: \n");
                scanf("%d", &input);
                insere_elemento(&lst, input);
            break;

            case 3:
                 printf("Digite o numero a ser removido: \n");
                 scanf("%d", &input);
                 if (remove_elemento(&lst, input)==0)
                 {
                     printf("Falha \n");
                 }
            break;

            case 4:
                apaga_lista(&lst);
                    printf("Todos Removidos \n");
            break;

            case 5:
                if(lista_vazia(lst)!=1)
                {
                    printf("A lista e:\n\n");
                    imprime_lista(lst);
                }
                else
                    printf("Falha, lista vazia \n");
            break;

            case 6:
                tam = tamanho_lista(&lst);
                printf("\n O tamanho da lista e: %d\n \n", tam);
            break;

            case 7:
                if (remove_maior(&lst, &input)==0)
                 {
                     printf("Falha \n");
                 }
                 else
                    printf("Elemento %d removido \n", input);
            break;

            case 8:
                lst2 = inverte(&lst);
                if (lst2==NULL)
                 {
                     printf("Falha ao inverter\n");
                 }
                 else
                 {
                     printf("A lista e:\n\n");
                     imprime_lista(lst2);
                     apaga_lista(&lst2);
                 }
            break;

            case 9:
                lst2 = primos(&lst);
                printf("A lista apenas com os primos e:\n\n");
                imprime_lista(lst2);
                apaga_lista(&lst2);
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
