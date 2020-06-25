

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/*#include<tokenizer.h>*/
int space_char(char c);
int non_space_char(char c);
char *word_start(char *str);
char *word_terminator(char *str);
int count_words(char *str);
char *copy_str(char *inStr, short len);
char **tokenize(char *str);
void print_tokens(char **tokens);
int main()
{
  char str[20];
  printf("\n enter string: ");
  scanf("%[^\n]", str);

  printf("\nYou have entered: %s", str);

  int length = strlen(str);
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
  
  printf("\nLength of string: %d", length_final);
  printf("\nspaces : %d", spaces);
  printf("\nnon_spaces: %d", non_spaces);
  printf("\nnext space char: %c", *next_space);
  printf("\nnumber of words: %d", word_count);
  printf("\ncopy String: %c", *copy);
  char **tokens;
  tokens= tokenize(str);
  print_tokens(tokens);
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
  /*char *tokens[word_count+1];*/
  char **tokens =malloc (word_count + 1);
  
  char *beg = str;
  char *end =  word_terminator(beg);
  int i =0;
  for(;i<word_count;i++)
    {
      
      int word_length = end - beg;
      char *token = (char *) malloc(word_length + 1);
      token = copy_str(beg, word_length);
      /*    tokens[i]= &token; */
      tokens = &token;
      tokens++;
      beg = word_start(beg);
      end = word_terminator(beg);
      
    }
  /*tokens[i] = '0';*/
  tokens++;
  char zer = '0';
  char *last = &zer;
  tokens = &last;
  
  
  return tokens;
}

void print_tokens(char **tokens)
{
  printf("test: %c", tokens);
    
  

}
 
