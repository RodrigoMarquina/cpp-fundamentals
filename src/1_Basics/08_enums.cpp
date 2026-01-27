#include <iostream>

using namespace std;

enum Costs {
    CARROTS = 23,
    POTATOES = 40,
    APPLES = 35
};

int runEnums(){

    enum Costs carrotCost = CARROTS;

    cout << carrotCost << endl; 

    return 0;
}
