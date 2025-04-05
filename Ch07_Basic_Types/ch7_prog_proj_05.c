/*
 * ch7_prog_proj_05.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Scrabble

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char input_ch;
	int score = 0;

	printf("Enter a word: ");

	while((input_ch = getchar()) != '\n')
	{
		switch(toupper(input_ch))
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

	printf("Scrabble value: %d\n", score);

	return 0;
}


// Faster implementation using arrays (to be studied in ch8)
// (Tradeoff between memory and speed)
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int face_value[26] =
	{
			1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
	};

	char input_ch;
	int score = 0;

	printf("Enter a word: ");

	while((input_ch = getchar()) != '\n')
	{
		if(input_ch >= 'A' && input_ch <= 'z')
			score += face_value[toupper(input_ch) - 'A'];
	}

	printf("Scrabble value: %d\n", score);

	return 0;
}
*/
