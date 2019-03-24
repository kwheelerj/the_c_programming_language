#include <stdio.h>

#define SIZE	100000

int binsearch_fast(int x, int v[], int n);

int main()
{
	int result, i;
	int nums[SIZE];
	for (i = 0; i < SIZE; i++)
		nums[i] = i+1;	
	
	result = binsearch_fast(4, nums, SIZE);

	printf("Result: %d\n", result);

	return 0;
}

int binsearch_fast(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	while (low <= high && x != v[mid])
	{
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid-1;
		else
			low = mid+1;
	}

	return (x == v[mid]) ? mid : -1;
}
