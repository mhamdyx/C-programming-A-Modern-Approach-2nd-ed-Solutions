/*
 * ch18_exercises.c
 *
 *  Created on: May 1, 2020
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 * a) static char **lookup(int level);
 *
 * Storage class: static
 * Type qualifier: -
 * Type specifier: char
 * Declarator: **lookup(int level)
 * Initializer: -
 *
 *
 *
 * b) volatile unsigned long io_flags;
 *
 * Storage class: -
 * Type qualifier: volatile
 * Type specifier: unsigned long
 * Declarator: io_flags
 * Initializer: -
 *
 *
 *
 * c) extern char *file_name[MAX_FILES], path[];
 *
 * Storage class: extern
 * Type qualifier: -
 * Type specifier: char
 * Declarator: *file_name[MAX_FILES] & path[]
 * Initializer: -
 *
 *
 *
 * d) static const char token_buf[] = "";
 *
 * Storage class: static
 * Type qualifier: const
 * Type specifier: char
 * Declarator: token_buf[]
 * Initializer: ""
 *
 *
 */

//----------------------------------

// Q2

/*
 * a) extern
 *
 * b) static
 *
 * c) static and extern (both for local variables)
 *
 */

//----------------------------------

// Q3

/*
 * extern float a;
 * 
 * Static storage duration
 * File scope
 * External linkage
 * 
 * ---
 * 
 * register double b
 * 
 * Automatic storage duration
 * Block scope
 * No linkage
 * 
 * ---
 * 
 * static int c;
 * 
 * Static storage duration
 * Block scope
 * No linkage
 * 
 * ---
 * 
 * auto char d;
 * 
 * Automatic storage duration
 * Block scope
 * No linkage
 *
 */

//----------------------------------

// Q4

/*
 * If f has never been called before, f(10) will return 0
 *
 * If f has been called five times already, f(10) will return 50
 * 
 * After calling f(10) five times, j became 5, hence calling f(10)
 * for the last time returns 10 * 5, which is 50
 * (j is post-incremented and next time f is called, j will be 
 * evaluated as 6)
 *
 */

//----------------------------------

// Q5

/*
 * a) False: Local static variables that are defined in functions
 * (or blocks) have block scope
 *
 * b) False: As extern variables declared inside functions that have
 * external definitions in another have external linkage
 *
 * c) True: As variables with internal linkage were already declared
 * static, so they have static storage duration
 *
 * d) True: As they are defined in a function which is already a block
 *
 */

//----------------------------------

// Q6

/*
// The problem is that n has automatic storage duration so it doesn't
// retain its value (accumulated number of calls), to solve this:
// we make n declaration static

#include <stdio.h> // To use printf
void print_error(const char *message)
{
	static int n = 1;
	printf("Error %d: %s\n", n++, message);
}
*/

//----------------------------------

// Q7

/*
 * a) False
 *
 * b) True
 *
 * c) True
 *
 * d) True
 *
 */

//----------------------------------

// Q8

/*
 * a) Array of 10 pointers to functions that take integer as input
 * and return a character
 *
 * b) Function that takes an int as input and returns a pointer to
 * an array of five integers
 *
 * c) Function that has a void parameter and returns a pointer to
 * a function that takes an integer as input and returns a pointer
 * to float
 *
 * d) Function that takes an integer and a pointer to function (that
 * takes an int and returns nothing) as inputs and returns a pointer
 * to function that takes an integer as input and returns nothing
 *
 */

//----------------------------------

// Q9
/*
 * a) char (*x[10])(int);
 *
 * typedef char fcn(int);
 * typedef fcn *fcn_ptr;
 * typedef fcn_ptr fcn_ptr_arr[10];
 * fcn_ptr_arr x;
 *
 * ---
 *
 * b) int (*x(int))[5];
 *
 * typedef int arr[5];
 * typedef arr *arr_ptr;
 * typedef arr_ptr arr_ptr_fcn(int);
 * arr_ptr_fcn x;
 *
 * ---
 *
 * c) float *(*x(void))(int);
 *
 * typedef float *fcn(int);
 * typedef fcn *fcn_ptr;
 * typedef fcn_ptr fcn_ptr_fcn(void);
 * fcn_ptr_fcn x;
 *
 * ---
 *
 * d) void (*x(int, void (*y)(int)))(int);
 *
 * typedef void f(int);
 * typedef f *fp;
 * typedef fp fp_fcn(int, fp);
 * fp_fcn x;
 *
 *
 */

//----------------------------------

// Q10

/*
 * a) char *(*p)(char *);
 *
 * b) void (*f(struct t *p, long int n))(void);
 *
 * c) void (*a[4])(void) = {insert, search, update, print};
 * or void (*a[])(void) = {insert, search, update, print};
 *
 * d) struct t (*b[10])(int, int);
 *
 */

//----------------------------------

// Q11

/*
 * Wrong: int f(int)[];
 *
 * Correction: int *f(int);
 *
 *
 * Wrong: int g(int)(int);
 *
 * Correction: int (*g(int))(int);
 *
 *
 * Wrong: int a[10](int);
 *
 * Correction: int (*a[10])(int);
 *
 */

//----------------------------------

// Q12

/*
 * a) f is a function that takes two parameters as inputs (a pointer to 
 * a function that takes long and returns a float, and a pointer to a 
 * character) and returns a pointer to a function that takes a double 
 * argument and returns an integer
 *
 *
 * b) Here is a fragment:
 * float (*float_fptr_long)(long) = some_function;
 * char ch = 'a';
 * double d = 2.2;
 * int i;
 * ...
 * i = (*f(float_fptr_long, &ch))(d);
 *
 */

//----------------------------------

// Q13

/*
 * a) Legal
 *
 * b) Illegal:
 * While the initialization of i is legal, the initialization of j is
 * illegal as the initializer of a variable with static storage duration
 * must be a constant expression.
 *
 * c) Legal
 *
 * d) Legal
 *
 */

//----------------------------------

// Q14

/*
 * e) None of the above, since all of them can be initialized
 *
 */

//----------------------------------

// Q15

/*
 * (a) Storage duration, since variables with static storage duration have
 * initial value of zero while variables with automatic storage duration
 * have no default initial value (different value each time the variable
 * comes into existence)
 *
 */
