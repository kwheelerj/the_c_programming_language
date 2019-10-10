#include <stdio.h>

void strcpy_arr1(char *, char *);
void strcpy_arr2(char *, char *);

void strcpy_ptr1(char *, char *);
void strcpy_ptr2(char *, char *);
void strcpy(char *, char *);

int main()
{
	char *char_ptr = "string constant";
	// printf("char_ptr = >%s<\n", char_ptr);
	char *copy_from = "copied";
	// strcpy_arr1(char_ptr, copy_from);	/* segmentation fault */
	/* Recall:
	 *	This will not work since a STRING CONSTANT cannot be modified.
	 */
	// char_ptr[0] = 'b';	/* segmentation fault */
	/* It is for the same reason that the above line does not work. */

	char char_arr[] = "character array";
	printf("char_arr = >%s<\n", char_arr);
	//strcpy_arr1(char_arr, copy_from);
	//strcpy_arr2(char_arr, copy_from);
	//strcpy_ptr1(char_arr, copy_from);
	//strcpy_ptr2(char_arr, copy_from);
	strcpy(char_arr, copy_from);
	printf("char_arr = >%s<\n", char_arr);

	if ('\0')
		printf("This will never print.\n");

return 0;
}

/* strcpy_arr1: copy t to s; very naive array subscript version */
void strcpy_arr1(char *s, char *t)
{
	int i, j;
	for (i=0, j=0; t[j] != '\0'; i++, j++)
		s[i] = t[j];
	s[i] = '\0';
}

/* strcpy_arr2: copy t to s; better array subscript version */
void strcpy_arr2(char *s, char *t)
{
	int i;
	i = 0;
	while ( (s[i] = t[i]) != '\0')
		i++;
}
/* strcpy: pointer version 1 */
void strcpy_ptr1(char *s, char *t)
{
	while ( (*s = *t) != '\0' )
	{
		s++; t++;
	}
}
/* strcpy: pointer version 2 */
void strcpy_ptr2(char *s, char *t)
{
	while ( (*s++ = *t++) != '\0' )
		;
}
/* strcpy: final, pointe version 3 */
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}
