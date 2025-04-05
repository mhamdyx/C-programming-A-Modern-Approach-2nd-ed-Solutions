/*
 * ch20_prog_proj_01.c
 *
 *  Created on: May 18, 2020
 *      Author: Mahmoud Hamdy
 */

// Programming Project 1: Float representation

#include <stdio.h>

union
{
	float value;
	struct
	{
		unsigned int fraction: 23, exponent: 8, sign: 1;
	} IEEE_STD;
} Float;

int main(void)
{
	Float.IEEE_STD.sign = 1;
	Float.IEEE_STD.exponent = 128;
	Float.IEEE_STD.fraction = 0;

	printf("Float value = %.1f\n", Float.value);

	return 0;
}
