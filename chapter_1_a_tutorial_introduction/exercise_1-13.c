/* Exercise 1-13. Write a program to print a histogram of the lengths of words
in its input. It is easy to draw the histogram with the bars horizontal; a
vertical orientation is more challenging */

#include <stdio.h>

int main(void)
{
  #define OUT 0
  #define IN 1
  #define UPPER 10 /* Upper histogram x and y axis limit */
  #define LOWER 1  /* Lower histogram x and y axis limit */

  int c, state, counter, i, j, k, l;
  int ndigits[UPPER+1];

  c = counter = 0;
  state = OUT;

  /* Inititalize the array */
  for (i = 0; i <= UPPER; i++)
    ndigits[i] = 0;

  printf("Please type input then click Ctrl+D.\n");

  /* Count length of each word */
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      if (counter <= UPPER)
        ndigits[counter]++;
      else
      {
        counter = UPPER;
        ndigits[counter]++;
      }
      counter = 0;
    }
    else
      state = IN;

    if (state == IN)
      counter++;
  }

  /* Print the histogram */
  printf("\n\nFREQUENCY\n%s\n", "+");

  for (j = UPPER; j >= LOWER; j--) /* Print y axis */
  {
    printf("%2d", j);
    for (k = LOWER; k <= UPPER+1; k++) /* Print histogram hashes */
    {
      if (ndigits[k] >= j)
        printf("%3s", "#");
      else
        printf("%3s", " ");
    }
    printf("\n");
  }

  printf("%2s", " ");
  for (l = LOWER; l <= UPPER; l++) /* Print x axis */
    printf("%3d", l);
  printf("+ LENGTH");

  printf("\n");
  return 0;
}
