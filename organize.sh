#!/bin/bash

# SPINDYZEL Problem Organizer
# Creates a directory structure for Codeforces problems

if [ $# -lt 1 ]; then
    echo "Usage: ./organize.sh <contest-number> [problem-letter]"
    echo "Example: ./organize.sh 1900 A"
    echo "Example: ./organize.sh 1900    # Creates all problems A-F"
    exit 1
fi

CONTEST=$1
PROBLEMS=${2:-"A B C D E F"}

# Create contest directory
mkdir -p "cf-$CONTEST"

# If specific problem provided
if [ $# -eq 2 ]; then
    PROBLEMS=$2
fi

for PROBLEM in $PROBLEMS; do
    PROBLEM_DIR="cf-$CONTEST/$PROBLEM"
    mkdir -p "$PROBLEM_DIR"
    
    # Copy template to problem directory
    cp template.cpp "$PROBLEM_DIR/$PROBLEM.cpp"
    
    # Update the template with problem link
    sed -i '' "s|║            Problem:.*║|║            Problem: $CONTEST$PROBLEM                                    ║|" "$PROBLEM_DIR/$PROBLEM.cpp"
    sed -i '' "s|║.*https://codeforces.com.*║|║            https://codeforces.com/contest/$CONTEST/problem/$PROBLEM              ║|" "$PROBLEM_DIR/$PROBLEM.cpp"
    
    echo "Created $PROBLEM_DIR/$PROBLEM.cpp"
done

echo ""
echo "Contest $CONTEST setup complete!"
echo "To work on a problem:"
echo "cd cf-$CONTEST/A"
echo "./../../run.sh A.cpp"