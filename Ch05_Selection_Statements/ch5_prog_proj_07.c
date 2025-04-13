/*
 * ch5_prog_proj_07.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 7: Largest and smallest integer

#include <stdio.h>

int main(void)
{
	int num1, num2, num3, num4, max12, min12, max34, min34;
	int largest_num, smallest_num;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

	if (num1 > num2)
	{
		max12 = num1;
		min12 = num2;
	}
	else
	{
		max12 = num2;
		min12 = num1;
	}

	if (num3 > num4)
	{
		max34 = num3;
		min34 = num4;
	}
	else
	{
		max34 = num4;
		min34 = num3;
	}

	if (max12 > max34)
		largest_num = max12;
	else
		largest_num = max34;

	if (min12 < min34)
		smallest_num = min12;
	else
		smallest_num = min34;


	printf("Largest: %d\n", largest_num);
	printf("Smallest: %d\n", smallest_num);

	return 0;
}
