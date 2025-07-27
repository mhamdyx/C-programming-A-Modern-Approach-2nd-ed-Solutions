/*
 * ch22_prog_proj_03.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 3: Files Concatenation

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, ch;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: fcat filename1 [filenames...]\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "%s can't be opened\n", argv[i]);
			continue;
		}

		while ((ch = getc(fp)) != EOF)
			putc(ch, stdout);

        fclose(fp);
	}

	return 0;
}


/*
 * Additional Hints:
 *
 * 1) The condition "if (argc < 2)" is just an assumption.
 * The question doesn't really enforce how fcat should behave
 *
 * For example:
 * I require it to print the content of at least one file,
 * hence the condition (argc < 2). Others may require two
 * files at least (argc < 3).
 *
 * There is a unix/linux tool named cat that does the same thing
 * and requires no files at all!
 *
 *
 * 2) The original unix/linux cat tool uses binary streams,
 * hence it uses the mode "rb". If you are working on a Unix/Linux
 * environment, you will see no difference in outputs.
 * But if you are working on Windows, lines end with \n\r, so this
 * will cause additional line breaks in the output.
 *
 * Text mode is the same for both windows and linux, this is why
 * I chose this portable solution. Learn the lesson and choose yours.
 *
 *
 */
