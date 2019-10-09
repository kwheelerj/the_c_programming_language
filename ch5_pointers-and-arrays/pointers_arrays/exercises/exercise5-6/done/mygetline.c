#include <stdio.h>

#define BUF_LIM 1024

int mygetline(char *, int);
int mygetline_old(char [], int);


int main()
{
	char line[BUF_LIM];
	int len;

	len = mygetline_old(line, BUF_LIM);
	printf("line = >%s<\n", line);
	printf("len = >%d<\n", len);

	len = mygetline(line, BUF_LIM);
	printf("line = >%s<\n", line);
	printf("len = >%d<\n", len);
	
return 0;
}

int mygetline(char *s, int lim)
{
	int c;
	char *p = s;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;
	//if (c == '\n')
	//	*s++ = c;
	*s = '\0';
	return s-p;
}

int mygetline_old(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
//	if (c == '\n')
//		s[i++] = c;
	s[i] = '\0';

	return i;
}
