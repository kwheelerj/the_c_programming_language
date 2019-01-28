#include <stdio.h>

#define MAXLINE	1000

int max;			/* max length so far */
char line[MAXLINE];		/* current input line */
char longest[MAXLINE];		/* longest line saved */ 

int mygetline(void);
void copy(void);

int main()
{
	int len;
/*	extern int max;		/* this line is optional */
/*	extern char longest[];	/* this line is optional */

	max = 0;
	while ((len = mygetline()) > 0)
		if (len > max)
		{
			max = len;
			copy();
		}
	if (max > 0)
		printf("%s", longest);

	return 0;
}

int mygetline(void)
{
	int c, i;
/*	extern char line[];	/* optional */	

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF
		&& c != '\n'; i++)
	{
		line[i] = c;
	}
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';

	return i;
}

void copy(void)
{
	int i;
/*	extern char line[], longest[];		/* optional*/

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		i++;
}
