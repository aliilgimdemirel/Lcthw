#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//#define MAX_DATA 512
//#define MAX_ROWS 100



struct Address {
    int id;
    int set;
    char name[512];
    char email[512];
};

struct Database {
	int MAX_ROWS;
	int MAX_DATA;
    struct Address **rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

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


struct Connection *Database_open(const char *filename, char mode, int MAX_ROWS, int MAX_DATA)
{ 
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
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
};

void Database_create(struct Connection *conn)
{	
// If I have connection I can get the MAX_DATA and MAX_ROWS
// I need to devise something to get those for local usage (or just use them directly but lets just get'em)

	int MAX_ROWS = conn->db->MAX_ROWS;
    //int MAX_DATA = conn->db->MAX_DATA;
    int i = 0;

	conn->db->rows = malloc(sizeof(struct Address*) * MAX_ROWS);

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it

//	printf("AAA\n");
		struct Address *addr = malloc(sizeof(struct Address));
//	printf("BBB\n");
        conn->db->rows[i] = addr;
        conn->db->rows[i]->id = i;
		conn->db->rows[i]->set = 0;
//	printf("CCC\n");
        // then just assign it
//	printf("DDD\n");
    }
	printf("SET : %d\n", conn->db->rows[MAX_ROWS]->set); 
}

void Database_set(struct Connection *conn, int id, const char *name,
    const char *email)
{
	//printf("Lets checkout our MAX_ROWS: %d\n", conn->db->MAX_ROWS);
	//printf("Lets checkout our MAX_DATA: %d\n", conn->db->MAX_DATA);
	printf("AAA\n");
	struct Address *addr = conn->db->rows[id]; 
	printf("BBB\n");
   
	printf("SET : %d\n", conn->db->rows[id]->set); 
	//addr = *(conn->db->rows[id]);

	printf("CCC\n");
    if (addr->set){
	printf("CCC\n");
        die("Already set, delete it first", conn);
	printf("CCC\n");
	}

    addr->set = 1;
    // WARNING: bug, read the "How To BreakIt" ad fix this
    char *res = strncpy(addr->name, name, conn->db->MAX_DATA);
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed", conn);

	printf("CCC\n");
    res = strncpy(addr->name, name, conn->db->MAX_DATA);
	printf("CCC\n");
    if (!res)
        die("Name copy failed", conn);
}



int main(int argc, char *argv[])
{

	int MAX_DATA = 32;
	int MAX_ROWS = 32;

	/* 
	 *
	 * struct Address addr = {.id = 0, .name = "what?my Name is!" };
	 *
	 * printf("Print myName: %s\n", addr.name);
	 *
	 */

	const char *filename = "Hasan";
	char action = 'c';

	struct Connection *conn = Database_open(filename, action, MAX_ROWS, MAX_DATA);

	// I should be able to create a proper CONN struct 
	// Now I can try my shenanigans!!

	printf("Lets print Size of Connection %lu\n", sizeof(struct Connection));
	
	printf("Lets print Size of Database %lu\n", sizeof(struct Database ));
	
	// These will be use to check MAX_DATA and MAX_ROWS 
	printf("Lets print Size of Database %lu\n", sizeof(struct Database ));
	printf("Lets print Size of Address %lu\n", sizeof(struct Address ));


	int id = 65;
	char *name = "Kel";
	char *email = "mahmut@greetings.com";
	
	printf("Entering create\n");
	Database_create(conn);
	printf("Exited create\n");
	
	printf("Lets print Size of created DB %lu\n", sizeof(**conn->db->rows));
	printf("Entering set\n");
	Database_set(conn, id, name, email);
	printf("Exiting set\n");
	

//	int rc = malloc(sizeof(struct Database));

	die("Till next time !\n",conn);

	return 0;
}
