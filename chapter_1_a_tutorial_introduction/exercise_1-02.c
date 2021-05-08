/* Exercise 1-2. Experiment to find out what happens when printf's
argument string contains \c, where c is some character not listed above. */

#include <stdio.h>

int main(void)
{
  printf("I wonder what happens if I put \c in here?");
}

/* exercise_1-02.c:8:42: warning: unknown escape sequence '\c'
      [-Wunknown-escape-sequence]
  printf("I wonder what happens if I put \c in here?"); */
