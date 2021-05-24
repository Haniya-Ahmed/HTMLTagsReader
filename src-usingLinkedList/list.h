
#ifndef LIST_H

#define LIST_H

typedef struct listnode {
  struct listnode * next;
  char * tagName;
} Node;

Node * Node_construct(int c, char * tag);
Node * List_search_and_insert(Node * head, char * tag);
void List_print(Node * head);
#endif
