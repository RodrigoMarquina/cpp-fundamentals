/* 
int - stores integers (whole numbers), without decimals, such as 123 or -123
double - stores floating point numbers, with decimals, such as 19.99 or -19.99
char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
string - stores text, such as "Hello World". String values are surrounded by double quotes
bool - stores values with two states: true or false
*/

#include <iostream>
#include <string>

using namespace std;

int runVariableTypes() {
    // Declare Many Variables
    int a = 5, b = 6, c = 50;
    cout << a + b + c;          

    // Display the input value   
    int x, y, z;
    x = y = z = 50;
    cout << x + y + z;          

    x = 5;
    cout << x;

    const int minutesPerHour = 60;

    int myNum = 5;               // Integer (whole number)
    float myFloatNum = 5.99;     // Floating point number
    double myDoubleNum = 9.98;   // Floating point number
    char myLetter = 'D';         // Character
    bool myBoolean = true;       // Boolean
    string myText = "Hello";     // String
    auto autoVariable = 5;              // auto, will turn to int

    return 0;
}
