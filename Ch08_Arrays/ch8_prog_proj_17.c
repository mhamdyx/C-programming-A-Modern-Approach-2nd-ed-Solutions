/*
 * ch8_prog_proj_17.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 17: Magic square (New implementation)

#include <stdio.h>

#define NUM_ROWS 99
#define NUM_COLS 99

int main(void)
{
	int n, row, col, number = 1, square_size;

	int magic_square[NUM_ROWS][NUM_COLS] = {0}; // Compatible with C89/C90

	// Reading the magic number
	printf("This program creates a magic square of a specified size\n");
	printf("The size must be an odd number between 1 and 99\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	// Alternative way to build the magic square in C99
	// but first delete this: int magic_square[NUM_ROWS][NUM_COLS] = {0};
	/*
	int magic_square[n][n];
	for(row = 0; row < n; row++)
		for(col = 0; col < n; col++)
			magic_square[row][col] = 0;
	*/

	row = 0, col = n / 2, square_size = n * n;

	magic_square[row][col] = number;


	for (number = 2; number <= square_size; number++)
	{
		if (magic_square[(row - 1 + n) % n][(col + 1) % n] == 0)
		{
			row = (row - 1 + n) % n;
			col = (col + 1) % n;
		}
		else
			row++;
		
		magic_square[row][col] = number;
	}

	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
			printf("%5d", magic_square[row][col]);

		putchar('\n');
	}

	return 0;
}
