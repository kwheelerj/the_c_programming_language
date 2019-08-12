#include <stdio.h>

void print_all(int *px, int *py)
{
printf("\tAddresses:\n");
	printf("\t\tpx = %d\n", px);
	printf("\t\tpy = %d\n", py);
printf("\tValues:\n");
	printf("\t\t*px = %d\n", *px);
	printf("\t\t*py = %d\n", *py);
	printf("\t************************************\n");
}

void swap_wrong(int *px, int *py)
{
// swap the pointers.
	int *temp;

	temp = px;
print_all(px, py);
	px = py;
	py = temp;
print_all(px, py);
/* This way is wrong because swapping the pointers will also swap the
 *	values with the pointers, so address 001 will still have value 1
 *	while address 002 will still have value 2 in the end.
 */
/* You need to swap the values at the pointers, swapping the addresses does not impact
 *	the values at the addresses.
 */
/* Here, you are just swapping COPIES of the address, without impact to the values! */
}

void swap(int *px, int *py)
{
// swap the values at the pointer.
	int temp;

	temp = *px;
print_all(px, py);
	*px = *py;
	*py = temp;
print_all(px, py);
}

int test1()
{
printf("================\n");
printf("test 1 (will fail):\n");
	int x = 1;
	int y = 2;

	printf("----------------\n");
	printf("BEFORE:\n");
	printf("\tx = %d\n", x);
	printf("\ty = %d\n", y);
	printf("----------------\n");

	swap_wrong(&x, &y);

	printf("----------------\n");
	printf("AFTER:\n");
	printf("\tx = %d\n", x);
	printf("\ty = %d\n", y);
	printf("----------------\n");
}


void test2()
{
printf("================\n");
printf("test 2 (will pass):\n");
	int x = 1;
	int y = 2;

	printf("----------------\n");
	printf("BEFORE:\n");
	printf("\tx = %d\n", x);
	printf("\ty = %d\n", y);
	printf("----------------\n");

	swap(&x, &y);

	printf("----------------\n");
	printf("AFTER:\n");
	printf("\tx = %d\n", x);
	printf("\ty = %d\n", y);
	printf("----------------\n");
}

int main()
{
	test1();
	test2();
return 0;
}
