

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "tokenizer.h"
#include "history.c"
int main()
{
  char str[20];
  printf("enter string:");
  scanf("%[^\n]", &str);
   List *history = init_history();
  while(strcmp(str, "quit") !=0)
    {

      
      printf("\nYou have entered: %s\n", str);
      int length = strlen(str);
      
            
	    
      add_history(history,str);
      if(strcmp(str, "!3") ==0)
	{
	  print_history(history);
	}
      int length_final =0;

      int spaces = 0;
      int non_spaces =0;
      for(int i =0; i<length; i++)
        {
          if(space_char(str[i])>0)
	    spaces++;
          if(non_space_char(str[i])>0)
	    non_spaces++;
          if(str[i] != ' ')
   	    length_final++;
        }
      char *ptr;
      char *next_space;
      ptr = str;
      next_space = word_start(str);
      char *copy;
      int word_count = count_words(str);
      copy = copy_str(str, length_final);
      char **tokens;
      tokens= tokenize(str);
      print_tokens(tokens);

      printf("Enter string:");
      scanf(" %[^\n]", &str);
      
    }
  return 0;
}

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;

  if(c=='\0')
    return 0;
  return 0;
}
int non_space_char(char c)
{
  if( c == ' ' || c == '\t' || c == '\0')
    return 0;
  else return 1;
}

char *word_start(char *str)
{
  char *ptr = str;
  while(non_space_char(*ptr))
    {
      ptr++;
    }
  while(space_char(*ptr))
    {
      ptr++;
    }
  
  return ptr; 
 } 


char  *word_terminator(char *word)
{
  while(non_space_char(*word))
    {
      word++;
    }
  
  return word; 
}
int count_words(char* str)
{
  int count = 0;
  char prev = '0';
  int i = 0;
  if(non_space_char(str[0])==1)
    count++;
  while(str[i]!= '\0')
    {
      if(str[i] != ' ' && prev == ' ')
	count++;
      prev = str[i];
      i++;
    }
  
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *new_word;
  new_word =(char *) malloc(len +1);
  
  int i =0;
  for(;i<len+1;i++)
    {
      new_word[i] =inStr[i];   
    }
  new_word[i] = '\0';
  return new_word;
}
char **tokenize(char* str)
{
  int word_count = count_words(str);
  
  char **tokens =malloc (sizeof(char *)*(word_count + 1));
  
  char *beg = str;
  char *end =  word_terminator(beg);
  int i =0;
  for(;i<word_count;i++)
    {
      
      int word_length = end - beg;
      
      char *token = copy_str(beg, word_length);
     
      tokens[i] = token;
      
      beg = word_start(beg);
      end = word_terminator(beg);
      
    }
  char var = '0';
  char *terminator = &var;
  tokens[i] = terminator;
  
  return tokens;
}

void print_tokens(char **tokens)
{
  
  int i=0;
  int j=0;
  
  /*TODO: tokens[2][0] = '0' is not being checked in the while condition 
    making it go further in the loop until error */
  
  while(tokens[i][j]!=NULL)
    {
      printf("Token #%d: ", i);      
      while(tokens[i][j] != '\0')
	{

	
	  printf("%c", tokens[i][j]);
	  j++;
	}
      printf("\n");
      i++;
      j=0;
      
      
      
    }
  
    
  

}
void free_tokens(char** tokens)
{
  char *ptr = *tokens;
  while(ptr != NULL)
    {
      free(ptr);
      ptr++;
    }
  free(ptr);
}
 
