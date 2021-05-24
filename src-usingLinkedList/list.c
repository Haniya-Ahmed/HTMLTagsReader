#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Node * Node_construct(int c, char * tag)
{
  Node * n = malloc(sizeof(Node));
  n-> tagName = malloc(sizeof(char)*(c+1));
  strcpy(n->tagName, tag);
  n-> next = NULL;
}

Node * List_search_and_insert(Node * head, char * tag)
{
  Node * ptr = Node_construct(strlen(tag), tag);
  bool dublicate_tag = false;
  if(head == NULL){
    head = ptr;
    //printf("Inserted tag %s\n", ptr->tagName);
  }
  else if(strcmp(head->tagName, tag) == 0 && head !=NULL && tag !=NULL){
    dublicate_tag = true;
    printf("Dublicate tag\n");
  }

  else{
    Node * p = head;
    while(p->next != NULL){
      p = p->next;
      if(strcmp(p-> tagName, tag)==0 && p!= NULL && tag!= NULL){
        dublicate_tag = true;
        break;
      }
    }
    if(!dublicate_tag){
      p->next = ptr;
      //printf("Inserted tag %s\n", ptr->tagName);
    }
  }
  return head;
}

void List_print(Node * head)
{
  while(head != NULL)
  {
    printf("%s\n",head->tagName);
    head = head->next;
  }
}
