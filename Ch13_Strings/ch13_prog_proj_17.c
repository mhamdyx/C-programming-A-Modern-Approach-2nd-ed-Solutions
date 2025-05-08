/*
 * ch13_prog_proj_17.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 17: Palindrome

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 100

bool is_palindrome(const char *message);

int main(void)
{
	char input, message[LEN], *msg_ptr = message;

	// Reading the message
	printf("Enter a message: ");
	while ((input = getchar()) != '\n' && msg_ptr < message + LEN)
		if (isalpha(input))
			*msg_ptr++ = tolower(input);

	*msg_ptr = '\0';

	// Palindrome Detection
	if (is_palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}

bool is_palindrome(const char *message)
{
	const char *head = message, *tail = message;

	while (*tail++);
	tail -= 2; // Go to last character

	while (head <= tail)
		if (*head++ != *tail--)
			return false;

	return true;
}
