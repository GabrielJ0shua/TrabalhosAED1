#include "struct.h"

typedef struct fila Fila;

Fila* cria_fila();
int fila_vazia(Fila *f);
int push(Fila *f, dados p);
int pop(Fila *f, dados *p);
int tamanho(Fila *f, int *tam);
int get_inicio(Fila *f, dados *p);
void libera_fila(Fila *f);
