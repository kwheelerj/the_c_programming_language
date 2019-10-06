#include <stdio.h>

int strend(char *, char *);


int main()
{
	char *str1 = "abcde";
	char *str2 = "de";

	int res;

	res = strend(str1, str2);
	printf("res = >%d<\n", res);

	char *str3 = "abcdefde";
	res = strend(str3, str2);
	printf("res = >%d<\n", res);

	
	char *str4 = "abcdefg";
	res = strend(str4, str2);
	printf("res = >%d<\n", res);

return 0;
}

int strend(char *s, char *t)
{
	char *p;
	while (*s != '\0')
	{
		if (*s == *t)
		{
			for (p = t; *s == *p; s++, p++)
				if (*p == '\0')
					return 1;
		}
		else
			s++;
	}
	return 0;	
}
