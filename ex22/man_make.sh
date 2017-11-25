#!/bin/bash

VAR=$1
if [ $VAR -ge 1 ]; then
	cc -Wall -g -DNDEBUG -c -o ex22.o ex22.c
	cc -Wall -g -DNDEBUG ex22_main.c ex22.o -o ex22_main
	ls
	./ex22_main

else
	rm ex22.o
	rm ex22_main
	ls
fi
