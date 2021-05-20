/* Exercise 1-17.c. Write a program to print all input lines that are longer
than 80 characters. */

/* 1. Get all input into one large array */
/* 2. Iterate through array, when find '\n' update length */
/* 3. If length exceeds target, copy into temp and print */

#include <stdio.h>
#define MAX_INPUT 1000 /* maxium input of characters size */
#define TARGET_LENGTH 80 /* print all input lines longer than this number of characters */

int input_length(char all_input[]); /* Return length of input including newline characters */
void print_line(char all_input[], int start_positition, int finish_position);
int establish_line_length(char all_input[], int input_length, int target_length, int start_positition);

/* print longest input line */
int main(void)
{
    int c, length, start_positition, finish_position;
    int max; /* maximum length seen so far */
    char all_input[MAX_INPUT]; /* current input*/

    int i = 0;

    printf("Please input up to %d characters and then click Ctrl+D\n", (MAX_INPUT - 1));
    while ((c = getchar()) != EOF)
    {
      all_input[i] = c;
      i++;
    }

    if (i >= MAX_INPUT)
      printf("Max number of characters exceeded.\n");

    length = input_length(all_input);

    if (length > 0)
    {
      start_positition = 0;
      while (start_positition <= length)
      {
      finish_position = establish_line_length(all_input, length, TARGET_LENGTH, start_positition);

      if ((finish_position - start_positition) >= TARGET_LENGTH)
        print_line(all_input, start_positition, finish_position);

      start_positition = finish_position + 2;
      }
    }

    return 0;
}

int input_length(char all_input[])
{
  int i;

  while (all_input[i] != '\0')
    i++;

  return i;
}

int establish_line_length(char all_input[], int input_length, int target_length, int start_positition)
{
  int i;
  int temp_line[input_length];
  int finish_position;

  for (i = start_positition; i <= input_length; i++)
  {
    if (all_input[i] == '\n' || all_input[i] == '\0')
    {
        finish_position = i - 1;
        return finish_position;
    }
  }
  return 0;
}

void print_line(char all_input[], int start_positition, int finish_position)
{
  int i;
  for (i = start_positition; i <= finish_position; i++)
    printf("%c", all_input[i]);
  printf("\n");
}
