//
// Created by Vasco Varas on 14-01-20.
//

int		fill_between(int *histogram, int p1, int p2, int min, int max)
{
	// if previously we filled to a greater height dont try re-filling
	if (max < min)
		return 0;

	int totalfill = 0;
	while(p1 < p2)
	{
		if (histogram[p1] < max)
		{
			// get the max fill for this histogram value taking in acount that what we can NOT fill is
			// the max between what's already filled and the histogram's value
			int filled = max - (min > histogram[p1] ? min : histogram[p1]);
			if (filled > 0)
				totalfill += filled;
		}
		p1++;
	}
	return totalfill;
}


int    volume_histogram(int *histogram, int size)
{
	// define the first and last histogram boundaries
	int p1 = 0;
	int p2 = size - 1;

	int last_max = 0;
	int filled = 0;

	// go shrinking size of fill-ing boundaries
	while(p1 < size)
	{
		p2 = size-1;
		while(p2 > 0)
		{
			// get the max height which can fill the histogram with the given bounds
			int new_max = histogram[p1] < histogram[p2] ? histogram[p1] : histogram[p2];
			// compute fill-ing size
			filled += fill_between(histogram, p1, p2, last_max, new_max);
			// save filled level to prevent re-filling
			last_max = new_max > last_max ? new_max : last_max;
			p2--;
		}
		p1++;
	}
	return filled;
}


/*
int main()
{

int    histogram[] = {1, 0, 2, 0, 2};
int    size = 5;

	printf("fill: %i\n", volume_histogram(histogram, size));

}
*/
