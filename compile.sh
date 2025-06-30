#!/bin/bash

# SPINDYZEL C++ Compiler for macOS
# This script handles macOS-specific compilation issues

if [ $# -eq 0 ]; then
    echo "Usage: ./compile.sh filename.cpp"
    exit 1
fi

filename=$1
basename="${filename%.*}"
executable="${basename}.out"

# Use clang++ explicitly with SDK path
clang++ -std=c++17 -O2 -Wall -Wextra -Wshadow \
    -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
    -I. \
    -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk \
    -o "$executable" "$filename"

if [ $? -eq 0 ]; then
    echo "Compilation successful! Created: $executable"
    exit 0
else
    echo "Compilation failed!"
    exit 1
fi