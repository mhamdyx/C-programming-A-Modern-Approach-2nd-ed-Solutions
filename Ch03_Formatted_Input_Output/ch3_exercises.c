/*
 * ch3_exercises.c
 *
 *  Created on: Mar 19, 2024
 *      Author: Mahmoud Hamdy
 */


// Q1
/**
 * s = space
 *
 * Hint: For unpredictable results with %g or %e, you can
 * include these lines in a program and notice the output
 *
 * a) ssss86,s1040
 *
 * b) 3.02530e+001
 *
 * c) 83.1620
 *
 * d) 1e-006
 *
 */

//----------------------------------

// Q2
/**
 * a) printf("%-8.1e", x);
 *
 * b) printf("%10.6e", x);
 *
 * c) printf("%-8.3f", x);
 *
 * d) printf("%6.0f", x);
 *
 */

//----------------------------------

// Q3
/**
 * a) Equivalent since scanf skips all white-space characters when
 * reading a number
 *
 * b) Not equivalent
 *
 * "%d-%d-%d" -> scanf does not expect a space after %d and before the
 * next '-' character, hence we cannot write inputs like this: 5 -2 -3
 *
 * "%d -%d -%d" -> scanf does expect a space between %d and the next
 * '-' although it's optional (because a whitespace character in a
 * format string matches any number of whitespace characters in the
 * input, including none)
 *
 * c) Not equivalent
 * "%f" -> scanf leaves '\n' to be read on the next scan
 * "%f " -> scanf leaves a space and '\n'to be read on the next scan
 * This will not make a difference if the next input to be read
 * is a number because scanf will skip all white-space characters
 * until it reaches the first digit to be read in the input number
 *
 *
 * d) Equivalent since scanf skips all white-space characters when
 * reading a number
 *
 */

//----------------------------------

// Q4
/**
 * i = 10
 *
 * x = 0.3
 *
 * j = 5
 *
 */

//----------------------------------

// Q5
/**
 * x = 12.3
 *
 * i = 45
 *
 * y = 0.6
 *
 */

//----------------------------------

// Q6
/**
 * We will have to change the formatted strings in scanf statements
 * Here are the new statements to be written:
 *
 * ...
 * scanf("%d /%d", &num1, &denom1);
 * ...
 * scanf("%d /%d", &num2, &denom2);
 * ...
 *
 *
 */
