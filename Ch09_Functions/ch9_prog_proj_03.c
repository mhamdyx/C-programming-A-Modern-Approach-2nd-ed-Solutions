/*
 * ch9_prog_proj_03.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Random Walk

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3
#define LAST_MOVE 'Z'
#define VALID_MOVE true
#define INVALID_MOVE false

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
	// Initialize array
	char walk[10][10];

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			walk[i][j] = '.';
		}
	}

	// Random walk algorithm
	generate_random_walk(walk);

	// Printing the walk
	print_array(walk);

	return 0;
}

void generate_random_walk(char walk[10][10])
{
	// Position Neighbours
	bool neighbour[4] = {INVALID_MOVE};

	// Set the seed of time
	srand((unsigned) time(NULL)); // NULL or 0

	// Initial move
	int direction, x_pos = 0, y_pos = 0;
	char move = 'A';
	walk[x_pos][y_pos] = move++;

	while(move <= LAST_MOVE)
	{
		if(x_pos - 1 >= 0 && walk[x_pos - 1][y_pos] == '.')
		{
			neighbour[UP] = VALID_MOVE;
		}

		if(x_pos + 1 <= 9 && walk[x_pos + 1][y_pos] == '.')
		{
			neighbour[DOWN] = VALID_MOVE;
		}

		if(y_pos - 1 >= 0 && walk[x_pos][y_pos - 1] == '.')
		{
			neighbour[LEFT] = VALID_MOVE;
		}

		if(y_pos + 1 <= 9 && walk[x_pos][y_pos + 1] == '.')
		{
			neighbour[RIGHT] = VALID_MOVE;
		}

		// Detecting closed loop (stopping condition)
		if(!neighbour[UP] && !neighbour[DOWN] && !neighbour[LEFT] && !neighbour[RIGHT])
			break;

		// Randomly generated direction
		direction = rand() % 4;

		switch(direction)
		{
			case UP:
				if(neighbour[UP] == VALID_MOVE)
				{
					walk[--x_pos][y_pos] = move++;
				}
				break;

			case DOWN:
				if(neighbour[DOWN] == VALID_MOVE)
				{
					walk[++x_pos][y_pos] = move++;
				}
				break;

			case LEFT:
				if(neighbour[LEFT] == VALID_MOVE)
				{
					walk[x_pos][--y_pos] = move++;
				}
				break;

			case RIGHT:
				if(neighbour[RIGHT] == VALID_MOVE)
				{
					walk[x_pos][++y_pos] = move++;
				}
				break;
		}

		neighbour[UP] = INVALID_MOVE;
		neighbour[DOWN] = INVALID_MOVE;
		neighbour[LEFT] = INVALID_MOVE;
		neighbour[RIGHT] = INVALID_MOVE;
	}
}

void print_array(char walk[10][10])
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			printf("%c ", walk[i][j]);
		}
		printf("\n");
	}
}
