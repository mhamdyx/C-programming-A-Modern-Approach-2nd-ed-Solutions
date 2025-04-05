/*
 * qsort.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 3: Quicksort algorithm

#include <stdio.h>
#include "quicksort.h"
#define N 10

int main(void)
{
	int a[N], i;

	printf("Enter %d numbers to be stored: ", N);

	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);

	quicksort(a, 0, N - 1);

	printf("In sorted order: ");
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);

	printf("\n");

	return 0;
}
