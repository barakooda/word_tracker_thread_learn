cmake_minimum_required(VERSION 3.10)
project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the main project's include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the test executable
add_executable(tests tests.cpp)

# Link the test executable to the main project library
target_link_libraries(tests PRIVATE WordTrackerLibrary)