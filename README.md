# SPINDYZEL C++ Competitive Programming

## macOS Setup (IMPORTANT)

On macOS, you need to set up the compiler paths first:

```bash
# Option 1: Run the setup alias (recommended for easy compilation)
./setup-alias.sh
source ~/.zshrc  # or ~/.bash_profile

# Option 2: Use the provided scripts (no setup needed)
```

## File Organization

### Method 1: Inline Tests (Recommended)
Keep your code and tests in the same file:

```cpp
// solution.cpp
#include "stdc++.h"
using namespace std;

int main() {
    // your solution
}

/* TEST
input_here
---
expected_output
*/
```

Run with: `python3 test-inline.py solution.cpp`

### Method 2: Contest Organization
Use the organize script to create folders:

```bash
# Create folders for a whole contest
./organize.sh 1900    # Creates cf-1900/A through F

# Create folder for specific problem
./organize.sh 1900 A  # Creates cf-1900/A/A.cpp
```

## Quick Start

### Running a single file:
```bash
./run.sh solution.cpp
```

### Running with inline tests:
```bash
python3 test-inline.py solution.cpp
```

### Running with separate test file:
```bash
python3 test.py solution.cpp tests.txt
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
# Method 1: Inline tests (recommended)
python3 test-inline.py watermelon-inline.cpp

# Method 2: Separate test files
python3 test.py 800-watermelon.cpp tests/watermelon.txt

# Run interactively
./run.sh solution.cpp

# Create contest structure
./organize.sh 1900 A
cd cf-1900/A
../../run.sh A.cpp
```

## Template

Use `template.cpp` as a starting point for new problems. It includes common macros and fast I/O setup.

## Important: Local vs Online Judge

**For Codeforces/Online Judges:** Use `template.cpp` with `#include <bits/stdc++.h>`

**For Local Testing on macOS:** Use `template-local.cpp` with `#include "stdc++.h"` or copy and change the include when submitting.

The provided scripts (`run.sh`, `test.py`) handle the macOS compilation issues automatically.