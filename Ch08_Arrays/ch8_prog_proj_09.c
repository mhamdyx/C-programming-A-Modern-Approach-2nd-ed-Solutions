/*
 * ch8_prog_proj_09.c
 *
 *  Created on: Oct 23, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 9: Random Walk

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_ROWS 10
#define NUM_COLS 10
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3
#define FIRST_MOVE 'A'
#define LAST_MOVE 'Z'
#define VALID_MOVE true
#define INVALID_MOVE false

int main(void)
{
	char arr[NUM_ROWS][NUM_COLS], move = FIRST_MOVE;
	int row, col, direction;
	bool move_made = false, neighbor[4] = {INVALID_MOVE};

	// Initialize the array
	for (row = 0; row < NUM_ROWS; row++)
		for (col = 0; col < NUM_COLS; col++)
			arr[row][col] = '.';

	// Prepare for random generation
	srand((unsigned) time(NULL));

	// First move is at 0,0
	row = 0;
	col = 0;
	arr[row][col] = move++;

	while (move <= LAST_MOVE)
	{
		// Check movement bounds
		if (row == 0)
			neighbor[UP] = INVALID_MOVE;
		else
			neighbor[UP] = VALID_MOVE;

		if (col == 0)
			neighbor[LEFT] = INVALID_MOVE;
		else
			neighbor[LEFT] = VALID_MOVE;

		if (row == NUM_ROWS - 1)
			neighbor[DOWN] = INVALID_MOVE;
		else
			neighbor[DOWN] = VALID_MOVE;

		if (col == NUM_COLS - 1)
			neighbor[RIGHT] = INVALID_MOVE;
		else
			neighbor[RIGHT] = VALID_MOVE;


		while(!move_made)
		{
			// Choose a random direction
			direction = rand() % 4;

			switch (direction)
			{
			case UP:
				if (neighbor[UP] == VALID_MOVE && arr[row - 1][col] == '.')
					arr[--row][col] = move;
				else
					neighbor[UP] = INVALID_MOVE;
				break;

			case LEFT:
				if (neighbor[LEFT] == VALID_MOVE && arr[row][col - 1] == '.')
					arr[row][--col] = move;
				else
					neighbor[LEFT] = INVALID_MOVE;
				break;

			case DOWN:
				if (neighbor[DOWN] == VALID_MOVE && arr[row + 1][col] == '.')
					arr[++row][col] = move;
				else
					neighbor[DOWN] = INVALID_MOVE;
				break;

			case RIGHT:
				if (neighbor[RIGHT] == VALID_MOVE && arr[row][col + 1] == '.')
					arr[row][++col] = move;
				else
					neighbor[RIGHT] = INVALID_MOVE;
				break;
			}

			// Check if all directions are blocked to terminate
			if(!neighbor[UP] && !neighbor[LEFT] && !neighbor[DOWN] && !neighbor[RIGHT])
				break;

			// Check if a move was made (because it was valid)
			if (neighbor[direction] == VALID_MOVE)
				move_made = true;
		}

		// Check if we need to terminate because of a block
		if (!move_made)
			break;

		// Increment move
		move++;

		// Reset movement flag
		move_made = false;
	}

	// Print the random walk
	for (row = 0; row < NUM_ROWS; row++)
	{
		for (col = 0; col < NUM_COLS; col++)
		{
			putchar(arr[row][col]);
			putchar(' ');
		}

		putchar('\n');
	}

	putchar('\n');

	return 0;
}
