/*
 * ch8_prog_proj_13.c
 *
 *  Created on: Apr 25, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 13: First name and Last name (modified)

#include <stdio.h>
#define NAME_LEN 20

int main(void)
{
	char input_ch, first_ch, last_name[NAME_LEN];
	int i, len = 0;

	printf("Enter a first and last name: ");

	while((input_ch = getchar()) == ' '); // Skipping initial spaces

	first_ch = input_ch;

	while(getchar() != ' '); // Skipping first name letters

	while((input_ch = getchar()) == ' '); // Skipping intermediate spaces

	do
	{
		last_name[len++] = input_ch;
	} while((input_ch = getchar()) != '\n');

	printf("You entered the name: ");

	for (i = 0; i < len; i++)
		putchar(last_name[i]);

	printf(", %c.\n", first_ch);

	return 0;
}
