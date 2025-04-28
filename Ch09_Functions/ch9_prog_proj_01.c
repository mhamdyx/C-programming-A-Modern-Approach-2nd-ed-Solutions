/*
 * ch9_prog_proj_01.c
 *
 *  Created on: Oct 23, 2019
 *      Author: Mahmoud Hamdy
 */


// Programming Project 1: Selection sort
#include <stdio.h>

void selection_sort(int a[], int n);

int main(void)
{
	int i, n;

	printf("Enter the number of integers to be entered: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter the list of numbers: ");

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	selection_sort(a, n);

	printf("Array after sorting:");

	for (i = 0; i < n; i++)
		printf(" %d", a[i]);

	putchar('\n');

	return 0;
}


void selection_sort(int a[], int n)
{
	int i, largest_val, largest_i;

	if (n == 1)
		return;

	largest_val = a[0], largest_i = 0;
	for (i = 1; i < n; i++)
	{
		if (a[i] > largest_val)
		{
			largest_val = a[i];
			largest_i = i;
		}
	}

	// Moving to last position
	a[largest_i] = a[n - 1];
	a[n - 1] = largest_val;

	selection_sort(a, n - 1);
}
