//
// Created by Vasco Varas on 9/17/19.
//

// CONSIDERATIONS: The arrays are sorted

#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int pos_a = 0, pos_b = 0;
	int started = 0;

	while (pos_a < na && pos_b < nb)
	{
		if (a[pos_a] == b[pos_b]) {
			if (started == 1)
				printf(" ");
			printf("%i", a[pos_a]);
			started = 1;
			pos_a++;
			pos_b++;
		}
		if (a[pos_a] > b[pos_b])
			pos_b++;
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