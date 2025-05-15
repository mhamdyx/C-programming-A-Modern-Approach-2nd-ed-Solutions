/*
 * ch15_exercises.c
 *
 *  Created on: Dec 28, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 * a) Other advantages:
 * - Breaking the problem into simpler sub-problems hence will be easy to deal with
 * - Information hiding and only making the necessary functions available for each file
 *
 * b) Some disadvantages:
 * - At some point, dealing with a large number of files can be confusing
 * - If the problem is small, it'd be unnecessary move to divide it into many files
 *
 */

//----------------------------------

// Q2

/*
 * (b) function definitions
 *
 * Because otherwise, we will have multiple definitions of the same function
 * in multiple files leading to potential errors
 *
 */

//----------------------------------

// Q3

/*
 * Yes and No.
 * Yes because if we had a local header file with the same name, it'd be found first
 * and we'd be including the wrong file.
 *
 * And no because if the compiler didn't find that file in our user-defined paths,
 * it'd return back to the system header files path.
 *
 */

//----------------------------------

// Q4

/*
 * a) Output:
 * Output if DEUBG is defined:
 * Value of i: 1
 * Value of j: 2
 * Value of k: 3
 * Value of i + j: 3
 * Value of 2 * i + j - k: 1
 * (blank line)
 *
 * b) Output:
 * Output if DEBUG is not defined:
 * (blank line)
 *
 *
 * c) Because when the DEBUG definition is omitted, the else condition in
 * the header file is satisfied which basically defines the parameterized
 * macro as empty (without any replacement list), so it does nothing
 * when calling it in the main function
 *
 *
 * d) Yes, the if condition in the header file depends on the pre-existence
 * of the DEBUG macro. If the order was to be altered, defining the DEBUG
 * macro later would be in vain.
 *
 */

//----------------------------------

// Q5 (This should be written in a file named: Makefile)
/*
demo: main.o f1.o f2.o
	gcc -o demo main.o f1.o f2.o

main.o: main.c f1.h
	gcc -c main.c

f1.o: f1.c f1.h f2.h
	gcc -c f1.c

f2.o: f2.c f2.h f1.h
	gcc -c f2.c
*/

//----------------------------------

// Q6

/*
 * a) All source files (f1.c, f2.c and main.c) need to be compiled.
 *
 * b) f1.c only will be recompiled
 *
 * c) Since it's included in all source files, all source files
 * need to be re-compiled
 *
 * d) Since it's included in f1.c and f2.c only, they are the only
 * source files that need to be re-compiled
 *
 * And re-linking the program applies to all (a, b, c, and d).
 *
 */
