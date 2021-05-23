#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define max 20
typedef struct fila * Fila;
struct paciente
{
    char nome [20];
    int gravidade, idade, orgao;

};
int imprime(Fila f, struct paciente *elem, int pos);
int esvazia_fila (Fila f);
int remove_inicio(Fila f, struct paciente *elem);
int insere_ord(Fila f, struct paciente elem);
int fila_cheia(Fila f);
int fila_vazia(Fila f);
Fila cria_fila();
void libera_fila(Fila f);
#endif // FILA_H_INCLUDED
