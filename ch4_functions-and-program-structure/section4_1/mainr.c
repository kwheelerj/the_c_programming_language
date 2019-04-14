#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
int strrindex(char src[], char t[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found_count = 0;
	int i;

	while (mygetline(line, MAXLINE) > 0)
		if ( (i = strrindex(line, pattern)) >= 0 )
		{
			printf("found the rightmost index of 'ould' at index %d\n", i);
			printf("%s", line);
			found_count++;
		}
	return found_count;
}
