#include <stdio.h>
#include "reverse.c"

int strrindex(char src[], char t[])
{
	reverse(src);
	reverse(t);

	int i, j, k;

	for (i=0; src[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k] != '\0' && src[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')	/* actually found the full pattern */
		{
				reverse(src);
				reverse(t);
				return strlen(src) - i - k;
		}
	}
	
	reverse(t);
	return -1;
}
