//
// Created by Vasco Varas on 9/17/19.
//

#include "flood_fill.h"
#include <cstdio>

void flood_fill_pixel(char **tab, t_point size, t_point begin, char target)
{

	// check the position is in the boundaries of the map
	if (begin.x >= 0 && begin.y >= 0 && begin.x < size.x && begin.y < size.y)
	{
		// check if the character is the target
		if (tab[begin.y][begin.x] == target)
		{
			// Set the current pixel to 'F'
			tab[begin.y][begin.x] = 'F';
			// Call the function on the other 4 sides
			//Top
			flood_fill_pixel(tab, size, (t_point){begin.x, begin.y - 1}, target);
			//Right
			flood_fill_pixel(tab, size, (t_point){begin.x + 1, begin.y}, target);
			//Bottom
			flood_fill_pixel(tab, size, (t_point){begin.x, begin.y + 1}, target);
			//Left
			flood_fill_pixel(tab, size, (t_point){begin.x - 1, begin.y}, target);
		}
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	// Check if the beginning is inside the boundaries
	if (begin.x >= 0 && begin.y >= 0 && begin.x < size.x && begin.y < size.y)
	{
		// Check if the beginning is not the replace character 'F' to prevent infinite loop
		if (tab[begin.y][begin.x] != 'F')
		{
			// call flood_fill_pixel to start
			flood_fill_pixel(tab, size, begin, tab[begin.y][begin.x]);
		}
	}
}

// MAIN AND MAIN's EXTRAS

void print_area(char **tab, t_point size)
{
	int x = 0;
	int y = 0;

	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			printf("%c ", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {2, 2};

	char line1[] = { '1', '1', '1', '1', '1', '1', '1', '1' };
	char line2[] = { '1', '0', '0', '0', '1', '0', '0', '1' };
	char line3[] = { '1', '0', '0', '1', '0', '0', '0', '1' };
	char line4[] = { '1', '0', '1', '1', '0', '0', '0', '1' };
	char line5[] = { '1', '1', '1', '0', '0', '0', '0', '1' };
	char *zone[] = {
			line1,
			line2,
			line3,
			line4,
			line5
	};
	print_area(zone, size);
	printf("\n");
	flood_fill(zone, size, begin);
	print_area(zone, size);
	return (0);
}

