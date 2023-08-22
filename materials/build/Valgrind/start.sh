#!/bin/bash

make test
g++ -lstdc++ -std=c++17 tests.cc  -lgtest -lgtest_main -lpthread list.a -o list
valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
