#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];		/* buffer for ungetch */
static int bufp = 0;

int getch(void)		/* get a (possibly pushed back) char */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push char back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch error: too many characters\n");
	else
		buf[bufp++] = c;
}
