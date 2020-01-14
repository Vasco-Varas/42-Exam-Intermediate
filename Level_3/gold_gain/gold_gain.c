//
// Created by Vasco Varas on 14-01-20.
//

#include<stdlib.h>

int mine_test(int **bettermine, int **mine, int n, int posx, int posy)
{
	// check if is not out of the mine bounds
	if (posy < 0 || posy >= n)
		return 0;

	// check if it's in the last move
	if (posx == n - 1)
		return mine[posy][posx];

	// check if it's already calculated
	if (bettermine[posy][posx] != -1)
		return bettermine[posy][posx];

	// calculate all 3 possible moves
	int forwardgain = mine_test(bettermine, mine, n, posx + 1, posy);
	int upgain = mine_test(bettermine, mine, n, posx + 1, posy - 1);
	int downgain = mine_test(bettermine, mine, n, posx + 1, posy + 1);

	// check the max possible gain for this cell
	int maxgain = forwardgain > upgain ? forwardgain : upgain;
	maxgain = maxgain > downgain ? maxgain : downgain;
	maxgain += mine[posy][posx];

	// save cell's gain to prevent re-calculations
	bettermine[posy][posx] = maxgain;

	return maxgain;
}

int	gold_gain(int **mine, int n)
{
	// create new grid to store the best score you can get from each cell
	int **bettermine = (int **)malloc(sizeof(int *) * n);
	for( int y = 0; y < n; y++)
	{
		bettermine[y] = (int *)malloc(sizeof(int) * n);
		for( int x = 0; x < n; x++)
		{
			bettermine[y][x] = -1;
		}
	}

	// calculate best mining gain for each starting row and return the best one
	int minegain = 0;
	for (int row = 0; row < n; row++)
	{
		int rowgain = mine_test(bettermine, mine, n, 0, row);
		minegain = minegain > rowgain ? minegain : rowgain;
	}

	return minegain;
}




/*
#include<stdio.h>
int main()
{
	int **mine = (int **)malloc(sizeof(int*) * 3);


	mine[0] = (int *)malloc(sizeof(int) * 3);
	mine[1] = (int *)malloc(sizeof(int) * 3);
	mine[2] = (int *)malloc(sizeof(int) * 3);

	mine[0][0] = 1;
	mine[0][1] = 2;
	mine[0][2] = 3;
	mine[1][0] = 3;
	mine[1][1] = 4;
	mine[1][2] = 8;
	mine[2][0] = 9;
	mine[2][1] = 6;
	mine[2][2] = 7;

	printf("gain: %i\n", gold_gain(mine, 3));

}
*/
