/* Exercise 1-14. Write a program to print a histogram of the frequencies
of different characters in its input. */

#include <stdio.h>

int main(void)
{
  #define MAX_CHARS 100
  #define CHAR_IN_ARRAY 1
  #define CHAR_NOT_IN_ARRAY 0
  #define UPPER 10
  #define LOWER 1

  char characters[MAX_CHARS];
  int number_of_characters[MAX_CHARS];
  int c, i, j, white_space, state;

  c = i = j = white_space = 0;
  state = CHAR_NOT_IN_ARRAY;

  /* initialize arrays to 0 */
  for (i = 0; i <= MAX_CHARS; i++)
  {
    characters[i] = 0;
    number_of_characters[i] = 0;
  }
  /* obtain input */
  printf("Input text and then click Ctrl+D\n");
  while ((c = getchar()) != EOF)
  {
  state = CHAR_NOT_IN_ARRAY; /* reset state */
  /* evalulate if character is in array */
  for (i = 0; i <= MAX_CHARS; i++)
    if (c == characters[i])
    {
      state = CHAR_IN_ARRAY;
      number_of_characters[i]++;
    }
  for (i = 0; i <= MAX_CHARS; i++)
    if (characters[i] == 0 && state == CHAR_NOT_IN_ARRAY)
    {
      characters[i] = c;
      state = CHAR_IN_ARRAY;
      number_of_characters[i]++;
    }
  }

  /* Print the histogram */
  printf("\n\nFREQUENCY\n%s\n", "+");
  for (i = UPPER; i >= LOWER; i--) /* Print y axis */
  {
    printf("%2d", i);
    for (j = 0; j <= MAX_CHARS; j++)
    {
      if (characters[j] != 0 && number_of_characters[j] >= i)
        printf("%3s", "#");
      else
        printf("%3s", " ");
    }
    printf("\n");
  }

  printf("%3s", " ");
  for (i = 0; i <= MAX_CHARS; i++) /* Print x axis */
  {
    if (characters[i] != 0)
      {
        if (characters[i] == ' ')
          printf("' '");
        else if (characters[i] == '\t')
          printf(" \\t ");
        else if (characters[i] == '\n')
          printf(" \\n ");
        else
          printf(" %c ", characters[i]);
      }
  }
  printf(" CHARACTERS");

  printf("\n");
  return 0;
}
