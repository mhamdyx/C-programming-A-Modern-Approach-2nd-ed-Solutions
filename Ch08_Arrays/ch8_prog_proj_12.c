/*
 * ch8_prog_proj_12.c
 *
 *  Created on: Apr 25, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 12: Scrabble (modified)

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char input_ch;
	int score = 0;
	int face_values[26] =
	{
			1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
			1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
	};

	printf("Enter a word: ");

	while ((input_ch = toupper(getchar())) != '\n')
		score += face_values[input_ch - 'A'];

	printf("Scrabble value: %d\n", score);

	return 0;
}
