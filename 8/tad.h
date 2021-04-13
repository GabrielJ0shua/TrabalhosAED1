struct termoEquacao
{
    int An,Xn;
};
typedef struct termoEquacao Termo;
typedef struct equacaoCompleta *Funcao;
Funcao* criaLista(void);
int inserirOrdenado(Funcao *l,Termo equacao);
int pegaValores(Funcao l,Termo *equacao);
int removeElemento(Funcao l,float x);
void limpaEquacao(Funcao *l);
int calculoPolinomio(Funcao *l,float* x);
void libera(Funcao *l);
int tamanhoDalista(Funcao *l);