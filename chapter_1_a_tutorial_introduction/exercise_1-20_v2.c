/* Exercise 1-20. Write a program detab that replaces tabs in the input with
the proper number of blanks to space to the next tab stop. Assume a fixed set
of tab stops, say every n columns. Should n be a variable or a symbolic
parameter? */

#include <stdio.h>

#define N_SPACES 8 /* Number of spaces in a tab */
#define REPLACE_CHAR ' ' /* Replace tabs with this character e.g. space */

int detab(int counter, int spaces, char replacement_character);

int main(void)
{
  int c, i, char_counter;

  char_counter = 0; /* count number of characters in a line */

/* For each line of input, replace tabs with N_SPACES spaces */
printf("Please type something. Click Ctrl+D to exit.\n");
  while ((c = getchar()) != EOF)
  {
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
      char_counter = detab(char_counter, N_SPACES, REPLACE_CHAR); /* reset counter */
    }
  }
  return 0;
}

int detab(int counter, int spaces, char replacement_character)
{
  int i = 0;
  if (counter > spaces)
  {
    while (counter > spaces)
      counter = counter - spaces;
  }
  while (i < (spaces - counter)) /* print space characters */
  {
    printf("%c", replacement_character);
    i++;
  }
  return 0; /* reset counter */
}
