#include <stdio.h>

void print_values(int, int, int, int, int);

int main()
{
	int x = 1, y = 2, z[10];

	int *ip;	/* This declares/defines variable ip as a pointer */
	//print_values(x, y, z[0], z[11], *ip);
	/* If one tries to print the value of a pointer which has not been initialized,
	 * they will get a "Segmentation fault".
	 */

	ip = &x;	/* ip now points to x; variable ip holds address of variable x */
	/* If ip is not defined as a pointer before the previous line, then
	 *	the compiler will warn of making an integer of a pointer, &x being the pointer.
	 */
	print_values(x, y, z[0], z[11], *ip);

	y = *ip;	/* y is now the value of the pointer (1) */
	print_values(x, y, z[0], z[11], *ip);

	*ip = 0;	/* The value of the pointer ip is now 0, so x = 0 */
	/* Note that y does NOT also equal 0, since y was set to be the VALUE of
	 *	the pointer; it attained a COPY of the value; y is NOT also a pointer! */
	print_values(x, y, z[0], z[11], *ip);

	ip = &z[0];	/* ip POINTS to z[0] */
	print_values(x, y, z[0], z[11], *ip);

/* Some things to note at this point in time:
 *	Pointers are constrained to point to a specific type of variable.
 *	A void * (pointer to void) is used to hold any type of pointer, BUT
 *		it cannot be dereferenced itself.
 */

	*ip = *ip + 10;
	printf("*ip = %d\n", *ip);

	y = *ip + 1;
	printf("y = %d\n", y);

	*ip += 1;
	printf("*ip = %d\n", *ip);

	++*ip;
	printf("*ip = %d\n", *ip);

	(*ip)++;
	printf("*ip = %d\n\n", *ip);
	/* This last one needs the parentheses since unary operators (like * and ++)
	 *	will associate RIGHT to LEFT.
	 */

	int *iq;

	iq = ip;	/* pointer iq points to what pointer ip points to (address values) */
	printf("*iq = %d\n", *iq);
	printf("\t(iq = %d)\n", iq);
	printf("\t(ip = %d)\n", ip);


return 0;
}


void print_values(int x, int y, int z0, int z11, int ip)
{
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	printf("z[0] = %d\n",z0);
	printf("z[11] = %d\n",z11);
	printf("*ip = %d\n\n",ip);
}
