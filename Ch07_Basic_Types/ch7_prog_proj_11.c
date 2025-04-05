/*
 * ch7_prog_proj_11.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 11: First name and Last name

#include <stdio.h>

int main(void)
{
	char last_ch, first_ch;

	printf("Enter a first and last name: ");

	while((first_ch = getchar()) == ' '); // Skipping initial spaces

	while(getchar() != ' '); // Skipping first name letters

	while((last_ch = getchar()) == ' '); // Skipping intermediate spaces

	do
	{
		printf("%c", last_ch);
	} while((last_ch = getchar()) != '\n');

	printf(", %c.\n", first_ch);

	return 0;
}
