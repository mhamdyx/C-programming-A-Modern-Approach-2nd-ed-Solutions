/*
 * line.h
 *
 *  Created on: Apr 8, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef LINE_H_
#define LINE_H_

/****************************************************************
 * clear_line: Clears the current line.                         *
 ****************************************************************/
void clear_line(void);

/****************************************************************
 * add_word: Adds word to the end of the current line.          *
 *           If this is not the first word on the line,         *
 *           puts on space before word.                         *
 ****************************************************************/
void add_word(const char *word);

/*********************************************************************************
 * space_remaining: Returns the number of characters left in the current line.   *
 *********************************************************************************/
int space_remaining(void);

/*********************************************************************************
 * write_line: Writes the current line with justification.                       *
 *********************************************************************************/
void write_line(void);

/*********************************************************************************
 * flush_line: Writes the current line without justification.                    *
 *********************************************************************************/
void flush_line(void);

#endif /* LINE_H_ */
