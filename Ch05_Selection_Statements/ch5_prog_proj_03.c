/*
 * ch5_prog_proj_03.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 3: Broker's Commission (modified)

#include <stdio.h>

int main(void)
{
	float commission, value;
	float rival_commission, price_per_share;
	int shares;

	//printf("Enter value of trade: ");
	//scanf("%f", &value);

	printf("Enter the number of shares: ");
	scanf("%d", &shares);

	printf("Enter the price per share: ");
	scanf("%f", &price_per_share);

	value = shares * price_per_share;

	// Computing original broker's commission
	if (value < 2500.00f)
		commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission = 155.00f + .0011f * value;
	else
		commission = 255.00f + .0009f * value;

	if (commission < 39.00f)
		commission = 39.00f;

	// Computing rival broker's commission:
	if(shares < 2000)
	{
		rival_commission = 33.00f + .03f * shares;
	}
	else
	{
		rival_commission = 33.00f + .02f * shares;
	}

	printf("Original broker's commission: $%.2f\n", commission);
	printf("Rival broker's commission: $%.2f\n", rival_commission);

	return 0;
}
