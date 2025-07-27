/*
 * ch22_prog_proj_01.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 1: canopen (modified)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, num_opened = 0;

	if (argc < 2)
	{
		printf("usage: canopen filename [filenames...]\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
			printf("%s can't be opened\n", argv[i]);
		else
		{
			printf("%s can be opened\n", argv[i]);
			num_opened++;
			fclose(fp);
		}
	}

	// Extra 1 for the program name (canopen)
	if (argc != num_opened + 1)
		exit(EXIT_FAILURE);

	return 0;
}


/*
 * Additional Hints:
 *
 *
 * 1) printf("usage: canopen filename [filenames...]\n");
 *
 * In a more practical sense, this line should be:
 * printf("usage: %s filename [filenames...]\n", argv[0]);
 *
 * This way, the terminal will tell you how to properly invoke your
 * program for your specific OS and terminal.
 * Examples: canopen, ./canopen, ./canopen.exe, ...etc
 *
 * 2) filename [filenames...] means there should be at least one
 * filename with additional filenames as optional
 * You will see these square brackets a lot in the language of
 * documentations or linux manual to indicate optional arguments
 *
 *
 * 3) You also use a bool variable like failure_flag that would be set
 * if any file can't be opened, then check that flag at the end
 * instead of num_opened and make proper adjustments to your program
 * accordingly.
 *
 */
