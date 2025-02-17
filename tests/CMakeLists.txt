cmake_minimum_required(VERSION 3.10)
project(SimpleTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the project's include directory.
include_directories(${CMAKE_SOURCE_DIR}/../include)

# Add the simple_tests executable.
add_executable(simple_tests simple_tests.cpp)
