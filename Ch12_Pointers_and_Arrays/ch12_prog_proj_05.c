/*
 * ch12_prog_proj_05.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Reverse words in a sentence

#include <stdio.h>
#define LEN 100
int main(void)
{
	char sentence[LEN], input, *sent_ptr = sentence, *word_begin, *word_end;

	printf("Enter a sentence: ");

	input = getchar();
	while(input != '!' &&  input != '?' && input != '.' && sent_ptr < sentence + LEN)
	{
		*sent_ptr++ = input;
		input = getchar();
	}
	sent_ptr--;

	// Sentence Reversal
	word_end = sent_ptr;
	word_begin = word_end;

	while(word_begin > sentence)
	{
		while(*word_begin != ' ' && word_begin != sentence) { word_begin--; }

		char *temp_ptr = (word_begin == sentence) ? word_begin : word_begin + 1;

		while(temp_ptr <= word_end)
		{
			printf("%c", *temp_ptr++);
		}

		if(word_begin != sentence)
		{
			printf("%c", *word_begin);
			word_end = --word_begin; // Moving to the next word backwords
		}
	}

	// Printing the terminal character
	printf("%c", input);

	return 0;
}
