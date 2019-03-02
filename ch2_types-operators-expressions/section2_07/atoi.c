#include <stdio.h>

int atoi(char s[])
{
	int i, n;
	
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

int main()
{
	char first[5] = "24";
	int second = 2;
	int test;

	test = atoi(first);
	test += second;

	printf("%s + %d = >%d<\n", first, second, test);


	test = atoi("1234");
	printf(">%d<\n", test);


	test = atoi("1,234,567");
	printf(">%d<\n", test);


	test = atoi("1234567");
	printf(">%d<\n", test);

return(0);
}
