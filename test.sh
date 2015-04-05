#!/bin/bash

cd /root/tests/
gcc -Wall *.c -o test
valgrind --leak-check=full ./test