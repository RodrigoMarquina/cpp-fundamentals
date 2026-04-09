//#include "node.hpp"

#include <iostream>
#include <string>

using namespace std;

void runProgramStructure();
void runVariableTypes();
void runOperators();
void runConditions();
void runLoops();
void runArrays();
void runFunctions();
void runStructures();
void runEnums();
void runReferences();
void runPointers();
void runExceptions();
void runClassesObjects();
void runInheritance();
void runPolymorphism();
void runFiles();
void runLinkedList();
void runTest();

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Run program: \n "
        "ProgramStructure = 0 \n "
        "Variable Types = 1 \n "
        "Operators = 2 \n "
        "Conditions = 3 \n "
        "Loops = 4 \n "
        "Arrays = 5 \n "
        "Functions = 6 \n "
        "Structures = 7\n "
        "Enums = 8 \n "
        "References = 9 \n "
        "Pointers = 10 \n ";
        "Exceptions = 11 \n"
        "Objects & Classes = 12 \n ";
        "Inheritance = 13 \n ";
        "Polymorphism = 14 \n ";
        "Files = 15 \n ";
        "Linked List = 16 \n ";
        return 1;
    }

    string mode = argv[1];

    if (mode == "0") {
        runProgramStructure();
    } else if (mode == "1") {
        runVariableTypes();
    } else if (mode == "2") {
        runOperators();
    } else if (mode == "3") {
        runConditions();
    } else if (mode == "4") {
        runLoops();
    } else if (mode == "5") {
        runArrays();
    } else if (mode == "6") {
        runFunctions();
    } else if (mode == "7") {
        runStructures();
    } else if (mode == "8") {
        runEnums();
    } else if (mode == "9") {
        runReferences();
    } else if (mode == "10") {
        runPointers();
    } else if (mode == "11") {
        runExceptions();
    } else if (mode == "12") {
        runClassesObjects();
    } else if (mode == "13") {
        runInheritance();
    } else if (mode == "14") {
        runPolymorphism();
    } else if (mode == "15") {
        runFiles();
    } else if (mode == "16") {
        runLinkedList();
    } else {
        cout << "Unknown mode\n";
    }

    return 0;
}

