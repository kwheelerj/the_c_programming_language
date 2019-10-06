#include <stdio.h>

int main()
{
	int a[10];

	int *pa;

	pa = &a[0];

	int x;

	x = *pa;

	*(pa+1);	/* refers to the contents of a[1], since pa = &a[0]; */
	/* Note, that this is truew no matter the type or size of the variables in the array! */

	pa = a;	/* This means the same thing as pa = &a[0], only since pa is a pointer and a is an array! */

	*(a+1);		/* refers to a[1] */

	/* Thus, we conclude that &a[1] and a+1 are identical. */

	pa[1]; /* identical to *(pa+1) */

/* "In short, an array-and-index expression is equivalent to one written as a pointer and offset." */

/* A pointer is a variable, so pa=a and pa++ are fine. BUT
 *	an array name is not a variable; constructors like a=pa and a++ are illegal.
 */

// f(int arr[]) {...} == f(int *arr) {...}

return 0;
}
