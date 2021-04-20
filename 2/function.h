typedef struct CARACTER *CHAR;

CHAR cria_lista();
int lista_vazia(CHAR p);
int lista_cheia(CHAR p);
int insere_ord(CHAR p, char N);
int remove_elem(CHAR p, char N);
int get_pos(CHAR p, int pos, char *elemento);
int esvazia_lista(CHAR p);
int remove_pares(CHAR p);
int menor_elemento(CHAR p, char *elemento);
int tamanho_lista(CHAR p, int *tam);
int intercala_listas(CHAR p, CHAR p2, CHAR p3);
void libera(CHAR p);
