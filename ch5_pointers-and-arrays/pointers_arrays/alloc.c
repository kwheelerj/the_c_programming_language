#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];
/* cannot be seen outside this file, since static */
/* This will be the large array to be set aside as what to pull from
with alloc. */
static char *allocp = allocbuf;


char *alloc(int n)	/* return pointer to n characters (from allocbuf) */
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n; /* old allocp */
	} else
		return 0;	/* C guarantees that 0 is NEVER a valid address for data. */
}

void afree(char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
