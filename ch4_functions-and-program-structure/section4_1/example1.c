#include <stdio.h>
#define MAXLINE 1000

int mygetline(char s[], int lim);
int strindex(char src[], char t[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found_count = 0;

	while (mygetline(line, MAXLINE) > 0)
		if ( strindex(line, pattern) >= 0 )
		{
			printf("%s", line);
			found_count++;
		}
	return found_count;
}

int mygetline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

int strindex(char src[], char t[])
{
	int i, j, k;

	for (i=0; src[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k] != '\0' && src[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')	/* actually found the full pattern */
				return k;
	}
	return -1;
}
