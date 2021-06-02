#include <string.h>
#include <time.h>

#define MAX_PLACA 8
#define MAX_CAR 10
#define MAX_BOXE 5 //ultimo boxe eh a fila de espera

typedef struct ESTACIONAMENTO *Estacionamento;

struct info_carro{

	char placa[MAX_PLACA];
	char servico;
	time_t entrada;

};
typedef struct info_carro Carro;

struct FILA{

	int ini, cont;
	Carro info[MAX_CAR];

};
typedef struct FILA Fila;

Estacionamento cria_fila();
int cheio(Estacionamento F);
int vazio(Estacionamento F);
int insere_fim(Estacionamento F, Carro *New_info);
int remove_placa(Estacionamento F, Carro *Busca_placa);
int tamanho(Estacionamento F, int fila, int *tam);
int get_inicio(Estacionamento F, int fila, Carro *Busca_placa);
void libera_fila(Estacionamento *F);
