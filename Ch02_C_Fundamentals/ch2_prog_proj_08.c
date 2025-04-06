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
	float loan_balance, monthly_payment, interest_rate;
	float monthly_interest_rate, remaining_balance;

	printf("Enter amount of loan: ");
	scanf("%f", &loan_balance);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);
	monthly_interest_rate = interest_rate / (100 * 12);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	remaining_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;

	printf("\nBalance remaining after first payment: $%.2f\n", remaining_balance);

	loan_balance = remaining_balance;
	remaining_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;

	printf("Balance remaining after second payment: $%.2f\n", remaining_balance);

	loan_balance = remaining_balance;
	remaining_balance = loan_balance - monthly_payment + loan_balance * monthly_interest_rate;

	printf("Balance remaining after third payment: $%.2f\n", remaining_balance);

	return 0;
}
