/*
 * ch44_exercises.c
 *
 *  Created on: Nov 19, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1

// Aliases for i:
// a) *p
// g) *&i

//----------------------------------

// Q2
/*
 * i is int variable and p and q are pointers to int
 * legal assignments:
 *
 * e) p = *&q;
 * f) p = q;
 * i) *p = *q;
 *
 */

//----------------------------------

// Q3
/*
// Correct implementation:

void avg_sum(double a[], int n, double *avg, double *sum)
{
	int i = 0;

	*sum = 0.0;
	for(i = 0; i < n; i++)
		*sum += a[i];

	*avg = (*sum) / n;
}

// test script
#include <stdio.h>

int main(void)
{
	double a[5], sum_a, avg_a;

	printf("Enter array elements: ");

	for(int i = 0; i < 5; i++)
	{
		scanf("%lf", &a[i]);
	}

	avg_sum(a, 5, &avg_a, &sum_a);

	printf("Sum = %lf\nAvg = %lf", sum_a, avg_a);

	return 0;
}
*/

//----------------------------------

// Q4
/*
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

// test script
#include <stdio.h>

int main(void)
{
	int a, b;

	printf("Enter a: ");
	scanf("%d", &a);

	printf("Enter b: ");
	scanf("%d", &b);

	printf("Before swapping, a is %d and b is %d\n", a, b);
	swap(&a, &b);
	printf("After swapping, a is %d and b is %d", a, b);

	return 0;
}
*/

//----------------------------------

// Q5
/*
void split_time(long total_sec, int *hr, int *min, int *sec)
{
	*sec = total_sec % 60;
	total_sec /= 60;

	*min = total_sec % 60;
	total_sec /= 60;

	*hr = total_sec;
}

// test script
#include <stdio.h>

int main(void)
{
	long total_sec_so_far = 9115; //2:30:55 AM

	// printf("Enter the time in sec: ");
	// scanf("%ld", &total_sec_so_far);

	int t_hr, t_min, t_sec;

	split_time(total_sec_so_far, &t_hr, &t_min, &t_sec);

	printf("Time = %d:%d:%d %cM", t_hr, t_min, t_sec, (t_hr > 12) ? 'P' : 'A');
}
*/

//----------------------------------

// Q6
/*
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	*largest = a[0];
	*second_largest = a[1];

	for(int i = 1; i < n; i++)
	{
		if(a[i] > *largest)
		{
			*second_largest = *largest;
			*largest = a[i];
		}
	}
}


#include <stdio.h>
int main(void)
{
	int a[10], max_elem, second_max_elem;

	printf("Enter array elements: ");

	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	// Finding the two largest elements
	find_two_largest(a, 10, &max_elem, &second_max_elem);

	printf("Largest element: %d\nSecond largest element: %d", max_elem, second_max_elem);

	return 0;
}
*/

//----------------------------------

// Q7
/*
void split_date(int day_of_year, int year, int *month, int *day)
{
	int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	*month = 1;

	// Detecting if leap year
	if(day_of_year > (31 + 28))
	{
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			days_per_month[1]++;
		}
	}

	// Finding month
	for(int i = 0; i < 12; i++)
	{
		if(day_of_year > days_per_month[i])
		{
			(*month)++;
			day_of_year -= days_per_month[i];

		}
		else
		{
			break;
		}
	}

	// Finding day
	*day = day_of_year;
}

// test script
#include <stdio.h>
int main(void)
{
	int day_of_year, year, month, day;

	printf("Enter a day in the year (Between 1 and 366): ");
	scanf("%d", &day_of_year);

	printf("Enter the year: ");
	scanf("%d", &year);

	// Finding date
	split_date(day_of_year, year, &month, &day);

	printf("Date(mm/dd/yyyy) is %d/%d/%d", month, day, year);

	return 0;
}
*/

//----------------------------------

// Q8
/*
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

//test script
#include <stdio.h>
int main(void)
{
	int a[10], *largest_elem;

	printf("Enter elements of array a: ");

	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	largest_elem = find_largest(a, 10);

	printf("Largest element: %d", *largest_elem);

	return 0;
}
*/
