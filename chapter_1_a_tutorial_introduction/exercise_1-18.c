/* Exercise 1-18. Write a program to remove trailing blanks and tabs
from each line of input, and delete entirely blank lines. */

#include <stdio.h>
#define MAX_INPUT 1000 /* maxium input of characters size */

int input_length(char all_input[]); /* Return length of input including newline characters */
void print_input(char all_input[]);
int end_of_line(char all_input[], int start_positition);
int line_wo_blanks(char all_input[], int start_positition, int end);

int main(void)
{
    int c, i, j,length, count, start_position, finish_position, amount_to_copy, leave_loop;
    char all_input[MAX_INPUT], cleaned_input[MAX_INPUT]; /* current input*/

    i = j = leave_loop = 0;
    count = 1;

    /* Get input */
    printf("Please input up to %d characters and then click Ctrl+D\n", (MAX_INPUT - 1));
    while ((c = getchar()) != EOF)
    {
      all_input[i] = c;
      i++;
      /* Handle too much input */
      if (i >= MAX_INPUT)
        printf("Max number of characters exceeded.\n");
    }


    length = input_length(all_input);

    if (length > 0)
    {
      start_position = 0;

      while (start_position < length)
      {
      finish_position = line_wo_blanks(all_input, start_position, end_of_line(all_input, start_position));

      for (i = start_position; i <= finish_position; i++)
        printf("%c", all_input[i]);
        count++;
      printf("\n");
      count++;

      start_position = end_of_line(all_input, start_position) + 1;
      while (all_input[start_position] == '\n')
        start_position++;
      }
    }

    printf("input was originally %d\ncleaned input is %d", length, count);

    return 0;
}

int input_length(char all_input[])
{
  int i;

  while (all_input[i] != '\0')
    i++;

  return i;
}

/* Go through array and find end of line '\n' and return position */
int end_of_line(char all_input[], int start_position)
{
  int i;
  i = start_position;
  while (all_input[i] != '\n' && all_input[i] != '\0')
  {
    i++;
  }
  return i;
}

/* While character is a space or tab or '\n' go back 1 character and return
   position of first non-space character. */
int line_wo_blanks(char all_input[], int start_position, int end)
{
  int i;
  i = end;
  while (all_input[i] == ' ' || all_input[i] == '\t' || all_input[i] == '\n')
  {
    i--;
  }
  return i;
}
