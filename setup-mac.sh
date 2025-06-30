#!/bin/bash

echo "SPINDYZEL C++ Setup for macOS"
echo "=============================="
echo ""
echo "This script will help you set up C++ for competitive programming on macOS."
echo ""
echo "Step 1: Checking Xcode Command Line Tools..."

# Check if Xcode Command Line Tools are installed
if ! xcode-select -p &> /dev/null; then
    echo "Xcode Command Line Tools not found. Please install them by running:"
    echo "xcode-select --install"
    echo ""
    echo "After installation, run this script again."
    exit 1
fi

echo "✓ Xcode Command Line Tools found at: $(xcode-select -p)"
echo ""

echo "Step 2: Testing C++ compilation..."

# Create a simple test file
cat > test_compile.cpp << 'EOF'
#include <iostream>
using namespace std;

int main() {
    cout << "C++ is working!" << endl;
    return 0;
}
EOF

# Try different compilation methods
echo "Testing standard g++ compilation..."
if g++ -std=c++17 test_compile.cpp -o test_compile 2>/dev/null; then
    echo "✓ Standard g++ compilation works!"
    ./test_compile
    rm test_compile
else
    echo "✗ Standard g++ compilation failed"
    
    echo ""
    echo "Testing with explicit SDK path..."
    SDK_PATH=$(xcrun --show-sdk-path)
    if g++ -std=c++17 -isysroot $SDK_PATH test_compile.cpp -o test_compile 2>/dev/null; then
        echo "✓ Compilation with SDK path works!"
        echo "SDK Path: $SDK_PATH"
        ./test_compile
        rm test_compile
        
        echo ""
        echo "SOLUTION: You need to use the SDK path when compiling."
        echo "Add this alias to your ~/.zshrc or ~/.bash_profile:"
        echo ""
        echo "alias g++='g++ -isysroot \$(xcrun --show-sdk-path)'"
        echo ""
        echo "Or use the provided compile scripts that handle this automatically."
    else
        echo "✗ Compilation with SDK path also failed"
        echo ""
        echo "Please try running: xcode-select --install"
        echo "If that doesn't work, you may need to reinstall Xcode Command Line Tools."
    fi
fi

rm -f test_compile.cpp

echo ""
echo "Step 3: Setting up competitive programming environment..."
echo ""
echo "Your setup includes:"
echo "- template.cpp: Starting template for problems"
echo "- stdc++.h: Local precompiled header (use #include \"stdc++.h\")"
echo "- run.sh: Quick run script"
echo "- test.py: Test runner with multiple test cases"
echo ""
echo "Usage examples:"
echo "./run.sh solution.cpp           # Run interactively"
echo "./run.sh solution.cpp input.txt # Run with input file"
echo "python3 test.py solution.cpp tests/problem.txt # Run with test cases"