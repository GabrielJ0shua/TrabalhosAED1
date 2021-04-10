typedef struct node *LISTA;

LISTA inicializar_lista();
int lista_vazia(LISTA l);
int insere_ord(LISTA *l, int potencia, int coeficiente);
int remove_ord(LISTA *l, int potencia);
double calc_px(LISTA *l, double x);
int imprime_lista(LISTA *l);
void reinicializa_polinomio(LISTA *l);
void clear();