// The Stack, Scope and Globals
#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

int get_age()
{
	return THE_AGE;
}

void set_age(int age)
{
	THE_AGE = age;
}

double update_ratio(double new_ratio)
{
	static double ratio = 1.0;

	double old_ratio = ratio;
	ratio = new_ratio;
	// this is fishy
	return old_ratio;
}

void print_size()
{
	log_info("I think size is %d", THE_SIZE);
}

// extern 
// This keyword is a way to tell the compiler "the variable exists, but
// it's in another 'external' location." Typically this means that one .c 
// file is going to use a variable that's been defined in another .c file.
// In this case, we're saying ex22.c has a variable THIS_SIZE that will
// be accessed from ex22_main.c

// static (file)
// This keyword is kind of the inverse of extern, and says that the variable
// is only used in this .c file and should not be available to other parts of
// the program. Keep in mind that *static* at the file level (as with 
// THE_AGE here) is different in other places.

// static (function)
// If you declare a variable in a function *static*, then that variable
// acts like a *static* defined in that file, but it's only accessible from
// that function. It's a way of creating constant state for a function, but
// in reality it's rarely used in modern C programming because they are hard
// to use with threads.
