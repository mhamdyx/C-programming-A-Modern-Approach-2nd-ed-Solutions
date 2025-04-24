/*
 * ch8_exercises.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Mahmoud Hamdy
 */


// Q1

/**
 *
 * Because every time we decide to change the data type of the array, we
 * will have to check if the macro definition type t matches.
 *
 * The expression sizeof(a) / sizeof(a[0]) relieves us from checking
 * this consistency because it is more generic
 *
 */

//----------------------------------
// Q2

/**
 *
 * It is assumed that we are using the ASCII character set
 *
 * Since the characters from '0' to '9' are not in the range from 0 to 9,
 * we can simply get simply get the position with respect to character '0'
 * Here is an example:
 *
 * int digit_count[10];
 * char ch;
 *
 * To set an array element corresponding to a certain digit, here is
 * how we can index the array:
 *
 * digit_count[ch - '0'] = 1;
 *
 */

//----------------------------------
// Q3

/**
 *
 * bool weekend[] = {1, 0, 0, 0, 0, 0, 1};
 *
 * or
 *
 * bool weekend[] = {true, false, false, false, false, false, true};
 *
 * Hint: Make sure you include <stdbool.h> or create the proper macros
 *
 */


//----------------------------------
// Q4

/**
 *
 * bool weekend[] = {[0] = true, [6] = true};
 *
 * or
 *
 * bool weekend[] = {[0] = 1, [6] = 1};
 *
 * Hint: Make sure you include <stdbool.h> or create the proper macros
 *
 */

// test script
/*
#include <stdio.h>
#include <stdbool.h> // C99

int main(void)
{
	bool weekend[] = {[0] = true, [6] = true}; // C99
	int i;

	for(i = 0; i < 7; i++)
		printf("%d ", weekend[i]);

	printf("\n");

	return 0;
}
*/


//----------------------------------
// Q5
/*
#include <stdio.h>
#define LEN 16

int main(void)
{
	int i, fib_numbers[LEN] = {0, 1};

	for(i = 2; i < LEN; i++)
		fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];

	// Test script
	printf("The Fibonacci numbers are:\n");

	for(i = 0; i < LEN; i++)
		if((i % 10 == 9) || (i == LEN - 1))
			printf("%d\n", fib_numbers[i]);
		else
			printf("%d, ", fib_numbers[i]);

	return 0;
}
*/

//----------------------------------
// Q6
/*
const int segments[10][7] =
{
		{1, 1, 1, 1, 1, 1, 0}, // 0
		{0, 1, 1, 0, 0, 0, 0}, // 1
		{1, 1, 0, 1, 1, 0, 1}, // 2
		{1, 1, 1, 1, 0, 0, 1}, // 3
		{0, 1, 1, 0, 0, 1, 1}, // 4
		{1, 0, 1, 1, 0, 1, 1}, // 5
		{1, 0, 1, 1, 1, 1, 1}, // 6
		{1, 1, 1, 0, 0, 0, 0}, // 7
		{1, 1, 1, 1, 1, 1, 1}, // 8
		{1, 1, 1, 1, 0, 1, 1}  // 9
};

// test script
#include <stdio.h>
int main(void)
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	if(segments[n][0])
		printf(" __");

	printf("\n");

	if(segments[n][5])
		printf("|");
	else
		printf(" ");

	if(segments[n][6])
		printf("__");
	else
		printf("  ");

	if(segments[n][1])
		printf("|");

	printf("\n");

	if(segments[n][4])
		printf("|");
	else
		printf(" ");

	if(segments[n][3])
		printf("__");
	else
		printf("  ");

	if(segments[n][2])
		printf("|");
	return 0;
}
*/

//----------------------------------
// Q7

/*
const int segments[10][7] =
{
		{1, 1, 1, 1, 1, 1}, // 0
		{0, 1, 1}, // 1
		{1, 1, 0, 1, 1, 0, 1}, // 2
		{1, 1, 1, 1, 0, 0, 1}, // 3
		{0, 1, 1, 0, 0, 1, 1}, // 4
		{1, 0, 1, 1, 0, 1, 1}, // 5
		{1, 0, 1, 1, 1, 1, 1}, // 6
		{1, 1, 1}, // 7
		{1, 1, 1, 1, 1, 1, 1}, // 8
		{1, 1, 1, 1, 0, 1, 1}  // 9
};
*/

//----------------------------------
// Q8

// float temperature_readings[30][24];

//----------------------------------
// Q9
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// Declaration fragment
	float temperature_readings[30][24];
	float total_readings = 0.0f, avg_temperature;
	int i, j;

	// Array initialization fragment
	// Done by scanf, reading from a file, ...etc
	// I will do it using random number generation (from 0 to 39 C)
	srand((unsigned) time(NULL));

	// Computation fragment
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 24; j++)
		{
			temperature_readings[i][j] = rand() % 40;
			total_readings += temperature_readings[i][j];
		}
	}

	avg_temperature = total_readings / (30 * 24);

	printf("Average temperature over the month = %.2f\n", avg_temperature);


	return 0;
}
*/

//----------------------------------
// Q10
/*

// Declaration + test script
#include <stdio.h>

int main(void)
{
	char chess_board[8][8] =
	{
			{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
			{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
			{'\0', '.', '\0', '.', '\0', '.', '\0', '.'},
			{'.', '\0', '.', '\0', '.', '\0', '.', '\0'},
			{'\0', '.', '\0', '.', '\0', '.', '\0', '.'},
			{'.', '\0', '.', '\0', '.', '\0', '.', '\0'},
			{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
			{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
	};

	int i, j;

	printf("Chess Board Setup:\n\n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			printf("%c ", chess_board[i][j]);

		printf("\n");
	}

	return 0;
}
*/


//----------------------------------
// Q11
/*
#include <stdio.h>

int main(void)
{
	char checker_board[8][8];

	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
				checker_board[i][j] = 'B';
			else
				checker_board[i][j] = 'R';

			printf("%c ", checker_board[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/
