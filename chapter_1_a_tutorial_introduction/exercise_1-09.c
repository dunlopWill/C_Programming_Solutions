#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output, replacing
string of one or more blanks by a single blank */

int main(void)
{

int c;
int blank;

blank = 0;

while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      if (blank == 0)
        putchar(c);
        blank = 1;
    }
    /* else */
    {
      putchar(c);
      blank = 0;
    }
  }

return 0;
}
