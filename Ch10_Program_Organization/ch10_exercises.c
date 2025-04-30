/*
 * ch10_exercises.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1
/*
 *  a) The f function
 *  Variables : a (external), c (local)
 *  Parameters: b (local)
 *
 *  b) The g function
 *  Variables : a (external), d (local)
 *  Parameters: -
 *
 *  c) The block in which e is declared
 *  Variables : a (external), d (local to g), e (local)
 *  Parameters: -
 *
 *  d) The main function
 *  Variables : a (external), f (local)
 *  Parameters: -
 *
 */

//----------------------------------
// Q2
/*
 *  a) The f function
 *  Variables : c (external), b (local), d (local)
 *  Parameters: -
 *
 *  b) The g function
 *  Variables : b (external), c (local)
 *  Parameters: a (local)
 *
 *  c) The block in which a and d are declared
 *  Variables : b (external), c (local to g), a (local), d (local)
 *  Parameters: -
 *
 *  d) The main function
 *  Variables : b (external), c (local), d (local)
 *  Parameters: -
 *
 */

//----------------------------------
// Q3

/*
 * Given enough memory, there is no limit to the number of blocks
 * that can be defined in the main function that hence no limit to the
 * number of i's that can be created in these blocks (one per block).
 *
 * However, it's certain that there can be one external variable &
 * one local variable to the main function scope.
 *
 */
