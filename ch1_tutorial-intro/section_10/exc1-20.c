#include <stdio.h>

#define	MAXLINE	1000
#define	TABSTOP	8

/* Write a program "detab" that replaces tabs in the input with the \
 * proper number pf blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every 'n' columns.  Should
 * 'n' be a variable or a symbolic parameter?
 */

int mygetline(char s[], int limit);

void replaceTabWithSpaces(char s[], int limit);

int main()
{
	int length;
	char line[MAXLINE];

	while ((length = mygetline(line, MAXLINE)) > 0)
	{
		//printf("LINE is:\n%s\n", line);
		replaceTabWithSpaces(line, length);
		printf("%s\n", line);
	}

	return 0;
}

int mygetline(char s[], int limit)
{
	int i, c;
	for(i = 0; i <= limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* Logic:
 * 	When '\t' is encountered, calculate how many spaces are
 * 	needed to reach a tab stop.  Then move to the end of the
 * 	string and pull everything forward by the spaces needed
 * 	that can fit.  Afterwards, fill the 'gap' with spaces.
 * 	Repeat.
 */
void replaceTabWithSpaces(char s[], int length)
{
	int i, j, k, nspaces;
	for (i = 0; s[i] != '\0'; i++)
	{
		//printf("s[%d] is: %c\n", i, s[i]);
		if (s[i] == '\t')
		{	
			s[i] = '_';
			//printf("found a tab\n");
			nspaces = (TABSTOP - (i % TABSTOP)) - 1;
			//printf("nspaces: %d\n", nspaces);
			// push rest of the string forward
			for (j = length-1; j >= i; j--)
			{
				//printf("BEFORE:\n%s\n", s);

				if (j + nspaces > MAXLINE-1)
				{
					//printf("1st condition: %d > %d\n", j+nspaces, MAXLINE-1);
					continue;
				}
				else if (j + nspaces == MAXLINE-1)
				{
					//printf("2nd condition: %d == %d\n", j+nspaces, MAXLINE-1);
					s[j+nspaces] = '\0';
				}
				else
				{
					//printf("s[j+nspaces] is s[%d] is %c\n",
					//		j+nspaces, s[j+nspaces]);
					s[j+nspaces] = s[j];
				}

				//printf("AFTER:\n%s\n", s);
			}
			length += nspaces;
			for (k = 0; k < nspaces; k++)
				s[i+k] = '_';
		}
	}
	s[length-1] = '\0';
}
