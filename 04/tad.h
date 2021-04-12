typedef struct no * Lista;
Lista criar_lista();
int lista_vazia(Lista lista);
double insere_ord(Lista *lista, double elemento);
double obtem_valor(Lista *lista, double *elemento, int posicao);
double esvaziar_lista(Lista *lista);
double maior_valor(Lista *lista, double *elemento);
int tamanho_lista(Lista *);
double intercalar_listas(Lista *, Lista *, Lista *);
