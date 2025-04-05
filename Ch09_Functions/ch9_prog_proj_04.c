/*
 * ch9_prog_proj_04.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Anagrams

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);


int main(void)
{
	// Arrays to detect anograms
	int word1_count[26] = {0}, word2_count[26] = {0};

	// Reading the first word
	printf("Enter first word: ");
	read_word(word1_count);

	// Reading the second word
	printf("Enter second word: ");
	read_word(word2_count);

	// Anagrams test
	if(equal_array(word1_count, word2_count))
	{
		printf("The words are anagrams");
	}
	else
	{
		printf("The words are not anagrams");
	}

	return 0;
}

void read_word(int counts[26])
{
	// Input char
	char c;

	do
	{
		c = getchar();

		if(isalpha(c))
		{
			c = tolower(c);
			counts[c - 'a']++;
		}

	}while(c != '\n');
}

bool equal_array(int counts1[26], int counts2[26])
{
	for(int i = 0; i < 26; i++)
	{
		if(counts1[i] != counts2[i])
			return false;
	}

	return true;
}
