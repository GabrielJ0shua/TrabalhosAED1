#define MAX 15

struct elemento
{
    int nu;
};

typedef struct elemento elem;
typedef struct Deque deque;

void liberaDeque(deque* dq);
deque* criaDeque();
int insere_inicio(deque* dq, elem aux);
int insere_final(deque* dq, elem aux);
int remove_inicio(deque* dq, elem* aux);
int remove_final(deque* dq, elem* aux);
int consultaFinal(deque* dq, elem *aux);
int consultaInicio(deque* dq, elem *aux);