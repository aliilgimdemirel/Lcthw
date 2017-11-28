CC=cc
CFLAGS=-Wall -g -DNDEBUG

all: ex22_main 

ex22_main: ex22.o ex22_main.c dbg.h ex22.h
	$(CC) $(CFLAGS) ex22_main.c ex22.o -o ex22_main 

ex22.o: ex22.c dbg.h ex22.h
	$(CC) $(CFLAGS) -c ex22.c -o ex22.o

clean:
	rm -f ex22_main ex22.o
