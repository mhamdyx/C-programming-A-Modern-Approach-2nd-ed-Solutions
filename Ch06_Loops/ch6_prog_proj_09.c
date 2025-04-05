/*
 * ch6_prog_proj_09.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 9: Remaining balance on a loan

#include <stdio.h>

int main(void)
{
	float loan_balance, monthly_payment;
	float interest_rate, monthly_interest_rate;
	int i, number_of_payments;

	handle_eclipse_terminal_emulator_bug();

	printf("Enter amount of loan: ");
	scanf("%f", &loan_balance);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);
	monthly_interest_rate = interest_rate / (100 * 12);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	printf("Enter the number of payments: ");
	scanf("%d", &number_of_payments);

	printf("\n");

	for(i = 1; i <= number_of_payments; i++)
	{
		loan_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;
		printf("Balance remaining after payment %d: $%.2f\n", i, loan_balance);
	}

	return 0;
}
