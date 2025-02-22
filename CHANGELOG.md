# CHANGELOG

## [v1.0.1] - 2025-02-22
### Added
- Unit tests in `tests/tests.cpp` covering word counting, input trimming, and validation.
- Improved error messages in interactive lookup.
### Fixed
- Removed duplicate variable declarations in `main.cpp`.
- Minor UI and error-handling refinements.

---

## [v1.0.0] - 2025-02-20
### Added
- Added `getSortedCounts()` in `WordCounter` to return a sorted vector of word counts.
- Introduced a dedicated `printSortedWordList()` function to display sorted counts.
- Updated `main.cpp` to use the new WordCounter interface for sorted output and interactive lookup.
### Changed
- Renamed the application to **WordTracker** for clarity.
- Refactored code to use modern C++ (lambdas, RAII, auto) for improved safety and readability.
### Fixed
- Resolved race conditions and memory leaks from earlier versions.

---

## [v0.4.0] - 2025-02-19
### Added
- Integrated a CMake build system (root `CMakeLists.txt`) to compile all source files in `src/` with headers from `include/`.
- Configured VS Code tasks and launch settings for full-project builds and debugging.
- Added a unified setup script (`scripts/setup.sh`) for automated building, cleaning, and testing on Ubuntu.
### Changed
- Reorganized the project structure into `src/` (source), `include/` (headers), `tests/` (unit tests), `scripts/` (automation), and `docs/` (documentation).
### Fixed
- Fixed build and linking issues by ensuring all source files are properly included via CMake.

---

## [v0.3.0] - 2025-02-18
### Added
- Developed UI functions and utility functions (in WordTracker.cpp/h) to print the title, read input, and handle interactive lookup.
- Added helper functions `trim()` and `isValidWord()` for robust input validation.
### Changed
- Separated UI/utility functions from core processing logic to improve modularity.

---

## [v0.2.0] - 2025-02-17
### Added
- Migrated from C-style strings and manual memory management to using `std::string` and STL containers (C++17).
- Introduced `ThreadSafeWordQueue` for safe inter-thread communication using `std::mutex` and `std::condition_variable`.
- Created `WordCounter` to process words from the queue and maintain counts in an `std::unordered_map`.
### Fixed
- Addressed race conditions and memory leaks observed during the learning phase.

---

## [v0.1.0] - 2025-02-16
### Learning Phase
- Reviewed and studied an old solution (used as a learning exercise) that relied on global variables, C-style strings, and raw pointers.
- Gained understanding of race conditions, unsafe input handling, and manual memory management.
