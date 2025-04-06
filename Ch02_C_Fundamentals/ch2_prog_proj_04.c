/*
 * ch2_prog_proj_04.c
 *
 *  Created on: Apr 6, 2025
 *      Author: Mahmoud Hamdy
 */

//  Project 4: Amount with taxes

#include <stdio.h>

int main(void)
{
	float amount, taxes;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	taxes = amount * 0.05f;

	printf("With tax added: $%.2f\n", amount + taxes);

	return 0;
}
