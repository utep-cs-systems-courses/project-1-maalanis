
#include "history.h"
#include <stdlib.h>
#include <stdio.h>
List* init_history()
{
  List *head=NULL;
  Item *data = NULL;
  head = (List *) malloc (sizeof(List));
  head->root = (Item *) malloc (sizeof(Item));
  head->root->id = 0;
  head->root->next = NULL;
  head->root->str = NULL;
  
  
  
 
  /*
  head->root->id = 0;
  printf("Test %d",head->root->id);
  */
  
 
  return head;
  
}

void add_history(List *list, char *str)
{
  List *ptr = list;
  Item *root_ptr = ptr->root;
  
  while(root_ptr->next !=NULL)
    {
     
      root_ptr = root_ptr->next;
    }
  
  
      
  Item *data = (Item *) malloc(sizeof(Item));
  data->str = str; 
  data->id = root_ptr->id+1;
  printf("test: %d", data->id);
  data->next = NULL;
  root_ptr->next = data;
  
     
      
  
  
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
  List *ptr = list;  
  while(ptr->root->next != NULL)
    {
      char *word = ptr->root->str;
      printf("history: %s",word);
      ptr->root = ptr->root->next;
      /*
      while(*word != '\0')
	{
	  printf("%c", word);
	  word++;
	}
      */
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
