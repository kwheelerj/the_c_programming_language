#include <stdio.h>	/* for getchar() */

#define	MAXLINE	100
#define	TABSTOP	8

/* Write a program "detab" that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every 'n' columns.  Should
 * 'n' be a variable or a symbolic parameter?
 */
/* MY ANSWER: it should be symbolic; doesn't change in life of pgm */

int mygetline(char s[]);
void replaceTabWithSpaces(char s[], int limit);
void arr_printf(char s[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = mygetline(line)) > 0)
	{
		replaceTabWithSpaces(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int mygetline(char s[])
{
	int i, c;
	for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
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
	printf("\tlength=%d\n",length);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '\t')
		{	
			nspaces = (TABSTOP - (i % TABSTOP));
			/*printf("nspaces: %d\n",nspaces);*/
			/* push rest of the string forward */
			for (j = length-1; j > i; j--)
			{
				if (j + nspaces - 1 > MAXLINE-1)
				{
					/*printf("\t1st condition: %d > %d\n", j+nspaces-1, MAXLINE-1);*/
					continue;
				}
				else if (j + nspaces - 1 == MAXLINE-1)
				{
					/*printf("\t2nd condition: %d == %d\n", j+nspaces-1, MAXLINE-1);*/
					s[j+nspaces-1] = '\0';
				}
				else
				{
					/*printf("\t3rd condition: %d < %d\n",j+nspaces-1, MAXLINE-1);
					printf("\tj=>%d<\n",j);
					printf("\ts[j+nspaces-1] is s[%d]=>%c<\n", j+nspaces-1, s[j+nspaces-1]);
					printf("\ts[j] is s[%d]=>%c<\n", j, s[j]);*/
					s[j+nspaces-1] = s[j];
				}
				//arr_printf(s);
			}
			length += nspaces-1;
			for (k = 0; k < nspaces; k++)
				s[i+k] = '_';
		}
		//arr_printf(s);
	}
	s[length-1] = '\0';
}

void arr_printf(char s[])
{
	int k;
	printf("|");
	for (k = 0; k < MAXLINE;k++)
	{
		if (s[k] == '\n')
			printf("\\n|");
		else if (s[k] == '\t')
			printf("\\t|");
		else if (s[k] == '\0')
			printf("\\0|");
		else
			printf(" %c|",s[k]);
	}
	printf("\n");
}
       
