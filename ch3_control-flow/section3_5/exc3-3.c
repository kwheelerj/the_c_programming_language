#include <ctype.h>
#include <stdio.h>

#define MAXLIMIT	10000

int expand(char s1[], char s2[]);
int mygetline(char s[], int limit);

int main()
{
	char line1[MAXLIMIT];
	char line2[MAXLIMIT];

	mygetline(line1, MAXLIMIT);
	mygetline(line2, MAXLIMIT);

	expand(line1);
	printf("%s\n", line1);

	return 0;
}

int expand(char s1[], s2[])
{

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
