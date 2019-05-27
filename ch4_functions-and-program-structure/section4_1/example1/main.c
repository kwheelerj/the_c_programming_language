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
