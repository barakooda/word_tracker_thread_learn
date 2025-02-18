cmake_minimum_required(VERSION 3.10)
project(WordTracker)

# Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the 'include' directory for header files.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Optionally, set output directories for build artifacts.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Add the library target.
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(WordTrackerLibrary ${SOURCE_FILES})

# Add the executable and link all source files
add_executable(WordTracker 
    src/main.cpp 
    src/ThreadSafeWordQueue.cpp 
    src/WordCounter.cpp
    src/WordTracker.cpp
)

# Link the executable to the library.
target_link_libraries(${PROJECT_NAME} PRIVATE WordTrackerLibrary)

# Enable testing and add the tests directory.
enable_testing()
add_subdirectory(tests)