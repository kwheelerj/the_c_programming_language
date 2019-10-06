#include <stdio.h>

int main()
{
	char *char_ptr = "This is a character pointer.";
	char char_arr[] = "This is a character array.";

	printf("char_ptr = >%s<\n", char_ptr);
	printf("char_arr = >%s<\n", char_arr);

	char *s = char_arr;

	for ( ; *s != '\0'; s++)
	{
		printf("*s = >%c<", *s);
		printf(" | s = >%s<\n", s);
	}

	char *p = char_ptr;
	for ( ; *p != '\0'; p++)
	{
		printf("*p = >%c<", *p);
		printf(" | p = >%s<\n", p);
	}

return 0;
}
