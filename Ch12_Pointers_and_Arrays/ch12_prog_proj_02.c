/*
 * ch12_prog_proj_02.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Palindrome

// (a)
/*
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 100

int main(void)
{
	char input, message[LEN];
	int left_index = 0, right_index = 0;
	bool palindrome = true;

	// Reading the message
	printf("Enter a message: ");
	while ((input = getchar()) != '\n' && right_index < LEN)
		if (isalpha(input))
			message[right_index++] = tolower(input);

	// Go back to the message end
	right_index--;

	// Palindrome Detection
	while (left_index < right_index)
	{
		if (message[left_index++] != message[right_index--])
		{
			palindrome = false;
			break;
		}
	}

	if (palindrome)
		printf("Palindrome");
	else
		printf("Not a palindrome");

	return 0;
}
*/

// (b)
/*
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 100

int main(void)
{
	char input, message[LEN], *left_ch = message, *right_ch = message;
	bool palindrome = true;

	// Reading the message
	printf("Enter a message: ");
	while ((input = getchar()) != '\n' && right_ch < message + LEN)
		if (isalpha(input))
			*right_ch++ = tolower(input);

	// Go back to the message end
	right_ch--;

	// Palindrome Detection
	while (left_ch < right_ch)
	{
		if (*left_ch++ != *right_ch--)
		{
			palindrome = false;
			break;
		}
	}

	if (palindrome)
		printf("Palindrome");
	else
		printf("Not a palindrome");

	return 0;
}
*/
