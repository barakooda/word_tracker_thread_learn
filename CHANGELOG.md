# CHANGELOG

## [v0.2.0] - 2025-02-17

### Added
- **C++17 Modernization:**
  - Upgraded the project to use C++17 features including `std::string`, lambda expressions, and RAII for safer memory management.
  
- **Thread-Safe Components:**
  - Added a **ThreadSafeWordQueue** class (with header in `include/ThreadSafeWordQueue.h` and implementation in `src/ThreadSafeWordQueue.cpp`) to handle safe communication between threads using `std::mutex` and `std::condition_variable`.
  - Encapsulated the word counting logic into a **WordCounter** class (with header in `include/WordCounter.h` and implementation in `src/WordCounter.cpp`) that processes words from the queue and maintains counts in an `std::unordered_map`.

- **Safe Input and Processing:**
  - Replaced unsafe C-style input functions with `std::getline` for robust reading of input.
  - Implemented logic to count and sort words alphabetically, then provide an interactive lookup mode.

- **Build System Improvements:**
  - Created a **CMakeLists.txt** to facilitate cross-platform builds and proper linking of all source files.
  - Configured the project to generate Unix Makefiles, ensuring compatibility on Ubuntu.
  - Added a custom **.vscode/tasks.json** that uses a shell task with wildcard expansion to compile all source files, simplifying the build process without relying on the default "build active file" task.
  - Updated **launch.json** for easy debugging from within VS Code by setting a preLaunchTask that builds the entire project.

- **Testing Infrastructure:**
  - Added a simple test executable (located in `tests/simple_tests.cpp`) along with its own CMake configuration to validate the functionality of the core classes without external dependencies.

### Fixed
- **Linking and Build Issues:**
  - Resolved linker errors by ensuring that all source files (`main.cpp`, `ThreadSafeWordQueue.cpp`, and `WordCounter.cpp`) are compiled and linked together.
  - Removed redundant build tasks from tasks.json so that only the custom "Build Entire Project" task is used, avoiding conflicts with default tasks provided by the C/C++ extension.
  
- **Project Structure and Configuration:**
  - Organized project folders:  
    - `include/` for header files,  
    - `src/` for implementation files,  
    - `bin/` for build outputs,  
    - `tests/` for test sources and CMake configurations,  
    - `docs/` for documentation.
  - Updated the VS Code configuration files (`tasks.json` and `launch.json`) to streamline building and debugging within the IDE.

### Notes
- The **custom build task** in `.vscode/tasks.json` now uses a shell command to compile all `.cpp` files from the `src` directory with proper include paths, making it unnecessary to update the task when adding new source files.
- The project is now fully configured to build with CMake or via the custom VS Code task, offering flexibility based on your development preferences.
- The integration with VS Code’s debugging tools via the updated **launch.json** makes it easy to run and debug the application with a single press of F5.

---