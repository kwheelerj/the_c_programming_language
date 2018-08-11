#include <ctype.h>
#include <stdio.h>

#define MAXLIMIT	10000

int atoi(char s[]);
int mygetline(char s[], int limit);

int main()
{
	char line[MAXLIMIT];
	int result;

	mygetline(line, MAXLIMIT);

	result = atoi(line);
	printf("Result is: %d\n", result);

	return 0;
}

int atoi(char s[])
{
	int i, n, sign;
	for (i=0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;	
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
