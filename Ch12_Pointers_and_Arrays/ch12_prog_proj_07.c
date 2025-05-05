/*
 * ch12_prog_proj_07.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: Largest and smallest elements in an array

#include <stdio.h>
#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
	int b[N], i, big, small;

	printf("Enter %d numbers: ", N);
	for (i = 0; i < N; i++)
		scanf("%d", &b[i]);

	max_min(b, N, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
	int *p;
	*max = *min = *a;

	for (p = a + 1; p < a + n; p++)
	{
		if (*p > *max)
			*max = *p;
		else if (*p < *min)
			*min = *p;
	}
}
