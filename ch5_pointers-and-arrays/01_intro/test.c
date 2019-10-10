#include <stdio.h>
#include <ctype.h>

#include "getch.c"

#define SIZE 10

//int getint(int *);

int main()
{
	int n, array[SIZE], getint(int *);

	printf("test\n");
	
	for(n=0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

return(0);
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
	printf("right before return.\n");
    return c;
}

