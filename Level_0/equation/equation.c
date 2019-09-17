//
// Created by Vasco Varas on 9/17/19.
//

#include <stdio.h>

void    equation(int n)
{
	int a = 0, b = 0, c = 0;
	// try all combinations (a total of 10^3 = 1000 combinations)
	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{
			c = 0;
			while (c < 10)
			{
				// For each character rotation try to match the result, if it does, print.
				if (((10*a)+b) + ((10*c)+a) == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

//int 	main(int argc, char **argv)
//{
//	equation(111);
//	return (0);
//}