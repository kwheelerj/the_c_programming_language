#include <stdio.h>

/* strlen: return length of string s */
int strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;

	return p - s;
}

int main()
{
	char name[10] = "Kenneth";

	printf("strlen of '%s' is: %d\n", name, strlen(name));

return 0;
}
