#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

#define SIZE 2

int main()
{
	int n, array[SIZE], getint(int *);

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

	printf("FINAL RESULTS:\n");
	for (n = 0; n < SIZE; n++)
		printf("%d\n", array[n]);

return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

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

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;
	printf("\t*pn = %d\n", *pn);

	if (c != EOF)
		ungetch(c);

	return c;
}

	
/* getch.c */
#define BUFSIZE 100

static char buf[BUFSIZE];		/* buffer for ungetch */
static int bufp = 0;

void printbuf(void)
{
	printf("printbuf----------------\n");
	printf("\t[ ");
	for (int i = 0; i < bufp; i++)
	{
		printf(">%d< ", buf[i]);
	}
	printf(" ]\nEND---------------------\n");
}

int getch(void)		/* get a (possibly pushed back) char */
{
	printbuf();
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push char back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch error: too many characters\n");
	else
		buf[bufp++] = c;
	printbuf();
}
