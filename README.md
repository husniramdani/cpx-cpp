# SPINDYZEL C++ Competitive Programming

## macOS Setup (IMPORTANT)

On macOS, you need to set up the compiler paths first:

```bash
# Option 1: Run the setup alias (recommended for easy compilation)
./setup-alias.sh
source ~/.zshrc  # or ~/.bash_profile

# Option 2: Use the provided scripts (no setup needed)
```

## Quick Start

### Running a single file:
```bash
./run.sh solution.cpp
```

### Running with input file:
```bash
./run.sh solution.cpp input.txt
```

### Running with test cases:
```bash
python3 test.py solution.cpp tests/problem.txt
```

## Test File Format

Create test files in `tests/` directory with this format:

```
### Test 1
<input line 1>
<input line 2>
---
<expected output line 1>
<expected output line 2>

### Test 2
<input>
---
<expected output>
```

## Example Usage

```bash
# Run watermelon solution with tests
python3 test.py 800-watermelon.cpp tests/watermelon.txt

# Run interactively
./run.sh 800-watermelon.cpp
```

## Template

Use `template.cpp` as a starting point for new problems. It includes common macros and fast I/O setup.

## Note on #include "stdc++.h"

On macOS, `bits/stdc++.h` isn't available by default. Use `#include "stdc++.h"` instead (quotes, not angle brackets). This includes all standard C++ libraries for competitive programming.