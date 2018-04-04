#include <stdio.h>

/* Write a program to print all input lines that are longer
 * than 80 characters.
 */

#define MAXLINE	1000
#define EIGHTY	80

int mygetline(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = mygetline(line, MAXLINE)) > 0)
		if (len > EIGHTY)
			printf("%s", line);

	return 0;
}

int mygetline(char s[], int limit)
{
	int c, i;

	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}
