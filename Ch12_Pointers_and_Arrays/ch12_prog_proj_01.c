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
	char input, message[LEN] = {0};
	int msg_len = 0;

	printf("Enter a message: ");

	// Reading the message
	input = getchar();

	while(input != '\n' && msg_len < LEN)
	{
		message[msg_len] = input;
		msg_len++;
		input = getchar();
	}

	printf("Reversal is: ");
	for(int i = msg_len - 1; i >= 0; i--)
	{
		printf("%c", message[i]);
	}

	return 0;
}
*/

// (b)
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
