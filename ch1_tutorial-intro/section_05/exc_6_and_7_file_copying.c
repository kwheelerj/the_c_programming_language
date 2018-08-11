#include <stdio.h>

int main()
{
	int c;	

	while((c=getchar()) != EOF)
	{
		if (c == '\n')
			printf("\\n");
		else
			putchar(c);
		printf(" : getchar() != EOF: %d\n", c != EOF);
	}

	printf("getchar() != EOF: %d\n", c != EOF);
	printf("End of file char is: %d\n", c);
	
	return 0;
}
