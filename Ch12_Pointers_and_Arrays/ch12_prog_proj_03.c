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
	char input, message[LEN], *msg_ptr = message;

	// Reading the message
	printf("Enter a message: ");
	while ((input = getchar()) != '\n' && msg_ptr < message + LEN)
		*msg_ptr++ = input;

	// Reversing the message
	printf("Reversal is: ");
	while (msg_ptr > message)
		putchar(*--msg_ptr);

	return 0;
}
