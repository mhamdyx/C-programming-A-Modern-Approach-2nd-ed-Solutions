/*
 * ch3_prog_proj_06.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Mahmoud Hamdy
 */

// Programming Project 6: Adding Fractions

#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;

	printf("Enter two fractions separated by a plus sign: ");
	scanf("%d /%d +%d /%d", &num1, &denom1, &num2, &denom2);
    
    // Note: "%d /%d +%d /%d" is better than "%d/%d+%d/%d"
    // as we are allowed to insert spaces before and after
    // each character like in exercise 6

	result_num = num1 * denom2 + num2 * denom1;
	result_denom = denom1 * denom2;

	printf("The sum is %d/%d\n", result_num, result_denom);

	return 0;
}
