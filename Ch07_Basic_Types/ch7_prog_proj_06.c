/*
 * ch7_prog_proj_06.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: sizeof different types

#include <stdio.h>

int main(void)
{
	printf("Size of int is %lu\n", (unsigned long) sizeof(int));
	printf("Size of short is %lu\n", (unsigned long) sizeof(short));
	printf("Size of long is %lu\n", (unsigned long) sizeof(long));
	printf("Size of float is %lu\n", (unsigned long) sizeof(float));
	printf("Size of double is %lu\n", (unsigned long) sizeof(double));
	printf("Size of long double is %lu\n", (unsigned long) sizeof(long double));

	return 0;
}
