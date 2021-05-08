/* Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
    that is, from 300 to 0. */

#include <stdio.h>

int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of temperature table */
  upper = 300;    /* upper limit */
  step = 20;      /* step size */

  fahr = upper;

  printf("\nFahrenheit-Celsius table; floating-point version\n\n");
  printf("Fah  Cels\n");

  while (fahr >= lower)
  {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr - step;
  }

  printf("\n");

  return 0;
}
