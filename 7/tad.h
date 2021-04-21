struct Dados{
    char nome_do_soldado[20];
};
 
typedef struct soldado *Batalhao;
typedef struct Dados dado;
Batalhao* iniciaLista(void);
int inserirFinal(Batalhao* l, char* nome_do_soldado);
int removeDoInicio(Batalhao* l);
int removeAleatorio(Batalhao* l, char* nome_do_soldado);
int removeComPosicao(Batalhao* l,int i, char* nome_do_soldado);
void liberaLista(Batalhao* l);
int problemaDeJosephus(Batalhao* l,dado* soldado, int qnt_percorrimento,int escolha);
int tamanhoLista(Batalhao* l);
int insereInicio(Batalhao* l, dado valor);