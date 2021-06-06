#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
typedef struct no * Pilha;
union parte
    {
        double real;
        char cara;
    };
int get_topo(Pilha plh, struct unionTipo * elem);
int push(Pilha * plh, union parte elem, int tipo);
int pilha_vazia(Pilha plh);
Pilha cria_pilha();
#endif // FILA_H_INCLUDED
