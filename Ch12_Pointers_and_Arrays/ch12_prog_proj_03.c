/*
 * ch12_prog_proj_03.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Message Reversal (Same as 1.b)

#include <stdio.h>
#define LEN 100

int main(void)
{
	char input, message[LEN] = {0}, *msg_ptr = message;

	printf("Enter a message: ");

	// Reading the message
	input = getchar();

	while(input != '\n' && msg_ptr < message + LEN)
	{
		*msg_ptr++ = input;
		input = getchar();
	}
	msg_ptr--;

	printf("Reversal is: ");
	while(msg_ptr >= message)
	{
		printf("%c", *msg_ptr--);
	}

	return 0;
}
