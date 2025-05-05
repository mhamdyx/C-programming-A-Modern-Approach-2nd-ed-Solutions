/*
 * ch8_prog_proj_14.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 14: Reverse words in a sentence (New implementation)

#include <stdio.h>
#define MAX_LEN 100

int main(void)
{
	char sentence[MAX_LEN], input_ch;
	int len = 0, word_start, word_end;

	printf("Enter a sentence: ");
	while ((input_ch = getchar()) != '\n')
	{
		if (input_ch == '.' || input_ch == '?' || input_ch == '!')
			break;
		else
			sentence[len++] = input_ch;
	}

	printf("Reversal of sentence: ");
	for (word_start = len - 1; word_start > 0;)
	{
		while (sentence[word_start - 1] != ' ' && word_start > 0)
			word_start--;

		for (word_end = word_start; word_end < len && sentence[word_end] != ' '; word_end++)
			putchar(sentence[word_end]);

		while (sentence[word_start - 1] == ' ' && word_start > 0)
		{
			putchar(' ');
			word_start--;
		}
	}

	putchar(input_ch); // Print the terminating character
	putchar('\n');

	return 0;
}
