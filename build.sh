#!/bin/bash

SRC=$(find . -name '*.c' ! -name '#*' ! -name '*#' ! -name '.#*')
OUT="a.out"
gcc $SRC -o $OUT
echo "Build complete. Running..."
./$OUT
