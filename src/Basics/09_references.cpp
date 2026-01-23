//A reference is an alias for a variable. We use the & operator to create it.

#include <iostream>
#include <string>

using namespace std;

struct goblin {
    string name;
    int age;
};

int runReferences() {

    goblin redGoblin;

    string &name = redGoblin.name;

    name = "Red Goblin";

    cout << "name variable \"" << name  << "\" address: " << &name << endl;
    cout << "redGoblin.name \"" << redGoblin.name << "\" address: " << &redGoblin.name << endl;

    redGoblin.name = "Gus";
    cout << "Named changed..." << endl;

    cout << "name variable \"" << name  << "\" address: " << &name << endl;
    cout << "redGoblin.name \"" << redGoblin.name << "\" address: " << &redGoblin.name << endl;


    return 0;
}

//Note: Both variables refer to the same memory location. Changing one affects the other.