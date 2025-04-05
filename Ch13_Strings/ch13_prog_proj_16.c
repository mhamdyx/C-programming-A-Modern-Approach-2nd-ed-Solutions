/*
 * ch13_prog_proj_16.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 16: Message Reversal

#include <stdio.h>
#define LEN 100

void reverse(char *message);

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


	reverse(message);
	printf("Reversal is: %s\n", message);

	return 0;
}

void reverse(char *message)
{
	char *tail = message, *head = message, temp;
	while(*tail)
		tail++;

	tail--;

	while(head < tail)
	{
		temp = *head;
		*head++ = *tail;
		*tail-- = temp;
	}
}
