/*
 * ch10_prog_proj_03.c
 *
 *  Created on: Nov 8, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Poker

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

// External Variables
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
int hand[NUM_CARDS][2] = {{0}};
bool straight, flush, four, three;
int pairs; // can be 0, 1, or 2

// Prototypes
void read_cards(void);
void sort_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
	for(;;)
	{
		read_cards();
		analyze_hand();
		print_result();
	}
	return 0;
}

void read_cards(void)
{
	bool card_exists;
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card;
	int cards_read = 0;


	while(cards_read < NUM_CARDS)
	{
		bad_card = false;
		card_exists = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch(rank_ch)
		{
		case '0': exit(EXIT_SUCCESS);
		case '2': rank = 0; break;
		case '3': rank = 1; break;
		case '4': rank = 2; break;
		case '5': rank = 3; break;
		case '6': rank = 4; break;
		case '7': rank = 5; break;
		case '8': rank = 6; break;
		case '9': rank = 7; break;
		case 't': case 'T': rank = 8; break;
		case 'j': case 'J': rank = 9; break;
		case 'q': case 'Q': rank = 10; break;
		case 'k': case 'K': rank = 11; break;
		case 'a': case 'A': rank = 12; break;
		default: bad_card = true;
		}

		suit_ch = getchar();
		switch(suit_ch)
		{
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true;
		}

		while((ch = getchar()) != '\n')
			if(ch != ' ')
				bad_card = true;


		// Detect duplications
		for(int i = 0; i < cards_read; i++)
		{
			if(hand[i][RANK] == rank && hand[i][SUIT] == suit)
			{
				card_exists = true;
				break;
			}
		}

		if(bad_card)
		{
			printf("Bad Card; ignored.\n");
		}
		else if(card_exists)
		{
			printf("Duplicate Card; ignored.\n");
		}
		else
		{
			hand[cards_read][RANK] = rank;
			hand[cards_read][SUIT] = suit;
			cards_read++;
		}

	}
}

void sort_cards(void)
{
	int temp_rank, temp_suit;
	// Sorting by rank (bubble sort)
	for(int i = 0; i < NUM_CARDS - 1; i++)
	{
		for(int j = i + 1; j < NUM_CARDS; j++)
		{
			if(hand[j][RANK] < hand[i][RANK])
			{
				temp_rank = hand[i][RANK];
				temp_suit = hand[i][SUIT];
				hand[i][RANK] = hand[j][RANK];
				hand[i][SUIT] = hand[j][SUIT];
				hand[j][RANK] = temp_rank;
				hand[j][SUIT] = temp_suit;
			}
		}
	}
}

void analyze_hand(void)
{
	int num_consec = 1, flush_count = 1, rank_count = 1, last_checked_rank = 0;

	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	// Sort the cards by rank only (no need to sort by suit)
	sort_cards();

	// Check for flush
	for(int i = 1; i < NUM_CARDS; i++)
	{
		if(hand[i][SUIT] != hand[0][SUIT])
		{
			break;
		}
		flush_count++;
	}

	if(flush_count == NUM_CARDS)
		flush = true;

	// Check for straight
	for(int i = 1; i < NUM_CARDS; i++)
	{
		if((hand[i][RANK] - hand[i - 1][RANK]) != 1)
		{
			break;
		}
		num_consec++;
	}

	if(num_consec == NUM_CARDS)
	{
		straight = true;
		return;
	}

	// Check for 4-of-a-kind, 3-of-a-kind, and pairs
	for(int i = 0; i < NUM_CARDS - 1; i++)
	{
		if(hand[i][RANK] == last_checked_rank)
		{
			continue;
		}

		for(int j = i + 1; j < NUM_CARDS; j++)
		{
			if(hand[j][RANK] == hand[i][RANK])
			{
				rank_count++;
			}
		}

		if(rank_count == 4)
		{
			four = true;
			break;
		}
		else if(rank_count == 3)
		{
			three = true;
		}
		else if(rank_count == 2)
		{
			pairs++;
		}

		rank_count = 1;
		last_checked_rank = hand[i][RANK];
	}
}

void print_result(void)
{
	if(straight && flush)
		printf("Straight flush");
	else if(four)
		printf("Four of a kind");
	else if(three && pairs == 1)
		printf("Full house");
	else if(flush)
		printf("Flush");
	else if(straight)
		printf("Straight");
	else if(three)
		printf("Three of a kind");
	else if(pairs == 2)
		printf("Two pairs");
	else if(pairs == 1)
		printf("Pair");
	else
		printf("High card");

	printf("\n\n");
}
