#include <stdio.h>

int main()
{
	char arr[] = "basic string";	/* CHARACTER ARRAY */
	char *t = arr;
	char val = 'j';

	printf("Step 0:\n");
	printf("\t*t = >%c<\n", *t);
	printf("\tarr = >%s<\n", arr);
	
	*t++ = val;
	/* Note: this FIRST dereference t, NEXT sets *t to val, LAST increments ptr t. */
	printf("Step 1:\n");
	printf("\t*t = >%c<\n", *t);
	printf("\tarr = >%s<\n", arr);


	/* The same behavior is NOT seen if we try to modify a string constant */
	char *ptr = "basic string";	/* STRING CONSTANT */
	char *p = ptr;

	printf("Step 0:\n");
	printf("\t*p = >%c<\n", *p);
	printf("\tptr = >%s<\n", ptr);
	
//	*p++ = val;
/* This causes an issue since modifying a string pointer is NOT the same as modifying a char array */
/* From the book:
 *		On the other hand, pmessage is a pointer, initialized to point to a string constant;
 *		the pointer may subsequently be modified to point elsewhere, but the result is undefined
 *		if you try to modify the string contents.
 *	Kernighan, Brian W.. C Programming Language (p. 104). Pearson Education. Kindle Edition. 
 */


	/* What happens if I try to modify the string arr contents directly, without a "helper" pointer? */
	char *str = "another string";
	printf("str = >%s<\n", str);
	*str++ = val;
	printf("str = >%s<\n", str);
	

/* MAIN IDEA:
 *	There are important differences between a char array and a char pointer, the most significant one being
 *		that char pointers should be seen as STRING CONTSTANTS and are NOT modifiable.
 *	A "helper pointer" will only modify a string if it is in fact a CHARACTER ARRAY.
 */


return 0;
}
