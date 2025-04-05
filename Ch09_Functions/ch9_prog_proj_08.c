/*
 * ch9_prog_proj_08.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 8: Game of craps

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define WIN  (bool) 1
#define LOSS (bool) 0

int roll_dice(void);
bool play_game(void);

int main(void)
{
	// Seeding for random
	srand((unsigned) time(NULL));

	// Game Data
	bool game_outcome;
	int win_count = 0, loss_count = 0;
	char input_key = 0;

	do
	{
		// Game Playing
		game_outcome = play_game();

		if(game_outcome == WIN)
		{
			printf("You win!\r\n");
			win_count++;
		}
		else
		{
			printf("You lose!\r\n");
			loss_count++;
		}

		printf("Play again? ");
		fflush(stdout);
		input_key = getchar();
		fflush(stdin);

	}while(input_key == 'y' || input_key == 'Y');

	// Game Result
	printf("\nWins: %d  Losses: %d", win_count, loss_count);

	return 0;
}

int roll_dice(void)
{
	int dice1, dice2;

	dice1 = (rand() % 6) + 1;
	dice2 = (rand() % 6) + 1;

	return (dice1 + dice2);
}

bool play_game(void)
{
	bool outcome;
	int point = 0, roll;

	// First roll
	roll = roll_dice();

	if(roll == 7 || roll == 11)
	{
		outcome = WIN;
	}
	else if(roll == 2 || roll == 3 || roll == 12)
	{
		outcome = LOSS;
	}
	else
	{
		point = roll;
	}

	printf("You rolled: %d\n", roll);

	if(point)
	{
		printf("You point is %d\n", point);
	}

	// Another roll (if exists)
	while(point != 0)
	{
		roll = roll_dice();
		printf("You rolled: %d\n", roll);

		if(roll == point)
		{
			outcome = WIN;
			break;
		}
		else if(roll == 7)
		{
			outcome = LOSS;
			break;
		}
	}

	return outcome;
}
