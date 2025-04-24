/*
 * ch8_prog_proj_04.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Reversing a Series of Numbers (modified)

#include <stdio.h>

#define N 10
#define SIZE (int) (sizeof(a) / sizeof(a[0]))

int main(void)
{
	int a[N], i;

	printf("Enter %d numbers: ", N);
	for (i = 0; i < SIZE; i++)
		scanf("%d", &a[i]);

	printf("In reverse order: ");
	for (i = SIZE - 1; i >= 0; i--)
		printf(" %d", a[i]);

	printf("\n");

	return 0;
}
