/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of temperature table */
  upper = 150;    /* upper limit */
  step = 10;      /* step size */

  fahr = lower;

  printf("\nCelsius-Fahrenheit table; floating-point version\n\n");
  printf("Cels   Fahr\n");

  while (celsius <= upper)
  {
    fahr = (celsius * 9.0/5.0) + 32.0;
    printf("%6.1f %3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  printf("\n");

  return 0;
}
