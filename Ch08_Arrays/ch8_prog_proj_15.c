/*
 * ch8_prog_proj_15.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 15: Caesar Cipher

#include <stdio.h>
int main(void)
{
	char input_ch, plain[80], cipher;
	int msg_len = 0, key;

	printf("Enter message to be encrypted: ");

	while((input_ch = getchar()) != '\n')
	{
		plain[msg_len++] = input_ch;
	}

	printf("Enter shift amount (1-25): ");
	scanf("%d", &key);

	printf("Encrypted message: ");

	for(int i = 0; i < msg_len; i++)
	{
		if(plain[i] >= 'A' && plain[i] <= 'Z')
		{
			cipher = ((plain[i] - 'A') + key) % 26 + 'A';
		}
		else if(plain[i] > 'Z' && plain[i] <= 'z')
		{
			cipher = ((plain[i] - 'a') + key) % 26 + 'a';
		}
		else
		{
			cipher = plain[i];
		}

		printf("%c", cipher);
	}
	printf("\n");

	return 0;
}
