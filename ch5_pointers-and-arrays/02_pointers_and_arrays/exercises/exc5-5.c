#include <stdio.h>

char *strncpy(char *, char *, size_t);
char *strncat(char *, char *, size_t);
int strncmp(char *, char *, size_t);


int main()
{
	printf("strncpy test:\n\n");
	char str[] = "This is a normal string.";
	char *cpyf = "copied_garbage";
	printf("str = >%s<\n", str);
	char *res_p;
	res_p = strncpy(str, cpyf, 6);
	printf("str = >%s<\n", str);
	printf("res_p = >%s<\n", res_p);

	printf("---\nstrncmp test:\n\n");
	char *str2 = "grape";
	char *str3 = "grapple";	// should be able to compare 4 letters and get 0
	int res;
	res = strncmp(str2, str3, 4);
	printf("res = >%d<\n", res);
	res = strncmp(str2, str3, 5);
	printf("res = >%d<\n", res);

	printf("---\nstrncat test:\n\n");
	char str4[] = "A comple";
	char *str5 = "te sentence. lhfdajlk";
	printf("str4 = >%s<\n", str4);
	res_p = strncat(str4, str5, 12);
	printf("str4 = >%s<\n", str4);
	printf("res_p = >%s<\n", res_p);

return 0;
}


char *strncat(char *s, char *t, size_t n)
{
	char *p;
	int i;
	p = s;
	while (*s)
		s++;
	i = 0;
	while (i++ < n && (*s++ = *t++))
		;	
	*s = '\0'; /* If you fail to due this, garbage (whatever is in memory there) can print out */
	return p;
}

int strncmp(char *s, char *t, size_t n)
{
	int i;
	for (i = 0; *s == *t && i < n; s++, t++, i++)
		if (*s == '\0')
			return 0;
	if (i == n)
		return 0;
	return *s - *t;
}

char *strncpy(char *s, char *t, size_t n)
{
	int i;
	char *p;
	for (i = 0, p = s; i < n && *t != '\0'; i++)
		*p++ = *t++;
	*p = '\0';
	return s;
}
