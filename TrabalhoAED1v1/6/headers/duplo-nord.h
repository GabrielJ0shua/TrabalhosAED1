typedef struct node* list;

list initializeList();
int emptyList(list *header);
int insertNode(list *header, int data);
int removeNode(list *header, int data);
int listSize(list *header);
int getValue(list *header, int *output, int position);
int clearList(list *header);
int removeAll(list *header, int data);
int removeGreater(list *header, int *output);
int reverseList(list *header, list *reverse);
int threeMultiList(list *header, list *threeMultiples);