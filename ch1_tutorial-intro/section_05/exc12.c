#include <stdio.h>

#define IN	1
#define OUT	0

/* Write a program that prints its input one word per line. */

int main()
{
	int c, state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (state == OUT)
		{
			if (!(c == ' ' || c == '\n' || c == '\t'))
			{
				putchar(c);
				state = IN;
			}
		} 
		else
		{
			if (c == ' ' || c == '\n' || c == '\t')
			{
				putchar('\n');
				state = OUT;
			}
			else 
				putchar(c);
		}	
	}

	return 0;
}
