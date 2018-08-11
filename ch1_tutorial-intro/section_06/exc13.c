#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input. */

#define IN	1
#define OUT	0

int main()
{
	int c, i, state = OUT, wordlength = 0, count;
	int histogram[10];

	for (i = 0; i < 10; i++)
		histogram[i] = 0;

	while ((c = getchar()) != EOF) {
		if (state == IN) {
			if (c != ' ' && c != '\t' && c != '\n')
				wordlength++;
			else {
				state = OUT;
				histogram[wordlength]++;
				wordlength = 0;
			}
		} else {
			if (c != ' '  && c != '\t' && c != '\n')
			{
				state = IN;
				wordlength++;
			}
			else
				continue;
		}
	}

	printf("Histogram:\n");
	for (i = 0; i < 10; i++) {
		printf("Length of %d:\t", i);
		count = histogram[i];
		for (count = 0; count < histogram[i]; count++)
			printf("*");
		printf("\n");
	}

	return 0;
}
