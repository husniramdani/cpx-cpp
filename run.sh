#!/bin/bash

# SPINDYZEL C++ Test Runner
# Usage: ./run.sh filename.cpp [input_file]

if [ $# -eq 0 ]; then
    echo "Usage: ./run.sh filename.cpp [input_file]"
    echo "Example: ./run.sh solution.cpp"
    echo "Example: ./run.sh solution.cpp input.txt"
    exit 1
fi

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

filename=$1
basename="${filename%.*}"
executable="${basename}.out"

# Compile with optimization flags
echo -e "${BLUE}Compiling $filename...${NC}"
SDK_PATH="/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk"
clang++ -std=c++17 -O2 -Wall -Wextra -Wshadow \
    -I"$SDK_PATH/usr/include/c++/v1" \
    -I"$SDK_PATH/usr/include" \
    -I. \
    -o "$executable" "$filename"

if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful!${NC}"
echo -e "${BLUE}Running $executable...${NC}"
echo "=============================="

# Run with input file or stdin
if [ $# -eq 2 ]; then
    # Input file provided
    ./"$executable" < "$2"
else
    # Interactive mode
    ./"$executable"
fi

# Clean up executable
rm -f "$executable"