#include "fila.h"
#include <stdio.h>
#include <string.h>

int main(){
    Pilha pi = cria_pilha();
    Pilha resultado = cria_pilha();
    int opc=0, i, j;
    int tam = 0, tamanho;
    struct unionTipo elem;
    char express[22];
    while(opc!=2)
    {
        printf("\n1 - Entra com a expressao\n2 - Sair\n");
        scanf("%d",&opc);
        if(opc==1)
        {
            while(pilha_vazia(pi)==1)
            {
                gets(express);
                tamanho = strlen(express);
                for (j=0;j<tamanho;j++)
                    {
                        elem.valor.cara = express[j];
                        elem.tipo = 1;
                        printf("%c",elem.valor.cara);
                        i = push(&pi, elem);
                        if(i==2)
                        {
                            printf("Falha no caractere %d, use apenas letras maiusculas de A ate F ou +, -, *, /, ^, (, ), [, ], {, }\n", (j+1));
                            liberaPilha(&pi);
                            break;
                        }
                        else if (i==0)
                        {
                            printf("Falha");
                            liberaPilha(&pi);
                            break;
                        }
                    }
            }
            int i=converte_pos_fixo(pi, &resultado);
            if(i!=0 && i!=1)
            {
                switch (i)
                {
                    case 2:
                        printf("Fechamento de escopo sem abertura respectiva\n");
                        return 0;
                    case 3:
                        printf("Prioridade de escopo nao respeitada: Ordem {, [, (\n");
                        return 0;
                    case 4:
                        printf("Escopo aberto nao foi fechado corretamente\n");
                        return 0;
                    default:
                        printf("Erro desconhecido");
                        return 0;
                }
            }
            i = encontra_literais(resultado,&pi);
            if(i==0)
            {
                printf("Literais nao encontradas.\n");
                return 0;
            }
            tam = tamanho_pilha(pi);
            char literais[tam];
            double doubles[tam];
            for(int k=0; k<tam; k++)
            {
                pop(&pi, &elem);
                literais[k]=elem.valor.cara;
                printf("Escolha o valor pra literal %c\n", elem.valor.cara);
                scanf("%lf",&doubles[k]);
            }
            double fim;
            i = avalia_expressao(resultado, literais, doubles, tam, &fim);
            if(i!=1)
            {

            }

        }

        else if (opc == 2)
            liberaPilha(&pi);
        else
            printf("\nOpção invalida...");

        }
    liberaPilha(&pi);
    return 1;
}

