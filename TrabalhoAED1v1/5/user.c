#include <stdio.h>
#include <string.h>
#include "implementacao.h"


int main()
{
    LISTA l;
    int flag = 0;
    clear();
    while(1)
    {
        int opcao;
        double elem;
        int posicao_aux;

        printf("\n==============================\n");
        printf("1. Inicializar Lista\n");
        printf("2. Inserir no Inicio\n");
        printf("3. Inserir na Posição\n");
        printf("4. Remover na Posição\n");
        printf("5. Maior Elemento\n");
        printf("6. Tamanho da Lista\n");
        printf("7. Imprimir Lista\n");
        printf("8. Sair\n");
        printf("==============================\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        clear();

        switch (opcao)
        {
        case 1:
            l = criar_lista();
            flag = 1;
            break;

        case 2:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            printf("Informe o elemento a ser inserido: ");
            scanf("%lf", &elem);
            inserir_inicio(&l, elem);
            clear();
            break;
            
        case 3:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            printf("Informe o elemento a ser inserido: ");
            scanf("%lf", &elem);
            printf("Informe a posição para inserir: ");
            scanf("%d", &posicao_aux);
            inserir_posicao(&l, elem, posicao_aux);
            clear();
            break;

        case 4:
            printf("Informe a posição a ser removida: ");
            scanf("%d", &posicao_aux);
            remove_posicao(&l, posicao_aux);
            clear();
            break;

        case 5:
            printf("O maior elemento é: %lf", maior(&l));
            break;

        case 6:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            clear();
            printf("O tamanho é: %d ", tamanho(&l));
            break;

        case 7:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            clear();
            imprime_lista(l);
            break;

        case 8:
            return 0;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}