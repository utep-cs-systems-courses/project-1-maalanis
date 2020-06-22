#include<stdio.h>
#include<string.h>
#include<tokenizer.h>
int main()
{
  char str[20];
  printf("\n enter string: ");
  scanf("%[^\n]", str);

  printf("\nYou have entered: %s", str);

  int length = strlen(str);
  int length_final =0;
  for(int i =0; i<length; i++)
    {
      if(str[i] != ' ')
	length_final++;
    }
  printf("\nLength of string: %d", length_final);

  return 0;
}

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;

  if(c=='0')
    return 0;
}
int non_space_char(char c)
{
  if( c == ' ' || c == '\t')
    return 0;
  else return 1;
}
char word_start(char *str)
{
  char previous = '0';
  while(*str!= '\0')
    {
      if(*str != ' ' && previous == ' ')
	return str;
      previous = *str;
      str++
    }
  return 0;
}
char  *word_terminator(char *word)
{
  while(*word != '\0')
    {
      word++;
    }
  char *terminator_pointer = word++;
  return terminator_pointer; 
}
int count_words(char* str)
{
  int count = 0;
  char prev = '0';
  while(str!= '\0')
    {
      if(str != ' ' && prev == ' ')
	count++;
      prev = str;
      str++;
    }
  return count;
}
char *copy_str(char *inStr, short len)
{
  char *new_word;
  newWord =(char *) malloc(len +1);
  char *temp = newWord;
  while(inStr!='\0')
    {
      temp = inStr;
      inStr++;
      temp++;
    }
  return newWord;
}
