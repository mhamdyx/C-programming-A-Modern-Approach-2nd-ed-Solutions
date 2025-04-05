/*
 * ch10_prog_proj_07.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Mahmoud Hamdy
 */

// Programming Project 7: Seven-segment display

/*
 *   0            _0_            _0_           012 (3 = horizontal space)
 * 5   1       5 |   | 1  -->  5|_6_|1  -->  0  _
 *   6    -->  5 |_6_| 1       4|_3_|2       1 |_|
 * 4   2       4 |   | 2                     2 |_|
 *   3         4 |_3_| 2                    (3 = vertical space)
 *
 */


#include <stdio.h>

#define MAX_DIGITS 10

// External variables
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

char digits[4][MAX_DIGITS * 4];

int segment_coordinates[7][2] =
{
		{0, 1}, // seg 0
		{1, 2}, // seg 1
		{2, 2}, // seg 2
		{2, 1}, // seg 3
		{2, 0}, // seg 4
		{1, 0}, // seg 5
		{1, 1}  // seg 6
};

// Prototypes
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
	char num;
	int num_count = 0;

	// Initialize digits array
	clear_digits_array();

	printf("Enter a number: ");

	while(num_count < MAX_DIGITS)
	{
		num = getchar();

		if(num >= '0' && num <= '9')
		{
			process_digit(num - '0', num_count);
			num_count++;
		}
		else if(num == '\n')
		{
			break;
		}
	}

	// Printing digits array
	print_digits_array();

	return 0;
}

void clear_digits_array(void)
{
	int digits_width = MAX_DIGITS * 4;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < digits_width; j++)
		{
			digits[i][j] = ' ';
		}
	}
}

void process_digit(int digit, int position)
{
	int row, col;
	for(int seg = 0; seg <= 6; seg++)
	{
		row = segment_coordinates[seg][0];
		col = segment_coordinates[seg][1];

		if(segments[digit][seg])
		{
			digits[row][position * 4 + col] = (seg % 3 == 0) ? '_' : '|';
		}
	}
}

void print_digits_array(void)
{
	int digits_width = MAX_DIGITS * 4;

	for(int row = 0; row < 4; row++)
	{
		for(int col = 0; col < digits_width; col++)
		{
			printf("%c", digits[row][col]);
		}
		printf("\n");
	}
}
