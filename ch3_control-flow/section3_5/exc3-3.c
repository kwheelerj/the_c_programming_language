#include <ctype.h>
#include <stdio.h>
#include "../mygetline.h"

/* Exercise 3-3:
 *	Write afunction 'expand(s1, s2) that shorthand notations like a-z in the string
 *	s1 (in) into the equivalnt complete list abc...xyz in s2 (out).  Allow for letters
 *	of eithercase and digits, and be prepared to handle cases like:
 *		a-b-c
 *		a-z0-9
 *		-a-z
 *	Arrange that a leading or trailing '-' is taken literally.
 */

int expand(char in[], char out[]);
int skip(int from, char c, char v[]);
int fill(char v[], int from, char start, char end);

int main()
{
	char line[MAXLIMIT], result[MAXLIMIT];
	int len;

	mygetline(line, MAXLIMIT);

	expand(line, result);
	printf("Expanded:\n%s\n", result);

	return 0;
}

int expand(char in[], char out[])
{
	int i, j;
	int FIRST_LETTER = 0;
	int NEEDS_EXPAND = 0;
	char start, end;

	for (i = j = 0; in[i] != '\0' && i < MAXLIMIT - 1; i++)
	{
		/* printf("out (sofar) = >%s<\n", out); */
		if (FIRST_LETTER == 0)
		{
			if (in[i] == '-')
			{
				out[j++] = in[i];
				continue;
			}
			else
			{
				FIRST_LETTER = 1;
			}
		}
		if (FIRST_LETTER == 1)
		{
			if (NEEDS_EXPAND == 0)
			{
				if (in[i+1] == '-')
				{
					start = in[i];
					NEEDS_EXPAND = 1;
					continue;
				}
				else
				{
					/* Special case:
					 *	Decided output of "ab-d-z" should be "abcd-z",
					 *	because otherwise the output should be "abcde...wxyz",
					 *	but then there would be no reason to specify the "d-" at all.
					 */
					out[j++] = in[i];
					continue;
				}
			}
			else /* NEEDS_EXPAND == 1 */
			{
				if (in[i+1] == '-')
					continue;
				else
					end = in[++i];
			}
	
			/* printf("start=>%c< | end=>%c<\n", start, end); */
			
			j = fill(out, j, start, end);
			NEEDS_EXPAND = 0;
		}
	}
}

int fill(char v[], int from, char start, char end)
{
	int i, j;
	v[from] = start;
	if (start > end)
		for (j = 1, i = from + j; i < MAXLIMIT - 2 && (start - j) > end; i++, j++)
			v[i] = start - j;
	else
		for (j = 1, i = from + j; i < MAXLIMIT - 2 && (start + j) < end; i++, j++)
			v[i] = start + j;
	v[i++] = end;
	return i;
}
