typedef struct REAIS *Reais;

Reais cria_lista();
int lista_vazia(Reais p);
int lista_cheia(Reais p);
int insere_elem(Reais p, float N);
int remove_elem(Reais p, float N);
int get_pos(Reais p, int pos, float *elem);
int esvazia_lista(Reais p);
int remove_impares(Reais p);
int maior_elemento(Reais p, float *elem);
int tamanho_lista(Reais p, float *tam);
int lista_invertida(Reais p, Reais p2);
int concatena_listas(Reais p, Reais p2, Reais p3);
void libera(Reais p, Reais p2, Reais p3);
