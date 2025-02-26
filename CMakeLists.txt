cmake_minimum_required(VERSION 3.10)
project(WordTracker)

# Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the 'include' directory for header files.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Optionally, set output directory for executables.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Define the library target using only the common source files.
add_library(WordTrackerLibrary
    src/ThreadSafeWordQueue.cpp
    src/WordCounter.cpp
    src/WordTracker.cpp
)

# Define the executable target using main.cpp.
add_executable(WordTracker src/main.cpp)

# Link the executable with the library.
target_link_libraries(WordTracker PRIVATE WordTrackerLibrary)

# Enable testing and add the tests directory.
enable_testing()
add_subdirectory(tests)

file(COPY ${PROJECT_SOURCE_DIR}/media DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
