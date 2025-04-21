/*
 * ch7_prog_proj_07.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: Adding Fractions (modified)

#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;
	char operator;

	printf("Enter two fractions separated by an operator(+, -, *, or /): ");
	scanf("%d /%d %c%d /%d", &num1, &denom1, &operator, &num2, &denom2);

    // Note: "%d /%d %c%d /%d" is better than "%d/%d%c%d/%d"
    // as we are allowed to insert spaces before and after
    // each character like in ch3/ex6

	switch (operator)
	{
	case '+':
		result_num = num1 * denom2 + num2 * denom1;
		result_denom = denom1 * denom2;
		break;
	case '-':
		result_num = num1 * denom2 - num2 * denom1;
		result_denom = denom1 * denom2;
		break;
	case '*':
		result_num = num1 * num2;
		result_denom = denom1 * denom2;
		break;
	case '/':
		result_num = num1 * denom2;
		result_denom = denom1 * num2;
		break;
	default: printf("Invalid operator!\n"); return 0;
	}

	printf("The result is %d/%d\n", result_num, result_denom);

	return 0;
}
