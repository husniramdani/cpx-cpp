#!/usr/bin/env python3
"""
SPINDYZEL Inline Test Runner
Tests are embedded in the source code as comments
Usage: python3 test-inline.py solution.cpp
"""

import subprocess
import sys
import os
import re
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

def extract_tests(filename):
    """Extract test cases from source file comments"""
    with open(filename, 'r') as f:
        content = f.read()
    
    # Pattern to match test blocks in comments
    # /* TEST
    # input
    # ---
    # output
    # */
    pattern = r'/\*\s*TEST\s*\n(.*?)\n---\n(.*?)\n\*/'
    matches = re.findall(pattern, content, re.DOTALL)
    
    tests = []
    for match in matches:
        input_text = match[0].strip()
        output_text = match[1].strip()
        tests.append((input_text, output_text))
    
    return tests

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

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 test-inline.py solution.cpp")
        sys.exit(1)
    
    cpp_file = Path(sys.argv[1])
    if not cpp_file.exists():
        print(f"{RED}File {cpp_file} not found!{RESET}")
        sys.exit(1)
    
    # Extract tests
    tests = extract_tests(cpp_file)
    
    if not tests:
        print(f"{YELLOW}No tests found in {cpp_file}{RESET}")
        print("Add tests in your code like this:")
        print("/* TEST")
        print("8")
        print("---")
        print("YES")
        print("*/")
        sys.exit(0)
    
    # Compile
    executable = compile_cpp(cpp_file)
    if not executable:
        sys.exit(1)
    
    try:
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
    
    finally:
        # Clean up
        if os.path.exists(executable):
            os.remove(executable)

if __name__ == "__main__":
    main()