#include <stdio.h>
#include <string.h>
#include "../mygetline.h"

#define MAXLIMIT	10000

int reverse(char s[]);

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
