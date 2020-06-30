//tokenizer file
//this program reads a string, and stores it in a allocated memory
//that is read inside an array of pointers 

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
  
  // Initialize the history pointer.
  List *history = init_history();
  
  // Quit sequence
  while(compare(str, "EOF") != 0) 
    {
      printf("\nYou have entered: %s\n", str);
      int length = strlen(str);     
      int length_final =0;
      int spaces = 0;
      int non_spaces =0;

      // For loop counts spaces and non_spaces
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
      if(compare(copy, "!*") !=0 && copy[0]-'!' != 0)
	{
	  add_history(history, copy);
	}
      if(compare(copy,"!*") ==0)
	{
	  print_history(history);
	}
      if(copy[0] - '!' == 0 && copy[1]>=48 && copy[1]<=57)
	{
	  get_history(history, copy[1]);

	}
      char **tokens;
      if(compare(copy, "!*") !=0 && copy[0]-'!' != 0){
	tokens=tokenize(str);
	print_tokens(tokens);
      }
      

      printf("Enter string:");
      scanf(" %[^\n]", &str);
      
    }
  return 0;
}
// Returns number of spaces
int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;

  if(c=='\0')
    return 0;
  return 0;
}
// Returns non space characters
int non_space_char(char c)
{
  if( c == ' ' || c == '\t' || c == '\0')
    return 0;
  else return 1;
}
// returns pointer to the start of the next word after space
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

// Returns pointer to the end of a word
char  *word_terminator(char *word)
{
  while(non_space_char(*word))
    {
      word++;
    }
  
  return word; 
}
// Returns integer of words in str
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
// Returns pointer of an allocated copy of inStr till lenght len
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

// Returns double pointer with tokens in format:
//tokens[0] = "hello\0"
//tokens[1] = "world\0"
//tokens[2] = "0"
char **tokenize(char* str)
{
  int word_count = count_words(str);
  char **tokens =malloc (sizeof(char *)*(word_count + 1));
  char *beg = str;
  char *end =  word_terminator(beg);
  int i =0;  
  for(;i<word_count;i++)
    {
      int word_length = end - beg; // Subtracts pointers to copy word from string
      char *token = copy_str(beg, word_length);
      tokens[i] = token;

      // Switches pointers for next copy_str
      beg = word_start(beg); 
      end = word_terminator(beg);
    }

  // Make last index of tokenz === "0"
  char var = '0';
  char *terminator = &var;
  tokens[i] = terminator;
  return tokens;
}

void print_tokens(char **tokens)
{
  
  int i=0;
  int j=0;
  
  
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
  printf("\n");

}
// Free the allocated space
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
 
int compare (char *str1, char *str2)
{
  int i =0;
  while(str1[i] == str2[i])
    {
      if(str1[i]== '\0' && str2[i] == '\0')
	break;

      i++;
      
    }
  return str1[i] - str2[i];

}
