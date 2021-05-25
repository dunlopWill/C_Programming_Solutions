/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the same tab
stops as for detab (see Exercise 1-20). When either a tab or a single blanks
would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define MAX_INPUT 1000 /* Maximum input */
#define N_SPACES 8 /* Number of spaces in a tab */
#define REPLACE_W_SPACE '#' /* Replace with this character e.g. space */
#define REPLACE_W_TAB '%' /* Replace with this character e.g. space */

/*
1. Read all input into an array.
2. If a space character is followed by another, increment counter.
3. If counter <8, print spaces. While >= 8, print a tab and -8 from counter.
   Then print remaining spaces.
4. Else print characters.
*/

int main(void)
{
  char s[1000];
  int c, i, length, space_counter, j;

  i = length = space_counter = j = 0;

  while ((c = getchar()) != EOF)
  {
    s[i] = c;
    i++;
  }

  length = i;

  if (length > 0)
    for (i = 0; i <= length; i++)
    {
      if (s[i] != ' ') /* More efficient to print tabs, so only consider spaces */
      {
        if (space_counter > 0)
        {
          if (space_counter == 1)
            printf("%c", REPLACE_W_SPACE);
          else if (space_counter < N_SPACES)
          {
            j = space_counter;
            while (j < space_counter)
            {
              printf("%c", REPLACE_W_SPACE);
              j++;
            }
          }
          else if (space_counter >= N_SPACES)
          {
            while (space_counter >= N_SPACES)
            {
              printf("%c", REPLACE_W_TAB);
              space_counter = space_counter - N_SPACES;
            }
            if (space_counter < N_SPACES)
            {
              j = space_counter;
              while (j < space_counter)
              {
                printf("%c", REPLACE_W_SPACE);
                j++;
              }
            }
          }
        }
        /* Then print the non space character regardless */
        printf("%c", s[i]);
        space_counter = 0; /* and reset the counter */
      }
      else
      {
        space_counter++;
      }
    }

  return 0;
}
