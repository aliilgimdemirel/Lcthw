// The Stack, Scope and Globals

#include "ex22.h"
#include "dbg.h"
#include <stdlib.h>

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
	log_info("count is: %d", count);

	if (count > 10) {
		static int count = 5; // BAD! BUGS!

		log_info("count is in this scope is %d", count);
		count += 850 ; // BAD! BUGS!
		log_info("count is in this scope is %d", count);
	}

	log_info("count is at exit: %d", count);

	count = 300 ; // BAD! BUGS!
	log_info("count after assign: %d", count);
}

void spy() { 
	int i = 0;
	int loop = 5;
	int x = 0;
	for (i = 0; i < loop*2; i++) {
		x = i - loop;
		if (x < 0) {
			printf("*(&(THE_SIZE)-%d) %d\n", abs(x), *(&(THE_SIZE)+x) );
		} else {
			printf("*(&(THE_SIZE)+%d) %d\n", x, *(&(THE_SIZE)+x) );
		}
	}
}

int main(int args, char *argv[])
{
	// test out THE_AGE accessors
	spy();
	*(&(THE_SIZE)+1) = 8;
	spy();
	log_info("My name: %s, age: %d", MY_NAME, get_age());
	
	set_age(100);

	log_info("My age is now: %d", get_age());

	// test out THE_SIZE extern
	log_info("THE_SIZE is :%d", THE_SIZE);
	print_size();
	
	THE_SIZE = 9;

	log_info("THE_SIZE is now:%d", THE_SIZE);
	print_size();
	
	// test the ratio function static
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once more: %f", update_ratio(300.0));

	//test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);
	//scope_demo(count * 25);
	//scope_demo(count * 50);

	log_info("count after calling scope_demo: %d", count);

	printf("From printf: THE_SIZE: %d\n", THE_SIZE);
	spy();

	return 0;
}
