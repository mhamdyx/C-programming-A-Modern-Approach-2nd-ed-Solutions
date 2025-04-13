/*
 * ch5_exercises.c
 *
 *  Created on: Apr 13, 2025
 *      Author: Mahmoud Hamdy
 */

 // Q1
/**
 * a) i = 2; j = 3;
 * k = i * j == 6;
 * printf("%d", k);
 *
 * i * j == 6  ---> ((i * j) == 6)
 * ((2 * 3) == 6) ---> (6 == 6) ---> 1 (true)
 * k = 1;
 *
 * Output:
 * 1
 *
 *
 * b) i = 5; j = 10; k = 1;
 * printf("%d", k > i < j);
 *
 * k > i < j ---> ((k > i) < j)
 * ((1 > 5) < 10) ---> (0 < 10) ---> 1 (true)
 *
 * Output:
 * 1
 *
 *
 * c) i = 3; j = 2; k = 1;
 * printf("%d", i < j == j < k);
 *
 * i < j == j < k ---> ((i < j) == (j < k))
 * ((3 < 2) == (2 < 1)) ---> (0 == 0) ---> 1 (true)
 *
 * Output:
 * 1
 *
 *
 * d) i = 3; j = 4; k = 5;
 * printf("%d", i % j + i < k);
 *
 * i % j + i < k ---> (((i % j) + i) < k)
 * (((3 % 4) + 3) < 5) ---> ((3 + 3) < 5)
 * (6 < 5) ---> 0 (false)
 *
 * Output:
 * 0
 *
 *
 */


//----------------------------------

// Q2
/**
 * a) i = 10; j = 5;
 * printf("%d", !i < j);
 *
 * !i < j ---> ((!i) < j)
 * ((!10) < 5) ---> (0 < 5) ---> 1 (true)
 *
 * Output:
 * 1
 *
 *
 * b) i = 2; j = 1;
 * printf("%d", !!i + !j);
 *
 * !!i + !j ---> ((!(!i)) + (!j))
 * ((!(!2)) + (!1)) ---> ((!0) + 0)
 * (1 + 0) ---> 1 (true)
 *
 * Output:
 * 1
 *
 *
 * c) i = 5; j = 0; k = -5;
 * printf("%d", i && j || k);
 *
 * i && j || k ---> ((i && j) || k)
 * ((5 && 0) || k) ---> (0 || k)
 * (0 || k) ---> (0 || 5) ---> 1 (true)
 *
 * Output:
 * 1
 *
 *
 * d) i = 1; j = 2; k = 3;
 * printf("%d", i < j || k);
 *
 * i < j || k ---> ((i < j) || k)
 * ((1 < 2) || k) ---> (1 || k) ---> 1 (short-circuit true)
 *
 * Output:
 * 1
 *
 *
 *
 */


//----------------------------------

// Q3
/**
 *
 * a) i = 3; j = 4; k = 5;
 * printf("%d ", i < j || ++j < k);
 * printf("%d %d %d", i, j, k);
 *
 * i < j || ++j < k ---> ((i < j) || ((++j) < k))
 * ((3 < 4) || ((++j) < k))
 * (1 || ((++j) < k)) ---> 1
 * (short-circuit true hence ++j < k is not evaluated)
 *
 * Output:
 * 1 3 4 5
 *
 *
 * b) i = 7; j = 8; k = 9;
 * printf("%d ", i - 7 && j++ < k);
 * printf("%d %d %d", i, j, k);
 *
 * i - 7 && j++ < k ---> ((i - 7) && ((j++) < k))
 * ((7 - 7) && ((j++) < k)) ---> (0 && ((j++) < k)) ---> 0
 * (short-circuit false hence j++ < k is not evaluated)
 *
 * Output:
 * 0 7 8 9
 *
 *
 * c) i = 7; j = 8; k = 9;
 * printf("%d ", (i = j) || (j = k));
 * printf("%d %d %d", i, j, k);
 *
 * (i = j) || (j = k) ---> ((i = j) || (j = k))
 * ((i = 8) || (j = k)) ---> (8 || (j = k)) ---> 1
 * (short-circuit true hence j = k is not evaluated)
 *
 * Output:
 * 1 8 8 9
 *
 *
 * d) i = 1; j = 1; k = 1;
 * printf("%d ", ++i || ++j && ++k);
 * printf("%d %d %d", i, j, k);
 *
 * ++i || ++j && ++k ---> ((++i) || ((++j) && (++k)))
 * ((++i) || ((++j) && (++k))) ---> (2 || ((++j) && (++k))) ---> 1
 * (short-circuit true hence ++j && ++k is not evaluated)
 *
 * Output:
 * 1 2 1 1
 *
 *
 *
 */


//----------------------------------

// Q4
/**
 *
 * (i > j) - (i < j);
 *
 * Tests:
 *
 * T1: i = 1, j = 2
 * (i > j) - (i < j) ---> 0 - 1 ---> -1
 *
 * T2: i = 2, j = 2
 * (i > j) - (i < j) ---> 0 - 0 ---> 0
 *
 * T3: i = 3, j = 2
 * (i > j) - (i < j) ---> 1 - 0 ---> 1
 *
 *
 */


//----------------------------------

// Q5
/**
 * The if statement is legal but it is not working as intended
 * Whatever the value of n, the condition will always be true
 *
 * Suppose n = 999
 *
 * (999 >= 1 <= 10) ---> (1 <= 10) ---> 1 (true)
 *
 * so if n is zero, the condition is still true and printf will execute
 *
 * but this holds true for all other values
 *
 * To fix this, this should be the condition:
 * if (n >= 1 && n <= 10)
 *
 *
 */


//----------------------------------

// Q6
/**
 * It's legal, but it does nothing as the condition is always
 * if (n == -9), so the printf will never execute
 *
 * If n is 5, still nothing happens
 *
 */



//----------------------------------

// Q7
/**
 * If i is 17, i will be printed as it is, hence 17
 * If i is -17, i will be negated then printed, hence 17 again
 *
 * This expression acts like the absolute value function in Mathematics
 *
 */


//----------------------------------

// Q8
/**
 *
 * teenager = (age >= 13 && age <= 19) ? true : false;
 *
 */


//----------------------------------

// Q9
/**
 *
 * The two statements are equivalent
 *
 */


//----------------------------------

// Q10
/**
 *
 * Since there are no break statements, case 1 statements any
 * subsequent case statements are executed, hence the output is:
 *
 * onetwo
 *
 */


//----------------------------------

// Q11
/*

switch (area_code)
{
	case 229:
		printf("Albany");
		break;
	case 404: case 470: case 678: case 770:
		printf("Atlanta");
		break;
	case 478:
		printf("Macon");
		break;
	case 706: case 762:
		printf("Columbus");
		break;
	case 912:
		printf("Savannah");
		break;
	default:
		printf("Area code not recognized");
		break;
}

*/

