/*
 * ch8_prog_proj_06.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: B1FF Filter

#include <stdio.h>
#include <ctype.h>

#define LEN 50 // Arbitrary for max array length
#define EXCL_COUNT 10 // Arbitrary for max number of exclamation marks

int main(void)
{
	char message[LEN];
	int i, msg_len = 0;

	printf("Enter message: ");
	for (i = 0; i < LEN; i++)
	{
		message[i] = getchar();

		if (message[i] == '\n')
			break;

		msg_len++;
	}

	printf("In B1FF-speak: ");
	for (i = 0; i < msg_len; i++)
	{
		switch(message[i])
		{
		case 'A': case 'a': putchar('4'); break;
		case 'B': case 'b': putchar('8'); break;
		case 'E': case 'e': putchar('3'); break;
		case 'I': case 'i': putchar('1'); break;
		case 'O': case 'o': putchar('0'); break;
		case 'S': case 's': putchar('5'); break;
		default: putchar(toupper(message[i])); break;
		}
	}

	for (i = 0; i < EXCL_COUNT; i++)
		putchar('!');

	putchar('\n');

	return 0;
}
