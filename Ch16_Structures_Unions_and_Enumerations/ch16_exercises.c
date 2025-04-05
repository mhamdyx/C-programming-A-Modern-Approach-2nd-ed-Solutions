/*
 * ch16_exercises.c
 *
 *  Created on: Mar 12, 2020
 *      Author: Mahmoud Hamdy
 */

// Q1

/*
 * Yes, actually they are both legal on either individual bases or being together
 * as the scope of their members is limited to the structure only so they are not
 * available to the outside (including the struct name).
 *
 */


//----------------------------------

// Q2

/*
 * a) struct { double real, imaginary; } c1, c2, c3;
 *
 * b) struct { double real, imaginary; } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
 *
 * c) This can be done in one statement: c1 = c2;
 *    It doesn't require two statements but still can also be written like this:
 *    c1.real = c2.real; c1.imaginary = c2.imaginary;
 *
 * d) c3.real = c1.real + c2.real;
 *    c3.imaginary = c1.imaginary + c2.imaginary;
 *
 */

// test script
/*
#include <stdio.h>

// a) + b)
struct { double real, imaginary; } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// c)
	c1 = c2;

	// d)
	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;

	// Note: comment c before testing d
	printf("c3 = %lf + %lf i\n", c3.real, c3.imaginary);

	return 0;
}
*/

//----------------------------------

// Q3 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

// a)
struct complex
{
	double real, imaginary;
};

// b)
struct complex c1, c2, c3;

// c)
struct complex make_complex(double real, double imaginary);

// d)
struct complex add_complex(struct complex c1, struct complex c2);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test 1
	c1 = make_complex(1.0, 2.0);
	c2 = make_complex(2.0, 1.0);

	c3 = add_complex(c1, c2);
	printf("c3 = %lf + %lf i\n", c3.real, c3.imaginary);

	return 0;
}

// c)
struct complex make_complex(double real, double imaginary)
{
	return (struct complex) {real, imaginary}; // c99
}

// d)
struct complex add_complex(struct complex c1, struct complex c2)
{
	return (struct complex) {c1.real + c2.real, c1.imaginary + c2.imaginary}; // c99
}
*/

//----------------------------------

// Q4 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

// a)
typedef struct
{
	double real, imaginary;
} Complex;

// b)
Complex c1, c2, c3;

// c)
Complex make_complex(double real, double imaginary);

// d)
Complex add_complex(Complex c1, Complex c2);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test 1
	c1 = make_complex(1.0, 2.0);
	c2 = make_complex(2.0, 1.0);

	c3 = add_complex(c1, c2);
	printf("c3 = %lf + %lf i\n", c3.real, c3.imaginary);

	return 0;
}

// c)
Complex make_complex(double real, double imaginary)
{
	return (Complex) {real, imaginary}; // c99
}

// d)
Complex add_complex(Complex c1, Complex c2)
{
	return (Complex) {c1.real + c2.real, c1.imaginary + c2.imaginary}; // c99
}
*/

//----------------------------------

// Q5 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

struct date
{
	int month, day, year;
};

// a)
int day_of_year(struct date d);

// b)
int compare_dates(struct date d1, struct date d2);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test 1
	struct date d1 = {3, 10, 2020};
	struct date d2 = {3, 10, 2020};
	struct date d3 = {5, 1, 2020}; // Black Widow release date (MCU fan detected :D)
	struct date d4 = {3, 10, 2019};

	// printing days
	printf("d1 = %d days\n", day_of_year(d1));
	printf("d2 = %d days\n", day_of_year(d2));
	printf("d3 = %d days\n", day_of_year(d3));
	printf("d4 = %d days\n", day_of_year(d4));
	printf("\n");

	// date comparison
	int compare_code = compare_dates(d1, d2);
	if(compare_code == 1)
	{
		printf("d1 comes after d2\n");
	}
	else if(compare_code == -1)
	{
		printf("d1 comes before d2\n");
	}
	else if(compare_code == 0)
	{
		printf("d1 and d2 are identical\n");
	}
	printf("\n");


	compare_code = compare_dates(d1, d3);
	if(compare_code == 1)
	{
		printf("d1 comes after d3\n");
	}
	else if(compare_code == -1)
	{
		printf("d1 comes before d3\n");
	}
	else if(compare_code == 0)
	{
		printf("d1 and d3 are identical\n");
	}
	printf("\n");


	compare_code = compare_dates(d1, d4);
	if(compare_code == 1)
	{
		printf("d1 comes after d4\n");
	}
	else if(compare_code == -1)
	{
		printf("d1 comes before d4\n");
	}
	else if(compare_code == 0)
	{
		printf("d1 and d4 are identical\n");
	}
	printf("\n");


	return 0;
}

int day_of_year(struct date d)
{
	int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Detect Leap year
	if(!(d.year % 400) || (!(d.year % 4) && (d.year % 100)))
	{
		days_month[1] = 29;
	}

	int total_days = d.day;

	while(d.month-- > 1)
	{
		total_days += days_month[d.month - 1];
	}

	return total_days;
}


int compare_dates(struct date d1, struct date d2)
{
	if(d1.year > d2.year)
		return 1;
	else if(d1.year < d2.year)
		return -1;
	else
	{
		if(d1.month > d2.month)
			return 1;
		else if(d1.month < d2.month)
			return -1;
		else
		{
			if(d1.day > d2.day)
				return 1;
			else if(d1.day < d2.day)
				return -1;
		}
	}

	return 0;
}
*/

//----------------------------------

// Q6 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

struct time
{
	int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test
	struct time t1 = split_time(9600);
	struct time t2 = split_time(11500);
	struct time t3 = split_time(65556);

	printf("t1 = %02d:%02d:%02d\n", t1.hours, t1.minutes, t1.seconds);
	printf("t2 = %02d:%02d:%02d\n", t2.hours, t2.minutes, t2.seconds);
	printf("t3 = %02d:%02d:%02d\n", t3.hours, t3.minutes, t3.seconds);

	return 0;
}

struct time split_time(long total_seconds)
{
	struct time t;

	t.hours = total_seconds / 3600;
	total_seconds %= 3600;
	t.minutes = total_seconds / 60;
	t.seconds = total_seconds % 60;

	return t;
}
*/

//----------------------------------

// Q7 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

struct fraction
{
	int numerator, denomenator;
};

// a)
int gcd(int a, int b);
struct fraction simplify(struct fraction f);

// b)
struct fraction add(struct fraction f1, struct fraction f2);

// c)
struct fraction subtract(struct fraction f1, struct fraction f2);

// d)
struct fraction multiply(struct fraction f1, struct fraction f2);

// e)
struct fraction divide(struct fraction f1, struct fraction f2);



int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test
	struct fraction f1 = {1, 2}, f2 = {3, 4}, f3 = {9, 6}, f4;

	f4 = simplify(f3);
	printf("%d/%d = %d/%d\n", f3.numerator, f3.denomenator, f4.numerator, f4.denomenator);

	f4 = add(f1, f2);
	printf("%d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denomenator,
			f2.numerator, f2.denomenator, f4.numerator, f4.denomenator);

	f4 = subtract(f3, f1);
	printf("%d/%d - %d/%d = %d/%d\n", f3.numerator, f3.denomenator,
				f1.numerator, f1.denomenator, f4.numerator, f4.denomenator);

	f4 = subtract(f1, f3);
	printf("%d/%d - %d/%d = %d/%d\n", f1.numerator, f1.denomenator,
				f3.numerator, f3.denomenator, f4.numerator, f4.denomenator);

	f4 = multiply(f2, f3);
	printf("%d/%d * %d/%d = %d/%d\n", f2.numerator, f2.denomenator,
				f3.numerator, f3.denomenator, f4.numerator, f4.denomenator);

	f4 = divide(f2, f3);
	printf("%d/%d / %d/%d = %d/%d\n", f2.numerator, f2.denomenator,
				f3.numerator, f3.denomenator, f4.numerator, f4.denomenator);


	return 0;
}

// a)

int gcd(int a, int b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}

struct fraction simplify(struct fraction f)
{
	int com_factor = gcd(f.numerator, f.denomenator);
	f.numerator /= com_factor;
	f.denomenator /= com_factor;

	return f;
}

// b)
struct fraction add(struct fraction f1, struct fraction f2)
{
	struct fraction f;
	f.denomenator = f1.denomenator * f2.denomenator;
	f.numerator = f1.numerator * f2.denomenator + f2.numerator * f1.denomenator;

	return simplify(f);
}

// c)
struct fraction subtract(struct fraction f1, struct fraction f2)
{
	f2.numerator *= -1;
	struct fraction f = add(f1, f2);

	return simplify(f);
}

// d)
struct fraction multiply(struct fraction f1, struct fraction f2)
{
	struct fraction f = {f1.numerator * f2.numerator, f1.denomenator * f2.denomenator};

	return simplify(f);
}

// e)
struct fraction divide(struct fraction f1, struct fraction f2)
{
	struct fraction f = {f1.numerator * f2.denomenator, f1.denomenator * f2.numerator};

	return simplify(f);
}
*/

//----------------------------------

// Q8

/*
 * a) struct color MAGNETA = {255, 0, 255};
 *
 * b) struct color MAGNETA = {.red = 255, .blue = 255};
 *
 */

//----------------------------------

// Q9 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>
#include <stdbool.h>

struct color
{
	int red;
	int green;
	int blue;
};

// a)
struct color make_color(int red, int green, int blue);

// b)
int getRed(struct color c);

// c)
bool equal_color(struct color color1, struct color color2);

// d)
struct color brighter(struct color c);

// e)
struct color darker(struct color c);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test
	struct color c1, c2, c3, c4, c5, c6, c7, br_c4, br_c7, dk_c5;

	// a)
	c1 = make_color(255, 0, 0); // red
	c2 = make_color(0, 255, 0); // green
	c3 = make_color(0, 0, 255); // blue
	c4 = make_color(0, 0, 0); // black
	c5 = make_color(255, 255, 255); // white
	c6 = make_color(255, 255, 255); // white
	c7 = make_color(2, 200, 25);

	// b)
	printf("red in c1 = %d\n", getRed(c1));
	printf("red in c2 = %d\n", getRed(c2));
	printf("\n");

	// c)
	printf("c3 & c4 are %s colors\n", equal_color(c3, c4) ? "equal" : "different");
	printf("c5 & c6 are %s colors\n", equal_color(c5, c6) ? "equal" : "different");
	printf("\n");

	// d)
	br_c4 = brighter(c4);
	printf("original c4 = (%d, %d, %d)\n", c4.red, c4.green, c4.blue);
	printf("brighter c4 = (%d, %d, %d)\n", br_c4.red, br_c4.green, br_c4.blue);
	printf("\n");
	br_c7 = brighter(c7);
	printf("original c7 = (%d, %d, %d)\n", c7.red, c7.green, c7.blue);
	printf("brighter c7 = (%d, %d, %d)\n", br_c7.red, br_c7.green, br_c7.blue);
	printf("\n");

	// e)
	dk_c5 = darker(c5);
	printf("original c5 = (%d, %d, %d)\n", c5.red, c5.green, c5.blue);
	printf("darker c5 = (%d, %d, %d)\n", dk_c5.red, dk_c5.green, dk_c5.blue);
	printf("\n");



	return 0;
}

// a)
struct color make_color(int red, int green, int blue)
{
	struct color c;
	c.red = red > 0 ? (red > 255 ? 255 : red) : 0;
	c.green = green > 0 ? (green > 255 ? 255 : green) : 0;
	c.blue = blue > 0 ? (blue > 255 ? 255 : blue) : 0;

	return c;
}

// b)
int getRed(struct color c)
{
	return c.red;
}

// c)
bool equal_color(struct color color1, struct color color2)
{
	if(color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue)
	{
		return true;
	}

	return false;
}

// d)
struct color brighter(struct color c)
{
	if(!c.red && !c.green && !c.blue)
	{
		c.red = c.green = c.blue = 3;
	}
	else
	{
		// (179+ / 0.7) > 255
		c.red = c.red > 0 && c.red < 3 ? 3 / 0.7 : (c.red > 178 ? 255 : c.red / 0.7);
		c.green = c.green > 0 && c.green < 3 ? 3 / 0.7 : (c.green > 178 ? 255 : c.green / 0.7);
		c.blue = c.blue > 0 && c.blue < 3 ? 3 / 0.7 : (c.blue > 178 ? 255 : c.blue / 0.7);
	}

	return c;
}

// e)
struct color darker(struct color c)
{
	c.red *= 0.7;
	c.green *= 0.7;
	c.blue *= 0.7;

	return c;
}
*/

//----------------------------------

// Q10 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>
#include <stdbool.h>

// given
struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

// a)
int area_rect(struct rectangle r);

// b)
struct point center_rect(struct rectangle r);

// c)
struct rectangle move_rect(struct rectangle r, int x, int y);

// d)
bool belong_to_rect(struct rectangle r, struct point p);


int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test (rectangle of length = 8, width = 6 and lies on the 1st quad)
	struct point UL = {0, 6}, LR = {8, 0}, cp, p1, p2;

	struct rectangle r = {UL, LR}, r_dash;

	int x, y;

	// a)
	printf("Area of rectangle = %d squared unit length\n\n", area_rect(r));

	// b)
	cp = center_rect(r);
	printf("Center of rectangle r = (%d, %d)\n\n", cp.x, cp.y);

	// c)
	x = 2;
	y = 2;
	r_dash = move_rect(r, x, y);
	printf("After moving r %d units in x-direction and %d units in y-direction:\n", x, y);
	printf("Old coordinates of r = (%d, %d), (%d, %d)\nNew coordinates of r = "
			"(%d, %d), (%d, %d)\n\n", r.upper_left.x, r.upper_left.y, r.lower_right.x,
			r.lower_right.y, r_dash.upper_left.x, r_dash.upper_left.y,
			r_dash.lower_right.x, r_dash.lower_right.y);


	// d)
	p1.x = 0;
	p1.y = 0;
	p2.x = 9;
	p2.y = 6;
	printf("p1 %s belong to rectangle r\n", belong_to_rect(r, p1) ? "does" : "does not");
	printf("p2 %s belong to rectangle r\n", belong_to_rect(r, p2) ? "does" : "does not");


	return 0;
}

// a)
int area_rect(struct rectangle r)
{
	return (r.lower_right.x - r.upper_left.x) * (r.upper_left.y - r.lower_right.y);
}

// b)
struct point center_rect(struct rectangle r)
{
	return (struct point) {(r.upper_left.x + r.lower_right.x) / 2,
	(r.lower_right.y + r.upper_left.y) / 2};
}

// c)
struct rectangle move_rect(struct rectangle r, int x, int y)
{
	return (struct rectangle) {(struct point) {r.upper_left.x + x, r.upper_left.y + y},
		(struct point) {r.lower_right.x + x, r.lower_right.y + y}};
}

// d)
bool belong_to_rect(struct rectangle r, struct point p)
{
	return (p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
			p.y >= r.lower_right.y && p.y <= r.upper_left.y);
}
*/

//----------------------------------

// Q11
/*
 * Assuming no holes:
 * Space = double size + union size + char[4] size
 *       = 8 + max(char[4] size, double size, int size) + 4
 *       = 12 + double size = 12 + 8 = 20 bytes
 *
 * Maximum size for a union member is allocated to the union that's why I wrote max()
 *
 */

//----------------------------------

// Q12
/*
 * Assuming no holes:
 * Space = max(double size, struct size, char[4] size)
 *       = max(8, char[4] size + double size + int size, 4)
 *       = max(8, 4 + 8 + 4, 4) = max(8, 16, 4) = 16
 *
 * The compiler will allocate space to cover the member with the max size
 *
 */

//----------------------------------

// Q13
/*
 * a) s.shape_kind = RECTANGLE; ---> legal
 *
 * b) s.center.x = 10; ---> legal
 *
 * c) s.height = 25; ---> illegal
 * 	  Correction ---> s.u.rectangle.height = 25;
 *
 * d) s.u.rectangle.width = 8; ---> legal
 *
 * e) s.u.circle = 5; ---> illegal
 *    Correction ---> s.u.circle.radius = 5;
 *
 * f) s.u.radius = 5; ---> illegal
 *    Correction ---> s.u.circle.radius = 5;
 *
 */

//----------------------------------

// Q14 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

#define RECTANGLE 1
#define CIRCLE 2
#define PI 3.14159

struct point { int x, y; };

struct shape
{
	int shape_kind;
	struct point center;

	union
	{
		struct { int height, width; } rectangle;

		struct { int radius; } circle;
	} u;
};

// a)
double area_shape(struct shape s);

// b)
struct shape move_shape(struct shape s, int x, int y);

// c)
struct shape scale_shape(struct shape s, double scale);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test
	struct shape r, c;

	r.shape_kind = RECTANGLE;
	r.center = (struct point) {4, 3};
	r.u.rectangle.width = 8;
	r.u.rectangle.height = 6;

	c.shape_kind = CIRCLE;
	c.center = (struct point) {0, 0};
	c.u.circle.radius = 5;

	// a)
	printf("Area of rectangle = %lf\n\n", area_shape(r));
	printf("Area of circle = %lf\n\n", area_shape(c));

	// b)
	r = move_shape(r, 2, 2);
	printf("Now the center of the rectangle is (%d, %d)\n\n", r.center.x, r.center.y);

	// c)
	c = scale_shape(c, 2);
	printf("Now the radius of the circle is %d\n\n", c.u.circle.radius);


	return 0;
}

// a)
double area_shape(struct shape s)
{
	double area = 0.0; // Indication that shape_kind is not even set

	if(s.shape_kind == RECTANGLE)
	{
		area = s.u.rectangle.height * s.u.rectangle.width;
	}
	else if(s.shape_kind == CIRCLE)
	{
		area = PI * s.u.circle.radius * s.u.circle.radius;
	}

	return area;
}

// b)
struct shape move_shape(struct shape s, int x, int y)
{
	s.center.x += x;
	s.center.y += y;
	return s;
}

// c)
struct shape scale_shape(struct shape s, double scale)
{
	if(s.shape_kind == RECTANGLE)
	{
		s.u.rectangle.height *= scale;
		s.u.rectangle.width *= scale;
	}
	else if(s.shape_kind == CIRCLE)
	{
		s.u.circle.radius *= scale;
	}

	return s;
}
*/

//----------------------------------

// Q15
/*
 * a) enum week_days {SATURDAY, SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};
 *
 * b) typedef enum
 *    {
 *    	SATURDAY, SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY
 *    } week_days;
 *
 */

//----------------------------------

// Q16
/*
 * a) true
 *
 * b) false --> 1) They have block scope not global scope
 *              2) They are not replaced by the preprocessor hence appear in debugging
 *
 * c) true
 *
 * d) false --> Same values are allowed
 *
 * e) true
 *
 */

//----------------------------------

// Q17
/*
 * a) legal and safe
 *
 * b) legal but not safe ---> b won't have a meaningful value if i's value is neither 0 nor 1
 *
 * c) legal but not safe ---> b won't have a meaningful value if b originally was 1 (TRUE)
 *
 * d) legal and safe
 *
 * e) legal and safe
 *
 */

//----------------------------------

// Q18
/*
// a)
typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {BLACK, WHITE} Color;

// b)
typedef struct
{
	Piece piece;
	Color color;
} Square;

// c) and d)
Square board[8][8] =
{
		{{ROOK, BLACK}, {KNIGHT, WHITE}, {BISHOP, BLACK}, {QUEEN, WHITE},
		 {KING, BLACK}, {BISHOP, WHITE}, {KNIGHT, BLACK}, {ROOK, WHITE}},
		{{PAWN, WHITE}, {PAWN, BLACK}, {PAWN, WHITE}, {PAWN, BLACK},
		 {PAWN, WHITE}, {PAWN, BLACK}, {PAWN, WHITE}, {PAWN, BLACK}},
		{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
		 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
		{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
		 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
		{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
		 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
		{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
		 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
		{{PAWN, BLACK}, {PAWN, WHITE}, {PAWN, BLACK}, {PAWN, WHITE},
		 {PAWN, BLACK}, {PAWN, WHITE}, {PAWN, BLACK}, {PAWN, WHITE}},
		{{ROOK, WHITE}, {KNIGHT, BLACK}, {BISHOP, WHITE}, {QUEEN, BLACK},
		 {KING, WHITE}, {BISHOP, BLACK}, {KNIGHT, WHITE}, {ROOK, BLACK}}
};
*/

//----------------------------------

// Q19
/*
#define NAME_LEN 40

struct pinball_machine
{
	char name[NAME_LEN + 1];
	int year;
	enum {EM, SS} type;
	int players;
};
*/

//----------------------------------

// Q20 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

enum {NORTH, SOUTH, EAST, WEST} direction;

void update_coordinates(void);
int x = 0, y = 0;

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// test (goal: achieve coordinates(4, 3))
	direction = EAST;
	update_coordinates();
	update_coordinates();
	update_coordinates();
	update_coordinates();
	direction = NORTH;
	update_coordinates();
	update_coordinates();
	update_coordinates();

	printf("Current coordinates: (%d, %d)\n", x, y);

	return 0;
}

void update_coordinates(void)
{
	// Required statement
	switch(direction)
	{
	case NORTH: y++; break;
	case SOUTH: y--; break;
	case EAST: x++; break;
	case WEST: x--; break;
	}
}
*/

//----------------------------------

// Q21
/*
 * a) NUL = 0, SOH = 1, STX = 2, ETX = 3
 *
 * b) VT = 11, FF = 12, CR = 13
 *
 * c) SO = 14, SI = 15, DLE = 16, CAN = 24, EM = 25
 *
 * d) ENQ = 45, ACK = 46, BEL = 47, LF = 37, ETB = 38, ESC = 39
 *
 */

//----------------------------------

// Q22 + Test scripts (rolled into one for better understanding)
/*
#include <stdio.h>

enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

// a)
//const int piece_value[] = {200, 9, 5, 3, 3, 1};

// b)
const int piece_value[] =
{
		[KING] = 200, [QUEEN] = 9, [ROOK] = 5, [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1
};


int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int i;
	for(i = 0; i < 6; i++)
		printf("piece_value[%d] = %d\n", i, piece_value[i]);

	return 0;
}
*/
