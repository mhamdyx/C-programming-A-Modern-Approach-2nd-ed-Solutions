/*
 * ch17_prog_proj_06.c
 *
 *  Created on: Apr 9, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: Sort Words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int read_line(char str[], int n);
int compare_words(const void *word1, const void *word2);

int main(void)
{
	char word[MAX_WORD_LEN + 1];
	int num_words = 0, max_words = 10, word_len;

	char **words_ptr = malloc(max_words * sizeof(char *));
	if(words_ptr == NULL)
	{
		printf("No enough memory is available\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter word: ");

	while((word_len = read_line(word, MAX_WORD_LEN)) != 0)
	{
		if(num_words == max_words)
		{
			char **temp;
			max_words *= 2;

			temp = realloc(words_ptr, max_words * sizeof(char *));
			if(temp == NULL)
			{
				printf("Memory is full!\n");
				exit(EXIT_FAILURE);
			}
			else
				words_ptr = temp;
		}

		words_ptr[num_words] = malloc(word_len + 1);
		strcpy(words_ptr[num_words], word);
		num_words++;

		printf("Enter word: ");
	}

	qsort(words_ptr, num_words, sizeof(char *), compare_words);

	printf("\nIn sorted order: ");
	for(int i = 0; i < num_words; i++)
		printf("%s ", words_ptr[i]);

	printf("\n");

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while((ch = getchar()) != '\n')
		if(i < n)
			str[i++] = ch;
	str[i] = '\0';

	return i;
}


int compare_words(const void *word1, const void *word2)
{
	return strcmp(*(const char **)word1, *(const char **)word2);
}
