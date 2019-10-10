#include <stdio.h>

/* strcpy: copy t to s; array subscript version */
void strcpy_arr(char *s, char *t)
{
	int i;
	i = 0;
	while ( (s[i] = t[i]) != '\0')
		i++;
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy_ptr_1(char *s, char *t)
{
	while ( (*s = *t) != '\0')
	{
		s++;
		t++;
	}
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_ptr_2(char *s, char *t)
{
	while ( (*s++ = *t++) != '\0')
		;
/* This works since earlier we saw that ++*t works like (*t)++
 *	since the precedence that unary operators like ++ and
 *	* work from RIGHT to LEFT with precedence, but since ++
 *	precedence will impact the variable after it is read through,
 *	the *t will resolve to the value at pointer t BEFORE the increment
 *	to the address of t.
 */
}

int main()
{
	char *src1 = "kenneth";
	char src2[8] = "wheeler";

	//char *targ1;	/* This will not work as a target to copy in to.  This address is null! */
	char targ1[10];
	char targ2[10];
	char targ3[10];

	char *ptarg3;
	ptarg3 = targ3;

	printf("src1 = %s\n", src1);
	printf("src2 = %s\n\n", src2);

	strcpy_arr(targ1, src1);
	printf("targ1 = %s\n", targ1);

	strcpy_ptr_1(targ2, src2);
	printf("targ2 = %s\n", targ2);

	strcpy_ptr_2(ptarg3, src1);
	printf("ptarg3 = %s\n", ptarg3);
	
return 0;
}
