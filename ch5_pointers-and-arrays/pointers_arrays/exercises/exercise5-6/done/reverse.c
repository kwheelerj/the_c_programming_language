#include <stdio.h>
#include <string.h>


int reverse(char s[]);
int reverse_old(char s[]);

int main()
{
	char line[] = "abcdefghi";
	printf("%s\n", line);
	reverse_old(line);
	printf("%s\n", line);

	reverse(line);
	printf("%s\n", line);

return 0;
}

int reverse(char s[])
{
	int c;
	char *p = s + strlen(s) - 1;
	while (*s != *p)
		c = *s,	*s++ = *p, *p-- = c;
}

int reverse_old(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
