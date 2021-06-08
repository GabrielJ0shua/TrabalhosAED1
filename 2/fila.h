#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
typedef struct no * Pilha;
union parte
    {
        double real;
        char cara;
    };

typedef union parte Parte;

Pilha cria_pilha();
void liberaPilha(Pilha pi);
int pilha_vazia(Pilha* plh);
int push(Pilha * plh, union parte elem, int tipo);
int pop(Pilha * plh, struct unionTipo * elem);
int valida_escopo(Pilha plh);
int converte_pos_fixo(Pilha plh, Pilha * resultado);
int avaliaçãoDaExpressao(Pilha plh, Pilha * resultado);

#endif // FILA_H_INCLUDED