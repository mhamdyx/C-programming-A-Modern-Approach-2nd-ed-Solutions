/*
 * ch5_prog_proj_04.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 4: Wind Force

#include <stdio.h>

int main(void)
{
	int wind_speed;

	printf("Enter the wind speed (in knots): ");
	scanf("%d", &wind_speed);

	printf("Wind force estimation: ");

	if (wind_speed < 1)
	{
		printf("Calm\n");
	}
	else if (wind_speed <= 3)
	{
		printf("Light air\n");
	}
	else if (wind_speed <= 27)
	{
		printf("Breeze\n");
	}
	else if (wind_speed <= 47)
	{
		printf("Gale\n");
	}
	else if (wind_speed <= 63)
	{
		printf("Storm\n");
	}
	else
	{
		printf("Hurricane\n");
	}

	return 0;
}
