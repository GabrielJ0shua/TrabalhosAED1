typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int lista_cheia(Lista li);
int insere_elemento(Lista *li, int elem);
int remove_elem(Lista *li, int elem);
int tamanho_lista(Lista *li, int *tam);
int maior_elemento(Lista *li, int *maior);
int esvazia_lista(Lista *li);
int get_pos(Lista *li, int pos, int *elem);
int intercala_lista(Lista *L1, Lista *L2, Lista *L3);
int listas_iguais(Lista *L1, Lista *L2);
void libera_lista(Lista *li);