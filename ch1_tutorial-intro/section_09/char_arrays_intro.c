#include <stdio.h>

/* "... let's write a program that reads a set of text lines
 * and prints the longest."
 */

#define MAXLINE	1000	// max input lines size

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	if (max > 0)	// there was a line
		printf("%s", longest);

	return 0;
}

// getline: read a line into s, return length
int mygetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

// copy: copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
