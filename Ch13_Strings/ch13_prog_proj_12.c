/*
 * ch13_prog_proj_12.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 12: Reverse words in a sentence

#include <stdio.h>
#include <stdbool.h>

#define WORDS_NUM 30
#define WORDS_LEN 20

bool end_with_special_ch(char *str, char *special_ch);

int main(void)
{
	char sentence[WORDS_NUM][WORDS_LEN + 1], special_ch;
	int i;

	printf("Enter a sentence: ");

	for(i = 0; i < WORDS_NUM; i++)
	{
		scanf("%s", sentence[i]);
        
		if(end_with_special_ch(sentence[i], &special_ch))
			break;
	}

	if(i == WORDS_NUM)
		i--;

	// Printing the reversed sentence
	while(i > 0)
	{
		printf("%s ", sentence[i--]);
	}
	printf("%s%c\n", sentence[i], special_ch);

	return 0;
}

bool end_with_special_ch(char *str, char *special_ch)
{
	while(*str++);
	str -= 2; // Go back to the last character

	if(*str == '.' || *str == '!' || *str == '?')
	{
		*special_ch = *str;
		*str = '\0';
		return true;
	}

	return false;
}
