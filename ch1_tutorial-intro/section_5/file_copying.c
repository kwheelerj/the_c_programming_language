#include <stdio.h>

/* copy input to output; 1st version */

int main()
{
	int c;
	/* Notice that we are using an int type
	 * vs. a char type, even though we expect to
	 * accept a char.
	 * This is because we also want to accept the
	 * EOF value.
	 */

	c = getchar();
	while(c != EOF)
	{
		putchar(c);
		c = getchar();
	}

	return 0;
}

