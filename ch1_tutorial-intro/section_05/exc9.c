#include <stdio.h>

/* Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

int main()
{
	int c, spaceflag = 0;

	while( (c = getchar()) != EOF ) {
		if (spaceflag == 1) {
			if (c != ' ' && c != '\t') {
				spaceflag = 0;
				putchar(c);
			}
		} else {
			if (c == ' ' || c == '\t') {
				spaceflag = 1;
				putchar(' ');
			} else
				putchar(c);
		}
	}

	return 0;
}
