#!/bin/bash +e

./tests/libex29_tests ./build/libex29.so print_a_message "hello there"

./tests/libex29_tests ./build/libex29.so uppercase "hello there"
./tests/libex29_tests ./build/libex29.so lowercase "HELLO tHeRe"

./tests/libex29_tests ./build/libex29.so fail_on_purpose "i fail"

./tests/libex29_tests ./build/libex29.so fail_on_purpose

./tests/libex29_tests ./build/libex29.so asdasdasd asdasdasd
./tests/libex29_tests ./build/libex.so asdasdasd asasdasd
