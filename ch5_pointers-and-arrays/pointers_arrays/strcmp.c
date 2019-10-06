#include <stdio.h>

int strcmp_old(char *, char *);
int strcmp(char *, char *);


int main()
{
	int res;
	char str1[] = "qwerty";
	char str2[] = "qwerp";
	
	printf("str1 = >%s<\n", str1);
	printf("str2 = >%s<\n", str2);

	res = strcmp_old(str1, str2);
	printf("res = >%d<\n", res);

	res = strcmp(str1, str2);
	printf("res = >%d<\n", res);

return 0;
}

int strcmp_old(char *s, char *t)
{
	int i;
	for (i=0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

int strcmp(char *s, char *t)
{
	//for ( ; *s++ == *t++; )
	for ( ; *s == *t; s++, t++)
		//if ( !(*s) )
		if (*s == '\0')
			return 0;
	return *s - *t;
}
