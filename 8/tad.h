struct termoEquacao
{
    float aux, aux1;
};
typedef struct termoEquacao Termo;
typedef struct equacaoCompleta *comple;
comple criaLista(void);
int inserir(comple l,Termo equacao);
int pegaValores(comple l,Termo *equacao);
int removeElemento(comple l,float x);
void limpaEquacao(comple l);
int calculoPolinomio(comple l,float* x);
void libera(comple l);