/*
 * ch8_prog_proj_16.c
 *
 *  Created on: Oct 23, 2019
 *      Author: Mahmoud Hamdy
 */

 
// Programming Project 16: Anagrams

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	// Counters to compute the length of each word
	int word_len = 0;

	// Input char
	char c;

	// Array to detect anagrams
	int anagrams[26] = {0};

	// Reading the first word
	printf("Enter first word: ");

	do
	{
		c = getchar();

		if(isalpha(c))
		{
			word_len++;
			c = tolower(c);
			anagrams[c - 'a']++;
		}

	}while(c != '\n');

	// Reading the second word
	printf("Enter second word: ");

	do
	{
		c = getchar();

		if(isalpha(c))
		{
			word_len--;
			c = tolower(c);
			anagrams[c - 'a']--;
		}

	}while(c != '\n');

	// Anagrams test 1
	if(word_len != 0)
	{
		printf("The words are not anagrams");
		return 0;
	}

	// Anagrams test 2
	for(int i = 0; i < 26; i++)
	{
		if(anagrams[i] != 0)
		{
			printf("The words are not anagrams");
			return 0;
		}
	}

	printf("The words are anagrams");

	return 0;
}
