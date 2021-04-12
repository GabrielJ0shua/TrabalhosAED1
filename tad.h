typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lista);
int insere_ord(Lista *lista, int elemento);
int obtem_valor(Lista *lista, int *elemento, int posicao);
int esvaziar_lista(Lista *lista);
int maior_valor(Lista *lista, int *elemento);
int tamanho_lista(Lista *lista);
int intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3);
