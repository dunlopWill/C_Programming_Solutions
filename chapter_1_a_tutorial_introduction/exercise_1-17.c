/* Exercise 1-17.c. Write a program to print all input lines that are longer
than 80 characters. */

/* 1. Obtain Input
   2. Read characters into array (i.e. all characters + 1 because '\0')
   3. If use every bit of array, create a new array and copy characters into the new array */

#include <stdio.h>

#define EXPECTED_CHARS 10

int main(void)
{
  int i, c, copy_chars;
  int chars[EXPECTED_CHARS + 1];

  i = c = 0;

  /* Inititalize array */
  for (i = 0; i <= EXPECTED_CHARS; i++)
    chars[i] = 0;

  /* Read input */
  i = 0;
  while ((c = getchar()) != EOF)
  {
    chars[i] = c;
    i++;
  }

  for (i = 0; i <= EXPECTED_CHARS + 1; i++)
    printf("%c", chars[i]);

  return 0;
}
