/* Exercise 1-16. Revise the main routine of the longest-line program so it
will correctly print the length of arbitrarily long input lines, and as much
as possible of the text. */

#include <stdio.h>
#define MAXLINE 10 /* maxium input line size */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    int prev_max, get_more;
    char temp[MAXLINE];

    max = prev_max = get_more = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
      if (line[len - 1] != '\n')
      {
        if (get_more == 0)
          copy(temp, line);
        prev_max += len;
        if (max < prev_max)
          max = prev_max;
        get_more = 1;
      }
      else
      {
        if (get_more == 1)
        {
          if (max < prev_max + len)
          {
            max = prev_max + len;
            copy(longest, temp);
            longest[MAXLINE - 2] = '\n';
          }
          get_more = 0;
        }
        else if (len > max)
        {
          max = len;
          copy(longest, line);
        }
        prev_max = 0;
      }
    }

    if (max > 0) /* there was a line */
      printf("%s", longest);

    return 0;
}

/*getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
  {
    s[i] = c;
    i++;
  }
  else if (c == EOF && i > 0)
  {
    s[i] = '\n';
    i++;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
