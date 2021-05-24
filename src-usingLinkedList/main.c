#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
  int limit = 100000;
  char input[limit];
  Node * head = NULL;

  if (argc != 2){
    printf("file not found\n");
    return EXIT_FAILURE;
  }

   FILE* fptr = fopen(*(argv+1), "r");
   if (fptr == NULL)
       return EXIT_FAILURE;

    //reading in html file
    int i =0;
    int ch = fgetc(fptr);
    while(ch != EOF){
      input[i] = ch;
      i++;
      ch = fgetc(fptr);
    }
    input[i] = '\0';

    //read tags.
    int j;
    for(j =0; j<limit && (input[j] != '\0'); j++)
    {
      if((input[j]== '<') && (input[j+1] != '/')  && (i+1 < limit))
      {
        char tag[10] ="";
        j++;
        char c = input[j];
        do {
          strncat(tag, &c,1);
          j++;
          c = input[j];
        } while(c != '>' && !(isspace(c)));
        head = List_search_and_insert(head, tag);
      }//if c == '>'.
    }//for loop outer.

    printf("Tags In the Linked List:\n");
    List_print(head);
}
