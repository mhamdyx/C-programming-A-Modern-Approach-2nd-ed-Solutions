/*
 * ch13_prog_proj_03.c
 *
 *  Created on: Dec 18, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Dealing random hand of cards(8.2 deal.c)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = {{false}};
	int num_cards, rank, suit;

	const char *rank_code[] =
	{
			"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
			"Ten", "Jack", "Queen", "King", "Ace"
	};

	const char *suit_code[] = {"clubs", "diamonds", "hearts", "spaces"};

	srand((unsigned) time(NULL)); // Setting a seed

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);

	printf("You hand:\n");

	while(num_cards > 0)
	{
		suit = rand() % NUM_SUITS;
		rank = rand() % NUM_RANKS;

		if(!in_hand[suit][rank])
		{
			in_hand[suit][rank] = true;
			num_cards--;
			printf("%s of %s\n", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n");

	return 0;
}
