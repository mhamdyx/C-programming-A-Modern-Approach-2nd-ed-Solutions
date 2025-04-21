/*
 * ch7_prog_proj_04.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Alphabetic phone number

#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter phone number: ");
	ch = getchar();

	while (ch != '\n')
	{
		switch(ch)
		{
			case 'A': case 'B': case 'C': putchar('2'); break;
			case 'D': case 'E': case 'F': putchar('3'); break;
			case 'G': case 'H': case 'I': putchar('4'); break;
			case 'J': case 'K': case 'L': putchar('5'); break;
			case 'M': case 'N': case 'O': putchar('6'); break;
			case 'P': case 'R': case 'S': putchar('7'); break;
			case 'T': case 'U': case 'V': putchar('8'); break;
			case 'W': case 'X': case 'Y': putchar('9'); break;
			default: putchar(ch);
		}

		ch = getchar();
	}

	return 0;
}
