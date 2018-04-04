#include <stdio.h>

/* "Let us write a program to count the number of occurences of each digit,
 * of white space characters (blank, tab, newline), and of all other characters. 
 */

int main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", whitespace = %d, other = %d\n", nwhite, nother);

	return 0;
}
