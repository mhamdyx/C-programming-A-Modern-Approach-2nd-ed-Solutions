/*
 * readline.h
 *
 *  Created on: Aug 6, 2025
 *      Author: Mahmoud Hamdy
 */


#ifndef READLINE_H_
#define READLINE_H_

/**********************************************************
 * read_line: Skips leading white-space characters, then  *
 *            reads the remainder of the input line and   *
 *            stores it in str. Truncates the line if its *
 *            length exceeds n. Returns the number of     *
 *            characters stored.                          *
 **********************************************************/
int read_line(char str[], int n);

#endif /* READLINE_H_ */
