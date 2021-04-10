typedef struct node *LISTA;

LISTA criar_lista();
int lista_vazia(LISTA l);
int inserir_inicio(LISTA *l, double elem);
int inserir_posicao(LISTA *l, double elem, int pos);
int remove_posicao(LISTA *l, int pos);
int tamanho(LISTA *l);
double maior(LISTA *l);
int imprime_lista(LISTA l);
void clear();