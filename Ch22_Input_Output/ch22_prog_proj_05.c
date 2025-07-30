/*
 * ch22_prog_proj_05.c
 *
 *  Created on: Jul 30, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 5: XOR Encryption (modified)

#include <stdio.h>
#include <stdlib.h>
#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	int orig_char;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: xor orig_file new_file\n");
		exit(EXIT_FAILURE);
	}

	if ((in_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((out_fp = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[2]);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while ((orig_char = getc(in_fp)) != EOF)
		putc(orig_char ^ KEY, out_fp);

	fclose(out_fp);
	return 0;
}

/*
 * Additional Hints:
 * How to verify your program?
 * Create msg file
 * run the program: ./xor msg newmsg
 * run again: ./xor newmsg origmsg
 * Check that msh and origmsg are the same. How?
 * Run this command in your terminal: diff msg origmsg
 * Windows guys: Use a terminal like cygwin to run the command
 *
 */
