/*
 * justify.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Justify

#include <string.h>
#include "line.h"
#include "word.h"
#define MAX_WORD_LEN 20

int main(void)
{
	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();

	for(;;)
	{
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);

		if(word_len == 0)
		{
			flush_line();
			return 0; // Terminate program
		}

		if(word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';

		if(word_len + 1 > space_remaining())
		{
			write_line();
			clear_line();
		}
		add_word(word);
	}


	return 0;
}
