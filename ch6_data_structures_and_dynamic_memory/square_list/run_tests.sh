#!/usr/bin/env bash

set -e

CC=gcc
CFLAGS="-Wall -Wextra -Wunused-parameter -g"
BIN=test_square_list

echo "compiling"
$CC $CFLAGS test.c square_list.c -lm -o $BIN

echo
echo "running tests"
./$BIN

echo
echo "running tests with valgrind"

valgrind \
  -- leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --error-exitcode=1 \
  ./$BIN

echo
echo "tests have passed with no memory leaks found"
