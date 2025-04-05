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
	printf("Size of int is %u\n", sizeof(int));
	printf("Size of short is %u\n", sizeof(short));
	printf("Size of long is %u\n", sizeof(long));
	printf("Size of float is %u\n", sizeof(float));
	printf("Size of double is %u\n", sizeof(double));
	printf("Size of long double is %u\n", sizeof(long double));

	return 0;
}
