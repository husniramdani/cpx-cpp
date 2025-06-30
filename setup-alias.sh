#!/bin/bash

# SPINDYZEL C++ Alias Setup
# This creates a convenient g++ alias that works on macOS

echo "Setting up g++ alias for macOS..."

# Detect shell config file
if [ -n "$ZSH_VERSION" ]; then
    CONFIG_FILE="$HOME/.zshrc"
elif [ -n "$BASH_VERSION" ]; then
    CONFIG_FILE="$HOME/.bash_profile"
else
    CONFIG_FILE="$HOME/.profile"
fi

# Create the alias
ALIAS_LINE='alias g++="clang++ -std=c++17 -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1 -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"'

# Check if alias already exists
if grep -q "alias g++=" "$CONFIG_FILE" 2>/dev/null; then
    echo "g++ alias already exists in $CONFIG_FILE"
    echo "Current alias:"
    grep "alias g++=" "$CONFIG_FILE"
else
    echo "" >> "$CONFIG_FILE"
    echo "# SPINDYZEL C++ alias for macOS" >> "$CONFIG_FILE"
    echo "$ALIAS_LINE" >> "$CONFIG_FILE"
    echo "✓ Added g++ alias to $CONFIG_FILE"
fi

echo ""
echo "To activate the alias immediately, run:"
echo "source $CONFIG_FILE"
echo ""
echo "Now you can compile C++ files normally:"
echo "g++ solution.cpp -o solution"