//
// Created by Vasco Varas on 9/17/19.
//

#include <stdio.h>
#include <stdlib.h>

int 	count_each_2(int n)
{
	int count = 0;
	// If n is 2 digits or more, call count for the first part without the last digit and for the last digit separately
	if (n >= 10)
	{
		count = count_each_2(n / 10);
		count += count_each_2(n % 10);
	}
	else
	{
		if (n == 2)
			// If it's a 2, add it to count
			count++;
	}
	return count;
}

int    count_of_2(int n)
{
	// Return 0 if n <= 1 (Explicit rule)
	if (n <= 1)
		return 0;
	int i = 0;

	int count = 0;
	// Do it for each number up to n
	while (i <= n)
	{
		// Count and add it to the total count
		count += count_each_2(i);
		i++;
	}
	return count;
}


// MAIN

//int			main(int argc, char *argv[])
//{
//	if (argc == 2)
//		printf("%i\n", count_of_2(atoi( argv[1] )));
//	return (0);
//}