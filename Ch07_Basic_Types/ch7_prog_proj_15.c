/*
 * ch7_prog_proj_15.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Mahmoud Hamdy
 */

// Programming Project 15: Factorial of a positive number
/**
 * Answers are found below the code
 * 
 * This code will allow you to test multiple values without having to 
 * re-run the program many time, unless you input 0 (termination condition)
 * 
 * Hint: If you are using MINGW on windows, you will have issues with printing
 * the long double type (it will print zeroes no matter what you do)
 * There is a workaround for handling long double variable in MINGW, but it 
 * does not apply to this example, as we should stick to the %LF specifier
 * 
 * Maybe try to run your program elseware for this specific case
 * Suggestion: https://www.onlinegdb.com/
 * 
 */

#include <stdio.h>

int main(void)
{
	unsigned long n, i;

	// a) short
	short int factorial;

	// b) int
	//int factorial;

	// c) long
	//long factorial;

	// d) long long
	//long long factorial;

	// e) float
	//float factorial;

	// f) double
	//double factorial;

	// g) long double
	//long double factorial;

	printf("Enter a positive number: ");
	scanf("%lu", &n);

    while(n != 0)
	{
		factorial = 1.0L;

		for(i = n; i > 0; i--)
		{
			factorial *= i;
		}

		// a) short
		printf("Factorial of %lu: %hd\n", n, factorial);

		// b) int
		//printf("Factorial of %lu: %d\n", n, factorial);

		// c) long
		//printf("Factorial of %lu: %ld\n", n, factorial);

		// d) long long
		//printf("Factorial of %lu: %lld\n", n, factorial);

		// e) float
		//printf("Factorial of %lu: %f\n", n, factorial);

		// f) double
		//printf("Factorial of %lu: %f\n", n, factorial);

		// g) long double
		//printf("Factorial of %lu: %Lf\n", n, factorial);

		printf("\nEnter a positive number: ");
		scanf("%lu", &n);
	}

	return 0;
}

/**
 *
 * a) For a short, the largest value of n = 7
 *
 * b) For a int, the largest value of n = 12
 *
 * c) For a long, the largest value of n = 12
 * Note: long and int have the same size of 4 bytes on my machine :)
 *
 * d) For a long long, the largest value of n = 20
 *
 * e) For a float, the largest value of n = 34
 *
 * f) For a double, the largest value of n = 170
 *
 * g) For a long double, the largest value of n = 1754
 *
 *
 */
