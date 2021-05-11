/* Exercise 1-17.c. Write a program to print all input lines that are longer
than 80 characters. */

/* 1. Obtain Input
   2. Read characters into array (i.e. all characters + 1 because '\0')
   3. If use every bit of array, create a new array and copy characters into the new array */

#include <stdio.h>

#define STEP 5

int main(void)
{
  int i, j, c;
  int expected_chars = 10;
  int chars[expected_chars + 1];
  i = j = c = 0;

  /* Inititalize array */
  for (i = 0; i <= expected_chars; i++)
    chars[i] = 0;
  chars[expected_chars+1] = '\0';

  /* Read input */
  i = 0;
  while ((c = getchar()) != EOF)
  {
    chars[i] = c;
    i++;

    /* Handle more characters than expected by copying into a bigger array */
    int copy_chars[expected_chars + 1 + STEP];
    if (i == expected_chars)
    {
      for (j = 0; j <= expected_chars; j++)
      {
        copy_chars[j] = chars[j];
      }
      expected_chars = expected_chars + STEP;
      chars[expected_chars+1] = chars[expected_chars + 1];
      /* Inititalize array */
      for (i = 0; i <= expected_chars; i++)
        chars[i] = 0;
      chars[expected_chars + 1] = '\0';
      for (j = 0; j <= expected_chars && copy_chars[j] != '\0'; j++)
      {
        chars[j] = copy_chars[j];
      }

    }
  }

  /* Print array */
  for (i = 0; i <= expected_chars + 1; i++)
    printf("%c", chars[i]);

  return 0;
}
