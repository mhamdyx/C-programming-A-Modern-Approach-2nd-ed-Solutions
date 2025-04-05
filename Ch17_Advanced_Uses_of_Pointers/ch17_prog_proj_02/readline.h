/*
 * readline.h
 *
 *  Created on: Apr 7, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef READLINE_H_
#define READLINE_H_

/************************************************************
 * read_line: Skips leading white-space characters, then    *
 *            reads the remainder of the input line and     *
 *            stores it in str. Truncates the line if its   *
 *            length exceeds n. Returns the number of       *
 *            characters stored                             *
 *                                                          *
 ************************************************************/

int read_line(char str[], int n);

#endif /* READLINE_H_ */
