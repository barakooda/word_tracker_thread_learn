# WordTracker

WordTracker is a multi-threaded C++ application. This project reads a list of words from standard input, counts the occurrences of each word (ignoring the termination keyword `"end"`), prints the words in alphabetical order, and then provides an interactive lookup mode for querying individual word counts.

## Features
- **Multi-threaded Processing:** A dedicated worker thread processes words from a thread-safe queue.
- **Robust Input Handling:** Input is validated and trimmed to ensure accurate word counting.
- **Interactive Lookup:** Users can query word counts interactively (terminates on EOF).
- **Unit Testing:** Comprehensive tests verify functionality and handle various edge cases.
- **Modern C++:** Developed using C++17 and modular design principles.

## Project Structure
```
WordTracker/
├── CMakeLists.txt
├── README.md
├── CHANGELOG.md
├── docs/
│   └── Reactor Coding Challenge 01.pdf
│   └── bad_old_code.cxx
├── include/
│   ├── ThreadSafeWordQueue.h
│   ├── WordCounter.h
│   └── WordTracker.h
├── src/
│   ├── main.cpp
│   ├── ThreadSafeWordQueue.cpp
│   ├── WordCounter.cpp
│   └── WordTracker.cpp
├── tests/
│   ├── CMakeLists.txt
│   └── tests.cpp
└── scripts/
    └── run.sh
    └── setup.sh
    └── tests_run.sh
```


## Prerequisites

Ensure you have the following installed on your Ubuntu (22.04/24.04) system:
- **g++** (with C++17 support)
- **CMake** (minimum version 3.10)
- **Make**

The provided setup script can automatically install these dependencies if needed.

## Building the Project

### Using the Setup and Run Scripts

1. Open a terminal.
2. Navigate to the `scripts/` directory:
    ```
    cd scripts
    ```
3. Run the setup script:
    ```
    ./setup.sh
    ```
4. Run WordTracker:
    ```
    ./run.sh
    ```
4. Run tests (if needed):
    ```
    ./tests_run.sh
    ```

