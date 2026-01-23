/*
Here are some common operators in C++, from highest to lowest priority:

() - Parentheses
*, /, % - Multiplication, Division, Modulus
+, - - Addition, Subtraction
>, <, >=, <= - Comparison
==, != - Equality
&& - Logical AND
|| - Logical OR
= - Assignment
*/

#include <iostream>

using namespace std;

int runOperators() {
    int x = 10;
    int y = 3;
    cout << (x + y) << "\n"; // 13
    cout << (x - y) << "\n"; // 7
    cout << (x * y) << "\n"; // 30
    cout << (x / y) << "\n"; // 3 (integer division)
    cout << (x % y) << "\n"; // 1
    int z = 5;
    ++z;
    cout << z << "\n"; // 6
    --z;
    cout << z << "\n"; // 5

    int savings = 100; 
    savings += 50; // add 50 to savings
    cout << "Total savings: " << savings;

    int passwordLength = 5;
    cout << (passwordLength >= 8) << "\n"; // 0 (false), too short  
    cout << (passwordLength < 8) << "\n";  // 1 (true), needs more characters   

    return 0;
}


