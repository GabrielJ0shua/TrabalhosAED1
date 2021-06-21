#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED
 
typedef struct Dados{

	char nome[20];
	int idade;
	int comorbidade;
	char vacina;
	int dia1, mes1, ano1;
	int dia2, mes2, ano2;
	int local;

}dados;

typedef struct vacinas{

	int A;//Astrazeneca
	int P;//Pfizer
	int C;//Coronavac

}Vacinas;

int hospital;
 
#endif

#define N_HOSP 4