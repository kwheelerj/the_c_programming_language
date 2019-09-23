#include <stdio.h>

#define BUFSIZE 100

void print_buf(void);

static char buf[BUFSIZE];		/* buffer for ungetch */
static int bufp = 0;

int getch(void)		/* get a (possibly pushed back) char */
{
	//return (bufp > 0) ? buf[--bufp] : getchar();
	int ret;
	if (bufp > 0) 
		ret = buf[--bufp];
	else
		ret = getchar();

	print_buf();

	return ret;
}

void ungetch(int c)		/* push char back on input */
{
	printf("unget(int %d)\n", c);
	if (bufp >= BUFSIZE)
		printf("ungetch error: too many characters\n");
	else
		buf[bufp++] = c;

	print_buf();
}

void print_buf()
{
	printf("\tbufp = %d\n", bufp);
	if (bufp == 0)
		printf("buf is empty.\n");
	 else
	{
		printf("buf[ ");
		for (int i = 0; i < bufp; i++)
		{
			printf("<%c> ", ( (buf[i] == 10) ? 33 : buf[i]) );
		}
		printf("]\n");
	}
}
