typedef struct cabecalho *Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int insere_elem_ord(Lista *li, double elem);
int remove_elem(Lista *li, double elem);
int maior_elemento(Lista *li, double *elem);
int tamanho_lista(Lista *li, int *tam);
int get_pos(Lista *li, int pos, double *numero);
int intercala_listas(Lista *L1, Lista *L2, Lista *L3);
void esvaziar_lista(Lista li);
void libera_lista(Lista li);
int listas_iguais(Lista *L1, Lista *L2);
