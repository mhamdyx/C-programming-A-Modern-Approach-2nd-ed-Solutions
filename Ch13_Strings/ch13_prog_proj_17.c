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
	char input, message[LEN] = {0}, *msg_ptr = message;

	printf("Enter a message: ");

	// Reading the message
	input = getchar();

	while(input != '\n' && msg_ptr < message + LEN)
	{
		if((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z'))
		{
			*msg_ptr++ = (input <= 'Z') ? tolower(input) : input;
		}
		input = getchar();
	}
	msg_ptr--;

	// Palindrome Detection
	if(is_palindrome(message))
	{
		printf("Palindrome");
	}
	else
	{
		printf("Not a palindrome");
	}

	return 0;
}

bool is_palindrome(const char *message)
{
	const char *head = message, *tail = message;

	while(*tail)
		tail++;
	tail--;

	while(head <= tail)
	{
		if(*head++ != *tail--)
		{
			return false;
		}
	}

	return true;
}
