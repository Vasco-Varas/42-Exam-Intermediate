//
// Created by Vasco Varas on 05-02-20.
//

#define IS_LOWER (int)argv[1][i] >= 97 && (int)argv[1][i] <= 122
#define IS_UPPER (int)argv[1][i] >= 65 && (int)argv[1][i] <= 90

#define PRINT_COUNT(count, character) { printf("%s%d%c", i == 0 ? "" : ", ", count, character); count = 0; }

#define END { printf("\n"); return 0; }

#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		END;

	int count['a' - 'A' + 1] = {0};

	for (int i = 0; argv[1][i]; i++) {
		if (IS_LOWER)
			count[(int)argv[1][i] - 'a']++;
		else if (IS_UPPER)
			count[(int)argv[1][i] + ('a'-'A') - 'a']++;
	}

	for (int i = 0; argv[1][i]; i++) {
		if (IS_LOWER && count[(int)argv[1][i] - 'a'] > 0)
			PRINT_COUNT(count[(int)argv[1][i] - 'a'], argv[1][i]);
		if (IS_UPPER && count[(int)argv[1][i] + ('a'-'A') - 'a'] > 0)
			PRINT_COUNT(count[(int)argv[1][i] + ('a'-'A') - 'a'], argv[1][i] + ('a'-'A'));
	}
	END;
}