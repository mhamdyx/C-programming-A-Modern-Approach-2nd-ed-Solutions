/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

// (Section 5.2, Page 81)

/*
 * ch6_prog_proj_04.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 4: Broker's commission

#include <stdio.h>

int main(void)
{
	float commission, value;

	for(;;)
	{
		printf("Enter value of trade: ");
		scanf("%f", &value);

		if(value <= 0.0f)
			break;

		if(value < 2500.00f)
			commission = 30.00f + .017f * value;
		else if(value < 6250.00f)
			commission = 56.00f + .0066f * value;
		else if(value < 20000.00f)
			commission = 76.00f + .0034f * value;
		else if(value < 50000.00f)
			commission = 100.00f + .0022f * value;
		else if(value < 500000.00f)
			commission = 155.00f + .0011f * value;
		else
			commission = 255.00f + .0009f * value;

		if(commission < 39.00f)
			commission = 39.00f;

		printf("Commission: $%.2f\n\n", commission);
	}

	return 0;
}
