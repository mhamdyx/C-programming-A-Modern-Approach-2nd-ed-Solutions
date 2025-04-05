/*
 * ch8_prog_proj_17.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 17: Magic square

#include <stdio.h>

int main(void)
{
	// Magic square size
	int n;

	// Reading the magic number
	printf("This program creates a magic square of a specified size\n");
	printf("The size must be an odd number between 1 and 99\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	// Building the magic square
	int magic_square[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			magic_square[i][j] = 0;
		}
	}

	int x_pos = 0, y_pos = n / 2, square_size = n * n;

	magic_square[x_pos][y_pos] = 1;


	for(int i = 1; i < square_size; i++)
	{
		if(magic_square[(x_pos - 1 + n) % n][(y_pos + 1) % n] == 0)
		{
			x_pos = (x_pos - 1 + n) % n;
			y_pos = (y_pos + 1) % n;
			magic_square[x_pos][y_pos] = i + 1;
		}
		else
		{
			x_pos++;
			magic_square[x_pos][y_pos] = i + 1;
		}
	}


	// Padding output
	int padding_len = 1;
	int multiplier = 10;
	for(int i = 0; i < 10; i++)
	{
		if((square_size / multiplier)  == 0)
		{
			break;
		}
		padding_len++;
		multiplier *= 10;

	}

	// Printing the magic square (with correct padding)
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%0*d   ", padding_len, magic_square[i][j]);
		}
		printf("\n");
	}
	return 0;
}
