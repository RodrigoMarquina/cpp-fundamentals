#include <iostream>
#include <string>

using namespace std;

int runPointers() {

    int num = 3;
    int &ref = num;
    int *ptr = &ref;                                // You can also use the original variable: int *ptr = &num;

    cout << "Adress of Pointer: " << ptr << endl;   // Prints the address: Adress of Pointer: 0x7ffd0650eda4

    //Dereference
    cout << "Value of Pointer: " << *ptr << endl;   // Print the actual value of the pointer: Value of Pointer: 3

    *ptr = 5;

    cout << "Adress of Pointer: " << ptr << endl; 

    cout << "Value of Pointer: " << *ptr << endl;

    cout << sizeof(ptr) << endl;                    // Prints the size in bytes

    //New
    int *newPtr = new int;                          // Creates one space of memory for the new int
    *newPtr = 35;                                   // Stores the number inside the memory
    cout << *newPtr << endl;                        // Prints the number

    //When you create something with new, it's your job to remove it when you're done.

    //Delete
    delete newPtr;

    return 0;
}


