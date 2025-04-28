/*
 * ch9_prog_proj_05.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Magic square (New implementation)

#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{
	int n;

	// Reading the magic number
	printf("This program creates a magic square of a specified size\n");
	printf("The size must be an odd number between 1 and 99\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	char magic_square[n][n];

	// Building the magic square
	create_magic_square(n, magic_square);

	// Printing the magic square (with correct padding)
	print_magic_square(n, magic_square);

	return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
	int row, col, number = 1, square_size;

	for(row = 0; row < n; row++)
		for(col = 0; col < n; col++)
			magic_square[row][col] = 0;

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

}

void print_magic_square(int n, char magic_square[n][n])
{
	int row, col;

	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
			printf("%5d", magic_square[row][col]);

		putchar('\n');
	}
}
