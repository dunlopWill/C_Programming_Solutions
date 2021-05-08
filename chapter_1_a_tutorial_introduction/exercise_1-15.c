/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2
to use a function for conversion. */

#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

float fahr_to_celsius_conversion(float celsius);

int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of temperature table */
  upper = 300;    /* upper limit */
  step = 20;      /* step size */

  fahr = lower;

  printf("\nFahrenheit-Celsius table; floating-point version\n\n");
  printf("Fah  Cels\n");

  while (fahr <= upper)
  {
    printf("%3.0f %6.1f\n", fahr, fahr_to_celsius_conversion(fahr));
    fahr = fahr + step;
  }

  printf("\n");

  return 0;
}

float fahr_to_celsius_conversion(float fahr)
{
  float celsius;

  celsius = (5.0/9.0) * (fahr-32.0);

  return celsius;
}
