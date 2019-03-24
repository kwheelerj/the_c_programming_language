#include <stdio.h>

#define SIZE	1000000

int binsearch(int x, int v[], int n);

int main()
{
	int result, i;
	int nums[SIZE];
	for (i = 0; i < SIZE; i++)
		nums[i] = i+1;
	
	result = binsearch(4, nums, SIZE);

	printf("Result: %d\n", result);

	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}
