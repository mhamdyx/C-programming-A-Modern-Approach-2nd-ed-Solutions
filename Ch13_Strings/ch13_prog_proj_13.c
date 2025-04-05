/*
 * ch13_prog_proj_13.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 13: Caesar Cipher

#include <stdio.h>

void encrypt(char *message, int shift);

int main(void)
{
	char input_ch, plain[80];
	int msg_len = 0, key;

	printf("Enter message to be encrypted: ");

	while((input_ch = getchar()) != '\n')
	{
		plain[msg_len++] = input_ch;
	}
	plain[msg_len] = '\0'; // Turn the plain array into a string

	printf("Enter shift amount (1-25): ");
	scanf("%d", &key);

	encrypt(plain, key);
	printf("Encrypted message: %s\n", plain);

	return 0;
}


void encrypt(char *message, int shift)
{
	while(*message)
	{
		if(*message >= 'A' && *message <= 'Z')
		{
			*message = ((*message - 'A') + shift) % 26 + 'A';
		}
		else if(*message > 'Z' && *message <= 'z')
		{
			*message = ((*message - 'a') + shift) % 26 + 'a';
		}
		message++;
	}
}
