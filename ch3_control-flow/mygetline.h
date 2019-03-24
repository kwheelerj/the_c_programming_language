#ifndef MYGETLINE
#define MYGETLINE

#include <stdio.h>

#define MAXLIMIT	10000

int mygetline(char s[], int limit)
{
	int i;
	char c;
	for (i=0; i<limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\0';
	return i;
}
#endif /* MYGETLINE */
