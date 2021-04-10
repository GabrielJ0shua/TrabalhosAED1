#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(void)
{
    Lista li;
    Lista li2;
    Lista li3;
    int op, out;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    float elem, ma, ig;

    do
    {
        printf("digite a operação desejada\n");
        printf("\n");
        printf("[01] Criar primeira lista \n");
        printf("[02] Criar segunda lista \n");
        printf("[03] Insere elemento na primeira lista \n");
        printf("[04] Insere elemento na segundo lista \n");
        printf("[05] Remove elemento na primeira lista \n");
        printf("[06] Remove elemento na segundo lista \n");
        printf("[07] tamanho da primeira lista \n");
        printf("[08] tamanho da segunda lista \n");
        printf("[09] Maior elemento da primeira lista \n");
        printf("[10] Maior elemento da segunda lista \n");
        printf("[11] Intercala listas \n");
        printf("[12] Imprime primeira lista \n");
        printf("[13] Imprime segunda lista  \n");
        printf("[14] Imprime lista intercalda  \n");
        printf("[15] verifica se as listas sao iguais \n");
        printf("[16] Esvaziar primeira lista \n");
        printf("[17] Esvaziar segunda lista \n");
        printf("[18] sair \n");
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (flag1 == 1)
            {
                printf("lista criada,favor esvazia-la antes de tentar inicializa-la\n");
                break;
            }
            li = cria_lista();
            flag1 = 1;
            break;
        case 2:
            if (flag2 == 1)
            {
                printf("lista criada,favor esvazia-la antes de tentar inicializa-la\n");
                break;
            }
            li2 = cria_lista();
            flag2 = 1;
            break;
        case 3:
            if (flag1 == 0)
            {
                printf("Lista nao inicializada\nImpossivel Inserir na Lista\n");
                break;
            }
            printf("digite 0 elem:\n");
            scanf("%f", &elem);

            insere_ord(li, elem);

            break;
        case 4:
            if (flag2 == 0)
            {
                printf("Lista nao inicializada\nImpossivel Inserir na Lista\n");
                break;
            }
            printf("digite 0 elem:\n");
            scanf("%f", &elem);

            insere_ord(li2, elem);

            break;
        case 5:
            if (flag1 == 0)
            {
                printf("Lista nao inicializada\nImpossivel Remover na Lista\n");
                break;
            }

            printf("digite o elem:\n");
            scanf("%f", &elem);

            out = remove_ord(li, elem);
            if (out == 0)
            {
                printf("Lista vazia ou elemento nao existe\n");
            }

            break;
        case 6:
            if (flag2 == 0)
            {
                printf("Lista nao inicializada\nImpossivel Remover na Lista\n");
                break;
            }

            printf("digite o elem:\n");
            scanf("%f", &elem);

            out = remove_ord(li2, elem);

            if (out == 0)
            {
                printf("Lista vazia ou elemento nao existe\n");
            }

            break;
        case 7:
            if (flag1 == 0)
            {
                printf("Lista nao inicializada\n");
                break;
            }
            out = tamanho(li);
            printf("%d\n", out);
            break;
        case 8:
            if (flag2 == 0)
            {
                printf("Lista nao inicializada\n");
                break;
            }
            out = tamanho(li2);
            printf("%d\n", out);

            break;
        case 9:
            if (flag1 == 0)
            {
                printf("Lista nao inicializada\n");
                break;
            }
            maior(li, &ma);
            printf("%f\n", ma);
            break;
        case 10:
            if (flag2 == 0)
            {
                printf("Lista nao inicializada\n");
                break;
            }
            maior(li2, &ma);
            printf("%f\n", ma);
            break;
        case 11:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Alguma das listas nao foi  inicializada\n");
                break;
            }
            li3 = intercala(li, li2);
            if (li3 != NULL)
            {
                flag3 = 1;
            }

            break;
        case 12:
            if (flag1 == 0 || lista_vazia(li) == 1)
            {
                printf("Lista nao inicializada ou lista vazia\n");
                break;
            }
            imp(li);
            break;
        case 13:

            if (flag2 == 0 || lista_vazia(li2) == 1)
            {
                printf("Lista nao inicializada ou lista vazia\n");
                break;
            }
            imp(li2);
            break;
        case 14:
            if (flag3 == 0)
            {
                printf("Lista nao intercalada\n");
                break;
            }

            imp(li3);
            break;
        case 15:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Alguma lista nao inicializada\n");
                break;
            }

            out = iguais(li, li2);
            if (out == 0)
            {
                printf("as listas sao diferentes\n");
            }
            else
            {
                printf("sao iguais\n");
            }

            break;
        case 16:
            if (flag1 == 0)
            {
                break;
            }

            esvaziar(li);
            flag1 = 0;
            break;
        case 17:
            if (flag2 == 0)
            {
                break;
            }

            esvaziar(li2);
            flag2 = 0;
            break;
        }
    } while (op != 18);

    return 0;
}
