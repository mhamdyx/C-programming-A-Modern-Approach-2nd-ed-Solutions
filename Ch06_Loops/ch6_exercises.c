/*
 * ch6_exercises.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Mahmoud Hamdy
 */

// Q1

/**
 *
 * 1 2 4 8 16 32 64 128
 *
 */

//----------------------------------

// Q2

/**
 *
 * 9384 938 93 9
 *
 */

//----------------------------------

// Q3

/**
 *
 * Hint: For a comma expression, the return value of this expression
 * is the value of last expression (after the last comma operator)
 * Hence, the controlling expression depends only on the condition j > 0
 *
 * 5 4 3 2
 *
 */

//----------------------------------

// Q4

/**
 *
 * (c) is not equivalent to (a) and (b) because unlike them, the value
 * of i is incremented before the execution of the loop body
 *
 */

//----------------------------------

// Q5

/**
 *
 * (c) is not equivalent to (a) and (b) because regardless the value
 * of i, the loop body is guaranteed to be executed at least once
 * (which is not be the case for (a) and (b) for values greater than
 * or equal to 10)
 *
 */

//----------------------------------

// Q6

/**
 *
 * for(i = 1; i <= 128; i *= 2)
 * {
 * 		printf("%d ", i);
 * }
 *
 */

//----------------------------------

// Q7

/**
 *
 * Because the question mentioned "a single" for statement, this
 * solution is acceptable and will give the same output:
 *
 * for(i = 9384; i > 0; i /= 10)
 * {
 * 		printf("%d ", i);
 * }
 *
 * If it's required to convert the do statement into a for statement
 * given the value of i = n (general case), then the exact conversion
 * that will give the exact output should look like this:
 *
 * i = n;
 * printf("%d ", i);
 *
 * for(; i > 0; i /= 10)
 * {
 * 		printf("%d ", i);
 * }
 *
 */

//----------------------------------

// Q8

/**
 *
 * This for statement is an infinite loop that will print 10 5 3 2
 * at first then when i reaches 1 this value will stay the same
 * forever hence we don't exit the loop because i will always be >= 1
 *
 * 10 5 3 2 1 1 1 ...
 *
 */

//----------------------------------

// Q9

/**
 *
 * i = 10;
 *
 * while(i >= 1)
 * {
 * 		printf("%d ", i++);
 * 		i /= 2;
 * }
 *
 */

//----------------------------------

// Q10

/**
 *
 * Suppose we have a loop like this one:
 * for( expr1; expr2; expr3)
 * {
 * 		if(condition)
 * 		{
 * 			continue;
 * 		}
 *
 * 		// The rest of the loop body
 *
 * }
 *
 * As we know, if the condition is true, continue statement gets
 * executed and the rest of the loop body is skipped because
 * the control is actually transferred at the end of the loop body
 *
 * Hence we can achieve the same behavior using for statement and
 * label at that point (let's call it, END_OF_LOOP_BODY):
 *
 * for(expr1; expr2; expr3)
 * {
 * 		if(condition)
 * 		{
 * 			goto END_OF_LOOP_BODY;
 * 		}
 *
 * 		// The rest of the loop body
 *
 * END_OF_LOOP_NODY: ; // At least one statement is required here
 *
 * }
 *
 *
 */

//----------------------------------

// Q11

/**
 *
 * 20
 *
 * Hint: This program prints the sum of +ve even numbers less than 10
 *
 */

//----------------------------------

// Q12

/**
 *
 * for(d = 2; d * d <= n; d++)
 * 		if(n % d == 0)
 * 			break;
 *
 */

//----------------------------------

// Q13

/**
 *
 * for(n = 0; m > 0; m /= 2, n++);
 *
 */

//----------------------------------

// Q14

/**
 *
 * The extra semicolon at the end of the if statement represents
 * a null statement and hence belongs to the if statement
 * and the printf statement becomes just another line that gets
 * executed regardless the value of n is, so by removing that extra
 * semicolon, the program is fixed.
 *
 * if(n % 2 == 0)
 * 		printf("n is even\n");
 *
 */
