#include <stdio.h>
#include <stdlib.h>
#include "duplo.h"
int main()
{
    Lista lst;
    lst = cria_lista;

    insere_elem(&lst, 3);
    insere_elem(&lst, 5);
    insere_elem(&lst, 9);
    imprime_lista(lst);

    printf("maior valor removido: %d", remove_maior(*lst));
    imprime_lista(lst);

    insere_elem(&lst, -13);
    insere_elem(&lst, 13);
    Lista lista_2 = inverte(&lst);
    imprime_lista(lista_2);

    lista_2 = primos(&lst);
    imprime_lista(lista_2);
    esvaziar(&lista_2);
    esvaziar(&lst);
    imprime_lista(lista_2);
    return 0;
}
