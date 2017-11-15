// TODO LIST
// [Postponed ]1- make DEBUG option // Will come after 2 more exercises.
// [DONE] 2- solve the create/intialization thing
// [DONE] 3- Make the python/bash script
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

// NOTODO
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

// NOTODO
void Address_print(struct Address *addr)
{
	printf("id:%d\t set:%d\t name:%s, email:%s\n", addr->id, addr->set, addr->name, addr->email);
}

// NOTODO
// can make the load search for db's and matching MAX_DATA&MAX_ROWS?
// But that logic is inside Database_open
void Database_load(struct Connection *conn)
{
// 	printf("Entering LOAD\n"); // debug
	rewind(conn->file);

	int rc = 0;
	int i = 0;
	for ( i = 0; i < conn->db->MAX_ROWS; i++)	
	{
		// the usage of rc here is xtremely stupid.
		rc = fread(&conn->db->rows[i]->id, sizeof(int), 1, conn->file);
		rc = fread(&conn->db->rows[i]->set, sizeof(int), 1, conn->file);
		rc = fread(conn->db->rows[i]->name, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		rc = fread(conn->db->rows[i]->email, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Failed to load database.\n", conn);
	}
// 	printf("Exiting LOAD\n"); // debug
}

// NOTODO
// 1- MAX_DATA & MAX_ROWS should be put inside DB here. [DONE]
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
			Database_load(conn);
			//Address_print(conn->db->rows[0]);
		}
    }

    if (!conn->file)
        die("Failed to open the file.\n", conn);
	
// 	printf("Exiting OPEN\n"); // debug
    return conn;
};

// TODO
void Database_create(struct Connection *conn)
{
// 	printf("Entering CREATE\n"); // debug
	int i = 0;
	
	for (i = 0; i < conn->db->MAX_ROWS; i++) {
		// make a prototype to initialize it
		memset(conn->db->rows[i]->email, 0, conn->db->MAX_DATA);
		memset(conn->db->rows[i]->name, 0, conn->db->MAX_DATA);
		// then just assign it
	}
// 	printf("Entering CREATE\n"); // debug
}


// TODO
void Database_write(struct Connection *conn)
{
// 	printf("Entering WRITE\n"); // debug
	rewind(conn->file);

	int i = 0;

	for(i = 0; i < conn->db->MAX_ROWS; i++)
	{	
		int rc = fwrite(&conn->db->rows[i]->id, sizeof(int ), 1, conn->file);
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

// NOTODO
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

// NOTODO
void Database_delete(struct Connection *conn, int id)
{
// 	printf("Entering DELETE\n"); // debug
	if (conn->db->rows[id]->set == 0) {
		//cond for already unset
		;
	} else { 
		// needs deletion
		printf("debug\n"); // debug
		conn->db->rows[id]->id = id;
		conn->db->rows[id]->set = 0;
		memset(conn->db->rows[id]->email, 0, conn->db->MAX_DATA);
		memset(conn->db->rows[id]->name, 0, conn->db->MAX_DATA);
		//conn->db->rows[id]->name = NULL;
		printf("debug\n"); // debug
		Address_print(conn->db->rows[id]);
	}
// 	printf("Exiting DELETE\n"); // debug
}

// NOTODO
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
		default:
			die("Invalid saction: c=create, g=get, s=set, d=del, l=list", conn);
	}

	Database_close(conn);

	return 0;
}
