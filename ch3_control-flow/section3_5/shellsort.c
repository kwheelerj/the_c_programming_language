#include <stdio.h>

#define SIZE	10000

void shellsort(int v[], int n);

int main()
{
	int nums[SIZE], i;
	for (i = 0; i < SIZE; i++)
		nums[i] = rand() % SIZE; 

	shellsort(nums, SIZE);	
	for (i = 0; i < SIZE; i++)
		printf("%d\n", nums[i]);
	
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
