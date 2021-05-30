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
3. If counter <8, print spaces. While >= 8, print a tab and -8 from counter.
   Then print remaining spaces.
4. Else print characters.
*/

int get_input(char char_array[]);
void copy_array(char to[], char from[], int to_position, int from_position);
void print_array(char array_of_characters[], int start_position, int finish_position);
int get_new_word_start(char s[], int last_word_end);
int get_word_end(char s[], int start_position);
int count_char_frequency(char s[], int word_end, int word_start, char specified_char);

int main(void)
{
  int i, c, length, start_of_word, end_of_word, array_position, spaces, tabs, new_lines;
  char inputted_chars[MAX_INPUT];

  i = start_of_word = end_of_word = array_position = 0;

  length = get_input(inputted_chars);
  inputted_chars[length + 1] = '\0'; /* Signify end of input */

  while(array_position <= length)
  {
    if (inputted_chars[array_position] == ' ' || inputted_chars[array_position] == '\t')
    {
      printf("registered\n");
      spaces = count_char_frequency(inputted_chars, array_position, get_new_word_start(inputted_chars, array_position), ' ');
      tabs = count_char_frequency(inputted_chars, array_position, get_new_word_start(inputted_chars, array_position), '\t');

      array_position = array_position + spaces + tabs - 1;

      while (tabs > 0)
      {
        spaces = spaces + N_SPACES;
        tabs--;
      }

      printf("%d", spaces);

      while (spaces > 0)
      {
        if (spaces < N_SPACES)
          for (i = 0; i <= spaces; i++)
          {
            printf("%c", REPLACE_W_SPACE);
            spaces--;
          }
        else
        {
          printf("%c", REPLACE_W_TAB);
          spaces = spaces - N_SPACES;
        }
      }

    }
    else
    {
      print_array(inputted_chars, array_position, get_word_end(inputted_chars, array_position));
      array_position = get_word_end(inputted_chars, array_position);
    }
    
    array_position++;
  }


  return 0;
}

/* Function to take input and allocate characters into array;
   also returns length of input */
int get_input(char array_for_characters[])
{
  int i, c, length_of_input;
  i = 0;
  while ((c = getchar()) != EOF)
  {
    array_for_characters[i] = c;
    i++;
  }
  array_for_characters[i+1] = '\0'; /* make easy to find end of input */
  length_of_input = i + 1;
  return length_of_input;
}

/* Copy from one array in to another */
void copy_array(char to[], char from[], int to_position, int from_position)
{
  to[to_position] = from[from_position];
}

/* Function that prints each character within a given array from a starting
position to a finish position */
void print_array(char array_of_characters[], int start_position, int finish_position)
{
  int i;

  for (i = start_position; i <= finish_position; i++)
    printf("%c", array_of_characters[i]);
}

/* Function that returns start of new word position */
int get_new_word_start(char s[], int last_word_end)
{
  int i;
  i = last_word_end;

  while (s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
    i++;

  return i;
}

/* Function that returns end of word position */
int get_word_end(char s[], int start_position)
{
  int i;
  i = start_position;

  while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
    i++;

  return i;
}

/* Function that returns frequency of a specified character between two points */
int count_char_frequency(char s[], int start_pos, int end_pos, char specified_char)
{
  int i, number_of_specified_char;
  number_of_specified_char = 0;
  for (i = start_pos; i <= end_pos; i++)
  {
    if (s[i] == specified_char)
      number_of_specified_char++;
  }
  return number_of_specified_char;
}
