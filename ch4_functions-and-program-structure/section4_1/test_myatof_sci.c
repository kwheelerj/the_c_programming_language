#include <stdio.h>

#define MAXLINE 1000

int main()
{
	double atof_sci(char[]);
	char line[MAXLINE];
	int mygetline(char line[], int max);

	while (mygetline(line, MAXLINE) > 0)
		printf("\t%g\n", atof_sci(line));

return 0;
}
