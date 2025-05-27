/*
 * ch17_prog_proj_05.c
 *
 *  Created on: Apr 9, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Sort Words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LEN 20

int read_line(char str[], int n);
void sort_words(char **words, int n);

int main(void)
{
	char word[MAX_WORD_LEN + 1];
	int i, num_words = 0, max_words = 10, word_len;
	char **words_ptr = malloc(max_words * sizeof(char *));
	if (words_ptr == NULL)
	{
		printf("No enough memory is available\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter word: ");
	while ((word_len = read_line(word, MAX_WORD_LEN)) != 0)
	{
		if (num_words == max_words)
		{
			char **temp = realloc(words_ptr, max_words * 2 * sizeof(char *));
			if (temp == NULL)
			{
				printf("Can't extend words array! Memory is full!\n");
				exit(EXIT_FAILURE);
			}

			max_words *= 2;
			words_ptr = temp;
		}

		words_ptr[num_words] = malloc(word_len + 1);
		if (words_ptr[num_words] == NULL)
		{
			printf("Can't allocate space for a new word! Memory is full!\n");
			exit(EXIT_FAILURE);
		}

		strcpy(words_ptr[num_words], word);
		num_words++;
		printf("Enter word: ");
	}

	sort_words(words_ptr, num_words);

	printf("\nIn sorted order: ");
	for (i = 0; i < num_words; i++)
		printf("%s ", words_ptr[i]);

	printf("\n");

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';

	return i;
}

void sort_words(char **words, int n)
{
	int i, j;
	char *temp_word;

	if (n == 1)
		return;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (strcmp(words[j], words[j + 1]) > 0)
			{
				temp_word = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp_word;
			}
}
