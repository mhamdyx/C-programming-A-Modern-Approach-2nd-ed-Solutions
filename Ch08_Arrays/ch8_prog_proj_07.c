/*
 * ch8_prog_proj_07.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: 5 x 5 array of integers

#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 5

int main(void)
{
	int arr[NUM_ROWS][NUM_COLS], row, col;
	int row_totals[NUM_ROWS] = {0}, column_totals[NUM_COLS] = {0};

	for (row = 0; row < NUM_ROWS; row++)
	{
		printf("Enter row %d: ", row + 1);
		for (col = 0; col < NUM_COLS; col++)
		{
			scanf("%d", &arr[row][col]);
			row_totals[row] += arr[row][col];
			column_totals[col] += arr[row][col];
		}
	}

	printf("\nRow totals:");
	for (row = 0; row < NUM_ROWS; row++)
		printf(" %d", row_totals[row]);

	printf("\nColumn totals:");
	for (col = 0; col < NUM_COLS; col++)
		printf(" %d", column_totals[col]);

	printf("\n");

	return 0;
}
