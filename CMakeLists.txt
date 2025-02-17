cmake_minimum_required(VERSION 3.10)
project(BarakKorenProject)

# Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the 'include' directory for header files.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Optionally, set output directories for build artifacts.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Add the executable.
# This assumes that all your main source files are in the 'src' directory.
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# If you have any required libraries to link, add them here.
# For example: target_link_libraries(${PROJECT_NAME} some_library)

# Enable testing and add the tests directory.
enable_testing()
add_subdirectory(tests)
