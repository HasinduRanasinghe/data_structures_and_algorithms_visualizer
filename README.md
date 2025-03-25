# Data Structures and Algorithms Visualizer in C++

This repository contains a C++ program to visualize data structures and algorithms using a modular architecture. This demonstrates how different data structures work and how algorithms operate on them.

## Overview

### Folder Architecture
```
data_structures_and_algorithms_visualizer/
├── src/                           # Source code files
│   ├── main.cpp                   # Main program
│   │
│   ├── visualization/             # Visualization module
│   │   └── visualizer.cpp
│   │  
│   ├── data_structures/           # Data structures module
│   │   ├── binary_search_tree.cpp 
│   │   ├── hash_table.cpp
│   │   └── linked_list.cpp
│   │ 
│   └── algorithms/                # Algorithms module
│       ├── searching/             # Sub-folder for sorting algorithms
│       │   └── searching.cpp
│       │   
│       └── sorting/               # Sub-folder for searching algorithms 
│           └── sorting.cpp
│
|── include/                       # Header files
|   ├── visualization/ 
|   │   └── visualizer.h  
|   │
|   ├── data_structures/           # Data structures module
|   │   ├── binary_search_tree.h
|   │   ├── hash_table.h
|   │   └── linked_list.h
|   |   
|   └── algorithms/                # Algorithms module
|       ├── searching/             # Sub-folder for sorting algorithms
|       │   └── searching.h
|       │   
|       └── sorting/               # Sub-folder for searching algorithms 
|           └── sorting.h
|
└── CMakeLists.txt                 # CMake build configuration
```

### Features

1. Data Structure Visualization:

    - Linked List: Insert, delete, and search operations with visual feedback
    - Binary Search Tree: Tree operations with level-order display
    - Hash Table: Shows buckets, entries, and collision handling


2. Algorithm Visualization:

    - Sorting: Bubble, Selection, Insertion, Merge, and Quick sort with step-by-step visualization
    - Searching: Linear and Binary search with highlighted elements


3. Visual Feedback:

    - Color-coded elements to show the current operation
    - Animated transitions between states
    - Clear display of data structure state after each operation


## Installation 

### Prerequisites 

- C++ compiler with C++ 14 support
- CMake for building

### Building with CMake

```bash
# Clone the repository
git clone https://github.com/HasinduRanasinghe/data_structures_and_algorithms_visualizer.git
cd data_structures_and_algorithms_visualizer

# Create build directory
mkdir build && cd build

# Generate build files and compile
cmake ..
cmake --build .
```
