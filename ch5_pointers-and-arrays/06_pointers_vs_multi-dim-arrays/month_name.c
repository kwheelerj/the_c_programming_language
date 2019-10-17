#include <stdio.h>

/* month_name: return name of n-th month */
char *month_name(int n)
{
	/* 15 here servers as the max 'col' length, or in this case
	 *	it is actually the max length of the strings accessed
	 *	via the first subscript in the aname multi-dim array.
	 */
	static char aname[][15] =
	{
		"Illegal month",
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	return (n < 1 || n > 12) ? aname[0] : aname[n];

/* The characters of each string are placed 'somewhere', each string is assigned
 *	a corresponding position in the array.
 * The pointer is all that matters here, stored in name[i].
 *
 * Since the size of the array is not specified, the compiler counts the initializers
 *	and fills in the correct number.
 */

}

int main()
{
	char *res;

	res = month_name(13);
	printf("res = >%s<\n\n", res);
	
	res = month_name(1);
	printf("res = >%s<\n\n", res);

	res = month_name(9);
	printf("res = >%s<\n\n", res);

return 0;
}
