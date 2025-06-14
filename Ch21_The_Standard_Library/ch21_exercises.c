/*
 * ch21_exercises.c
 *
 *  Created on: May 23, 2020
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 * Depending on your OS and your toolchain
 *
 * If you are using windows, probably you are using MinGW, Cygwin, ...etc.
 * Default path: C:\<your_toolchain>\include
 *
 * Examples:
 * cygwin64: C:\cygwin64\usr\include
 * MinGW: C:\MinGW\include
 * mingw64: C:\mingw64\x86_64-w64-mingw32\include
 *
 * If you are using linux, you can locate gcc header files starting with
 * this path:
 * usr/include/
 *
 * When you browse to any of these locations, you know which headers
 * are standard, otherwise are non-standard and maybe platform-dependent.
 *
 * Whether you are using Windows and/or Linux, there are other locations
 * for header files, but this is dependent on one's installation of the
 * toolchains.
 *
 */

//----------------------------------

// Q2

/*
 * The answer to this question depends on the compiler you are using,
 * the version of the compiler, and the platform (your OS).
 *
 * First, try to locate where the c libraries are stored.
 * This is totally dependent on where you installed the compiler,
 * but if you used the default installation settings, check Q1 for ideas
 *
 * Second, open any header file (stdio.h as a suggestion), and then search
 * for macros (search keyword: #define), then when you spot a function name,
 * try to use that name as a search keyword to spot where the function
 * declaration is, then bingo! you found one.
 *
 * Here is an example I used many years ago when I installed MinGW on my
 * windows 10 machine:
 *
 * In <stdio.h> using windows and MinGW: 
 * The function getwc is hidden by a macro
 *
 * Line 775: wint_t __cdecl getwc(FILE *_File);
 * Line 866: #define getwc(_stm) fgetwc(_stm)
 *
 * Please note that the provided example may not be found for your case, so
 * it's better to work this question out by yourself using the provided
 * guidelines, good luck :)
 *
 */

//----------------------------------

// Q3

/*
 * The function prototype must always appear first for the declaration
 * to take effect later in the compilation process. If the macro was
 * to be added first, macro expansions would be done later (during the
 * pre-processing stage and before the compilation stage) to the
 * function declaration and syntax errors would arise.
 *
 */

//----------------------------------

// Q4

/*
 * The following names are grouped under individual headers for convenience.
 * All external names described below are reserved no matter what headers
 * are included by the program:
 *
 * - Complex arithmetic <complex.h>:
 * cerf    cerfc    cexp2    cexpm1    clog10    clog1p    clog2    clgamma    ctgamma
 *
 * and the same names suffixed with f or l may be added to the declarations
 * in the <complex.h> header.
 *
 *
 * - Character handling <ctype.h>:
 * > Function names that begin with either is or to, and a lowercase letter
 * may be added to the declarations in the <ctype.h> header.
 *
 *
 * - Errors <errno.h>:
 * > Macros that begin with E and a digit or E and an uppercase letter
 * may be added to the declarations in the <errno.h> header.
 *
 *
 * - Format conversion of integer types <inttypes.h>:
 * > Macro names beginning with PRI or SCN followed by any lowercase letter
 * or X may be added to the macros defined in the <inttypes.h> header.
 *
 *
 * - Localization <locale.h>:
 * > Macros that begin with LC_ and an uppercase letter may be added to the
 * definitions in the <locale.h> header.
 *
 *
 * - Signal handling <signal.h>:
 * > Macros that begin with either SIG and an uppercase letter or SIG_ and
 * an uppercase letter may be added to the definitions in the <signal.h> header.
 *
 *
 * - Boolean type and values <stdbool.h>:
 * > The ability to undefine and perhaps then redefine the macros bool, true,
 * and false is an obsolescent feature.
 *
 *
 * - Integer types <stdint.h>:
 * > Typedef names beginning with int or uint and ending with _t may be added
 * to the types defined in the <stdint.h> header. Macro names beginning with
 * INT or UINT and ending with _MAX, _MIN, or _C may be added to the macros
 * defined in the <stdint.h> header.
 *
 *
 * - Input/output <stdio.h>:
 * > Lowercase letters may be added to the conversion specifiers and length
 * modifiers in fprintf and fscanf. Other characters may be used in extensions.
 *
 * > The use of ungetc on a binary stream where the file position indicator
 * is zero prior to the call is an obsolescent feature.
 *
 *
 *
 * - General utilities <stdlib.h>:
 * > Function names that begin with str and a lowercase letter may be added to
 * the declarations in the <stdlib.h> header.
 *
 *
 * - String handling <string.h>:
 * > Function names that begin with str, mem, or wcs and a lowercase letter may be
 * added to the declarations in the <string.h> header.
 *
 *
 * - Extended multibyte and wide character utilities <wchar.h>:
 * > Function names that begin with wcs and a lowercase letter may be added to
 * the declarations in the <wchar.h> header.
 *
 * > Lowercase letters may be added to the conversion specifiers and length modifiers
 * in fwprintf and fwscanf. Other characters may be used in extensions.
 *
 *
 * - Wide character classification and mapping utilities <wctype.h>:
 * > Function names that begin with is or to and a lowercase letter may be added
 * to the declarations in the <wctype.h> header.
 *
 *
 */

//----------------------------------

// Q5

/*
 * Because according to the C standard, a parameterized macro that
 * substitutes for a library function must be "fully protected" by
 * parentheses and must evaluate its arguments exactly once.
 * While the given macro is fully protected by parentheses, it will
 * have to evaluate its argument twice which may lead to problems.
 *
 * For example: Imagine the situation when we call this macro with
 * an expression that has side effects
 *
 * islower(i++)
 *
 * This will be expanded to: ((i++) >= 'a' && (i++) <= 'z')
 * which is an undefined behavior.
 *
 */

//----------------------------------

// Q6

/*
 * a) Because these types of identifiers (beginning with underscore) are
 * reserved for use only within libraries and according to the C standard,
 * macros appearing in a standard header can't be redefined if the header
 * is included, so it's kind of restriction and protection to these macros.
 *
 *
 * b) _ctype array will contain a bit-field of length 8 bits (of type
 * char or unsigned char, doesn't matter since they are ANDed with
 * integers) corresponding to the properties of each character in
 * the ASCII character set. Each element in the array is indexed by the
 * ASCII value.
 *
 * Horizontal-tab character:
 * _ctype[9] = _CONTROL | _SPACE | _BLANK = 0x08 | 0x20 | 0x80
 *           = 0000_1000 | 0010_0000 | 1000_0000 = 1010_1000 = 0xA8 = 168
 *
 * Space character:
 * _ctype[32] = _SPACE | _BLANK = 0x20 | 0x80 = 0010_0000 | 1000_0000
 *            = 1010_0000 = 0xA0 = 160
 *
 * Letter A:
 * _ctype[65] = _UPPER = 0x01 = 1
 *
 * ^ character:
 * _ctype[94] = _PUNCT = 0x10 = 16
 *
 * Hint: To verify this answer, create a small program that calls the
 * ctype functions that properties of the character.
 *
 *
 *
 * c) Advantages:
 * 1) Performance: Fast searching as the array provides a random access
 * 2) Parameters are evaluated once (meeting the c standard conditions)
 *
 *
 */

//----------------------------------

// Q7

/*
 *
 * a) <time.h>
 *
 * b) <ctype.h>
 *
 * c) <limits.h>
 *
 * d) <math.h>
 *
 * e) <limits.h>
 *
 * f) <float.h>
 *
 * g) <string.h>
 *
 * h) <stdio.h>
 *
 *
 */
