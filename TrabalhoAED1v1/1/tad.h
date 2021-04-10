typedef struct numero lista;


lista *cria();
void libera(lista *li);
int tamanho(lista *li);
int vazia(lista *li);
int insercao(lista *li, int numero);
int remove_qualquer(lista *li, int numero);
int imprimir_lista(lista *li);
int remove_impar(lista *li);
int consulta_qualquer (lista *li, int numero, int *pos);
int consulta_menor (lista *li, int *menor);
int tamanho(lista *li);
int inverter_lista(lista *li, lista *aux);
int concatenar(lista *li, lista *li2, lista *li3);