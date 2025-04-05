/*
 * ch7_prog_proj_13.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 13: Average word length for a sentence

#include <stdio.h>

int main(void)
{
	int total_len = 0, word_len = 0, word_count = 0;
	char input_ch;
	float avg;

	printf("Enter a sentence: ");

	while((input_ch = getchar()) != '\n')
	{
		if(input_ch == ' ')
		{
			total_len += word_len;
			word_count++;
			word_len = 0;
		}
		else
		{
			word_len++;
		}
	}

	word_count++;
	total_len += word_len;

	avg = ((float) total_len) / word_count;
	printf("Average word length: %.1f\n", avg);

	return 0;
}
