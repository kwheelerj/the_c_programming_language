#include <ctype.h>
#include <stdio.h>

#include "getch.c"

int getch(void);
void ungetch(int);

#define SIZE 2

int main()
{
	int n, getfloat(float *);
	float array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	printf("FINAL RESULTS:\n");
	for (n = 0; n < SIZE; n++)
		printf("%f\n", array[n]);

return 0;
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
	int c, sign, floatcount;

	while ( isspace(c = getch()) )
		;

	if ( !isdigit(c) && c != EOF && c != '+' && c != '-' )
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');

	/* new for float processing */
	if (c == '.')
	{
		c = getch();
		floatcount = 0;
	}

	for ( ; isdigit(c); c = getch())
	{
		*pn = 10.0 * *pn + (c - '0');
		floatcount++;
	}

	for (int i = 0; i < floatcount; i++)
		*pn /= 10.0;

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}
