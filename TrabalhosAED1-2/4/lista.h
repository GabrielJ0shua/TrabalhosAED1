#include "struct.h"

typedef struct cabecalho *Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int insere_nao_ordenado(Lista li, dados p);
int remover_inicio(Lista li, dados *p);
int maior_idade(Lista li, dados *p);
int menor_data(Lista li, dados *p);
void libera(Lista *li);