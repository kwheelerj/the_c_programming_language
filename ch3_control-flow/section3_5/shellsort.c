#include <stdio.h>
#include <stdlib.h>

#define SIZE	10000

/* Shell sort:
 *	invented in 1959 by D. L. Shell
 *	in early stages, far apart elements are compared
 *	ELIMINATES LARGE AMOUNTS OF DISORDER QUICKLY
 *	interval between compared elements gradually descreases to 1:
 *		which is then essentially an adjacent interchange.
 */
void shellsort(int v[], int n);
void init_arr(int v[]);
void print_arr(int v[]);

int main()
{
	int nums[SIZE];

	init_arr(nums);
	/* print_arr(nums); */

	shellsort(nums, SIZE);	
	print_arr(nums);	

	return 0;
}

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i <n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

void init_arr(int v[])
{
	for (int i = 0; i < SIZE; i++)
		v[i] = rand() % SIZE; 
}

void print_arr(int v[])
{
	for (int i = 0; i < SIZE; i++)
		printf("%d\n", v[i]);
}
