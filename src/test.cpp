#include <iostream>  
#include <string>  

using namespace std;

struct student {
    string name;
    int age;
    char grade;
};

void runTest() {     
    cout << "Printing Test " << "\n";     
    student jimi;
    jimi.name = "Jimi";
    jimi.age = 20;
    jimi.grade = 'A';
    cout << jimi.name << "\n";
}