typedef struct node* list;

list initializeList();
int emptyList(list *header);
int insertSoldier(list *header, char name[]);
int qtdSoldiers(list *header);
int startByFirst(list *header, int counter, char soldier[]);
int startByRandom(list *header, char startSoldier[], char ***outSoldier, int *startPosition);
int startByName(list *header, char startSoldier[], char ***outSoldier, int *counter);
void showSoldiers(list *header);
