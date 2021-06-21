struct Dados{
    char nome_do_soldado[20];
};
 
typedef struct soldado *Batalhao;
typedef struct Dados dado;
Batalhao* iniciaLista(void);
int insereFinal(Batalhao* l, dado valor);
void liberaLista(Batalhao* l);
int problemaDeJosephus(Batalhao* l,dado* soldado, int* qnt_percorrimento,int* escolha, int trigger);
int tamanhoLista(Batalhao* l);
int insereInicio(Batalhao* l, dado valor);