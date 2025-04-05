/*
 * ch8_prog_proj_14.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 14: Reverse words in a sentence

#include <stdio.h>
#define LEN 100
int main(void)
{
	char sentence[LEN], input;
	int sent_len = 0, word_begin, word_end;

	printf("Enter a sentence: ");

	input = getchar();
	while(input != '!' &&  input != '?' && input != '.' && sent_len < LEN)
	{
		sentence[sent_len++] = input;
		input = getchar();
	}

	// Sentence Reversal
	word_end = sent_len - 1;
	word_begin = word_end;

	while(word_begin > 0)
	{
		while(sentence[word_begin] != ' ' && word_begin != 0) { word_begin--; }

		for(int i = (word_begin == 0) ? word_begin : word_begin + 1; i <= word_end; i++)
		{
			printf("%c", sentence[i]);
		}

		if(word_begin != 0)
		{
			printf("%c", sentence[word_begin]);
			word_end = --word_begin; // Moving to the next word backwords
		}
	}

	// Printing the terminal character
	printf("%c", input);

	return 0;
}
