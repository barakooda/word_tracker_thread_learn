# CHANGELOG

## [v0.1.0] - 2025-02-17

### Added
- **Modern C++ Adoption:**
  - Upgraded the project to C++17, utilizing features such as `std::string`, lambda expressions, and RAII for resource management.
- **Thread-Safe Queue:**
  - Introduced a `ThreadSafeWordQueue` class to safely pass words from the input thread to the worker thread.
  - Implemented using `std::mutex` and `std::condition_variable` to avoid race conditions and busy waiting.
- **WordCounter Class:**
  - Encapsulated word counting logic into a separate `WordCounter` class.
  - Processes words from the queue and maintains counts in an `std::unordered_map`.
- **Safe Input Handling:**
  - Replaced unsafe C-style functions (like `std::gets` and `std::strcpy`) with `std::getline` and `std::string` to ensure buffer-safe input.
- **Sorting and Interactive Lookup:**
  - After processing input, the program copies the word counts into a vector, sorts it alphabetically, and prints the sorted list.
  - Added an interactive lookup mode to query word counts.
- **Unit Testing:**
  - Added a simple test suite using assert-based tests (in `tests/simple_tests.cpp`) to validate the word counting logic without relying on external libraries.
- **CMake Build System:**
  - Created a top-level `CMakeLists.txt` for building the project.
  - Added a separate `CMakeLists.txt` in the `tests` directory for building tests.
- **Improved Project Structure:**
  - Organized project directories for clarity:
    - `include/` for header files.
    - `src/` for source files.
    - `docs/` for documentation.
    - `scripts/` for build scripts.
    - `tests/` for test files.
    - Root-level documentation (README, CHANGELOG).

### Fixed
- **Race Conditions:**
  - Removed unsafe shared variable and busy waiting loop by implementing a thread-safe queue with proper locking mechanisms.
- **Memory Leaks:**
  - Eliminated manual memory management by replacing raw pointers with STL containers.
- **Unsorted Output:**
  - Resolved sorting issues by copying the unordered_map to a vector and sorting it using a custom comparator.

### Advantages of This Format
- **Clarity:**  
  The use of headings and bullet points makes it easy to understand the scope of changes.
- **Readability:**  
  Markdown formatting highlights key sections and improves readability across different tools (GitHub, VSCode, etc.).
- **Documentation:**  
  A well-structured changelog helps team members and users quickly grasp the evolution of the project.
- **Future Maintenance:**  
  Clear versioning and date stamps simplify tracking changes and planning future updates.