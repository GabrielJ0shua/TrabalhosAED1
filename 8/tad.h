struct termoEquacao
{
    int aux, aux1;
};
typedef struct termoEquacao Termo;
typedef struct equacaoCompleta *Funcao;
Funcao* criaLista(void);
int inserir(Funcao l,Termo equacao);
int pegaValores(Funcao l,Termo *equacao);
int removeElemento(Funcao l,float x);
void limpaEquacao(Funcao l);
int calculoPolinomio(Funcao l,float* x);
void libera(Funcao *l);