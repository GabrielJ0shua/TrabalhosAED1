#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
typedef struct no * Pilha;
union parte
    {
        double real;
        char cara;
    };
struct unionTipo
{
    union parte valor;
    int tipo;
};
typedef union parte Parte;

Pilha cria_pilha();
void liberaPilha(Pilha * pi);
int pilha_vazia(Pilha plh);
int push(Pilha * plh, struct unionTipo elem);
int pop(Pilha * plh, struct unionTipo * elem);
int valida_escopo(Pilha plh);
int converte_pos_fixo(Pilha plh, Pilha * resultado);
int avalia_expressao(Pilha plh, char literais[], double doubles[], int tam , double * fim);
int encontra_literais(Pilha plh, Pilha * literal);
int tamanho_pilha(Pilha plh);
#endif // FILA_H_INCLUDED
