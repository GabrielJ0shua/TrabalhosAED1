#ifndef CICLICO_H_INCLUDED
#define CICLICO_H_INCLUDED

typedef struct no * Lista;
Lista cria_lista();
void apaga_lista(Lista *lst);
int lista_vazia (Lista lst);
int remove_inicio(Lista *lst, char *elem);
int insere_pos(Lista *lst, char elem, int pos);
int insere_inicio(Lista *lst, char elem);
int tamanho_lista(Lista * lst);
int remove_final(Lista *lst, char *elem);
char remove_pos(Lista *lst, int pos);
char get_posicao(Lista lst, int pos);
int insere_final(Lista *lst, char elem);
#endif // CICLICO_H_INCLUDED