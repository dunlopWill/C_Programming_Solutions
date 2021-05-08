/* Exercise 1-8. Write a program to count blanks, tabs and newlines. */

#include <stdio.h>

int main(void)
{
  int c, blanks, tabs, newlines;
  blanks = tabs = newlines = 0;

  printf("\nPlease type something then press Ctrl+D.\n\n");

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      ++blanks;
    if (c == '\t')
      ++tabs;
    if (c == '\n')
      ++newlines;
  }

  printf("\nThere are %d blanks, %d tabs and %d newlines.\n", blanks, tabs, newlines);

  return 0;
}
