/*
 * word.h
 *
 *  Created on: Apr 8, 2020
 *      Author: Mahmoud Hamdy
 */

#ifndef WORD_H_
#define WORD_H_

/*********************************************************************************
 * read_word: Reads the next word from the input and stores it in word.          *
 *            Makes word empty if no word could be read because of end-of-file.  *
 * 			  Truncates the word if its length exceeds len.                      *
 *********************************************************************************/
void read_word(char *word, int len);


#endif /* WORD_H_ */
