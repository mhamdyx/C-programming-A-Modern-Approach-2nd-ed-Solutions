/*
 * line.c
 *
 *  Created on: Apr 8, 2020
 *      Author: Mahmoud Hamdy
 */

#include <stdio.h>
#include <string.h>
#include "line.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LINE_LEN 60

struct node
{
	struct node *next;
	char word[];
};

struct node *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	struct node *temp;
	while(line != NULL)
	{
		temp = line;
		line = line->next;
		free(temp);
	}

	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	struct node *last_word, *new_word;

	new_word = malloc(sizeof(struct node) + strlen(word) + 1);
	if(new_word == NULL)
	{
		printf("Memory is not enough for the text\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new_word->word, word);
	new_word->next = NULL;


	if(num_words > 0)
	{
		line_len++;

		// Traverse to the last word in a line
		for(last_word = line; last_word->next != NULL; last_word = last_word->next);
		last_word->next = new_word;
	}
	else
	{
		line = new_word;
	}

	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, j;
	struct node *cur_word;

	extra_spaces = MAX_LINE_LEN - line_len;

	for(cur_word = line; cur_word != NULL; cur_word = cur_word->next)
	{
		printf("%s", cur_word->word);

		if(num_words > 1)
		{
			spaces_to_insert = extra_spaces / (num_words - 1);

			for(j = 1; j <= spaces_to_insert + 1; j++)
				putchar(' ');

			extra_spaces -= spaces_to_insert;
		}
		num_words--;
	}
	putchar('\n');
}


void flush_line(void)
{
	struct node *cur_word;

	if(line_len > 0)
		for(cur_word = line; cur_word != NULL; cur_word = cur_word->next)
			printf("%s ", cur_word->word);

	printf("\n");

}
