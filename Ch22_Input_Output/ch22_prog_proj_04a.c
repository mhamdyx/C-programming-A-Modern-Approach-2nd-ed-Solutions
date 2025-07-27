/*
 * ch22_prog_proj_04a.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 4: Text File Statistics
// (a) Number of Characters

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

	for (count = 0; getc(fp) != EOF; count++);

	fclose(fp);
	fprintf(stdout, "Number of characters = %u\n", count);

	return 0;
}
