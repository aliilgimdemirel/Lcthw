#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double double_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char second_name[] = "Shaw";

	printf("You are %u miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", double_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a name %s.\n", first_name);
	printf("I have a second name %s.\n", second_name);
	printf("My whole name is %c. %s %s.\n", initial, first_name, second_name);
	
	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
	
	long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024;
	printf("The entire universe has %ld bugs.\n",universe_of_defects);
	
	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f of bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("This is only a %e portion of the universe.\n", part_of_universe);
	
	// this makes no sens, just a demo of something weird
	char nul_byte = '\0';
	
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_percentage);

	return 0;
}
