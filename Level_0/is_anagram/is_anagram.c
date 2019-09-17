//
// Created by Vasco Varas on 9/17/19.
//

#include <stdio.h>

int is_anagram(char *a, char *b)
{
	// make an array of itegers of the size of the max character ascii index to see how many have been used
	int charsUsed[127] = {0};
	int pos = 0;

	// save the amount of each character used in the first string
	while (a[pos])
		charsUsed[(int)a[pos++]]++;
	pos = 0;
	// subtract the amount of each character used on the second string, so that the remaining value, is de difference in the amount of characters
	while (a[pos])
		charsUsed[(int)b[pos++]]--;
	pos = 0;
	// if any difference is not 0, it means, that one string had more of that character than the other so return 0
	while (pos < 127)
	{
		if (charsUsed[pos++] != 0)
			return 0;
	}
	return 1;
}


// MAIN

//int 	main(int argc, char **argv)
//{
//	char *a = "abcdef";
//	char *b = "fabcde"; // result = 1
//
////	char *a = ".123?.";
////	char *b = "?321.."; // result = 1
////
////	char *a = "abca";
////	char *b = "bcab"; // result = 0
//
//	printf("%i", is_anagram(a, b));
//	return (0);
//}