/*
 * ch6_prog_proj_05.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 5: Reversing number's digits

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("The reversal is: ");

	do
	{
		printf("%d", n % 10);
		n /= 10;
	} while(n > 0);

	printf("\n");

	return 0;
}
