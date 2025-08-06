/*
 * ch22_prog_proj_07/a/compress_file.c
 *
 *  Created on: Aug 6, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 7a: File Compression (run-length encoding)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#define DEBUG_PROJ_7A

#ifdef DEBUG_PROJ_7A
void dump_file(const char *filename, FILE *dumpstream);
#endif // DEBUG_PROJ_7A

int main(int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	char *compressed_filename;
	int filename_len, prev_byte, curr_byte, byte_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: compress_file original-file\n");
		exit(EXIT_FAILURE);
	}

	if ((in_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	filename_len = sizeof(char) * (strlen(argv[1]) + strlen(".rle") + 1);
	compressed_filename = malloc(filename_len);

	if (compressed_filename == NULL)
	{
		fprintf(stderr, "cannot create an output filename\n");
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	strcat(strcpy(compressed_filename, argv[1]), ".rle");

	if ((out_fp = fopen(compressed_filename, "wb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", compressed_filename);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	if (feof(in_fp))
		return 0;

	prev_byte = getc(in_fp);
	byte_count = 1;

	do
	{
		curr_byte = getc(in_fp);

		if (curr_byte == prev_byte)
		{
			byte_count++;
			continue;
		}

		putc(byte_count, out_fp);
		putc(prev_byte, out_fp);

		prev_byte = curr_byte;
		byte_count = 1;
	} while (prev_byte != EOF);

	fclose(in_fp);
	fclose(out_fp);

#ifdef DEBUG_PROJ_7A
	dump_file(argv[1], stdout);
	fprintf(stdout, "\n\n");
	dump_file(compressed_filename, stdout);
#endif // DEBUG_PROJ_7A

	return 0;
}

#ifdef DEBUG_PROJ_7A
void dump_file(const char *filename, FILE *dumpstream)
{
	FILE *fp;
	unsigned char bytes[10];
	int len, i, byte_offset = 0;

	if ((fp = fopen(filename, "rb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", filename);
		exit(EXIT_FAILURE);
	}

	fprintf(dumpstream, "Offset%14sBytes%14sCharacters\n", "", "");
	fprintf(dumpstream, "------  -----------------------------  ----------\n");

	while (!feof(fp))
	{
		len = fread(bytes, 1, 10, fp);
		fprintf(dumpstream, "%6d  ", byte_offset);

		for (i = 0; i < len; i++)
			fprintf(dumpstream, "%02X ", bytes[i]);

		for ( ; i < 10; i++)
			fprintf(dumpstream, "   ");

		putc(' ', dumpstream);

		for (i = 0; i < len; i++)
			fprintf(dumpstream, "%c", isprint(bytes[i]) ? bytes[i] : '.');

		putc('\n', dumpstream);
		byte_offset += 10;
	}

	fclose(fp);
}
#endif // DEBUG_PROJ_7A
