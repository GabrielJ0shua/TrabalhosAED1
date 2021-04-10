#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "implementacao.h"

// Escolhendo a lista dinâmica/encadeada simples, pois o tamanho não é definido inicialmente e não é necessária a utilização de nenhum
// outro tipo de encadeamento

struct node
{
    int potencia;
    int coeficiente;
    struct node *prox;
};

LISTA inicializar_lista()
{
    return NULL;
}

int lista_vazia(LISTA l)
{
    if(l == NULL)
    {
        return 1;
    }
    return 0;
}

int insere_ord(LISTA *l, int potencia, int coeficiente)
{
    LISTA N = (LISTA)malloc(sizeof(struct node));
    if(N == NULL)
    {
        printf("Falha na alocação do novo nó!\n");
        return 0;
    }
    N->potencia = potencia;
    N->coeficiente = coeficiente;
    if(lista_vazia(*l) || potencia >= (*l)->potencia)
    {
        N->prox = *l;
        *l = N;
        return 1;
    }
    LISTA aux = *l;
    while(aux->prox != NULL && aux->prox->potencia > potencia)
    {
        aux = aux->prox;
    }
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord(LISTA *l, int potencia)
{
    if (lista_vazia(*l) == 1 || potencia > (*l)->potencia)
    {
        printf("Lista vazia ou potência inválida!");
        return 0;
    }
    LISTA aux = *l;
    if (potencia == (*l)->potencia) 
    {
        *l = aux->prox;
        free(aux);
        return 1; 
    }
    while (aux->prox != NULL && aux->prox->potencia > potencia)
    {
        aux = aux->prox;
    }
    if (aux->prox == NULL || aux->prox->potencia < potencia)
    {
        printf("Polinômio não encontrado!\n");
        return 0;
    }
    LISTA aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

double calc_px(LISTA *l, double x)
{
    double res = 0;
    double num_aux;
    LISTA aux = *l;
    while (aux != NULL)
    {
        num_aux = pow(x, aux->potencia);
        res += num_aux * aux->coeficiente;
        aux = aux->prox;
    }
    return res;
}

int imprime_lista(LISTA *l)
{
    if(lista_vazia(*l))
    {
        return 0;
    }
    LISTA aux = *l;
    int flag = 0;
    printf("P(x) = ");
    while (aux != NULL)
    {
        if(aux->coeficiente == 0)
        {
            // não imprime...
        }
        else if(flag != 0)
        {
            if(aux->potencia == 0)
            {
                if(aux->coeficiente < 0)
                {
                    printf("- %d ", abs(aux->coeficiente));
                }
                else
                {
                    printf("+ %d ", aux->coeficiente);
                }
            }
            else
            {
                if(aux->coeficiente < 0)
                {
                    printf("- %dx^%d ", abs(aux->coeficiente), aux->potencia);
                }
                else
                {
                    printf("+ %dx^%d ", aux->coeficiente, aux->potencia);
                }
            }
        }
        else
        {
            printf(" %dx^%d ", aux->coeficiente, aux->potencia);
        }
        aux = aux->prox;
        flag = 1;
    }
    return 1;
}

// Mesma coisa, liberar cada node e ir avançando
void reinicializa_polinomio(LISTA *l)
{
    *l = NULL;
}

// A de cima ja faz isso, inutil essa aqui.
void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}