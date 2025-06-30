#!/usr/bin/env python3
"""
SPINDYZEL C++ Test Runner with Multiple Test Cases
Usage: python3 test.py solution.cpp
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

def run_test(executable, test_input, expected_output, test_num):
    """Run a single test case"""
    result = subprocess.run(
        [f"./{executable}"],
        input=test_input,
        capture_output=True,
        text=True
    )
    
    actual_output = result.stdout.strip()
    expected_output = expected_output.strip()
    
    if actual_output == expected_output:
        print(f"{GREEN}Test {test_num}: PASSED{RESET}")
        return True
    else:
        print(f"{RED}Test {test_num}: FAILED{RESET}")
        print(f"Input:\n{test_input}")
        print(f"Expected:\n{expected_output}")
        print(f"Got:\n{actual_output}")
        return False

def read_test_cases(test_file):
    """Read test cases from file"""
    tests = []
    with open(test_file, 'r') as f:
        lines = f.readlines()
    
    i = 0
    while i < len(lines):
        if lines[i].strip().startswith('###'):
            # Read input until next ### or ---
            i += 1
            test_input = []
            while i < len(lines) and not lines[i].strip().startswith('---'):
                test_input.append(lines[i].rstrip())
                i += 1
            
            # Read expected output
            i += 1
            expected = []
            while i < len(lines) and not lines[i].strip().startswith('###'):
                if lines[i].strip():
                    expected.append(lines[i].rstrip())
                i += 1
            
            tests.append(('\n'.join(test_input), '\n'.join(expected)))
        else:
            i += 1
    
    return tests

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 test.py solution.cpp [test_file.txt]")
        sys.exit(1)
    
    cpp_file = Path(sys.argv[1])
    if not cpp_file.exists():
        print(f"{RED}File {cpp_file} not found!{RESET}")
        sys.exit(1)
    
    # Compile
    executable = compile_cpp(cpp_file)
    if not executable:
        sys.exit(1)
    
    try:
        if len(sys.argv) == 3:
            # Test file provided
            test_file = Path(sys.argv[2])
            if not test_file.exists():
                print(f"{RED}Test file {test_file} not found!{RESET}")
                sys.exit(1)
            
            tests = read_test_cases(test_file)
            print(f"\n{BLUE}Running {len(tests)} test cases...{RESET}")
            print("=" * 40)
            
            passed = 0
            for i, (test_input, expected) in enumerate(tests, 1):
                if run_test(executable, test_input, expected, i):
                    passed += 1
                print()
            
            print("=" * 40)
            if passed == len(tests):
                print(f"{GREEN}All tests passed! ({passed}/{len(tests)}){RESET}")
            else:
                print(f"{YELLOW}Passed {passed}/{len(tests)} tests{RESET}")
        else:
            # Interactive mode
            print(f"\n{BLUE}Running in interactive mode...{RESET}")
            print("=" * 40)
            subprocess.run([f"./{executable}"])
    
    finally:
        # Clean up
        if os.path.exists(executable):
            os.remove(executable)

if __name__ == "__main__":
    main()