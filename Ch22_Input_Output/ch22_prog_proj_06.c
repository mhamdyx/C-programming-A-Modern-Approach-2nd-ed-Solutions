/*
 * ch22_prog_proj_06.c
 *
 *  Created on: Aug 5, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 6: File Content Display

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define OFFSET_VAL 10

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned char bytes[OFFSET_VAL];
	int len, i, byte_offset = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./program filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Offset%14sBytes%14sCharacters\n", "", "");
	printf("------  -----------------------------  ----------\n");

	while (!feof(fp))
	{
		len = fread(bytes, 1, OFFSET_VAL, fp);
		printf("%6d  ", byte_offset);

		for (i = 0; i < len; i++)
			printf("%02X ", bytes[i]);

		for ( ; i < OFFSET_VAL; i++)
			printf("   ");

		putchar(' ');

		for (i = 0; i < len; i++)
			printf("%c", isprint(bytes[i]) ? bytes[i] : '.');

		putchar('\n');
		byte_offset += OFFSET_VAL;
	}

	fclose(fp);
	return 0;
}
