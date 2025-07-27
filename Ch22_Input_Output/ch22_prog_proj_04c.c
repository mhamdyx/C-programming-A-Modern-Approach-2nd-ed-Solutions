/*
 * ch22_prog_proj_04c.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 4: Text File Statistics
// (c) Number of Lines

#define CH22_Q4C_SOL1
//#define CH22_Q4C_SOL2

#ifdef CH22_Q4C_SOL1

#include <stdio.h>
#include <stdlib.h>
#define LEN 400 // Arbitrary

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int count;
	char line[LEN];

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

	for (count = 0; fgets(line, LEN, fp) != NULL; count++);

	fclose(fp);
	fprintf(stdout, "Number of lines = %u\n", count);

	return 0;
}

#elif defined(CH22_Q4C_SOL2)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int count;
	int ch, prev_ch = EOF;

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

	for (count = 0; (ch = getc(fp)) != EOF; prev_ch = ch)
		if (ch == '\n')
			count++;

	if (prev_ch != '\n') // Check for last unterminated line before EOF
		count++;

	fclose(fp);
	fprintf(stdout, "Number of lines = %u\n", count);

	return 0;
}

#endif
