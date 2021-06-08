#include <stdlib.h>
#include "fila.h"

struct fila
{
    struct paciente info[max];
    int ini, cont;
};

Fila cria_fila()
{    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->ini = 0;
        f->cont = 0;
    }
    return f;
}

int fila_vazia(Fila f)
{
    if (f->cont == 0)
        return 1;
    else
        return 0;
}

int fila_cheia(Fila f)
{
    if (f->cont == max)
        return 1;
    else
        return 0;
}

int insere_ord(Fila f, struct paciente elem)
{
    int aux=0;
    if (f == NULL || fila_cheia(f) == 1)
        return 0;
    if(fila_vazia(f) == 1)
    {
        f->info[f->ini] = elem;
        f->cont++; // Incremento normal
        return 1;
    }
    while(f->info[(f->ini+aux)%max].gravidade>elem.gravidade && aux<(f->ini+f->cont)%max)
    {
        aux++;
    }
    if (aux==(f->ini+f->cont)%max)// Insere elemento no final
    {
        f->info[aux] = elem;
    }
    else
    {
        int i = (f->ini+f->cont)%max;
        while ( i != (f->ini+aux)%max)
        {
            f->info[i] = f->info[i-1];

            if(i==0)
            {
             i=max-1;
            }
            else
            {
                i--;
            }
        }
        f->info[aux] = elem;
    }
    f->cont++; // Incremento normal
    return 1;
}

int remove_inicio(Fila f, struct paciente *elem)// Remove o elemento do inicio
{
    if (f == NULL || fila_vazia(f) == 1)
        return 0;
    *elem = f->info[f->ini];
    f->ini = (f->ini+1)%max; // Incremento circular
    f->cont--; // Decremento não circular
        return 1;
}

int esvazia_fila (Fila f)
{
    if (f == NULL || fila_vazia(f) == 1)
        return 0;// Remove o elemento do inicio
        f->cont = 0;
    return 1;
}

void libera_fila(Fila *f)
{
    if(*f != NULL){
        free(*f);
        *f=NULL;
    }
}
