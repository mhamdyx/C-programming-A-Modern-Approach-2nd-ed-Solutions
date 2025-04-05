/*
 * ch2_prog_proj_08.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Mahmoud Hamdy
 */

// Project 8: Remaining balance on a loan

#include <stdio.h>

int main(void)
{
	float loan_balance, monthly_payment;
	float interest_rate, monthly_interest_rate;

	printf("Enter amount of loan: ");
	scanf("%f", &loan_balance);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);
	monthly_interest_rate = interest_rate / (100 * 12);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	loan_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;

	printf("\nBalance remaining after first payment: $%.2f\n", loan_balance);

	loan_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;

	printf("Balance remaining after second payment: $%.2f\n", loan_balance);

	loan_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;

	printf("Balance remaining after third payment: $%.2f\n", loan_balance);

	return 0;
}
