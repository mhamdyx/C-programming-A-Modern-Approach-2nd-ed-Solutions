/*
 * ch5_prog_proj_10.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */


// Programming Project 10: Numerical to Letter Grade

#include <stdio.h>

int main(void)
{
	int grade, tens_digit;

	printf("Enter numerical grade: ");
	scanf("%d", &grade);

	if(grade < 0 || grade > 100)
	{
		printf("Error: invalid numerical grade");
		return 0;
	}

	tens_digit = grade / 10;

	switch(tens_digit)
	{
	case 0: case 1: case 2: case 3: case 4: case 5:
		printf("Letter grade: F\n");
		break;
	case 6:
		printf("Letter grade: D\n");
		break;
	case 7:
		printf("Letter grade: C\n");
		break;
	case 8:
		printf("Letter grade: B\n");
		break;
	case 9: case 10:
		printf("Letter grade: A\n");
		break;
	}

	return 0;
}
