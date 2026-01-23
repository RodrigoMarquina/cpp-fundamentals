cmake_minimum_required(VERSION 3.16)
project(cpp_fundamentals)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_fundamentals
    src/main.cpp
    src/Basics/00_program_structure.cpp
    src/Basics/01_variable_types.cpp
    src/Basics/02_operators.cpp
    src/Basics/03_conditions.cpp
    src/Basics/04_loops.cpp
    src/Basics/05_arrays.cpp
    src/Basics/06_functions.cpp
    src/Basics/07_structures.cpp
    src/Basics/08_enums.cpp
    src/Basics/09_references.cpp
    src/Basics/10_pointers.cpp
    src/test.cpp
)