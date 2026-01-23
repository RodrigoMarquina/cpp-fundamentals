#include <iostream>  
#include <string>  

using namespace std;

struct {
    string structureName;
    int numberInside;
    char grade;
} struct1, struct2;

/*
✔ Anonymous type
✔ Variables created immediately
❌ Type cannot be referenced again
❌ Cannot create more instances elsewhere
*/

struct student {
    string name;
    int age;
    char grade;
};

/*
✔ Reusable type
✔ Can be passed to functions
✔ Can be stored in containers
✔ Can be extended later
*/

void runStructures() {      

    struct1.numberInside = 2;
    char gradeStudent = struct2.grade = 'D';
    cout << gradeStudent  << endl;

    student jimi;
    jimi.name = "Jimi";
    jimi.age = 20;
    jimi.grade = 'A';
    cout << jimi.name << "\n";
}