#include <stdio.h>

/* Exercise 1-4:
 * 	Write a program to print the corresponding
 * 	Celsius to Fahrenheit table.
 */ 

/* print Celsius-Fahrenheit table
 *  for cels = -20, -10, ..., 150 
 */

int main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = -20;
	upper = 150;
	step = 10;

	celsius = lower;
	
	printf("%5s %6s\n", "Cels", "Fahr");

	while (celsius <= upper)
	{
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%5.0f %6.0f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
