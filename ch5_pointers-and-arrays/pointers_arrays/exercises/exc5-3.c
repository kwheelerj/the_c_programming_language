#include <stdio.h>

void strcat(char *, char *);
void strcat_v1(char *, char *);
void strcat_v2(char *, char *);


int main()
{
	char str[] = "character arr";
	char *ext = "ay";

	printf("str = >%s>\n", str);
	printf("ext = >%s>\n", ext);

	//strcat_v1(str, ext);
	//strcat_v2(str, ext);
	strcat(str, ext);
	printf("str = >%s>\n", str);

return 0;
}

void strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;	
}

void strcat_v2(char *s, char *t)
{
	while (*s)
		s++;
	while(*t)
		*s++ = *t++;
}

void strcat_v1(char *s, char *t)
{
	while (*s != '\0')
		s++;
	for ( ; *t != '\0'; s++, t++)
		*s = *t;
}
