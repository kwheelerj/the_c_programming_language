#include <stdio.h>

int main()
{
	char amsg[] = "kenneth";
	char *pmsg = "kenneth";

	printf("amsg = %s\n", amsg);
	printf("pmsg = %s\n", pmsg);

	amsg[1] = 'i';

	printf("amsg = %s\n", amsg);
	printf("pmsg = %s\n", pmsg);

	// *(pmsg+1) = 'a'; /* Illegal */

	printf("*(pmsg+1) = %c\n", *(pmsg+1));

return 0;
}
