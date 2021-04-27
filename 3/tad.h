typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int lista_cheia(Lista li);
int insere_elemento(Lista *li, int elemento);
int remove_elemento(Lista *li, int elemento);
int tamanho_lista(Lista *li, int *tam);
int maior_elemento(Lista *li, int *maior);
int esvazia_lista(Lista *li);
int get_pos(Lista *li, int pos, int *elemento);
int intercala_lista(Lista *L1, Lista *L2, Lista *L3);
void libera_lista(Lista *li);
int listas_iguais(Lista *L1, Lista *L2);
