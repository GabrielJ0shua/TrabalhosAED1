#define MAX 50

typedef struct Inteiros *Pilha;

Pilha cria_pilha();
int pilha_cheia(Pilha p);
int pilha_vazia(Pilha p);
int push(Pilha p, int numero);
int pop(Pilha p, int *numero);
int le_topo(Pilha p, int *numero);
int esvazia(Pilha p);
void libera(Pilha p);
