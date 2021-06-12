#define MAX_NOME 20

typedef struct fila *Fila;

typedef struct Aluno{

	int matricula;
	char nome[MAX_NOME];
	double cra;
	int ano;

}aluno;

Fila cria_fp();
int fp_vazia(Fila f);
int fp_cheia(Fila f);
int inserir(Fila f, aluno *al);
int remover(Fila f, aluno *al);
void esvazia_fp(Fila f);
void libera_fp(Fila *f);

