#include <stdio.h>
#include "fila.h"
#include <string.h>
int main()
{
    Fila f = NULL, f2 = NULL;
    int orgao, idade, gravidade;
    struct paciente input;
    int escolha= 0;
    while(escolha!=6)
    {
        printf("Manipulador de fila: \n");
        printf("[1] Cria fila \n");
        printf("[2] Inserir paciente\n");
        printf("[3] Remove inicio\n");
        printf("[4] Esvazia fila\n");
        printf("[5] Imprime fila\n");
        printf("[6] Sair\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
            case 1:
                if (f==NULL)
                    f = cria_fila();
                else
                    printf("Falha \n");
            break;
            case 2:
                printf("Digite o nome: \n");
                setbuf(stdin, NULL);
                scanf("%s", input.nome);
                printf("Digite a idade: \n");
                scanf("%d", &idade);
                printf("Digite 1 para x, 2 para x, 3 para x, 4 para x: \n");
                scanf("%d", &orgao);
                while(orgao<1||orgao>4)
                {
                    printf("Numero invalido: Digite 1 para x, 2 para x, 3 para x, 4 para x\n");
                    scanf("%d", &orgao);
                }
                printf("Digite o nivel de gravidade: \n");
                scanf("%d", &gravidade);
                input.gravidade=gravidade;
                input.orgao=orgao;
                input.idade=idade;

                if (insere_ord(f, input)==0)
                {
                    printf("Falha \n");
                }
            break;

            case 3:
                if (remove_inicio(f, &input)==0)
                {
                    printf("Falha \n");
                }
                else
                    printf("Inicio removido \n");
            break;

            case 4:
                if(esvazia_fila(f)==0)
                {
                    printf("Falha \n");
                }
                else
                {
                    printf("Fila esvaziada \n");
                }
            break;

            case 5:
                if(f!=NULL && fila_vazia(f)!=1)
                {
                    f2=cria_fila();
                    while(fila_vazia(f)!=1)
                    {
                        remove_inicio(f, &input);
                        printf("Orgao-%d Idade-%d\n Gravidade-%d Nome-%s\n", input.orgao, input.idade, input.gravidade, input.nome);
                        insere_ord(f2, input);
                    }
                    while(fila_vazia(f2)!=1)
                    {
                        remove_inicio(f2, &input);
                        insere_ord(f, input);
                    }
                    libera_fila(&f2);
                }
                else
                    printf("Falha, fila vazia \n");
            break;

            case 6:
                libera_fila(&f);
            break;

            default:
                printf("Escolha invalida");
        }
    }
    return 0;
}
