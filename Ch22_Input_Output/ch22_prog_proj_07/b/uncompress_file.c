/*
 * ch22_prog_proj_07/b/uncompress_file.c
 *
 *  Created on: Aug 6, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 7b: File Uncompression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#define DEBUG_PROJ_7B

#ifdef DEBUG_PROJ_7B
void dump_file(const char *filename, FILE *dumpstream);
#endif // DEBUG_PROJ_7B

const char *get_extension(const char *filename);

int main(int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	char *decompressed_filename;
	const char *in_ext;
	int filename_len, byte_count, byte_val;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: uncompress_file compressed-file\n");
		exit(EXIT_FAILURE);
	}

	if ((in_ext = get_extension(argv[1])) == NULL || strcmp(in_ext, ".rle"))
	{
		fprintf(stderr, "Error: Wrong extension for compressed file\n");
		exit(EXIT_FAILURE);
	}

	if ((in_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	filename_len = sizeof(char) * (strlen(argv[1]) - strlen(".rle"));
	decompressed_filename = malloc(filename_len + 1);

	if (decompressed_filename == NULL)
	{
		fprintf(stderr, "cannot create an output filename\n");
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	strncpy(decompressed_filename, argv[1], filename_len);
	decompressed_filename[filename_len] = '\0';

	if ((out_fp = fopen(decompressed_filename, "wb")) == NULL)
	{
		fprintf(stderr, "%s cannot be opened\n", decompressed_filename);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while ((byte_count = getc(in_fp)) != EOF)
	{
		byte_val = getc(in_fp);

		while (byte_count--)
			putc(byte_val, out_fp);
	}

	fclose(in_fp);
	fclose(out_fp);

#ifdef DEBUG_PROJ_7B
	dump_file(argv[1], stdout);
	fprintf(stdout, "\n\n");
	dump_file(decompressed_filename, stdout);
#endif // DEBUG_PROJ_7B

	return 0;
}

const char *get_extension(const char *filename)
{
	const char *ptr = NULL;

	for (; *filename; filename++)
		if (*filename == '.')
			ptr = filename;

	return ptr;
}

#ifdef DEBUG_PROJ_7B
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
#endif // DEBUG_PROJ_7B
