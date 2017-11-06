//Heap and Stack Memory Allocation

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
	char *name;
	char *email;
};

struct Database {
	int MAX_DATA;
	int MAX_ROWS;
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

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to load database.\n", conn);
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
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) {
			Database_load(conn);
		}

	}

	if (!conn->file)
		die("Failed to open the file.\n", conn);

	return conn;
};

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

void Database_create(struct Connection *conn)
{
	int i = 0;
	conn->db->MAX_ROWS = MAX_ROWS;
	conn->db->MAX_DATA = MAX_DATA;

	for (i = 0; i < conn->db->MAX_ROWS; i++) {
		// make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		// then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name,
	const char *email)
{
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
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	
	if (addr->set) {
		Address_print(addr);
	} else {
		die("Id is not set", conn);
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;
	
	for(i = 0; i < conn->db->MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc<3)
		die("USAGE: ex17 <dbfile> <MAX_DATA> <MAX_ROWS> <action> [action params] ", NULL);

	char *filename = argv[1];
	char action = argv[4][0];
	int MAX_ROWS = atoi( argv[3] );
	int MAX_DATA = atoi( argv[2] );
	struct Connection *conn = Database_open(filename, action, MAX_ROWS, MAX_DATA); // TODO cursor
	int id = 0;

	if (argc > 5) id= atoi(argv[5]);
	if (id >= MAX_ROWS) die("There's not that many records.", conn);
	
	switch (action) {
		case 'c':
			Database_create(conn); // TODO
			Database_write(conn); // TODO
			break;

		case 'g':
			if (argc != 4)
				die("Need an id to get", conn);

			Database_get(conn, id); // TODO
			break;
	
		case 's':
			if (argc != 6)
				die("Need id, name, email to set", conn);
		
			Database_set(conn, id, argv[4], argv[5]); // TODO
			Database_write(conn); // TODO
			break;

		case 'd':
			if (argc != 4)
				die("Need id to delete", conn);
		
			Database_delete(conn, id); // TODO
			Database_write(conn); // TODO
			break;
			
		case 'l':
			Database_list(conn); // TODO
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
	}

	Database_close(conn); // TODO

	return 0;
}
