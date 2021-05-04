typedef struct cabecalho *Lista;

Lista cria_lista();
int lista_vazia(Lista li);

int insere_elem(Lista *li, char *nome);
int remove1(Lista *li, int contagem, int *pos, char *nome);
int get_soldado(Lista *li, int *pos, char *nome);
int get_pos(Lista *li, int pos, char *nome);
int tamanho_lista(Lista *li, int *tam);
void esvaziar_lista(Lista *li);
void libera_lista(Lista *li);