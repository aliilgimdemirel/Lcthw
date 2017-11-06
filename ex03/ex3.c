#include <stdio.h>

int main()
{
	int age = 12; // if not set it is set automatically to 0;
	int height = 72;
	
	// %d is called format sequence.
	printf("I am %d years old.\n", age);
	
	// \n or \t are called escape sequence. 
	printf("I am %d inches tall.\n", height); 

	/*  Some escape sequences;
		\a 	07 	Alert (Beep, Bell) (added in C89)[1]
		\b 	08 	Backspace
		\f 	0C 	Formfeed
		\n 	0A 	Newline (Line Feed); see notes below
		\r 	0D 	Carriage Return
		\t 	09 	Horizontal Tab
		\v 	0B 	Vertical Tab
		\\ 	5C 	Backslash
		\' 	27 	Single quotation mark
		\" 	22 	Double quotation mark
		\? 	3F 	Question mark (used to avoid trigraphs)
	*/

	return 0;
}
