#include <stdio.h>
#include "reverse.h"

/*itoa: convert int n to characters in s[] */
/* Modification: add ability to deal with largest 2's Complement negative. */
void itoa(int n, char s[]);

int main()
{
	char line[12];
	int inp;
	inp = -2147483647;
	itoa(inp, line);
	printf("%s\n", line);

	printf("\nLargest negative number:\n");
	inp = -2147483648;
	itoa(inp, line);
	printf("%s\n", line);

return(0);
}

void itoa(int n, char s[])
{
	int i;
	int sign;

	if ( (sign = n) < 0 )	/* record sign */
		/*n = -n;*/				/* This will cause the issue! */
		n = -(n+1);			/* This was the tweak needed! */
	i = 0;
	do {		/* generates digits in reverse order */
		s[i++] = n % 10 + '0';		/* get next digit */
	} while ( (n /= 10) > 0);		/* delete it */

	s[0] += 1;						/* correct the number back */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
