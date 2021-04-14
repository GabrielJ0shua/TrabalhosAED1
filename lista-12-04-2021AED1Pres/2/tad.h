struct pass{
        unsigned int mat;
        char nome[20];
        float me;
        int fal;
};
typedef struct pass Pass;
typedef struct caixa cad;
typedef struct caixa* lista;
lista *cria(void);
void libera (lista *li);
int insere(lista *li, Pass *aux);
int rem(lista *li,unsigned int b);
int pos(lista *li, unsigned int b, Pass *aux);
int imprime(lista *li, int i, Pass *aux);