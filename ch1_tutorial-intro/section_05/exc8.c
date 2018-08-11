#include <stdio.h>

int main()
{
	/* Write a program to count blanks, tabs, and newlines. */
	int c, blanks = 0, tabs = 0, newlines = 0, chars = 0;

	
	while ( (c = getchar()) != EOF ) {
		if (c == '\n')
			newlines++;
		else if (c == '\t')
			tabs++;
		else if (c == ' ')
			blanks++;
		else
			chars++;
	}
	printf("blanks: %d\ntabs: %d\nnewlines: %d\nchars: %d\n",
		       	blanks, tabs, newlines, chars);

	return 0;
}
