#include "history.h"
#include <stdlib.h>
#include <stdio.h>
List* init_history()
{
  struct s_List list;
  
}

void add_history(List *list, char *str)
{
  
  while(list->root->next != NULL)
    {
      list->root = list->root->next;
      
    }
  
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
