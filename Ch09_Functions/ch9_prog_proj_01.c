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
	int n;

	printf("Enter the number of integers to be entered: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter the list of numbers: ");

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	selection_sort(a, n);

	printf("Array after sorting: ");

	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}


void selection_sort(int a[], int n)
{
	if(n == 1)
		return;

	int max_element_value = a[0], max_element_index = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[i] > max_element_value)
		{
			max_element_value = a[i];
			max_element_index = i;
		}
	}

	// Moving to last position
	a[max_element_index] = a[n - 1];
	a[n - 1] = max_element_value;

	selection_sort(a, n - 1);
}
