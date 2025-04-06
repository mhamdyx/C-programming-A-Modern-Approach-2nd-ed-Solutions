/*
 * ch2_prog_proj_03.c
 *
 *  Created on: Apr 6, 2025
 *      Author: Mahmoud Hamdy
 */

// Project 3: Volume of a sphere (modified)

#include <stdio.h>
#define PI (3.14159f)

int main(void)
{
	float radius, volume;

	printf("Enter the radius: ");
	scanf("%f", &radius);

	volume = (4.0f/3.0f) * PI * radius * radius * radius;

	printf("Volume of sphere = %.2f cubic meters\n", volume);

	return 0;
}
