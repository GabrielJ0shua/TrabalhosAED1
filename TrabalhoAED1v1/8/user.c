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
        int potencia_aux;
        int coeficiente_aux;
        int posicao_aux;
        int x_value;

        printf("\n==============================\n");
        printf("1. Inicializar Polinômio\n");
        printf("2. Inserir Termo\n");
        printf("3. Imprimir P(x)\n");
        printf("4. Remover Termo de Potência x\n");
        printf("5. Reinicializar Polinômio\n");
        printf("6. Calcular P(x)\n");
        printf("7. Sair\n");
        printf("==============================\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        clear();

        switch (opcao)
        {
        case 1:
            l = inicializar_lista();
            flag = 1;
            break;

        case 2:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            printf("Informe a potencia do polinomio a ser inserido: ");
            scanf("%d", &potencia_aux);
            printf("Informe o coeficiente do polinomio a ser inserido: ");
            scanf("%d", &coeficiente_aux);
            insere_ord(&l, potencia_aux, coeficiente_aux);
            clear();
            break;

        case 3:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            imprime_lista(&l);
            break;

        case 4:
            printf("Informe a potência do polinômio a ser removido: ");
            scanf("%d", &potencia_aux);
            remove_ord(&l, potencia_aux);
            clear();
            break;

        case 5:
            reinicializa_polinomio(&l);
            break;

        case 6:
            if(flag == 0)
            {
                printf("Ainda não foi criada uma lista!\n");
                break;
            }
            clear();
            printf("Insira o valor de x: ");
            scanf("%d", &x_value);
            printf("P(x) = %lf \n", calc_px(&l, x_value));
            break;

        case 7:
            return 0;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}