

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
  return head;
}

//adds a pointer to an allocated space of Item
void add_history(List *list, char *str)
{    
  List *ptr = list;
  Item *tmp = ptr->root;
  while(tmp->next != NULL)
    {
      tmp = tmp->next; 
    }
  tmp->next = (Item *) malloc (sizeof(Item));
  tmp->next->id = tmp->id+1;
  tmp->next->str = str;
  if(list->root->str == NULL){
    list->root = list->root = list->root->next;
  }
  printf("String inserted: %s \n", tmp->next->str);
    
}
//returns pointer to the word in the position id
char *get_history(List *list, int id)
{
  
  List *head = list;
  Item *ptr = head->root;
  while(ptr != NULL)
    {
      if(ptr->id == id-48)
	{
	  printf("String at ID: %d is %s\n", id-48, ptr->str);
	return ptr->str;
	}
      ptr = ptr->next;
    }
  return list->root->str;
}

//prints history
void print_history(List *list)
{
  List *head = list;
  Item *ptr = head->root;
  while(ptr != NULL)
    {
   
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
