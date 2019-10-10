#include <stdio.h>

/* strlen: return length of string s */
int strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

int main()
{
	char *pname = "Kenneth";
	char name[10] = "Kenneth";
	printf("strlen of '%s' is: %d\n", name, strlen(name));

	printf("%d\n", strlen("hello"));
	printf("%d\n", strlen(pname));

	printf("%d\n", strlen(pname+2));

return 0;
}
