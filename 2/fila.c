#include "fila.h"
#include <stdlib.h>

struct unionTipo
{
    union parte valor;
    int tipo;
};

struct no
{
    struct unionTipo info;
    struct no * prox;
};

Pilha cria_pilha()
{
    return NULL;
}

void libera_pilha(Pilha*pi){
    if(pi != NULL){
        Pilha no;
        while ((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);        
    }
}

int pilha_vazia(Pilha* plh){
    if(plh==NULL)
        return 1;
    else
        return 0;
}

int push(Pilha * plh, union parte elem, int tipo)
{
    Pilha no = (Pilha) malloc(sizeof(*no));
    if (no==NULL)
        return 0;
    (no->info).valor = elem;
    (no->info).tipo = tipo;
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
        if((aux->info).tipo == 1)
        {
            switch ((aux->info).valor.cara)
            {
                case '(':
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, (aux->info).valor, 1);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == '{')
                            return 3;
                        push(&escopo, (aux->info).valor, 1);
                    }
                    break;
                case '[':
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, (aux->info).valor, 1);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == '(')
                            return 3;
                        push(&escopo, (aux->info).valor, 1);
                    }
                    break;
                case '{':
                    if(pilha_vazia(escopo)==1)
                    {
                        push(&escopo, (aux->info).valor, 1);
                    }
                    else
                    {
                        get_topo(escopo, &topo);
                        if(topo.valor.cara == '('||topo.valor.cara == '[')
                            return 3;
                        push(&escopo, (aux->info).valor, 1);
                    }
                    break;
                case ')':
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                        if(topo.valor.cara == '['||topo.valor.cara == '{')
                            return 4;
                    pop(&escopo, &topo);
                    break;
                case '}':
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                        if(topo.valor.cara == '['||topo.valor.cara == '(')
                            return 4;
                    pop(&escopo, &topo);
                    break;
                case ']':
                    if(pilha_vazia(escopo)==1)
                        return 2;
                    get_topo(escopo, &topo);
                        if(topo.valor.cara == '{'||topo.valor.cara == '(')
                            return 4;
                    pop(&escopo, &topo);
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
                    case '+':
                        prioridade[i] = 1;
                        break;
                    case '*':
                        prioridade[i] = 2;
                        break;
                    case '/':
                        prioridade[i] = 2;
                        break;
                    case '-':
                        prioridade[i] = 1;
                        break;
                    case '^':
                        prioridade[i] =3;
                        break;
                    case '(':
                        prioridade[i] =0;
                        break;
                    case '[':
                        prioridade[i] =0;
                        break;
                    case '{':
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
                case '[':
                push(&aux, (perc->info).valor, 1);
                    break;
                case '(':
                push(&aux, (perc->info).valor, 1);
                    break;
                case '{':
                push(&aux, (perc->info).valor, 1);
                    break;
                case '+':
                    while (pilha_vazia(aux)!=1)
                    {
                        flag_prioridade = prioridade((perc->info).valor.cara, (aux->info).valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, (perc->info).valor, 1);
                        }
                    }
                    push(&conv, (perc->info).valor, 1);
                break;
                case '*':
                    while (pilha_vazia(aux)!=1)
                    {
                        flag_prioridade = prioridade((perc->info).valor.cara, (aux->info).valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, (perc->info).valor, 1);
                        }
                    }
                    push(&conv, (perc->info).valor, 1);
                    break;
                case '/':
                    while (pilha_vazia(aux)!=1)
                    {
                        flag_prioridade = prioridade((perc->info).valor.cara, (aux->info).valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, (perc->info).valor, 1);
                        }
                    }
                    push(&conv, (perc->info).valor, 1);
                    break;
                case '-':
                    while (pilha_vazia(aux)!=1)
                    {
                        flag_prioridade = prioridade((perc->info).valor.cara, (aux->info).valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, (perc->info).valor, 1);
                        }
                    }
                    push(&conv, (perc->info).valor, 1);
                    break;
                case '^':
                    while (pilha_vazia(aux)!=1)
                    {
                        flag_prioridade = prioridade((perc->info).valor.cara, (aux->info).valor.cara);
                        if (flag_prioridade==1)
                        {
                            pop(&aux, &armazena);
                            push(&conv, (perc->info).valor, 1);
                        }
                    }
                    push(&conv, (perc->info).valor, 1);
                    break;
                case ']':
                    while ((aux->info).valor.cara != '[')
                    {
                        pop(&aux, &armazena);
                        push(&conv, (perc->info).valor, 1);
                    }
                    pop(&aux, &armazena);
                    break;
                case ')':
                    while ((aux->info).valor.cara != '(')
                    {
                        pop(&aux, &armazena);
                        push(&conv, (perc->info).valor, 1);
                    }
                    pop(&aux, &armazena);
                    break;
                case '}':
                    while ((aux->info).valor.cara != '{')
                    {
                        pop(&aux, &armazena);
                        push(&conv, (perc->info).valor, 1);
                    }
                    pop(&aux, &armazena);
                    break;
                default:
                    push(&conv, (perc->info).valor, 1);
                    break;
            }
        }
        perc = perc->prox;
    }
    *resultado = conv;
    return 1;
}

int avaliaçãoDaExpressao(Pilha plh, Pilha * resultado){
    if(converte_pos_fixo(plh, resultado) != 1) return 0;
    
}