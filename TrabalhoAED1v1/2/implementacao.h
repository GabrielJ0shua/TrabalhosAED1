typedef struct lista *LISTA;

LISTA criar_lista();
int lista_vazia(LISTA l);
int lista_cheia(LISTA l);
int inserir_ord(LISTA l, int elem);
int remover_ord(LISTA l, int elem);
int remover_pares(LISTA l);
int maior(LISTA l);
int tamanho(LISTA l);
int esvaziar(LISTA l);
LISTA intercalar(LISTA l1, LISTA l2);
int imprimir(LISTA l);
void clear();