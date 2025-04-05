/*
 * ch3_prog_proj_02.c
 *
 *  Created on: Mar 19, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 2: Formatting product information

#include <stdio.h>

int main(void)
{

	int item_no, month, day, year;
	float unit_price;

	printf("Enter item number: ");
	scanf("%d", &item_no);

	printf("Enter unit price: ");
	scanf("%f", &unit_price);

	printf("Enter purchase date (mm/dd/yyy): ");
	scanf("%d /%d /%d", &month, &day, &year);


	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	printf("%-d\t\t$%7.2f\t%d/%d/%d\n", item_no, unit_price,
			month, day, year);

	return 0;
}
