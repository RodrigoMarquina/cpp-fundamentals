#include <iostream>
#include <string>

using namespace std;

int runArrays() {

    string rainbowGoblins[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

    for(string goblin : rainbowGoblins){
        cout << goblin << "\n";
    }

    cout << "The Red goblin retired and the Cardinal Red is the Replacement!" << "\n";

    rainbowGoblins[0] = "Cardinal";

    for(string goblin : rainbowGoblins){
        cout << goblin << "\n";
    }

    //We use vectors for dynamic arrays.

    return 0;
}


