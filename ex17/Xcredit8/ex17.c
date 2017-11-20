#include <stdio.h>


int stack[8] = {};
int stackptr = 0;

void Init_stack()
{
	int i = 0;
	int length = sizeof(stack) / sizeof(int);
	int loop_length = length;
	for (i = 0; i < loop_length; i++)
	{
		stack[i] = 0;
	}
}


void Pop_stack()
{
	if (stackptr == 0)
	{
		printf("stack is empty, cannot pop\n");
		return;
	}

	stackptr--;
	// Act of pop'ing is printf ! :D for now.
	printf("content of popped element is: %d\n", stack[stackptr]);
	stack[stackptr] = 0;
}

void Push_stack(int new_element)
{
	if (stackptr == 8) // 8 is the MAX_STACK_SIZE
	{
		printf("stack is full cannot push more\n");
		return ;
	}
	
	stack[stackptr] = new_element;
	stackptr++;
	printf("content of pushed element is: %d\n", stack[stackptr-1]);
}

void List_stack()
{
	int i = 0;
	int length = sizeof(stack) / sizeof(int);
	int loop_length = length;
	for (i = 0; i < loop_length; i++)
	{
		printf("stack at pos:%d is:\t%d\n", i, stack[i]);
	}
}

int main(int argc, char *argv[])
{	
	// MAX size of the stack
	// What kind of things I want to store in the stack ?

	Init_stack();
	List_stack();
	Push_stack(5);
	Push_stack(237298374);
	List_stack();
	Push_stack(89);
	Push_stack(2013);
	List_stack();
	Pop_stack();	
	List_stack();

	Pop_stack();	
	Pop_stack();	
	Pop_stack();	
	Pop_stack();	
	Pop_stack();	
	List_stack();

	return 0;
}

