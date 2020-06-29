
#include "history.h"
#include <stdlib.h>
#include <stdio.h>
List* init_history()
{
  List *head=NULL;
  head = (List *) malloc (sizeof(List));
  head->root->id = 0;
  
  
  
 
  /*
  head->root->id = 0;
  printf("Test %d",head->root->id);
  */
  
 
  return head;
  
}

void add_history(List *list, char *str)
{
  List *ptr = list;
  if(ptr == NULL)
    printf("heeere");
  /*
  while(ptr->root->next !=NULL)
    {
      ptr->root = ptr->root->next;
    }
  */
  int id = 0;
      

      struct s_Item newItem;
      newItem.str = str;
      printf("test %s", newItem.str);
      newItem.id = id+1;
      printf("test 2 %d", newItem.id);
      struct s_Item *next = NULL;
      newItem.next = next;
      ptr->root->next = &newItem;
      
  
  
  /*
  struct s_Item newItem;
  newItem.str = str;
  printf("%c", str);
  newItem.id = list->root->id+1;
  printf("%d", newItem.id);
  list->root->next = &newItem;
  */
}

char *get_history(List *list, int id)
{
  
  return list->root[id].str;
}

void print_history(List *list)
{
  
  while(list->root != NULL)
    {
      char *word = list->root->str;
      while(*word != '\0')
	{
	  printf("%c", word);
	  word++;
	}
      
      printf("\n");
     
    }
}

void free_history(List *list)
{
  while(list != NULL)
    {
      free(list);
      list++;
    }
  free(list);
}
