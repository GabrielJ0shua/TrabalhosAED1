typedef struct soldado *Soldado;

Soldado iniciaLista(void);
int inserir(Soldado l, char* nome_do_soldado);
int removeDoInicio(Soldado l, char* nome_do_soldado);
int removeAleatorio(Soldado l, char* nome_do_soldado);
int removeComPosicao(Soldado l,int i, char* nome_do_soldado);
void liberaLista(Soldado l);