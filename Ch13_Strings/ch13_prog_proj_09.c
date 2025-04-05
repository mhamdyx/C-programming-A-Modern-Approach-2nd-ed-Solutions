/*
 * ch13_prog_proj_09.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 9: Number of Vowels

#include <stdio.h>
#include <ctype.h>
#define SENT_LEN 100

int compute_vowel_count(const char *sentence);
void read_sentence(char *sentence, int sent_len);

int main(void)
{
	char sentence[SENT_LEN];
	int num_vowels;

	printf("Enter a sentence: ");
	read_sentence(sentence, SENT_LEN);

	num_vowels = compute_vowel_count(sentence);

	printf("Your sentence contains %d vowels\n", num_vowels);

	return 0;
}


int compute_vowel_count(const char *sentence)
{
	int vowels_count = 0;

	while(*sentence)
	{
		switch(toupper(*sentence++))
		{
		case 'A': case 'E': case 'I': case 'O': case 'U':
			vowels_count++; break;
		}
	}

	return vowels_count;
}

void read_sentence(char *sentence, int sent_len)
{
	int count = 0;
	while((*sentence++ = getchar()) != '\n' && count++ < sent_len);
	*--sentence = '\0';

	if(count > sent_len)
		while(getchar() != '\n');
}
