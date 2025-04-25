/*
 * ch8_prog_proj_11.c
 *
 *  Created on: Apr 25, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 11: Alphabetic phone number (modified)

#include <stdio.h>
#define MAX_LEN 15

int main(void)
{
	char ch, phone_numeric_form[MAX_LEN];
	int i, len;

	printf("Enter phone number: ");

	for (i = 0; i < MAX_LEN; i++)
	{
		ch = getchar();

		if (ch == '\n')
			break;

		switch (ch)
		{
		case 'A': case 'B': case 'C': phone_numeric_form[i] = '2'; break;
		case 'D': case 'E': case 'F': phone_numeric_form[i] = '3'; break;
		case 'G': case 'H': case 'I': phone_numeric_form[i] = '4'; break;
		case 'J': case 'K': case 'L': phone_numeric_form[i] = '5'; break;
		case 'M': case 'N': case 'O': phone_numeric_form[i] = '6'; break;
		case 'P': case 'R': case 'S': phone_numeric_form[i] = '7'; break;
		case 'T': case 'U': case 'V': phone_numeric_form[i] = '8'; break;
		case 'W': case 'X': case 'Y': phone_numeric_form[i] = '9'; break;
		default: phone_numeric_form[i] = ch; break;
		}
	}

	len = i;

	printf("In numeric form: ");
	for (i = 0; i < len; i++)
		putchar(phone_numeric_form[i]);

	putchar('\n');

	return 0;
}
