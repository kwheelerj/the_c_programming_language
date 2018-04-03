#include <stdio.h>

/* Write a program to print a histogram of the frequencies of different
 * characters in its input.  
 */

#define NUM_LETTERS	26

int main()
{
	int c, i;
	int letters[NUM_LETTERS];
	for (i = 0; i < NUM_LETTERS; i++)
		letters[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
			letters[c-'a']++;
		else if (c >= 'A' && c <= 'Z')
			letters[c-'A']++;
	}

	for (i = 0; i < NUM_LETTERS; i++)
	{
		printf("Letter %c:\t", i + 'a');
		for (int j = 0; j < letters[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
