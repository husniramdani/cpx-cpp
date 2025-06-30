#!/usr/bin/env python3
"""
SPINDYZEL Simple Test Runner
Handles input/output format test files
Usage: python3 test-simple.py solution.cpp test.txt
"""

import subprocess
import sys
import os
from pathlib import Path

# Colors
GREEN = '\033[92m'
RED = '\033[91m'
BLUE = '\033[94m'
YELLOW = '\033[93m'
RESET = '\033[0m'

def compile_cpp(filename):
    """Compile C++ file"""
    basename = filename.stem
    executable = f"{basename}.out"
    
    print(f"{BLUE}Compiling {filename}...{RESET}")
    sdk_path = "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk"
    result = subprocess.run([
        'clang++', '-std=c++17', '-O2', '-Wall', '-Wextra', '-Wshadow',
        f'-I{sdk_path}/usr/include/c++/v1',
        f'-I{sdk_path}/usr/include',
        '-I.',
        '-o', executable, str(filename)
    ], capture_output=True, text=True)
    
    if result.returncode != 0:
        print(f"{RED}Compilation failed!{RESET}")
        print(result.stderr)
        return None
    
    print(f"{GREEN}Compilation successful!{RESET}")
    return executable

def parse_simple_test_file(test_file):
    """Parse test file with input/output format"""
    with open(test_file, 'r') as f:
        content = f.read().strip()
    
    # Split by input/output sections
    parts = content.split('input')
    if len(parts) < 2:
        return None, None
    
    # Get everything after 'input'
    after_input = parts[1]
    
    # Split by 'output'
    io_parts = after_input.split('output')
    if len(io_parts) < 2:
        return None, None
    
    input_text = io_parts[0].strip()
    output_text = io_parts[1].strip()
    
    return input_text, output_text

def run_test(executable, test_input, expected_output):
    """Run the test"""
    result = subprocess.run(
        [f"./{executable}"],
        input=test_input,
        capture_output=True,
        text=True
    )
    
    actual_output = result.stdout.strip()
    expected_output = expected_output.strip()
    
    print(f"{BLUE}Input:{RESET}")
    print(test_input)
    print(f"{BLUE}Expected Output:{RESET}")
    print(expected_output)
    print(f"{BLUE}Actual Output:{RESET}")
    print(actual_output)
    
    if actual_output == expected_output:
        print(f"{GREEN}✓ TEST PASSED{RESET}")
        return True
    else:
        print(f"{RED}✗ TEST FAILED{RESET}")
        return False

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 test-simple.py solution.cpp test.txt")
        sys.exit(1)
    
    cpp_file = Path(sys.argv[1])
    test_file = Path(sys.argv[2])
    
    if not cpp_file.exists():
        print(f"{RED}File {cpp_file} not found!{RESET}")
        sys.exit(1)
    
    if not test_file.exists():
        print(f"{RED}Test file {test_file} not found!{RESET}")
        sys.exit(1)
    
    # Parse test file
    test_input, expected_output = parse_simple_test_file(test_file)
    
    if test_input is None or expected_output is None:
        print(f"{RED}Could not parse test file! Expected format:{RESET}")
        print("input")
        print("test input here")
        print("")
        print("output") 
        print("expected output here")
        sys.exit(1)
    
    # Compile
    executable = compile_cpp(cpp_file)
    if not executable:
        sys.exit(1)
    
    try:
        print(f"\n{BLUE}Running test...{RESET}")
        print("=" * 50)
        
        success = run_test(executable, test_input, expected_output)
        
        print("=" * 50)
        if success:
            print(f"{GREEN}Test completed successfully!{RESET}")
        else:
            print(f"{RED}Test failed!{RESET}")
    
    finally:
        # Clean up
        if os.path.exists(executable):
            os.remove(executable)

if __name__ == "__main__":
    main()