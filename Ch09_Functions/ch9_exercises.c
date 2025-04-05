/*
 * ch9_exercises.c
 *
 *  Created on: Oct 21, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1

// Mistakes:
// 1) (double base, height) --> illegal
// should be (double base, double height)

// 2) double product; --> this line should be included between the
// braces (where the function's body is)

// After correction:
/*
double triangle_area(double base, double height)
{
	double product;

	product = base * height;

	return product / 2;
}
*/

//-----------------------------------

// Q2
/*
int check(int x, int y, int n)
{
	if(x >= 0 && x <= n && y >= 0 && y <= n)
		return 1;

	return 0;
}

// testing script
#include <stdio.h>

int main(void)
{
	int x, y, n;

	printf("Enter x: ");
	scanf("%d", &x);

	printf("Enter y: ");
	scanf("%d", &y);

	printf("Enter n: ");
	scanf("%d", &n);

	printf("Checking returns: %d", check(x, y, n));

	return 0;
}
*/

//-----------------------------------------

// Q3
/*
int gcd(int m, int n)
{
	if(n <= 1)
		return m;

	return gcd(n, m % n);
}

// test script
#include <stdio.h>

int main(void)
{
	int m, n;

	printf("Enter m: ");
	scanf("%d", &m);

	printf("Enter n: ");
	scanf("%d", &n);

	printf("gcd of %d & %d is %d\n", m, n, gcd(m, n));

	return 0;
}
*/

//-------------------------------

// Q4
/*
int day_of_year(int month, int day, int year)
{
	int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// from days
	int total = day;

	// from months
	// (excluding the current month as its days are already counted)
	for(int i = 0; i < month - 1; i++)
	{
		total += days_per_month[i];
	}

	// detecting leap year
	if(month > 2)
	{
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			total += 1;
		}
	}

	return total;
}


// test script
#include <stdio.h>

int main(void)
{
	int month, day, year;

	printf("Enter month: ");
	scanf("%d", &month);

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter year: ");
	scanf("%d", &year);

	printf("Day of the year is: %d", day_of_year(month, day, year));

	return 0;
}
*/

//---------------------------------

// Q5
/*
int num_digits(unsigned int n)
{
	int digits_count = 0;

	if(n == 0)
	{
		return 1;
	}

	while(n > 0)
	{
		n /= 10;
		digits_count++;
	}

	return digits_count;
}

// test script
#include <stdio.h>

int main(void)
{
	unsigned int n;

	printf("Enter n: ");
	scanf("%u", &n);

	printf("Number of digits in n: %d\n", num_digits(n));

	return 0;
}
*/

//---------------------------------

// Q6
/*
int digit(unsigned int n, int k)
{
	int step_count = 0, rem;

	if(sizeof(unsigned int) * 8 < k)
		return 0;

	while(step_count < k)
	{
		rem = n % 10;
		n /= 10;
		step_count++;
	}

	return rem;
}

// test script
#include <stdio.h>

int main(void)
{
	unsigned int n;
	int k;

	printf("Enter n: ");
	scanf("%u", &n);

	printf("Enter k: ");
	scanf("%d", &k);

	printf("Digit number %d from right in %u is %d\n", k, n, digit(n, k));

	return 0;
}
*/

//---------------------------------

// Q7

// int f(int a, int b){...}
// i --> int, x --> double
// i = f(83, 12);
// x = f(83, 12);
// i = f(3.15, 9.28);
// x = f(3.15, 9.28);
// f(83, 12);
//
// All are valid by the effect of Implicit conversion
// (Type conversion in assignment)


//---------------------------------

// Q8

// (a) void f(double x); ---> valid
// (b) void f(double);   ---> valid and used for good documentation
// (c) void f(x);        ---> invalid
// (d) f(double x);      ---> In C99, it's invalid but
//                            in C98, it's presumed to return an int


//---------------------------------

// Q9

// Output:
// i = 1, j = 2
// (yes, no change)

//---------------------------------

// Q10
/*
// (a) largest element of a
int largest_element(int a[], int n)
{
	int max_element = a[0];

	for(int i = 1; i < n; i++)
	{
		if(a[i] > max_element)
			max_element = a[i];
	}

	return max_element;
}

// (b) average of all elements in a
int avg_element(int a[], int n)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	return sum / n;
}

// (c) number of positive elements in a
int num_positive_element(int a[], int n)
{
	int pos_count = 0;

	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0)
			pos_count++;
	}

	return pos_count;
}

// test script
#include <stdio.h>

int main(void)
{
	int a[8] = {-2, 1, 8, 3, 5, 10, -12, 4};

	printf("Largest element in a = %d\n", largest_element(a, 8));

	printf("Average element in a = %d\n", avg_element(a, 8));

	printf("Number of positive elements in a = %d\n", num_positive_element(a,8));

	return 0;
}
*/

//---------------------------------

// Q11
/*
float compute_GPA(char grades[], int n)
{
	float total_grade = 0.0f;
	for(int i = 0; i < n; i++)
	{
		if(grades[i] == 'A' || grades[i] == 'a')
		{
			total_grade += 4.0f;
		}
		else if(grades[i] == 'B' || grades[i] == 'b')
		{
			total_grade += 3.0f;
		}
		else if(grades[i] == 'C' || grades[i] == 'c')
		{
			total_grade += 2.0f;
		}
		else if(grades[i] == 'D' || grades[i] == 'd')
		{
			total_grade += 1.0f;
		}
	}

	return (total_grade / n);
}

// test script
#include <stdio.h>

int main(void)
{
	int n;
	printf("Enter the number of grades: ");
	scanf("%d", &n);

	char x_grades[n];

	for(int i = 0; i < n; i++)
	{
		printf("Enter grade number %d: ", i + 1);
		(stdout);
		scanf("%c", &x_grades[i]);

	}

	printf("Average  grade of x = %f", compute_GPA(x_grades, n));

	return 0;
}
*/

//---------------------------------

// Q12
/*
double inner_product(double a[], double b[], int n)
{
	double total = 0.0;
	for(int i = 0; i < n; i++)
	{
		total += a[i] * b [i];
	}

	return total;
}

// test script
#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter the arrays length: ");
	scanf("%d", &n);

	double a[n], b[n];

	for(int i = 0; i < n; i++)
	{
		printf("Enter element %d in a: ", i + 1);
		scanf("%lf", &a[i]);

		printf("Enter element %d in b: ", i + 1);
		scanf("%lf", &b[i]);
	}

	printf("Inner product of a & b is: %lf", inner_product(a, b, n));

	return 0;
}
*/

//---------------------------------

// Q13
/*
int evaluate_position(char board[8][8])
{
	int white_weight = 0, black_weight = 0;

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			switch(board[i][j])
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
	}

	return (white_weight - black_weight);
}
*/

//---------------------------------

// Q14
/*
// Correct Implementation
#include <stdbool.h>

bool has_zero(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
			return true;
	}

	return false;
}

// test script
#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter n: ");
	scanf("%d", &n);

	int a[n];

	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	if(has_zero(a, n))
		printf("array a has zero(s)");
	else
		printf("array a does not have any zeros");

	return 0;
}
*/

//---------------------------------

// Q15
/*
// Correct Implementation
double median(double x, double y, double z)
{
	double median_val;

	if((x <= y && x >= z) || (x <= z && x >= y))
	{
		median_val = x;
	}
	else if((y <= x && y >= z) || (y <= z && y >= x))
	{
		median_val = y;
	}
	else
	{
		median_val = z;
	}

	return median_val;
}

// test script
#include <stdio.h>

int main(void)
{
	double x, y, z;

	printf("Enter x: ");
	scanf("%lf", &x);

	printf("Enter y: ");
	scanf("%lf", &y);

	printf("Enter z: ");
	scanf("%lf", &z);

	printf("The median of %lf, %lf, %lf = %lf", x, y, z, median(x, y, z));

	return 0;
}
*/

//---------------------------------

// Q16
// Condensed fact
int fact(int n)
{
	return (n <= 1) ? 1 : n * fact(n - 1);
}

//---------------------------------

// Q17
/*
// No recursive fact
int fact(int n)
{
	int result = 1;
	while(n > 1)
	{
		result *= n;
		n -= 1;
	}

	return result;
}
*/

//---------------------------------

// Q18
/*
int gcd(int m, int n)
{
	if(n == 0) //As specified by the exercise but could be n <= 1 instead.
		return m;

	return gcd(n, m % n);
}
*/

//---------------------------------

// Q19
/*
// Mystery function
#include <stdio.h>
void pb(int n)
{
	if(n != 0)
	{
		pb(n / 2);
		putchar('0' + n % 2);
	}
}


int main(void)
{
	int n;

	printf("Enter n: ");
	scanf("%d", &n);

	pb(n);

	return 0;
}

// From the output shown:
// Mystery function is actually a function that converts
// a number from the decimal form to its binary form.
*/
