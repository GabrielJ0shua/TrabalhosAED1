typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista list);
int insere_ord(Lista *lista, int elemento);
int remove_ord(Lista *lista, int elemento);
int obtem_valor(Lista *lista, int *elemento, int pos);
int esvaziar_lista(Lista *lista);
int remove_pos(Lista *lista, int pos, int *elemento);
int listas_iguais(Lista *lista_1, Lista *lista_2);
int maior_valor(Lista *lista, int *elemento);
int tamanho_lista(Lista *lista);
int intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3);
