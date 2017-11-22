#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

//int stack[8] = {};
//int stackptr = 0;


struct Stack {
	int *Array;
	int ArrayPos;
	int MAX_STACK_SIZE;
};

struct Connection {
	FILE *file;
	struct Stack *st;
};

void Close_stack(struct Connection *conn)
{
//  printf("Entering CLOSE\n"); // debug
    if (conn) {
        if (conn->file)
            fclose(conn->file);
        if (conn->st) {
            free(conn->st->Array);
            free(conn->st);
        }
        free(conn);
    }
//  printf("Exiting CLOSE\n"); // debug
}

void die(const char *message, struct Connection *conn)
{
//  printf("Entering DIE\n"); // debug
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    Close_stack(conn);

    exit(1);
//  printf("Exiting DIE\n"); // debug
}

void Load_stack(struct Connection *conn)
{
//	printf("Ent Load\n"); // debug
	rewind(conn->file);
	int i = 0;
	int rc = 0;

	rc = fread(&conn->st->ArrayPos, sizeof(int), 1, conn->file);
	if ( rc != 1)
		die("Failed to load Stack", conn);

	for (i = 0; i < conn->st->MAX_STACK_SIZE; i++) {
		rc = fread(conn->st->Array + i, sizeof(int), 1, conn->file);
		if ( rc != 1)
			die("Failed to load Stack", conn);
//		printf("Loaded Value is:%d\n", *(conn->st->Array + i) ); // debug
	}
//	printf("Ext Load\n"); // debug
}

struct Connection *Stack_open(char *filename, char *command, int MAX_STACK_SIZE )
{
	struct Connection *conn = malloc ( sizeof( struct Connection) );
    if (!conn)
         die("Memory error", conn);

	conn->st = malloc( sizeof(struct Stack) );
    if (!conn->st)
         die("Memory error", conn);

	conn->st->Array = malloc( sizeof(int ) * MAX_STACK_SIZE );
	conn->st->ArrayPos = 0;

	conn->st->MAX_STACK_SIZE = MAX_STACK_SIZE;

	if ( !strcmp(command, "create") ) {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
		if(conn->file) {
			Load_stack(conn);
		}
	}

	if (!conn->file)
	    die("Failed to open the file.\n", conn);

	return conn;
}

void Init_stack(struct Connection *conn)
{
	int i = 0;
	int length = conn->st->MAX_STACK_SIZE;

	for (i = 0; i < length; i++)
	{
		conn->st->Array[i] = 0;
	}
}

void Pop_stack(struct Connection *conn)
{
	if ( conn->st->ArrayPos == 0 ) {
		die("stack is empty, cannot pop", conn);
		return;
	}

	// Act of pop'ing is printf ! :D for now.
	conn->st->ArrayPos--;
	printf("content of popped element is: %d\n", conn->st->Array[conn->st->ArrayPos] );
	conn->st->Array[conn->st->ArrayPos] = 0;
}

void Push_stack(struct Connection *conn, int new_element)
{
//	printf("Ent Push\n"); // debug
	if ( conn->st->ArrayPos == 8) // 8 is the MAX_STACK_SIZE
	{
		die("stack is full cannot push more", conn);
		return ;
	}
	
	//stack[stackptr] = new_element;
	//stackptr++;
	//printf("content of pushed element is: %d\n", stack[stackptr-1]);

	conn->st->Array[conn->st->ArrayPos] = new_element;
	conn->st->ArrayPos++;
	printf("content of pushed element is: %d\n", conn->st->Array[conn->st->ArrayPos-1] );
//	printf("Ext Push\n"); // debug
}

void List_stack(struct Connection *conn)
{
	int i = 0;

	for (i = 0; i < conn->st->MAX_STACK_SIZE; i++)
	{
		printf("stack at pos:%d is:\t%d\n", i, *(conn->st->Array + i) ); 
		// printf("stack at pos:%d is:\t%d\n", i, conn->st->Array[conn->st->ArrayPos] ); // WHY NOT WORKING ??
		conn->st->ArrayPos++;
	}
}
//		printf("Loaded Value is:%d\n", *(conn->st->Array + i) );

void Write_stack(struct Connection *conn)
{
//	printf("Ent Write\n");
	rewind(conn->file);
	int i = 0;
	int rc = 0;

	rc = fwrite(&conn->st->ArrayPos, sizeof(int), 1, conn->file);
	if ( rc != 1)
	    die("Failed to load Stack", conn);


	for (i = 0; i < conn->st->MAX_STACK_SIZE; i++) {
        rc = fwrite(conn->st->Array + i, sizeof(int), 1, conn->file);
        if ( rc != 1)
            die("Failed to load Stack", conn);
    }
//	printf("Ext Write\n");
}

int main(int argc, char *argv[])
{	
	// MAX size of the stack
	// What kind of things I want to store in the stack ?
	// argv[1] > stack file
	// argv[2] > stack length
	// argv[3] > command // pop | push | list
	// argc[4] > command argument


	// What happens if there is an extra space in the command line arguements ?
	// lets see if it affects anything:

	//int i = 0;

	//for (i = 1; i <= argc; i ++) {
	//	printf("%s\n", argv[i]);
	//}
	
//	if ( argc > 2 ) {
//		char *command = argv[3];
//	} else {
//		printf("Without commands we're not going anywhere sorry.\n");
//		exit(1);
//	}
	
	char *command = argv[3];

	char *filename = argv[1];
	int MAX_STACK_SIZE = atoi( argv[2] );
	struct Connection *conn = Stack_open( filename, command, MAX_STACK_SIZE);

	if( !strcmp(command, "create") ) {
		Init_stack(conn);
		Write_stack(conn);
	} else if ( !strcmp(command, "pop") ){
		// do things
		Pop_stack(conn);
		Write_stack(conn);
	} else if ( !strcmp(command, "push") ){
		// do things
		if (argc == 5){
			// call pop
			int element = atoi( argv[4] );
			Push_stack(conn, element);
			Write_stack(conn);
		} else {
			printf("Need 4 arguments for Push operation!\n");
		}
	} else if ( !strcmp(command, "list") ){
		// do things
		List_stack(conn);
	} else {
			printf("No matching operation found for %s!\n", command);
	}

	Close_stack(conn);

	return 0;
}

