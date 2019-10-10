#include <stdio.h>

int strcmp(char *, char *);
int mystrcmp(char *, char *);


int main()
{
	int res;
	char str1[] = "qwerty";
	char str2[] = "qwerp";
	
	printf("str1 = >%s<\n", str1);
	printf("str2 = >%s<\n", str2);

	res = strcmp(str1, str2);
	printf("res = >%d<\n", res);

	res = mystrcmp(str1, str2);
	printf("res = >%d<\n", res);

	char same[] = "qwerp";
	res = strcmp(same, str2);
	printf("res = >%d<\n", res);

	res = mystrcmp(same, str2);
	printf("res = >%d<\n", res);

printf("\\0 - \\0 = >%d<\n", '\0' - '\0');

return 0;
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

int mystrcmp(char *s, char *t)
{
	while (*s == *t && *s)
		s++, t++;
	return *s - *t;
}
