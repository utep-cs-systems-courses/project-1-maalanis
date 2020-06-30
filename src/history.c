

// This file makes a list to keep track of the input strings on tokenizer.c

#include "history.h"
#include <stdlib.h>
#include <stdio.h>

// returns a pointer to an allocated space for List
List* init_history()
{
  List *head=NULL;
  head = (List *) malloc (sizeof(List));
  head->root = (Item *) malloc (sizeof(Item));
  head->root->id = 0;
  head->root->next = NULL;
  head->root->str = NULL; 
  return head;
}

//adds a pointer to an allocated space of Item
void add_history(List *list, char *str)
{
  List *head = list;
  Item *ptr = head->root;
  int count =0;
  while(ptr->next!=NULL)
    {
      printf("YO: %s", ptr->str);
      printf("Test: %d", ptr->id);
      ptr = ptr->next;
      count++;
    }
      
      ptr->next = (Item *) malloc (sizeof(Item));
      ptr->next->id = count;
      ptr->next->str = str;
      
      ptr->next->next = NULL;
 
}
//returns pointer to the word in the position id
char *get_history(List *list, int id)
{
  return list->root[id].str;
}

//prints history
void print_history(List *list)
{
  List *head = list;
  Item *ptr = head->root;
  while(ptr != NULL)
    {
      printf("History: %s", ptr->str);
      ptr = ptr->next;
      printf("\n");
    }
}
// frees memory used for storing the history
void free_history(List *list)
{
  while(list != NULL)
    {
      free(list);
      list++;
    }
  free(list);
}
