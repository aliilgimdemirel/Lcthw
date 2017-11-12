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
	printf("Entering CLOSE\n");
	//if (conn) {
	//	if (conn->file)
	//		fclose(conn->file);
	//	if (conn->db)
	//		free(conn->db);
	//	free(conn);
	//}
}

void die(const char *message, struct Connection *conn)
{
	printf("Entering DIE\n");
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	Database_close(conn);

	exit(1);
}

// NOTODO
void Address_print(struct Address *addr)
{
	printf("Entering ADD_PRINT\n");	
	printf("id:%d\t set:%d\t name:%s, email:%s\n ", addr->id, addr->set, addr->name, addr->email);
	
	//char *byte1 = addr->name;
	//char *byte2 = addr->name;

	//printf("BBB\n");	
	//for(int i = 0; i < 40 ; i++){
	//	printf("%c", (byte1[i]));
	//}
	//printf("\n");
	//for(int i = 0; i < 40 ; i++){

	//	printf("%c", (byte2[i]));
	//}
	//printf("\n");
	printf("Exiting ADD_PRINT\n");	

}

// TODO
// can make the load search for db's and matching MAX_DATA&MAX_ROWS?
// But that logic is inside Database_open
void Database_load(struct Connection *conn)
{
	printf("Entering LOAD\n");	
	rewind(conn->file);

	int rc = 0;
	int i = 0;
	for ( i = 0; i < conn->db->MAX_ROWS; i++)	
	{
		rc = fread(&conn->db->rows[i]->id, sizeof(int), 1, conn->file);
		//rc = fread(&set, sizeof(int), 1, conn->file);
		//rc = fread(name, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		//rc = fread(email, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		//printf("What is ID: %d\n", id);
		//printf("What is SET: %d\n", set);
		//printf("What is NAME: %s\n", name);
		//printf("What is EMAIL: %s\n", email);
		//conn->db->rows[i]->id = id;
		rc = fread(&conn->db->rows[i]->set, sizeof(int), 1, conn->file);
		rc = fread(conn->db->rows[i]->name, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		rc = fread(conn->db->rows[i]->email, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Failed to load database.\n", conn);
	}

	//Address_print(conn->db->rows[0]);
	printf("Exiting LOAD\n");	
}

// TODO
// 1- MAX_DATA & MAX_ROWS should be put inside DB here. [DONE]
struct Connection *Database_open(const char *filename, char mode, int MAX_ROWS, int MAX_DATA)
{
	printf("Entering OPEN\n");	
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

	
	printf("Exiting OPEN\n");	
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
	printf("Entering WRITE\n");	
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
	
		//rc = fflush(conn->file);
		//if (rc == -1)
		//	die("Connot flush database", conn);
		rc = fwrite(conn->db->rows[i]->name, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Cannot flush database", conn);
	
		//rc = fflush(conn->file);
		//if (rc == -1)
		//	die("Connot flush database", conn);
		rc = fwrite(conn->db->rows[i]->email, sizeof(char) * conn->db->MAX_DATA, 1, conn->file);
		if (rc != 1)
			die("Cannot flush database", conn);
	    
		//rc = fflush(conn->file);
		//if (rc == -1)
		//	die("Connot flush database", conn);
	}

}

// TODO
void Database_create(struct Connection *conn)
{
	printf("Entering CREATE\n");	
	// If I have connection I can get the MAX_DATA and conn->db->MAX_ROWS
    int i = 0;

    for (i = 0; i < conn->db->MAX_ROWS; i++) {
        // make a prototype to initialize it

        struct Address *addr = malloc(sizeof(struct Address));
        conn->db->rows[i] = addr;
        addr->id = i+1;
        addr->set = 0;
        addr->name = malloc(sizeof(char ) * conn->db->MAX_DATA );
        addr->email = malloc(sizeof(char ) * conn->db->MAX_DATA );

        // then just assign it
	}
	//printf("SET : %d\n", conn->db->rows[(conn->db->MAX_ROWS)-1]->set );
    conn->db->rows[0]->id = 1;
    conn->db->rows[0]->set = 1;
    conn->db->rows[0]->name = "Hasan Abi";
    conn->db->rows[0]->email = "hasan_abi@cimeyil.abc";
}

// TODO
void Database_set(struct Connection *conn, int id, const char *name,
	const char *email)
{
	printf("Entering SET\n");	
    struct Address *addr = conn->db->rows[id];

    if (addr->set){
        die("Already set, delete it first", conn);
    }

    addr->set = 1;
    // WARNING: bug, read the "How To BreakIt" and fix this TODO
	//printf("AAA\n");
	//conn->db->rows[id]->name = malloc(sizeof(char) * conn->db->MAX_DATA);
	//printf("BBB\n");
    char *res = strncpy(addr->name, name, (conn->db->MAX_DATA)-1);
	//printf("CCC\n");
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed", conn);

	//conn->db->rows[id]->email = malloc(sizeof(char) * conn->db->MAX_DATA);
	//printf("DDD\n");
    char *res2 = strncpy(addr->email, email, (conn->db->MAX_DATA)-1);
	//printf("EEE\n");
    if (!res2)
        die("Name copy failed", conn);

	printf("Exiting SET\n");	
}

// NOTODO
void Database_get(struct Connection *conn, int id)
{
	printf("Entering GET\n");
	struct Address *addr = conn->db->rows[id];
	
	if (addr->set) {
		Address_print(addr);
	} else {
		die("Id is not set", conn);
	}
}

// NOTODO
void Database_delete(struct Connection *conn, int id)
{
	printf("Entering DELETE\n");
	if (conn->db->rows[id]->set == 0) {
		//cond for already unset
		;
	} else { 
		// needs deletion
		conn->db->rows[id]->id = id;
		conn->db->rows[id]->set = 0;
		conn->db->rows[id]->email = NULL;
		conn->db->rows[id]->name = NULL;
	}
}

// NOTODO
void Database_list(struct Connection *conn)
{
	printf("Entering LIST\n");
	int i = 0;
	
	for(i = 0; i < conn->db->MAX_ROWS; i++) {
		struct Address *cur = conn->db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{	
	printf("Your argc is :%d\n", argc);
	//int i = 0;
	//for(i = 0; i<argc;i++){
	//	printf("@%d : %s.\n",i,argv[i]);
	//}
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
			//Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 6)
				die("Need an id to get", conn);

			Database_get(conn, id);
			break;
	
		case 's':
			if (argc != 8)
				die("Need id, name, email to set", conn);
		
			printf("b4 set\n");
			Database_set(conn, id-1, argv[6], argv[7]);
			printf("After set\n");
			printf("b4 write\n");
			Database_write(conn);
			printf("After write\n");
			break;

		case 'd':
			if (argc != 6)
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

	//Database_list(conn);

	return 0;
}
