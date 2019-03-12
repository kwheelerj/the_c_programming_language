#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
/* recall 'a' -> 97, 'A' -> 65 */

#define MAXLIMIT	1000

int lower(int c);
int mygetline(char s[], int length);

int main()
{
	int length, i;
	char line[MAXLIMIT];

	while ((length = mygetline(line, MAXLIMIT)) > 0)
	{
		printf("Before:\n\t>%s<\n",line);
		for (i = 0; i < length; i++)
			line[i] = lower(line[i]);
		printf("After:\n\t>%s<\n",line);
	}
	return 0;
}

int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + ('a' - 'A');
	else
		return c;
}

int mygetline(char s[], int limit)
{
	int i;
	char c;

	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\0';
	
	return i;
}
