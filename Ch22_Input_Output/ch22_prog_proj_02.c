/*
 * ch22_prog_proj_02.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 2: Capitalize All Letters of a File

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: program filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "%s can't be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
		putc(toupper(ch), stdout);

	fclose(fp);
	return 0;
}


/*
 * Additional Hints:
 *
 * 1) fprintf(stderr, "Usage: program filename\n");
 * fprintf(stderr, "%s can't be opened\n", argv[1]);
 *
 * These lines can be printf too without any context of the chosen
 * output stream, but I wrote it this way to emphasize good practice
 * 
 *
 * 2) putc(toupper(ch), stdout);
 *
 * You can also use putchar, but I am following the same approach
 * as I did when writing fprintf instead of printf
 *
 *
 * 3) You can just write putc(toupper(ch), stdout);
 * as the only line in the body of while without testing
 * any conditions because if ch is not an alpha character,
 * toupper returns ch as is (we will learn this in Ch23),
 * but you can figure it on your own for two reasons:
 *
 * - The author had already explained it in Section 7.3 (P.139)
 * - If you use an IDE, it often shows you the function doc
 * when you hover over it
 *
 *
 */
