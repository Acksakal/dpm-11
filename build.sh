#!/bin/bash

SRC=$(find src/ -name '*.c' ! -name '#*' ! -name '*#' ! -name '.#*')
OUT="a.out"
gcc -Iinclude $SRC -o $OUT
echo "Build complete. Running..."
./$OUT
