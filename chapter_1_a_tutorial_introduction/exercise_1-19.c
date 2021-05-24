/* Exercise 1-19. Write a function resverse(s) that reverses the character
    string s. Use it to write a program that reverses its input a line at
    a time. */

#include <stdio.h>
#define MAX_INPUT 1000 /* maximum input of characters size */

void reverse(char s[]);
void clean_s(char s[], int max_input);

int main(void)
{
  int c;
  int i = 0;
  char s[MAX_INPUT];

  /* Inititalize the array */
  clean_s(s, MAX_INPUT);

  /* Reset increment variable */
  i = 0;

  printf("Type a line, hit enter and watch it return the string reversed.\n");
  printf("To exit click Ctrl+D.\n");
  while ((c = getchar()) != EOF)
  {
    if (c != '\n')
    {
      s[i] = c;
      i++;
    }
    else
    {
      reverse(s);
      clean_s(s, MAX_INPUT);
      i = 0;
    }
  }

  return 0;
}

/* Function that reverses the character string s. */
void reverse(char s[])
{
  for (int i = MAX_INPUT; i >= 0; i--)
    if (s[i] != '\0')
    {
      printf("%c", s[i]);
    }
  printf("\n");
}

/* Function that sets values in array to '\0' */
void clean_s(char s[], int max_input)
{
  for (int i = 0; i <= max_input; i++)
    s[i] = '\0';
}
