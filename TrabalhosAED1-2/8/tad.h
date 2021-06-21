struct dado
{
    int nu;
};

typedef struct dado Dado;
typedef struct elemento elem;
typedef struct Deque deque;

void liberaDeque(deque* dq);
deque* criaDeque();
int insere_inicio(deque* dq, Dado aux);
int insere_final(deque* dq, Dado aux);
int remove_inicio(deque* dq, Dado* aux);
int remove_final(deque* dq, Dado* aux);
int consultaFinal(deque* dq, Dado *aux);
int consultaInicio(deque* dq, Dado *aux);