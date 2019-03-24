#include <ctype.h>
#include "../mygetline.h"


int atoi(char s[]);

int main()
{
	char line[MAXLIMIT];
	int result;

	mygetline(line, MAXLIMIT);

	result = atoi(line);
	printf("Result is: %d\n", result);

	return 0;
}

int atoi(char s[])
{
	int i, n, sign;
	for (i=0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')	/* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;	
}
