/*
 * ch13_prog_proj_14.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 14: Anagrams

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define WORD_LEN 100

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char word1[WORD_LEN + 1] = {0}, word2[WORD_LEN + 1] = {0};
	char input_ch, *word_ptr;

	// Reading the first word
	printf("Enter first word: ");
	word_ptr = word1;
	do
	{
		input_ch = getchar();

		if (isalpha(input_ch))
			*word_ptr++ = tolower(input_ch);
	} while (input_ch != '\n');

	// Reading the second word
	printf("Enter second word: ");
	word_ptr = word2;
	do
	{
		input_ch = getchar();

		if (isalpha(input_ch))
			*word_ptr++ = tolower(input_ch);

	} while(input_ch != '\n');

	if (are_anagrams(word1, word2))
		printf("The words are anagrams\n");
	else
		printf("The words are not anagrams\n");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int i, anagrams[26] = {0};

	while (*word1 && *word2)
	{
		anagrams[*word1++ - 'a']++;
		anagrams[*word2++ - 'a']--;
	}

	if (*word1 != *word2)
		return false;

	for (i = 0; i < 26; i++)
		if (anagrams[i])
			return false;

	return true;
}
