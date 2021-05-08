#include <stdio.h>

/* Exercise 1-10. Write a program to copy its input to its output, replacing
each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs
and backspaces visible in an unambiguous way. */

int main(void)
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      printf("%s", "\\t");
    if (c == '\b')
      printf("%s", "\\b");
    if (c == '\\')
      printf("%s", "\\");
    /* else */
    {
      putchar(c);
    }
  }

return 0;
}
