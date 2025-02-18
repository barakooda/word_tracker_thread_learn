# WordTracker

WordTracker is a multi-threaded C++ application developed as a solution to the **Reactor Coding Challenge 01**. The assignment required fixing and improving a pre-existing C++ project by enhancing its functionality, robustness, and maintainability. This project reads a list of words from standard input, counts the occurrences of each word (ignoring the termination keyword `"end"`), prints the words in alphabetical order, and then provides an interactive lookup mode for querying individual word counts.

## Assignment Context

The Reactor Coding Challenge 01 tasked you with:
- **Bug Fixing:** Identify and resolve issues in the existing code.
- **Design Improvements:** Refactor the code for better maintainability and readability.
- **Enhanced Functionality:** Implement multi-threaded word processing, robust input handling, and an interactive lookup mode.
- **Modern C++ Usage:** Utilize C++17 features and practices.
- **Testing:** Include unit tests to validate the behavior of core components.

This solution meets those requirements by clearly separating the thread-safe queue, word counting logic, and user-interaction functionality into distinct modules.

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

