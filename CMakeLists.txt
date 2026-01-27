cmake_minimum_required(VERSION 3.16)
project(cpp_fundamentals)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_fundamentals
    src/main.cpp
    src/1_Basics/00_program_structure.cpp
    src/1_Basics/01_variable_types.cpp
    src/1_Basics/02_operators.cpp
    src/1_Basics/03_conditions.cpp
    src/1_Basics/04_loops.cpp
    src/1_Basics/05_arrays.cpp
    src/1_Basics/06_functions.cpp
    src/1_Basics/07_structures.cpp
    src/1_Basics/08_enums.cpp
    src/1_Basics/09_references.cpp
    src/1_Basics/10_pointers.cpp
    src/1_Basics/11_exceptions.cpp
    src/2_OOP/12_classes_objects.cpp
    src/2_OOP/13_inheritance.cpp
    src/2_OOP/14_polymorphism.cpp
    src/2_OOP/15_files.cpp
    src/test.cpp
)