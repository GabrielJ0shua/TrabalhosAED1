typedef struct caixa cad;
typedef struct caixa* lista;
lista *cria(void);
void libera (lista *li);
int ord(lista *li,int l);
int rem(lista *li,int b);
int pos(lista *li,int b, int *aux);
int imprime(lista *li, int i, int *aux);