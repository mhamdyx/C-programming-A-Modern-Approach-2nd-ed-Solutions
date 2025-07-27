/*
 * ch22_prog_proj_04b.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 4: Text File Statistics
// (b) Number of Words
#define CH22_PP4B_SOL1
//#define CH22_PP4B_SOL2

#ifdef CH22_PP4B_SOL1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int count;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./program filename.txt\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (count = 0; fscanf(fp, "%*s") != EOF; count++);

	fclose(fp);
	fprintf(stdout, "Number of words = %u\n", count);

	return 0;
}

#elif defined(CH22_PP4B_SOL2)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int count = 0;
	int ch;
	bool word_sequence = false;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./program filename.txt\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		if (isspace(ch))
			word_sequence = false;
		else if (!word_sequence)
		{
			word_sequence = true;
			count++;
		}
	}

	fclose(fp);
	fprintf(stdout, "Number of words = %u\n", count);

	return 0;
}

#endif
