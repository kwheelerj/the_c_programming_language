#define ALLOCSIZE 10000	/* sdize of available space*/

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)	/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;	/* return old p */
	} 
	else
		return 0;
}

void afree(char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		alloc = p;
}
