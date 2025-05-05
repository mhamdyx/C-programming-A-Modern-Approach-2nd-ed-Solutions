/*
 * ch12_prog_proj_05.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Reverse words in a sentence (New implementation)

#include <stdio.h>
#define MAX_LEN 100

int main(void)
{
	char sentence[MAX_LEN], input_ch;
	char *sent_ptr = sentence, *word_start, *word_end;

	printf("Enter a sentence: ");
	while ((input_ch = getchar()) != '\n')
	{
		if (input_ch == '.' || input_ch == '?' || input_ch == '!')
			break;
		else
			*sent_ptr++ = input_ch;
	}

	printf("Reversal of sentence: ");
	for (word_start = sent_ptr - 1; word_start > sentence;)
	{
		// Detect the first character of the word to be printed
		while (*(word_start - 1) != ' ' && word_start > sentence)
			word_start--;

		// Print the word and make sure we don't go out of:
		// 1) sentence bound (the end of the sentence array)
		// 2) word bound (space)
		for (word_end = word_start; word_end < sent_ptr && *word_end != ' '; word_end++)
			putchar(*word_end);

		// Detect the last character in the next word to be printed
		while (*(word_start - 1) == ' ' && word_start > sentence)
		{
			putchar(' ');
			word_start--;
		}
	}

	putchar(input_ch); // Print the terminating character
	putchar('\n');

	return 0;
}
