/*
 * ch12_prog_proj_01.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Message Reversal

// (a)
/*
#include <stdio.h>
#define LEN 100

int main(void)
{
	char input, message[LEN];
	int i, msg_len = 0;

	// Reading the message
	printf("Enter a message: ");
	while ((input = getchar()) != '\n' && msg_len < LEN)
		message[msg_len++] = input;

	// Reversing the message
	printf("Reversal is: ");
	for (i = msg_len - 1; i >= 0; i--)
		putchar(message[i]);

	return 0;
}
*/

// (b)
/*
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
*/
