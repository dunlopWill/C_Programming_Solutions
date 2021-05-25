/* Exercise 1-20. Write a program detab that replaces tabs in the input with
the proper number of blanks to space to the next tab stop. Assume a fixed set
of tab stops, say every n columns. Should n be a variable or a symbolic
parameter? */

#include <stdio.h>

#define N_SPACES 8 /* Number of spaces in a tab */
#define REPLACE_CHAR ' ' /* Replace tabs with this character e.g. space */

int main(void)
{
  int c, i, char_counter;

  char_counter = 0; /* count number of characters in a line */

/* For each line of input, replace tabs with N_SPACES spaces */
printf("Please type something. Click Ctrl+D to exit.\n");
  while ((c = getchar()) != EOF)
  {
    i = 0; /* reset i */
    if (c != '\t' && c != '\n')
    {
      putchar(c);
      char_counter++;
    }
    else if (c == '\n') /* handle new lines */
    {
      putchar(c);
      char_counter = 0; /* reset counter */
    }
    else /* character is a tab */
    /* Replace tabs in the input with the proper number of blanks to space
    to the next tab stop. */
    {
      if (char_counter > N_SPACES)
      {
        while (char_counter > N_SPACES)
          char_counter = char_counter - N_SPACES;
      }
      while (i < (N_SPACES - char_counter)) /* print space characters */
      {
        printf("%c", REPLACE_CHAR);
        i++;
      }
      char_counter = 0; /* reset counter */
    }
  }
  return 0;
}
