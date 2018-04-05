#include <stdio.h>

int main()
{
	unsigned char c;
	c = 1;
	for (;;c++)
	{
		printf("%d\n", c);
		printf("%d\n", ++c);
		if (++c == 0)
			break;	
	}
	printf("Max value of char is: %d\n", --c);

	return 0;
}
