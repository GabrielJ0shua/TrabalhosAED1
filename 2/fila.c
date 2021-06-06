#include "fila.h"
#include <stdlib.h>

struct unionTipo
{
    union parte valor;
    int tipo;
};
struct no
{
    struct unionTipo info;
    struct no * prox;
};

Pilha cria_pilha()
{
    return NULL;
}

int pilha_vazia(Pilha plh)
{
    if(plh==NULL)
        return 1;
    else
        return 0;
}

int push(Pilha * plh, union parte elem, int tipo)
{
    Pilha no = (Pilha)malloc(sizeof(*no));
    if (no==NULL)
        return 0;
    (no->info).valor = elem;
    (no->info).tipo = tipo;
    no->prox = *plh;
    *plh= no;
    return 1;
}

int pop(Pilha * plh, struct unionTipo * elem)
{
    if (pilha_vazia(*plh) == 1)
        return 0;
    *elem = (*plh)->info;
    Pilha aux = *plh;
    *plh = (*plh)->prox;
    free(aux);
    return 1;
}

int get_topo(Pilha plh, struct unionTipo * elem)
{
    if (pilha_vazia(plh) == 1)
        return 0;
    *elem = plh->info;
    return 1;
}
int valida_escopo(Pilha plh)
{
    if(pilha_vazia(plh) == 1)
        return 0;
    Pilha aux = plh;
    Pilha escopo = cria_pilha();
    struct unionTipo topo;
    while (pilha_vazia(aux)!=1)
    {
        if((aux->info).tipo == 1)
        {
            switch ((aux->info).valor.cara)
            {
                case '(':
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, (aux->info).valor, 1);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == '{')
                            return 3;
                        push(&escopo, (aux->info).valor, 1);
                    }
                    break;
                case '[':
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, (aux->info).valor, 1);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == '(')
                            return 3;
                        push(&escopo, (aux->info).valor, 1);
                    }
                    break;
                case '{':
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, (aux->info).valor, 1);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == '('||topo.valor.cara == '[')
                            return 3;
                        push(&escopo, (aux->info).valor, 1);
                    }
                    break;
                case ')':
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                        if(topo.valor.cara == '['||topo.valor.cara == '{')
                            return 4;
                    pop(&escopo, &topo);
                    break;
                case '}':
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                        if(topo.valor.cara == '['||topo.valor.cara == '(')
                            return 4;
                    pop(&escopo, &topo);
                    break;
                case ']':
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                        if(topo.valor.cara == '{'||topo.valor.cara == '(')
                            return 4;
                    pop(&escopo, &topo);
                    break;
                default:
                    break;
            }
        }
        aux = aux->prox;
    }
    return 1;
}
