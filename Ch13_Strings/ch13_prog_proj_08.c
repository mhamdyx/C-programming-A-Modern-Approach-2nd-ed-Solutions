/*
 * ch13_prog_proj_08.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 8: Scrabble

// Faster implementation (Tradeoff between memory and speed)
#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *word);

int main(void)
{
	char input_word[100] = {0}; // Total number of tiles in real life
	char *word_ptr = input_word;
	int score;

	printf("Enter a word: ");

	while((*word_ptr = getchar()) != '\n')
		word_ptr++;

	*word_ptr = '\0'; // replace '\n' by '\0'

	score = compute_scrabble_value(input_word);
	printf("Scrabble value: %d\n", score);

	return 0;
}

int compute_scrabble_value(const char *word)
{
	int score = 0;

	int face_value[26] =
	{
			1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
	};

	while(*word++)
	{
		if(*word >= 'A' && *word <= 'z')
			score += face_value[toupper(*word) - 'A'];
	}

	return score;
}


// Slower Implementation (Treadeoff between memory and speed)
/*
#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *word);

int main(void)
{
	char input_word[100] = {0}; // Total number of tiles in real life
	char *word_ptr = input_word;
	int score;

	printf("Enter a word: ");

	while((*word_ptr = getchar()) != '\n')
		word_ptr++;

	*word_ptr = '\0'; // replace '\n' by '\0'

	score = compute_scrabble_value(input_word);

	printf("Scrabble value: %d\n", score);

	return 0;
}

int compute_scrabble_value(const char *word)
{
	int score = 0;

	while(*word++)
	{
		switch(toupper(*word))
		{
		case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R':
		case 'S': case 'T': case 'U': score++; break;

		case 'D': case 'G': score += 2; break;

		case 'B': case 'C': case 'M': case 'P': score += 3; break;

		case 'F': case 'H': case 'V': case 'W': case 'Y': score += 4; break;

		case 'K': score += 5; break;

		case 'J': case 'X': score += 8; break;

		case 'Q': case 'Z': score += 10; break;

		}
	}

	return score;
}
*/
