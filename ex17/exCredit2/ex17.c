//Heap and Stack Memory Allocation

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//#define MAX_DATA 512
//#define MAX_ROWS 100

// As for Xcredit2 MAX_ROWS & MAX_DATA are now variable
// There is no way to predetermine the sizes of name and email
// arrays. So we're making them a "ptr to a char array"
struct Address {
	int id;
	int set;
	char *name;
	char *email;
};

struct Database {
	int MAX_ROWS;
	int MAX_DATA;
	//struct Address rows[MAX_ROWS];
	struct Address **rows; // there is 2 level of indirection to the struct Address.
};

struct Connection {
	FILE *file;
	struct Database *db;
};

// TODO
void Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void die(const char *message, struct Connection *conn)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	Database_close(conn);

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// TODO
void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to load database.\n", conn);
}

// TODO
// 1- MAX_DATA & MAX_ROWS should be put inside DB here. [DONE]
struct Connection *Database_open(const char *filename, char mode, int MAX_ROWS, int MAX_DATA)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
    conn->db->rows = malloc(sizeof(struct Address*) * MAX_ROWS);
    if (!conn->db)
        die("Memory error", conn);

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
        conn->db->MAX_ROWS = MAX_ROWS;
        conn->db->MAX_DATA = MAX_DATA;
    } else {
        conn->file = fopen(filename, "r+");
    }

    if (!conn->file)
        die("Failed to open the file.\n", conn);
	
    return conn;

/*
	struct Connection *conn = malloc(sizeof(struct Connection));

	if (!conn)
		die("Memory error", conn);
	
	conn->db = malloc(sizeof(struct Database));
	// So we need to allocate memory to our DB using MAX_ROWS;
	//int MAX_ROWS = *conn->db->MAX_ROWS;
	//printf("MAX_ROWS = %d\n", MAX_ROWS);
	//conn->db = malloc( (sizeof(int) * 2 ) + ( sizeof(struct Address) * MAX_ROWS ) );

	if (!conn->db)
		die("Memory error", conn);
	
	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) {
			Database_load(conn);
		}

	}

	if (!conn->file)
		die("Failed to open the file.\n", conn);

	return conn;
*/
};

// TODO
void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Cannot flush database", conn);

	rc = fflush(conn->file);
	if (rc == -1)
		die("Connot flush database", conn);
}

// TODO
void Database_create(struct Connection *conn)
{

// If I have connection I can get the MAX_DATA and conn->db->MAX_ROWS
// I need to devise something to get those for local usage (or just use them directly but lets just get'em)
    int i = 0;



	//printf("AAA\n");
    for (i = 0; i < conn->db->MAX_ROWS; i++) {
        // make a prototype to initialize it

		//printf("AAA\n");
        struct Address *addr = malloc(sizeof(struct Address));
		//printf("BBB\n");
        conn->db->rows[i] = addr;
        conn->db->rows[i]->id = i;
        conn->db->rows[i]->set = 0;
	    //printf("CCC\n");
        // then just assign it
    	//printf("DDD\n");
    }
    //printf("EEE\n");
    //printf("SET : %d\n", conn->db->rows[(conn->db->MAX_ROWS)-1]->set );
    //printf("FFF\n");

/*
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++) {
		// make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		// then just assign it
		conn->db->rows[i] = addr;
	}
*/
}

// DONE
void Database_set(struct Connection *conn, int id, const char *name,
	const char *email)
{
    //printf("Lets checkout our MAX_ROWS: %d\n", conn->db->MAX_ROWS);
    //printf("Lets checkout our MAX_DATA: %d\n", conn->db->MAX_DATA);
    //printf("AAA\n");
    struct Address *addr = conn->db->rows[id];
    //printf("BBB\n");

    printf("SET : %d\n", conn->db->rows[id]->set );
    //addr = *(conn->db->rows[id]);

	//printf("AAA\n");
    if (addr->set){
    	//printf("BBB\n");
        die("Already set, delete it first", conn);
    	//printf("CCC\n");
    }

    //printf("CCCC\n");
    addr->set = 1;
    // WARNING: bug, read the "How To BreakIt" and fix this
	conn->db->rows[id]->name = malloc(sizeof(char) * conn->db->MAX_DATA);
    char *res = strncpy(addr->name, name, conn->db->MAX_DATA);
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed", conn);

    //printf("DDD\n");
	conn->db->rows[id]->email = malloc(sizeof(char) * conn->db->MAX_DATA);
    res = strncpy(addr->email, email, conn->db->MAX_DATA);
    //printf("DDD\n");
    if (!res)
        die("Name copy failed", conn);

/*
	struct Address *addr = &conn->db->rows[id];
	if (addr->set)
		die("Already set, delete it first", conn);

	addr->set = 1;
	// WARNING: bug, read the "How To BreakIt" ad fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	// demonstrate the strncpy bug
	if (!res)
		die("Name copy failed", conn);

	res = strncpy(addr->name, name, MAX_DATA);
	if (!res)
		die("Name copy failed", conn);
*/
}

// TODO
void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	
	if (addr->set) {
		Address_print(addr);
	} else {
		die("Id is not set", conn);
	}
}

// TODO
void Database_delete(struct Connection *conn, int id)
{
	if (conn->db->rows[id]->set == 0) {//cond for already unset
		;
	} else { // cond for set
		conn->db->rows[id]->id == id;
		conn->db->rows[id]->set == 0;
		conn->db->rows[id]->email == NULL;
		conn->db->rows[id]->name == NULL;
	}

	//struct Address addr = {.id = id, .set = 0};
	//conn->db->rows[id] = addr;
}

// TODO
void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;
	
	for(i = 0; i < conn->db->MAX_ROWS; i++) {
		struct Address *cur = db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	// As we are now still developing some checks are disabled.
	/* 
	if(argc<3)
		die("USAGE: ex17 <dbfile> <action> [action params] <MAX_DATA> <MAX_ROWS>", NULL);

	
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if (argc > 3) id= atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records.", conn);
	
	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 4)
				die("Need an id to get", conn);

			Database_get(conn, id);
			break;
	
		case 's':
			if (argc != 6)
				die("Need id, name, email to set", conn);
		
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4)
				die("Need id to delete", conn);
		
			Database_delete(conn, id);
			Database_write(conn);
			break;
			
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid saction: c=create, g=get, s=set, d=del, l=list", conn);
	}
	*/

	int MAX_DATA = 32;
    int MAX_ROWS = 3;

    /* 
     * struct Address addr = {.id = 0, .name = "what?my Name is!" };
     * printf("Print myName: %s\n", addr.name);
     */

    const char *filename = "Hasan";
    char action = 'c';

    struct Connection *conn = Database_open(filename, action, MAX_ROWS, MAX_DATA);

    // I should be able to create a proper CONN struct 
    // Now I can try my shenanigans!!

    printf("Lets print Size of Connection %lu\n", sizeof(struct Connection));
    printf("Lets print Size of Database %lu\n", sizeof(struct Database ));

    // These will be use to check MAX_DATA and MAX_ROWS 
    //printf("Lets print Size of Database %lu\n", sizeof(struct Database ));
    //printf("Lets print Size of Address %lu\n", sizeof(struct Address ));


    int id = 1;
    char *name = "Kel";
    char *email = "mahmut@greetings.com";

    printf("Entering create\n");
    Database_create(conn);
    printf("Exited create\n");

    printf("Lets print Size of created DB %lu\n", sizeof(**conn->db->rows));
    printf("Entering set\n");
    Database_set(conn, id, name, email);
    printf("Exiting set\n");

	Address_print(conn->db->rows[1]);

    die("Till next time !\n",conn);

	return 0;
}
