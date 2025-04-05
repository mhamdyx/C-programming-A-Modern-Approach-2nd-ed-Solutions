/*
 * ch12_prog_proj_04.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Palindrome (Same as 2.b)

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 100

int main(void)
{
	char input, message[LEN] = {0}, *msg_ptr = message, *left_ch, *right_ch;
	bool palindrome = true;

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
	left_ch = message;
	right_ch = msg_ptr;

	while(left_ch <= right_ch)
	{
		if(*left_ch != *right_ch)
		{
			palindrome = false;
			break;
		}

		left_ch++;
		right_ch--;
	}

	if(palindrome)
	{
		printf("Palindrome");
	}
	else
	{
		printf("Not a palindrome");
	}

	return 0;
}
