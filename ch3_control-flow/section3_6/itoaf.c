#include <stdio.h>
#include "reverse.h"

/* Exercise 3-6:
 *	Write a version of itoa that accepts three arguments instead of two.
 *	The third argument is a minimum field width; the converted number
 *	must be padded with blanks on the left if necessary to make it
 *	wide enough.
 */
void itoaf(int n, char s[], int width);

int main()
{
	char line[30];
	int inp;

	inp = -2147483648;
	itoaf(inp, line, 5);
	printf("%s\n", line);

	inp = 123;
	itoaf(inp, line, 5);
	printf("%s\n", line);

return(0);
}

void itoaf(int n, char s[], int width)
{
	int i;
	int sign;

	if ( (sign = n) < 0 )
		n = -(n+1);	
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ( (n /= 10) > 0);

	if (sign < 0)
	{
		s[0] += 1;
		s[i++] = '-';
	}

	/* Add the padding, if necessary */
	int padding_needed = 0;
	if (i < width)
	{
		padding_needed = width - i;
		for (int j = 0; j < padding_needed; j++)
			s[j+i] = ' ';
	}

	s[i + padding_needed] = '\0';
	reverse(s);
}
