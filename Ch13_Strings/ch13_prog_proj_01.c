/*
 * ch13_prog_proj_01.c
 *
 *  Created on: Dec 17, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Smallest & Largest words

#include <stdio.h>
#include <string.h>
#define WORD_LEN 20
#define STOP_LEN 4

void read_word(char *word, int word_len)
{
	int count = 0;

	while ((*word++ = getchar()) != '\n' && count++ < word_len);

	*--word = '\0';

	if (count > word_len)
		while (getchar() != '\n');
}

int main(void)
{
	char input_word[WORD_LEN + 1], smallest_word[WORD_LEN + 1], largest_word[WORD_LEN + 1];
	int i;

	for (i = 0; i < WORD_LEN + 1; i++)
	{
		smallest_word[i] = 'z'; // largest value possible
		largest_word[i] = 'A'; // smallest value possible
	}

	do
	{
		printf("Enter word: ");
		read_word(input_word, WORD_LEN);

		if (strcmp(smallest_word, input_word) > 0)
			strcpy(smallest_word, input_word);

		if (strcmp(largest_word, input_word) < 0)
			strcpy(largest_word, input_word);

	} while(strlen(input_word) != STOP_LEN);

	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
