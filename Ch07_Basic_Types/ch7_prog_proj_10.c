/*
 * ch7_prog_proj_10.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 10: Number of Vowels

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char input_ch;
	int num_vowels = 0;

	printf("Enter a sentence: ");

	while((input_ch = getchar()) != '\n')
	{
		switch(toupper(input_ch))
		{
		case 'A': case 'E': case 'I': case 'O': case 'U':
			num_vowels++; break;
		}
	}

	printf("Your sentence contains %d vowels\n", num_vowels);

	return 0;
}
