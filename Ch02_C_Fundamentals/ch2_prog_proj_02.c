/*
 * ch2_prog_proj_02.c
 *
 *  Created on: Apr 6, 2025
 *      Author: Mahmoud Hamdy
 */


// Project 2: Volume of a sphere

#include <stdio.h>
#define PI (3.14159f)

int main(void)
{
	float radius = 10.0f, volume;

	volume = (4.0f/3.0f) * PI * radius * radius * radius;

	printf("Volume of sphere = %.2f cubic meters\n", volume);

	return 0;
}
