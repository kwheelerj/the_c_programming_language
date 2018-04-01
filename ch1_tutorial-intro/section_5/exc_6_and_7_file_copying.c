#include <stdio.h>

int main()
{
	int c;	

	c = getchar();
	printf("getchar() != EOF : %d\n", getchar() != EOF);
	while(c != EOF)
	{
		//printf("c != EOF: %d\n", c != EOF);
		putchar(c);
		c = getchar();
	}

	printf("End of file char is: %d\n", EOF);
	printf("Last char sent: %d\n", c);
	
	return 0;
}
