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
 * c) static and extern (for local variables)
 *
 */

//----------------------------------

// Q3

/*
 * Storage duration
 * static: a, c
 * automatic: b, d
 *
 * Scope
 * block: b, c, d
 * file: a
 *
 * Linkage
 * internal: -
 * external: a
 * none: b, c, d
 *
 */

//----------------------------------

// Q4

/*
 * If f has never been called before, f(10) will return 0
 *
 * If f has been called five times already, f(10) will return 50
 * (Before the last return, i was 10 and j was 5)
 *
 */

//----------------------------------

// Q5

/*
 * a) False: Because static variables defined in functions (or blocks) have block scope
 *
 * b) False: Because extern variables defined inside functions have external linkage
 *
 * c) True: Because variables with internal linkage were already declared static
 * so they have static storage duration
 *
 * d) True: Because they are defined in a function which is already a block
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
 * a) Array of 10 pointers to functions that take integer as input and return a character
 *
 * b) Function that takes an int as input and returns a pointer to an array of five integers
 *
 * c) Function that has no parameters and returns a pointer to function that
 * takes an integer as input and returns a pointer to float
 *
 * d) Function that takes an integer and a pointer to function that takes an int and
 * returns nothing as inputs and returns a pointer to function that takes an integer
 * as input and returns nothing
 *
 */

//----------------------------------

// Q9
/*
// a) char (*x[10])(int);
typedef char fun(int);
typedef fun *fun_ptr;
typedef fun_ptr fun_ptr_arr[10];
//fun_ptr_arr x;


// b) int (*x(int))[5];
typedef int arr[5];
typedef arr *arr_ptr;
typedef arr_ptr fun(int);
//fun x;


// c) float *(*x(void))(int);
typedef float *fptr_fun_i(int);
typedef fptr_fun_i *fptr_fun_i_ptr;
typedef fptr_fun_i_ptr fun(void);
//fun x;


// d) void (*x(int, void (*y)(int)))(int);
typedef void v_fun_i(int);
typedef v_fun_i *v_fun_i_ptr;
typedef v_fun_i_ptr fun(int, v_fun_i_ptr);
//fun x;
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
 * a) A function f that takes as its parameters:
 * - A pointer to function that takes a long as its parameter and returns a float
 * - A pointer to character
 *
 * and returns a pointer to function that takes a double as its parameter and returns
 * an integer.
 *
 *
 * b) int *i_ptr = f(f_fun_l_ptr, ch_ptr)(lf_val);
 *
 */

//----------------------------------

// Q13

/*
 * a) Legal
 *
 * b) Illegal: because the initializer of a static variable (of static storage duration)
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
 * a) Storage duration, since variables with static storage duration have initial value
 * of zero while variables with automatic storage duration have no initial value
 *
 */
