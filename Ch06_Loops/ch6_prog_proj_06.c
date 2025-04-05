/*
 * ch6_prog_proj_06.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: Even squares between 1 and n

#include <stdio.h>

int main(void)
{
	int n, i;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Even squares are:\n");

	for(i = 2; i * i <= n; i += 2)
	{
		printf("%d\n", i * i);
	}

	return 0;
}
