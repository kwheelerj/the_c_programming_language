#include <stdio.h>
#include <string.h>

#define MAXLIMIT	10000

int reverse(char s[]);
int mygetline(char s[], int limit);

int main()
{
	char line[MAXLIMIT];

	mygetline(line, MAXLIMIT);

	reverse(line);
	printf("%s\n", line);

	return 0;
}

int reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

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
