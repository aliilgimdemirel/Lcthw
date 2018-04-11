#!/bin/bash +e

ex29 ./libex29.so print_a_message "hello there"
./ex29 ./libex29.so print_a_message "hello there"


./ex29 ./libex29.so uppercase "hello there"
./ex29 ./libex29.so lowercase "HELLO tHeRe"

./ex29 ./libex29.so fail_on_purpose "i fail"

./ex29 ./libex29.so fail_on_purpose

./ex29 ./libex29.so asdasdasd asdasdasd
./ex29 ./libex.so asdasdasd asasdasd
