//
// Created by Vasco Varas on 9/17/19.
//

// CONSIDERATIONS: The arrays are sorted

#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	// location inside int array a and b
	int pos_a = 0, pos_b = 0;
	// keep track if it has already printed something so we can add space
	int started = 0;

	// While the positions are less than the length or the arrays
	while (pos_a < na && pos_b < nb)
	{
		// If in the checking position, they are the same, print and find the next one
		if (a[pos_a] == b[pos_b]) {
			if (started == 1)
				printf(" ");
			printf("%i", a[pos_a]);
			started = 1;
			pos_a++;
			pos_b++;
		}
		// if the value on position b is less than the one on position a, increment on position b (only because arrays are sorted)
		if (a[pos_a] > b[pos_b])
			pos_b++;
		// if the value on pos a is less than on pos b, increment pos b (only works because arrays are sorted)
		if (a[pos_a] < b[pos_b])
			pos_a++;
	}
}

// MAIN

int			main(int argc, char *argv[])
{
	int a[] = { 100, 200, 300 };
	int b[] = { 1, 2, 3, 4 };
	print_doublon(a, 3, b, 4);
	return (0);
}