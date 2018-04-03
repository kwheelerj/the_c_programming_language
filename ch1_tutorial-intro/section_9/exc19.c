#include <stdio.h>

/* Write a function "reverse(s)" that reverses the character
 * string 's'.  Use it to write a program that reverses
 * its input a line at a time.
 */

#define MAXLINE	1000

int mygetline(char line[], int maxline);
void reverse(char s[], int length);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = mygetline(line, MAXLINE)) > 0)
	{
		reverse(line, len);
		printf("%s\n", line);
	}

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

void reverse(char s[], int length)
{
	int i;
	char temp;

	for (i = 0; i < length/2; i++)
	{
		temp = s[i];
		s[i] = s[length-1-i];
		s[length-1-i] = temp;
	}
}
