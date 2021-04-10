#include <stdio.h>
#include <string.h>
#include "implementacao.h"

int main()
{
    LISTA l1;
    LISTA l2;
    LISTA l3;

    int flag = 0;
    int flag_listas[3];
    int flag_sec[3];
    int i = 0;
    while (i < 3)
    {
        flag_listas[i] = 0;
        flag_sec[i] = 0;
        i++;
    }
    clear();
    while(1)
    {
        int opcao;
        int opcao2;
        int elem;
        int aux_flag_lista = 0;

        printf("\n==============================\n");
        printf("1. Criar Lista\n");
        printf("2. Inserir Elemento\n");
        printf("3. Remover Elemento\n");
        printf("4. Remover Pares\n");
        printf("5. Maior Elemento\n");
        printf("6. Tamanho da Lista\n");
        printf("7. Esvaziar Lista\n");
        printf("8. Intercalar Listas\n");
        printf("9. Imprimir Lista\n");
        printf("10. Sair\n");
        printf("==============================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            clear();
            if(flag_listas[0] == 1 && flag_listas[1] == 1 && flag_listas[2] == 1)
            {
                printf("Quantidade máxima de listas atingida!");
                break;
            }
            while(flag_listas[aux_flag_lista] != 0)
            {
                aux_flag_lista++;
            }
            switch (aux_flag_lista + 1)
            {
            case 1:
                l1 = criar_lista();
                printf("Criada a lista 1!\n");
                break;

            case 2:
                l2 = criar_lista();
                printf("Criada a lista 2!\n");
                break;

            case 3:
                l3 = criar_lista();
                printf("Criada a lista 3!\n");
                break;
            
            default:
                printf("Erro na escolha da lista a ser criada!\n");
                return 0;
                break;
            }
            flag_listas[aux_flag_lista] = 1;
            break;

        case 2:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: \n");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!");
                break;
            }
            else
            {
                printf("Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                switch (opcao)
                {
                case 1:
                    inserir_ord(l1, elem);
                    break;

                case 2:
                    inserir_ord(l2, elem);
                    break;

                case 3:
                    inserir_ord(l3, elem);
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 3:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                printf("Informe o elemento a ser removido: ");
                scanf("%d", &elem);
                switch (opcao)
                {
                case 1:
                    remover_ord(l1, elem);
                    break;

                case 2:
                    remover_ord(l2, elem);
                    break;

                case 3:
                    remover_ord(l3, elem);
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 4:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                switch (opcao)
                {
                case 1:
                    remover_pares(l1);
                    break;

                case 2:
                    remover_pares(l2);
                    break;

                case 3:
                    remover_pares(l3);
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 5:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                switch (opcao)
                {
                case 1:
                    printf("O maior elemento da lista 1 é: %d",maior(l1));
                    break;

                case 2:
                    printf("O maior elemento da lista 2 é: %d",maior(l2));
                    break;

                case 3:
                    printf("O maior elemento da lista 3 é: %d",maior(l3));
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 6:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                switch (opcao)
                {
                case 1:
                    printf("O tamanho da lista 1 é: %d",tamanho(l1));
                    break;

                case 2:
                    printf("O tamanho da lista 2 é: %d",tamanho(l2));
                    break;

                case 3:
                    printf("O tamanho da lista 3 é: %d",tamanho(l3));
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 7:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                switch (opcao)
                {
                case 1:
                    esvaziar(l1);
                    break;

                case 2:
                    esvaziar(l2);
                    break;

                case 3:
                    esvaziar(l3);
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 8:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a primeira lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                flag_sec[0] = 1;
                break;

            case 2:
                flag_sec[1] = 1;
                break;

            case 3:
                flag_sec[2] = 1;
                break;
            
            default:
                break;
            }
            if(opcao == 1)
            {
                flag_sec[0] = 1;
            }
            if(opcao == 2)
            {
                flag_sec[0] = 1;
            }
            if(opcao == 3)
            {
                flag_sec[0] = 1;
            }
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            printf("Informe a segunda lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1 && flag_sec[0] == 0)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1 && flag_sec[1] == 0)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1 && flag_sec[2] == 0)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            if(flag_sec[opcao - 1] == 1)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                if((opcao == 1 && opcao2 == 2) || (opcao == 2 && opcao2 == 1))
                {
                    imprimir(intercalar(l1, l2));
                }
                else if((opcao == 2 && opcao2 == 3) && (opcao == 3 && opcao2 == 2))
                {
                    imprimir(intercalar(l2,l3));
                }
                else if((opcao == 1 && opcao2 == 3) || (opcao == 3 && opcao2 == 1))
                {
                    imprimir(intercalar(l1,l3));
                }
            }
            break;

        case 9:
            clear();
            if(flag_listas[0] == 0 && flag_listas[1] == 0 && flag_listas[2] == 0)
            {
                printf("Nenhuma lista criada ainda!\n");
                break;
            }
            printf("Informe a lista a ser manipulada: ");
            printf("===== Listas Disponíveis =====\n");
            if(flag_listas[0] == 1)
            {
                printf("1. Lista [1]\n");
            }
            if(flag_listas[1] == 1)
            {
                printf("2. Lista [2]\n");
            }
            if(flag_listas[2] == 1)
            {
                printf("3. Lista [3]\n");
            }
            printf("==============================\n");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                printf("Opção inválida!\n");
                break;
            }
            if(flag_listas[opcao - 1] == 0)
            {
                printf("Lista inválida!\n");
                break;
            }
            else
            {
                switch (opcao)
                {
                case 1:
                    imprimir(l1);
                    break;

                case 2:
                    imprimir(l2);
                    break;

                case 3:
                    imprimir(l3);
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 10:
            return 0;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}