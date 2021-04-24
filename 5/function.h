typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int insere_elem(Lista *li, char elem);
int insere_pos(Lista *li, int pos, char elem);
int remove_fim(Lista *li, char *elem);
int remove_pos(Lista *li, int pos, char *valor);
int obtem_valor(Lista *li, int pos, char *valor);
int tamanho_lista(Lista *li, int *tam);
void libera_lista(Lista *li);