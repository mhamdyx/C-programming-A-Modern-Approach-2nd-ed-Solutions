/*
 * ch12_exercises.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 *            0   1   2   3   4  5   6   7
 * int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
 * int *p = &a[1], *q = &a[5];
 *
 * a) *(p + 3) = *(&a[4]) = 14
 *
 * b) *(q - 3) = *(&a[2]) = 34
 *
 * c) q - p = &a[5] - &a[1] = (&a[0] - &a[0]) + (5 - 1) = 4
 *
 * d) p < q is true
 *
 * e) *p < *q is false
 *
 */

//----------------------------------

// Q2

/*
 * middle = (low + high) / 2; is illegal because:
 * C doesn't support adding two pointers together but it supports subtraction.
 * So instead, we can do the following:
 *
 * middle = low + ((high - low) / 2);
 *
 * (high - low) is legal & (high - low) / 2 will return a constant
 *
 * so it will be: middle = low + const; which is also legal in pointer arithmetic.
 *
 */

//----------------------------------

// Q3

/*
 * contents of array a after execution:
 * {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
 * hence the array is reversed
 */

//----------------------------------

// Q4
/*
// Rewriting the stack example to include the new functions' implementation
// Note: you don't need all this but it was implemented anyway to be
// a self-contained test script

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

// External Variables
int contents[STACK_SIZE];
int *top_ptr = &contents[0];

// Stack prototypes
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);


int main(void)
{
	printf("Adding 2, 0, 1, 9 to the stack...\n");
	push(2);
	push(0);
	push(1);
	push(9);
	printf("Stack now contains 4 items.\nHowever, the stack is ");

	if(is_full())
	{
		printf("full.\n");
	}
	else
	{
		printf("not full.\n");
	}

	printf("And of course the stack is ");

	if(is_empty())
	{
		printf("empty.\n");
	}
	else
	{
		printf("not empty.\n");
	}

	printf("By calling make_empty(), the stack is now ");
	make_empty();

	if(is_empty())
	{
		printf("empty.\n");
	}
	else
	{
		printf("not empty.\n");
	}

	return 0;
}

void make_empty(void)
{
	top_ptr = &contents[0];
}

bool is_empty(void)
{
	return top_ptr == &contents[0];
}

bool is_full(void)
{
	return top_ptr == &contents[STACK_SIZE];
}

void push(int i)
{
	if(is_full())
	{
		stack_overflow();
	}
	else
	{
		*top_ptr++ = i;
	}
}

int pop(void)
{
	if(is_empty())
	{
		stack_underflow();
	}

	return *--top_ptr;
}

void stack_overflow(void)
{
	printf("Stack is full!");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Stack is empty!");
	exit(EXIT_FAILURE);
}
*/

//----------------------------------

// Q5
/*
 * p = a
 *
 * a) p == a[0] is illegal as p is of type (int *) while a[0] is of type (int)
 *
 * b) p == &a[0] is legal (as both of them are pointers and is true) and true
 *
 * c) *p == a[0] is legal (as both of them are integers) and true
 *
 * d) p[0] == a[0] is legal (as both of them can be subscripted) and true
 *
 */

//----------------------------------

// Q6
/*
int sum_array(const int *a, int n)
{
	int sum = 0;
	const int *p;

	for(p = a; p < a + n; p++)
		sum += *p;

	return sum;
}

// test script
#include <stdio.h>
int main(void)
{
	int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("Sum of array b is: %d", sum_array(b, 10));
	return 0;
}
*/

//----------------------------------

// Q7
/*
#include <stdbool.h>

bool search(const int a[], int n, int key)
{
	const int *p;
	for(p = a; p < a + n; p++)
	{
		if(*p == key)
			return true;
	}

	return false;
}

// test script
#include <stdio.h>
int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int key;

	printf("Enter a number: ");
	scanf("%d", &key);

	printf("Searching for %d: %s", key, search(a, 10, key) ? "found!\n" : "not found!\n");
	return 0;
}
*/

//----------------------------------

// Q8
/*
void store_zeros(int *a, int n)
{
	int *p;

	for(p = a; p < a + n; p++)
		*p = 0;
}

// test script
#include <stdio.h>
int main(void)
{
	int i, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	store_zeros(a, 10);

	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
*/

//----------------------------------

// Q9
/*
double inner_product(const double *a, const double *b, int n)
{
	const double *p, *q;
	double sum = 0.0;

	for(p = a, q = b; p < a + n; p++, q++)
	{
		sum += (*p) * (*q);
	}

	return sum;
}

// test script
#include <stdio.h>
int main(void)
{
	double a[5] = {1, 2, 3, 4, 5};
	double b[5] = {5, 4, 3, 2, 1};
	printf("Sum of array a is %lf", inner_product(a, b, 5));
	return 0;
}
*/

//----------------------------------

// Q10
/*
int *find_middle(int a[], int n)
{
	return (a + n / 2);
}

// test script
#include <stdio.h>
int main(void)
{
	int a[7] = {9, 5, 1, 8, 7, 5, 3};
	printf("Middle element in array a is %d", *(find_middle(a, 7)));
}
*/

//----------------------------------

// Q11
/*
int find_largest(int *a, int n)
{
	int *p, max = *a;

	for(p = a; p < a + n; p++)
	{
		if(*p > max)
			max = *p;
	}

	return max;
}

// test script
#include <stdio.h>
int main(void)
{
	int a[6] = {0, 12, 27, 11, 14, 2};

	printf("The largest elements in array a is %d", find_largest(a, 6));

	return 0;
}
*/

//----------------------------------

// Q12
/*
void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
	const int *p;
	*largest = *a;
	*second_largest = *(a + 1);

	for(p = a; p < a + n; p++)
	{
		if(*p > *largest)
		{
			*second_largest = *largest;
			*largest = *p;
		}
	}
}

// test script
#include <stdio.h>
int main(void)
{
	int a[6] = {0, 12, 27, 11, 14, 2};
	int largest, sec_largest;

	find_two_largest(a, 6, &largest, &sec_largest);

	printf("Largest element is %d\n", largest);
	printf("Second largest element is %d", sec_largest);

	return 0;
}
*/

//----------------------------------

// Q13
/*
// Implementation + Test script
#include <stdio.h>
#define N 10

int main(void)
{
	double ident[N][N], *p;
	int count = 0;

	for(p = &ident[0][0]; p <= &ident[N - 1][N - 1]; p++, count++)
	{
		if(count > 0 && count <= N)
		{
			*p = 0;
		}
		else
		{
			*p = 1;
			count = 0;
		}
	}

	// Print the 2D-array
	for(int row = 0; row < N; row++)
	{
		for(int col = 0; col < N; col++)
		{
			printf("%.1lf ", ident[row][col]);
		}
		printf("\n");
	}

	return 0;
}
*/

//----------------------------------

// Q14
/*
// Remember the function from exercise 7
#include <stdbool.h>

bool search(const int a[], int n, int key)
{
	const int *p;
	for(p = a; p < a + n; p++)
	{
		if(*p == key)
			return true;
	}

	return false;
}

// Test script including the questioned statement
#include <stdio.h>

int main(void)
{
	int temperature[7][24] = {{0}}; // All elements are initialized to 0

	// test case
	temperature[3][17] = 32; // Comment it to return false from search function

	// Search algorithm
	for(int i = 0; i < 7; i++)
	{
		if(search(temperature[i], 24, 32)) // The statement
		{
			printf("Value exists!");
			break;
		}

		if(i == 6)
		{
			printf("Value doesn't exist");
		}
	}

	return 0;
}
*/

//----------------------------------

// Q15
/*
// Test script + Loop
#include <stdio.h>
int main(void)
{
	int temperature[7][24] = {{0}}; // All elements are initialized to 0
	int *p, i;

	// Loop of processing rows
	for(i = 0; i < 7; i++)
	{
		for(p = temperature[i]; p < temperature[i] + 24; p++)
		{
			printf("%d ", *p);
		}
		printf("\n");
	}

	return 0;
}
*/

//----------------------------------

// Q16
/*
// Test script + Loop
#include <stdio.h>

int *find_largest(int a[], int n);

int main(void)
{
	int temperature[7][24] = {{0}}; // All elements are initialized to 0
	int *abs_max, *max_per_row, i;

	// Test case
	temperature[0][0] = 14;
	temperature[1][12] = 30;
	temperature[2][2] = 20;
	temperature[3][17] = 37;
	temperature[4][11] = 10;
	temperature[5][14] = 16;
	temperature[6][22] = 36;

	// Loop of finding the max element
	abs_max = find_largest(temperature[0], 24);
	for(i = 1; i < 7; i++)
	{
		max_per_row = find_largest(temperature[i], 24);

		if(*max_per_row > *abs_max)
		{
			abs_max = max_per_row;
		}
	}

	// Printing the maximum temp
	printf("%d", *abs_max);

	return 0;
}

int *find_largest(int a[], int n)
{
	int *max_elem = &a[0];

	for(int i = 1; i < n; i++)
	{
		if(a[i] > *max_elem)
			max_elem = &a[i];
	}

	return max_elem;
}
*/

//----------------------------------

// Q17
/*
// Function + Test script
#include <stdio.h>
#define LEN 4

int sum_two_dimensional_array(const int a[][LEN], int n)
{
	int sum = 0;
	const int *p;

	for(p = *a; p < *a + n * LEN; p++)
	{
		sum += *p;
	}

	return sum;
}

int main(void)
{
	int arr[3][LEN], sum_2D_arr;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < LEN; j++)
		{
			arr[i][j] = 1;
		}
	}

	sum_2D_arr = sum_two_dimensional_array((const int (*)[LEN])arr, 3);
	// Type casting to avoid warning but not necessary
	// Should return D1 * LEN

	// Print the total sum of 2D-array elements
	printf("Total sum = %d", sum_2D_arr);

	return 0;
}
*/


//----------------------------------

// Q18
/*
int evaluate_position(char board[8][8])
{
	int white_weight = 0, black_weight = 0;

	char *p;

	for(p = *board; p < *board + 64; p++)
	{
		switch(*p)
		{
		case 'Q':
			white_weight += 9;
			break;

		case 'R':
			white_weight += 5;
			break;

		case 'B':
			white_weight += 3;
			break;

		case 'N':
			white_weight += 3;
			break;

		case 'P':
			white_weight += 1;
			break;

		case 'q':
			black_weight += 9;
			break;

		case 'r':
			black_weight += 5;
			break;

		case 'b':
			black_weight += 3;
			break;

		case 'n':
			black_weight += 3;
			break;

		case 'p':
			black_weight += 1;
			break;
		}

	}

	return (white_weight - black_weight);
}
*/
