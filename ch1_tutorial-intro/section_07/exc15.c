#include <stdio.h>

/* Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion
 */

#define UPPER	300
#define	STEP	20

double fahr_to_cels(float fahr);

int main()
{
	float fahr = 0;
	double celsius;

	while (fahr <= UPPER)
	{
		printf("%3.0f %6.1f\n", fahr, fahr_to_cels(fahr));
		fahr += STEP;
	}

	return 0;
}

double fahr_to_cels(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}

