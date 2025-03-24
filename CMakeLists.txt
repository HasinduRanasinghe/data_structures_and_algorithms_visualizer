# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and C++ standard
project(DataStructuresVisualizer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define project source directories
set(SRC_DIR src)
set(INCLUDE_DIR include)

# Include directories
include_directories(${INCLUDE_DIR})
include_directories(${SRC_DIR}/visualization)
include_directories(${SRC_DIR}/data_structures)
include_directories(${SRC_DIR}/algorithms/sorting)
include_directories(${SRC_DIR}/algorithms/searching)

# Collect all source files automatically
file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/*.cpp
)

# Define the executable
add_executable(visualizer ${SOURCES})

# Enable more warnings for better code quality
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(visualizer PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(visualizer PRIVATE /W4)
endif()