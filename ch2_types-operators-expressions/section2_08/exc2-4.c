#include <stdio.h>

/* Write an alternate version of "squeeze(s1, s2)" that deletes each
 * character in "s1" that matches any character in string "s2".
 */

#define MAXLIMIT	1000

int mygetline(char s[], int limit);
void squeeze(char s1[], char s2[]);

int main()
{
	char line1[MAXLIMIT];
	char line2[MAXLIMIT];
	
	mygetline(line1, MAXLIMIT);
	mygetline(line2, MAXLIMIT);

	squeeze(line1, line2);
	printf("\n%s\n", line1);

	return 0;
}

int mygetline(char s[], int limit)
{
	int i;
	char c;

	for (i=0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k, flag;
	j = 0;	
	
	for (i = 0; s1[i] != '\0'; i++)
	{
		flag = 0;

		for (k = 0; s2[k] != '\0'; k++)
		{
			if (s1[i] == s2[k])
			{
				flag = 1;
				break;
			}
		}
		
		if (!flag)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
