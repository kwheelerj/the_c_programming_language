#include <stdio.h>

int strindex(char [], char []);
int strindex_old(char [], char []);


int main()
{
	char str[] = "abcdedefg";
	char find[] = "def";
	char nope[] = "hijk";

	int res;

	res = strindex_old(str, find);
	printf("found at index >%d< : >%c<\n", res, str[res]);

	res = strindex_old(str, nope);
	printf("index = >%d<\n", res);

	res = strindex(str, find);
	printf("found at index >%d< : >%c<\n", res, str[res]);

	res = strindex(str, nope);
	printf("index = >%d<\n", res);

return 0;
}

int strindex(char src[], char t[])
{
	char *j;
	char *k;
	char *p = src;
	for ( ; *p != '\0'; p++)
	{
		for (j=p, k=t; *k != '\0' && *j == *k; j++, k++)
			;
		if ( (k - t) > 0 && *k == '\0')
			return p - src;
	}
	return -1;
}

int strindex_old(char src[], char t[])
{
	int i, j, k;

	for (i=0; src[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k] != '\0' && src[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')	/* actually found the full pattern */
			return i;
	}
	return -1;
}
