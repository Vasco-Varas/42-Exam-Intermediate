//
// Created by Vasco Varas on 9/17/19.
//

#include <stdio.h>

int find_pivot(int *arr, int n)
{
	int pos = 0, left = 0, total = 0;

	// Find sum of array
	while (pos < n)
		total += arr[pos++];

	pos = 1;
	left = arr[0];
	while (pos < n)
	{
		// left is the total sum on the left of the current index. so total - left - the current pos, is the right sum
		if (left == total - left - arr[pos])
			return (pos);
		// add the current value to the left sum to keep it updated
		left += arr[pos];
		pos++;
	}
	return (-1);
}

//int 		main(int argc, const char *argv[])
//{
//	int arr[] = {-5, 10, 2, 5};
//
//	printf("Pivot: %d\n", find_pivot(arr, 4));
//
//	return (0);
//}