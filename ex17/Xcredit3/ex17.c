// TODO LIST
// [Postponed ]1- make DEBUG option // Will come after 2 more exercises.
// [DONE] 2- solve the create/intialization thing
// [DONE] 3- Make the python/bash script
// [DONE] 4- Need to write to the DB what MAX_ROWS & MAX_DATA it is using,
// and devise a control b4 loading or writing. 
// TODO LIST

//Heap and Stack Memory Allocation

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//#define MAX_DATA 512
//#define MAX_ROWS 100

#ifdef DEBUG
#define DEBUG
#endif

// As for Xcredit2 MAX_ROWS & MAX_DATA are now variable
// There is no way to predetermine the sizes of name and email
// arrays. Thus we cannot preemptively create them because we cannot dedicated
// a "space" for them. 
// Thus we are using pointers as vassals to their positions.
// So we're making them a "ptr to a char array"
struct Address {
	int id;
	int set;
	char *name;
	char *email;
};

struct Database {
	int MAX_ROWS;
	int MAX_DATA;
	struct Address **rows; // there is 2 level of indirection to the struct Address.
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn)
{
// 	printf("Entering CLOSE\n"); // debug
	if (conn) {
		if (conn->file)
			fclose(conn->file);
		if (conn->db) {
			int i = 0;
			for (i = 0; i < conn->db->MAX_ROWS; i++){
				free(conn->db->rows[i]->name);
				free(conn->db->rows[i]->email);
				free(conn->db->rows[i]);
			}
			free(conn->db->rows);
			free(conn->db);
		}
		free(conn);
	}
// 	printf("Exiting CLOSE\n"); // debug
}

void die(const char *message, struct Connection *conn)
{
// 	printf("Entering DIE\n"); // debug
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	Database_close(conn);

	exit(1);
// 	printf("Exiting DIE\n"); // debug
}

void Address_print(struct Address *addr)
{
	printf("id:%d\t set:%d\t name:%s, email:%s\n", addr->id, addr->set, addr->name, addr->email);
}

void Database_file_attributes_checker(struct Connection *conn, char mode, const char * filename)
{
// 	printf("Entering ATTR_CHK\n"); // debug
	int rc = 0;	
	int check = 0;

	rc = fread(&check, sizeof(int ), 1, conn->file);
	if (rc != 1)
		die("Cannot flush database", conn);
	if (check != conn->db->MAX_DATA){
		die("The file does not contain the desired MAX_DATA value", conn);
	}
	
	rc = fread(&check, sizeof(int ), 1, conn->file);
	if (rc != 1)
		die("Cannot flush database", conn);
	if (check != conn->db->MAX_ROWS){
		die("The file does not contain the desired MAX_ROWS value", conn);
	}
// 	printf("Exiting ATTR_CHK\n"); // debug
}

void Database_load(struct Connection *conn)
{
// 	printf("Entering LOAD\n"); // debug
	rewind(conn->file);
	fseek(conn->file, 8, SEEK_SET);

	int rc = 0;
	int i = 0;

	for ( i = 0; i < conn->db->MAX_ROWS; i++)	
	{
		// the usage of rc here is xtremely stupid. TODO
		rc = fread(&conn->db->rows[i]->id, sizeof(int), 1, conn->file);
		rc = fread(&conn->db->rows[i]->set, sizeof(int), 1, conn->file);
		rc = fread(conn->db->rows[i]->name, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		rc = fread(conn->db->rows[i]->email, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Failed to load database.\n", conn);
	}
// 	printf("Exiting LOAD\n"); // debug
}

struct Connection *Database_open(const char *filename, char mode, int MAX_ROWS, int MAX_DATA)
{
// 	printf("Entering OPEN\n"); // debug
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
    conn->db->rows = malloc(sizeof(struct Address*) * MAX_ROWS);
    if (!conn->db)
        die("Memory error", conn);

    conn->db->MAX_ROWS = MAX_ROWS;
	conn->db->MAX_DATA = MAX_DATA;
	
    for (int i = 0; i < conn->db->MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address *addr = malloc(sizeof(struct Address));
        conn->db->rows[i] = addr;
        addr->id = i;
        addr->set = 0;
        addr->name = malloc(sizeof(char ) * conn->db->MAX_DATA );
        addr->email = malloc(sizeof(char ) * conn->db->MAX_DATA );
        // then just assign it
	}

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
		if (conn->file) {
			Database_file_attributes_checker(conn, mode, filename);
			Database_load(conn);
		}
    }

    if (!conn->file)
        die("Failed to open the file.\n", conn);
	
// 	printf("Exiting OPEN\n"); // debug
    return conn;
};

void Database_create(struct Connection *conn)
{
// 	printf("Entering CREATE\n"); // debug
	int i = 0;
	int rc = 0;

	rewind(conn->file);
	
	rc = fwrite(&conn->db->MAX_DATA, sizeof(int ), 1, conn->file);
	if (rc != 1)
		die("Cannot flush database", conn);
	rc = fwrite(&conn->db->MAX_ROWS, sizeof(int ), 1, conn->file);
	if (rc != 1)
		die("Cannot flush database", conn);
		
	for (i = 0; i < conn->db->MAX_ROWS; i++) {
		memset(conn->db->rows[i]->email, 0, conn->db->MAX_DATA);
		memset(conn->db->rows[i]->name, 0, conn->db->MAX_DATA);
	}
// 	printf("Exiting CREATE\n"); // debug
}


void Database_write(struct Connection *conn)
{
// 	printf("Entering WRITE\n"); // debug
	rewind(conn->file);
	fseek(conn->file, 8, SEEK_SET);
	
	int rc = 0;
	int i = 0;

	for(i = 0; i < conn->db->MAX_ROWS; i++)
	{	
		rc = fwrite(&conn->db->rows[i]->id, sizeof(int ), 1, conn->file);
		if (rc != 1)
			die("Cannot flush database", conn);
		rc = fwrite(&conn->db->rows[i]->set, sizeof(int ), 1, conn->file);
		if (rc != 1)
			die("Cannot flush database", conn);

		rc = fwrite(conn->db->rows[i]->name, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Cannot flush database", conn);

		rc = fwrite(conn->db->rows[i]->email, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Cannot flush database", conn);
	}
// 	printf("Exiting WRITE\n"); // debug
}

// TODO
void Database_set(struct Connection *conn, int id, const char *name,
	const char *email)
{
// 	printf("Entering SET\n"); // debug
    struct Address *addr = conn->db->rows[id];

    if (addr->set){
        die("Already set, delete it first", conn);
    }

    addr->set = 1;
    // WARNING: bug, read the "How To BreakIt" and fix this TODO
    char *res = strncpy(addr->name, name, (conn->db->MAX_DATA)-1);
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed", conn);

    char *res2 = strncpy(addr->email, email, (conn->db->MAX_DATA)-1);
    if (!res2)
        die("Name copy failed", conn);

// 	printf("Exiting SET\n"); // debug
}

void Database_get(struct Connection *conn, int id)
{
// 	printf("Entering GET\n"); // debug
	struct Address *addr = conn->db->rows[id];
	
	if (addr->set) {
		Address_print(addr);
	} else {
		die("Id is not set", conn);
	}
// 	printf("Exiting GET\n"); // debug
}

void Database_delete(struct Connection *conn, int id)
{
// 	printf("Entering DELETE\n"); // debug
	if (conn->db->rows[id]->set == 0) {
		//cond for already unset
		;
	} else { 
		// needs deletion
		conn->db->rows[id]->id = id;
		conn->db->rows[id]->set = 0;
		memset(conn->db->rows[id]->email, 0, conn->db->MAX_DATA);
		memset(conn->db->rows[id]->name, 0, conn->db->MAX_DATA);
		//conn->db->rows[id]->name = NULL;
	}
// 	printf("Exiting DELETE\n"); // debug
}

void Database_list(struct Connection *conn)
{
// 	printf("Entering LIST\n"); // debug
	int i = 0;
	
	for(i = 0; i < conn->db->MAX_ROWS; i++) {
		struct Address *cur = conn->db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
// 	printf("Exiting LIST\n"); // debug
}

int Find_String(char *bigString, char *str, int bigLen, int smlLen)
{
 	//printf("Entering FIND_STR\n"); // debug
	int i = 0;
	int j = 0;
	int flag1 = 0;

	for (i = 0; i < bigLen - smlLen; i++ ) {
		flag1 = 0;
		for (j = 0; j < smlLen; j++) {
			//printf("CHARbig: %c\t CHARfind: %c\n", bigString[i+j], str[j]); // debug
			if(bigString[i+j] != str[j]) {
				flag1 = 1;
			}
		}
		if ( flag1 == 0){
			return 1;
		}
	}		
 	//printf("Exiting FIND_STR\n"); // debug
	return 0;
}

void Database_find(struct Connection *conn, char *findString, char *field)
{
 	//printf("Entering DB_FIND\n"); // debug
	int i = 0;
	
	if( !strcmp(field, "name") ) {
		for(i = 0; i < conn->db->MAX_ROWS; i++) {
			struct Address *cur = conn->db->rows[i];
			
			if (cur->set) {
				if ( Find_String(cur->name, findString, conn->db->MAX_DATA, strlen(findString)) )  {
					printf("Found match at id:\t%d. Printing;\n", i+1);
					Address_print(cur);
				}
			}
		}
	}
	else if( !strcmp(field, "email") ) {
		for(i = 0; i < conn->db->MAX_ROWS; i++) {
			struct Address *cur = conn->db->rows[i];
			
			if (cur->set) {
				if ( Find_String(cur->email, findString, conn->db->MAX_DATA, strlen(findString)) )  {
					printf("Found match at id:\t%d. Printing;\n", i+1);
					Address_print(cur);
				}
			}
		}
	}
	else {
		die("Wrong Address field try 'name' or 'email'", conn);
	}
 	//printf("Exiting DB_FIND\n"); // debug
}

int main(int argc, char *argv[])
{	
	if(argc<5)
		die("USAGE: ex17 <dbfile> <MAX_DATA> <MAX_ROWS> <action> [action params]", NULL);

	int MAX_DATA = atoi(argv[2]);
	int MAX_ROWS = atoi(argv[3]);
	
	char *filename = argv[1];
	char action = argv[4][0];
	struct Connection *conn = Database_open(filename, action, MAX_ROWS, MAX_DATA);
	int id = 0;

	if (argc > 5) id= atoi(argv[5]);
	if (id > MAX_ROWS) die("There's not that many records.", conn);
	
	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 6)
				die("Need an id to get", conn);

			Database_get(conn, id-1);
			break;
	
		case 's':
			if (argc != 8)
				die("Need id, name, email to set", conn);
		
			Database_set(conn, id-1, argv[6], argv[7]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 6)
				die("Need id to delete", conn);
		
			Database_delete(conn, id-1);
			Database_write(conn);
			break;
			
		case 'l':
			Database_list(conn);
			break;

		case 'f':
			if (argc != 7)
				die("Need a string to search and a field to search it in", conn);
		
			Database_find(conn, argv[5], argv[6]);
			break;

		default:
			die("Invalid saction: c=create, g=get, s=set, d=del, l=list", conn);
	}

	Database_close(conn);

	return 0;
}

//%s/^\(\/\/\)\( \/\/\)\(.*\)\(\/\/ debug\)$/\1\3\4
//if u've put extra _//_ by mistake etc. at the beginning, this is to remove them

//%s/^\(\/\/\)\(.*\)\(\/\/ debug\)$/\2\3
//will RMV leading //s 

//%s/\(.*\)\(\/\/ debug\)$/\/\/\1\2
//will PUT leading //s
