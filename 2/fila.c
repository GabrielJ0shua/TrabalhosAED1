#include "fila.h"
#include <stdlib.h>

struct no
{
    struct unionTipo info;
    struct no * prox;
};

Pilha cria_pilha()
{
    return NULL;
}

void liberaPilha(Pilha*pi){
    if(*pi != NULL){
        Pilha no;
        while ((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(*pi);
    }
    *pi = NULL;
}

int pilha_vazia(Pilha plh){
    if(plh==NULL)
        return 1;
    else
        return 0;
}

int push(Pilha * plh, struct unionTipo elem)
{
    Pilha no = (Pilha)malloc(sizeof(*no));
    if (no==NULL)
        return 0;
    if(elem.tipo == 1)
    {
        if(elem.valor.cara <65 || elem.valor.cara>70)
        {
            switch (elem.valor.cara)
            {
                case 40:
                case 41:
                case 42:
                case 43:
                case 45:
                case 47:
                case 91:
                case 93:
                case 94:
                case 121:
                case 123:
                case 125:
                    break;
                default:
                    return 2;
            }
        }
    }
    no->info = elem;
    no->prox = *plh;
    *plh= no;
    return 1;
}


int pop(Pilha * plh, struct unionTipo * elem){
    if (pilha_vazia(*plh) == 1)
        return 0;
    *elem = (*plh)->info;
    Pilha aux = *plh;
    *plh = (*plh)->prox;
    free(aux);
    return 1;
}

int get_topo(Pilha plh, struct unionTipo * elem)
{
    if (pilha_vazia(plh) == 1)
        return 0;
    *elem = plh->info;
    return 1;
}

int valida_escopo(Pilha plh){
    if(pilha_vazia(plh) == 1)
        return 0;
    Pilha aux = plh;
    Pilha escopo = cria_pilha();
    struct unionTipo topo;
    while (pilha_vazia(aux)!=1)
    {
        if(aux->info.tipo == 1)
        {
            switch (aux->info.valor.cara)
            {
                case (40):
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, aux->info);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == 123)
                            return 3;
                        push(&escopo, aux->info);
                    }
                    break;
                case (91):
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, aux->info);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == 40)
                            return 3;
                        push(&escopo, aux->info);
                    }
                    break;
                case (123):
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, aux->info);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == 40||topo.valor.cara == 91)
                            return 3;
                        push(&escopo, aux->info);
                    }
                    break;
                case (41):
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                    while (topo.valor.cara!=91)
                    {

                        if(topo.valor.cara == 91||topo.valor.cara == 123)
                            return 4;
                        pop(&escopo, &topo);
                    }

                    break;
                case (125):
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                    while (topo.valor.cara!=91)
                    {

                        if(topo.valor.cara == 91||topo.valor.cara == 40)
                            return 4;
                        pop(&escopo, &topo);
                    }
                    break;
                case (93):
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                    while (topo.valor.cara!=91)
                    {

                        if(topo.valor.cara == 123||topo.valor.cara == 40)
                            return 4;
                        pop(&escopo, &topo);
                    }
                    break;
                default:
                    break;
            }
        }
        aux = aux->prox;
    }
    return 1;
}

int prioridade (char a, char b)
{
    int prioridade[2];
    char vetor[2];
    vetor[0]=a;
    vetor[1]=b;
    int i=0;
    while(i<2)
    {


        switch (vetor[i])
        {
                    case (43):
                        prioridade[i] = 1;
                        break;
                    case (42):
                        prioridade[i] = 2;
                        break;
                    case (47):
                        prioridade[i] = 2;
                        break;
                    case (45):
                        prioridade[i] = 1;
                        break;
                    case (94):
                        prioridade[i] =3;
                        break;
                    case (40):
                        prioridade[i] =0;
                        break;
                    case (91):
                        prioridade[i] =0;
                        break;
                    case (123):
                        prioridade[i] =0;
                        break;
                    default:
                        return-1;
        }
        i++;
    }
    if (prioridade[0]<=prioridade[1])
        return 1;
    else
        return 2;
}

int converte_pos_fixo(Pilha plh, Pilha * resultado){
    int flag = valida_escopo(plh);
    if(flag!=1&& flag != 0)
        return flag;
    Pilha conv = cria_pilha(), aux = cria_pilha();
    Pilha perc = plh;
    struct unionTipo armazena;
    int flag_prioridade;
    while (pilha_vazia(perc)!=1)
    {
        if((perc->info).tipo==1)
        {
            switch ((perc->info).valor.cara)
            {
                case (91):
                push(&aux, perc->info);
                break;
                case (40):
                push(&aux, perc->info);
                break;
                case (123):
                push(&aux, perc->info);
                break;
                case (43):
                    while (flag_prioridade==1||pilha_vazia(aux)==1)
                    {
                        flag_prioridade = prioridade(perc->info.valor.cara, aux->info.valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, perc->info);
                        }
                    }
                    push(&conv, perc->info);
                    flag_prioridade=1;
                    break;
                case (42):
                    while (flag_prioridade==1||pilha_vazia(aux)==1)
                    {
                        flag_prioridade = prioridade(perc->info.valor.cara, aux->info.valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, perc->info);
                        }
                    }
                    push(&conv, perc->info);
                    flag_prioridade=1;
                    break;
                case (47):
                    while (flag_prioridade==1||pilha_vazia(aux)==1)
                    {
                        flag_prioridade = prioridade(perc->info.valor.cara, aux->info.valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, perc->info);
                        }
                    }
                    push(&conv, perc->info);
                    flag_prioridade=1;
                    break;
                case (45):
                    while (flag_prioridade==1||pilha_vazia(aux)==1)
                    {
                        flag_prioridade = prioridade(perc->info.valor.cara, aux->info.valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, perc->info);
                        }
                    }
                    push(&conv, perc->info);
                    flag_prioridade=1;
                    break;
                case (94):
                    while (flag_prioridade==1||pilha_vazia(aux)==1)
                    {
                        flag_prioridade = prioridade(perc->info.valor.cara, aux->info.valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, perc->info);
                        }
                    }
                    push(&conv, perc->info);
                    flag_prioridade=1;
                    break;
                case (93):
                    while (aux->info.valor.cara != 91)
                    {
                        pop(&aux, &armazena);
                        push(&conv, perc->info);
                    }
                    pop(&aux, &armazena);
                    break;
                case (41):
                    while (aux->info.valor.cara != 40)
                    {
                        pop(&aux, &armazena);
                        push(&conv, perc->info);
                    }
                    pop(&aux, &armazena);
                    break;
                case (125):
                    while (aux->info.valor.cara != 123)
                    {
                        pop(&aux, &armazena);
                        push(&conv, perc->info);
                    }
                    pop(&aux, &armazena);
                    break;
                default:
                    push(&conv, perc->info);
                    break;
            }
        }
        perc = perc->prox;
    }
    *resultado = conv;
    return 1;
}

int tamanho_pilha(Pilha plh)
{
    if(pilha_vazia(plh)==1)
        return 0;
    int i=0;
    Pilha aux = plh;
    while(pilha_vazia(aux)!=1)
    {
        i++;
        aux= aux->prox;
    }
    return i+1;
}
int encontra_literais(Pilha plh, Pilha * literal)
{
    if(pilha_vazia(plh)==1)
        return 0;
    liberaPilha(literal);
    Pilha aux= plh;
    char lista[6]= "------";
    int i=0, j=0;
    while (pilha_vazia(aux)!=1)
    {
        if(aux->info.valor.cara >64 && aux->info.valor.cara<71)
        {
            while(i<6)
            {
                if(aux->info.valor.cara==lista[i])
                {
                    break;
                }
                if(i==5)
                {
                    lista[j]=aux->info.valor.cara;
                    push(literal, aux->info);
                    j++;
                }
                i++;
            }
            i=0;
        }
        aux=aux->prox;
    }
    return 1;
}

int avalia_expressao(Pilha plh, char literais[], double doubles[], int tam , double * fim)
{
    Pilha aux = plh;
    Pilha valores = cria_pilha();
    Pilha operandos = cria_pilha();
    return 0;
}
