/*
 * ch13_exercises.c
 *
 *  Created on: Dec 17, 2019
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 * b) printf("%c", "\n"): will not work as %c expects the 2nd argument to be a char not a char*
 *
 * c) printf("%s", '\n'): will not work as %s expects a string not a char
 *
 * e) printf('\n'): will not work as printf expects a string literal as the 1st argument
 *
 * h) putchar("\n"): will not work as putchar expects a char (int tbh) not a string
 *
 * i) puts('\n'): will not work as puts expects a string not a char
 *
 * j) puts("\n"): will work actually but ends up printing two new-line characters not one
 *
 */

//----------------------------------

// Q2

/*
 * a) putchar(p): illegal as putchar expects a char (int tbh) not a char*
 *
 * b) putchar(*p): legal, output: a
 *
 * c) puts(p): legal, output: abc\n
 *
 * d) puts(*p): illegal as puts expects a char* not a char
 *
 */

//----------------------------------

// Q3

/*
 * i = 12
 * s = abc34
 * j = 56
 *
 * scanf will stop adding to string s when it encounters a white-space and then
 * starts looking for a numerical value to be assigned to j
 *
 */

//----------------------------------

// Q4

// Uncomment this section to test any function
/*
#include <stdio.h>
#include <ctype.h>
#define STR_LEN 12
*/

// Original version
/*
int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;

	str[i] = '\0';

	return i; // number of characters stored
}
*/

// a) skips white space before storing input characters
/*
int read_line(char str[], int n)
{
	int ch, i = 0;
	while (isspace(ch = getchar())); // skip leading white space

	do
	{
		if (i < n)
			str[i++] = ch;
	} while ((ch = getchar()) != '\n');

	str[i] = '\0';

	return i; // number of characters stored
}
*/

// b) Stops reading at the first white-space character
/*
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (!isspace(ch = getchar()))
		if (i < n)
			str[i++] = ch;

	str[i] = '\0';

	return i; // number of characters stored
}
*/

// c) Stops reading at the first new-line character and stores it in the string
/*
int read_line(char str[], int n)
{
	int ch, i = 0;

	do
	{
		ch = getchar();

		if (i < n)
			str[i++] = ch;
	} while (ch != '\n');

	str[i] = '\0';

	return i; // number of characters stored
}
*/

// d) Leaves behind characters that it doesn't have room to store
// We will flip the two conditions in the while and the if statements
// This way, we make sure we leave behind the next character to be read
// without dropping it if the string can not hold it
// Example Input: Mahmoud
// STR_LEN is 4
// Original behavior: str content: "Mahm", dropped ch: 'o', remaining: "ud"
// d's behavior: str content: "Mahm", no dropped ch, remaining: "oud"
/*
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (i < n)
 		if ((ch = getchar()) != '\n')
 			str[i++] = ch;

 	str[i] = '\0';

 	return i; // number of characters stored
}
*/

// test script: uncomment this along with the chosen version to be tested
/*
int main(void)
{
	char s[STR_LEN + 1];
	int str_len;

	printf("Enter string: ");

	// Uncomment the function definition of one version and comment the others
	str_len = read_line(s, STR_LEN);

	printf("You entered: %s\nLength = %d\n", s, str_len);

	return 0;
}
*/

//----------------------------------

// Q5

// Uncomment this section to test any function
//#include <stdio.h>
//#include <ctype.h>

// Accessing the characters:
// a) using array subscripting
/*
void capitalize(char str[])
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
}
*/

// b) using pointer arithmetic
/*
void capitalize(char *p_str)
{
	for (; *p_str != '\0'; p_str++)
		*p_str = toupper(*p_str);
}
*/

// test script
/*
int main(void)
{
	char str1[] = "Rias Gremory"; // test1
	char str2[] = "RIAS GREMORY"; // test2
	char str3[] = "rias gremory"; // test3

	// Uncomment the function definition of one version and comment the other
	capitalize(str1);
	capitalize(str2);
	capitalize(str3);

	// Print the result
	printf("str1 now = %s\nstr2 now = %s\nstr3 now = %s\n", str1, str2, str3);

	return 0;
}
*/

//----------------------------------

// Q6

/*
#include <stdio.h>
#include <string.h>

void censor(char str[], int len)
{
	int i = 0;

	while (i + 2 < len)
	{
		// or if (str[i] == 'f' && str[i + 1] = 'o' && str[i + 2] = 'o')
		if (!strncmp(str, "foo", 3))
		{
			str[i] = str[i + 1] = str[i + 2] = 'x';
			i += 3;
		}
		else
			i++;
	}
}
*/

// test script
/*
#include <stdio.h>
int main(void)
{
	char str1[] = "food fool";
	char str2[] = "for god sake";
	char str3[] = "fooooooooooo";
	censor(str1, strlen(str1));
	censor(str2, strlen(str2));
	censor(str3, strlen(str3));

	printf("After censoring:\nstr1 = %s\nstr2 = %s\nstr3 = %s\n", str1, str2, str3);

	return 0;
}
*/

//----------------------------------

// Q7

// (d) is different as it's just concatenate a null character to the existent string

//----------------------------------

// Q8

/*
 * strcpy(str, "tire-bouchon"); // str = "tire-bouchon"
 *
 * strcpy(&str[4], "d-or-wi");  // str = "tired-or-wi"
 *
 * strcat(str, "red?");         // str = "tired-or-wired?"
 *
 */

//----------------------------------

// Q9

/*
 * strcpy(s1, "computer"); // s1 = "computer"
 *
 * strcpy(s2, "science");  // s2 = "science"
 *
 * if(strcmp(s1, s2) < 0)  // true
 *
 * strcat(s1, s2);         // s1 = "computerscience"
 *
 * s1[strlen(s1) - 6] = '\0';  // = s1[15 - 6] = s1[9] = '\0'
 *
 * so s1 = "computers"
 *
 */

//----------------------------------

// Q10

/*
 * We can not copy the string pointed by p to q because q has undefined value 
 * hence unknown area in memory. 
 * 
 * So, this is considered as undefined behaviour with unpredictable results
 *
 */

//----------------------------------

// Q11
/*
// Function + Test script
#include <stdio.h>

int strcmp(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if(!*s)
			return 0;

	return *s - *t;
}

int main(void)
{
	char *s1 = "Dark Magician";
	char *s2 = "Dark Magician";
	char *s3 = "Blue-eyes White Dragon";
	char *s4 = "Red-eyes Black Dragon";

	printf("s1 = %s\ns2 = %s\ns3 = %s\ns4 = %s\n", s1, s2, s3, s4);
	printf("s1 & s2 are %s\n", (strcmp(s1, s2) == 0) ? "similar" : "different");
	printf("s3 & s4 are %s\n", (strcmp(s3, s4) == 0) ? "similar" : "different");

	return 0;
}
*/


//----------------------------------

// Q12
/*
// Function + Test script
#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension)
{
	const char *ptr_ext; // pointer to the extension of the last dot in the file

	for (ptr_ext = file_name; *file_name; file_name++)
		if (*file_name == '.')
			ptr_ext = file_name;

	if (*ptr_ext == '.')
		strcpy(extension, ptr_ext + 1);
	else
		strcpy(extension, "");
}

int main(void)
{
	char *f1 = "Mortal Kombat.exe", ext1[strlen(f1)];
	char *f2 = "Dark.Magician.jpg", ext2[strlen(f2)]; // That's why we added dots variable
	char *f3 = "Makefile", ext3[strlen(f3)];

	// Finding extension
	get_extension(f1, ext1);
	get_extension(f2, ext2);
	get_extension(f3, ext3);

	printf("Extension of \"%s\": %s\n", f1, (*ext1) ? ext1 : "no extension");
	printf("Extension of \"%s\": %s\n", f2, (*ext2) ? ext2 : "no extension");
	printf("Extension of \"%s\": %s\n", f3, (*ext3) ? ext3 : "no extension");

	return 0;
}
*/

//----------------------------------

// Q13
/*
// Function + Test script
#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url)
{
	strcat(strcat(strcpy(index_url, "http://www."), domain), "/index.html");
}

int main(void)
{
	char *domain = "knking.com";
	char index_url[50];

	build_index_url(domain, index_url);

	printf("%s", index_url);

	return 0;
}
*/

//----------------------------------

// Q14

// Hsjodi ---> ('H' - 1)('s' - 1)('j' - 1)('o' - 1)('d' - 1)('i' - 1)

// puts(s) = printf("Grinch\n");

// Output: Grinch followed by new-line character

//----------------------------------

// Q15

/*
 * a) 3
 *
 * b) 0
 *
 * c) Finds the first number of characters in s having matches in t
 *
 */

//----------------------------------

// Q16
/*
// Function + Test script
#include <stdio.h>
#include <string.h>

int count_spaces(const char *s)
{
	int count = 0;

	while (*s)
		if (*s++ == ' ')
			count++;

	return count;
}

int main(void)
{
	char *s1 = "No pain no gain"; // spaces = 3
	char *s2 = "Not all who wonder are lost"; // spaces = 5

	printf("Spaces in s1 = %d\nSpaces in s2 = %d\n", count_spaces(s1), count_spaces(s2));

	return 0;
}
*/

//----------------------------------

// Q17
/*
// Function + Test script
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool test_extension(const char *file_name, char *extension)
{
	const char *ptr_ext; // pointer to the extension of the last dot in the file

	for (ptr_ext = file_name; *file_name; file_name++)
		if (*file_name == '.')
			ptr_ext = file_name;

	if (*ptr_ext != '.') // check if file has no extension to begin with
		return false;

	for (ptr_ext++; toupper(*ptr_ext) == toupper(*extension); ptr_ext++, extension++)
		if (!*ptr_ext)
			break;

	return (*ptr_ext - *extension == 0 ? true : false);
}

int main(void)
{
	char *f1 = "Mortal Combat.exe", *ext1 = "ExE";
	char *f2 = "Dark.Magician.jpg", *ext2 = "jpg";
	char *f3 = "Makefile", *ext3 = "sh";
	char *f4 = "Blue-eyes White Dragon.png", *ext4 = "bmp";

	printf("Test of \"%s\" %s\n", f1, test_extension(f1, ext1) ? "succeeds" : "fails");
	printf("Test of \"%s\" %s\n", f2, test_extension(f2, ext2) ? "succeeds" : "fails");
	printf("Test of \"%s\" %s\n", f3, test_extension(f3, ext3) ? "succeeds" : "fails");
	printf("Test of \"%s\" %s\n", f4, test_extension(f4, ext4) ? "succeeds" : "fails");

	return 0;
}
*/

//----------------------------------

// Q18
/*
// Function + Test script
#include <stdio.h>
#include <string.h>

void remove_filename(char *url)
{
	char *last_slash;

	for(; *url; url++)
		if (*url == '/')
			last_slash = url;

	*last_slash = 0;
}

int main(void)
{
	char url1[] = "http://www.knking.com/index.html";
	char url2[] = "https://www.github.com/mhamdyx";
	char url3[] = "https://github.com/mhamdyx/b7b_el_cima/blob/master/README.md";

	remove_filename(url1);
	remove_filename(url2);
	remove_filename(url3);

	printf("URL1 now is %s\nURL2 now is %s\nURL3 now is %s\n", url1, url2, url3);

	return 0;
}
*/
