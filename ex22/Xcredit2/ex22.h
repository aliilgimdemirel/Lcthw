#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
//extern 
extern int THE_SIZE;
int THE_NMBR;

// gets and sets an internal static variable in ex22.c 
int get_age();
void set_age(int age);

// updates a static varible that's inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif

// From Book
// the important thing to see here is the use of extern int THE_SIZE, which i'll explain after you create this matching ex22.c
