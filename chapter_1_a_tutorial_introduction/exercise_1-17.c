/* Exercise 1-17.c. Write a program to print all input lines that are longer
than 80 characters. */

#include <stdio.h>

int get_line_length();

int main(void)
{

  printf("%d", get_line_length());

  return 0;
}

int get_line_length()
{
  int c, i, s[];
  i = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\0' || c == '\n')
      return i;
    i++;
    s[i] = c;
  }
}
