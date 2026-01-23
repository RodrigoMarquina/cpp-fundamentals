/* 
void process(Data d);        // takes a copy
void process(const Data& d); // borrows, read-only
void process(Data& d);       // borrows, modifies
void process(Data* d);       // optional / nullable
*/

#include <iostream>

using namespace std;

int increaseByTen(int num, int num2 = 0) { // We set the default value 
  cout << num << endl;
  return num2 + 10;
}

int duplicateNum(int number){ //Using a reference avoids creating a copy
  return number*2;
}

float duplicateNum(float number){ //Overloading
  return number*2;
}

int recurseToGoal(int y){ //Recursion
  if(y >= 10){
    return y;
  }
  return recurseToGoal(y + 1);
}

int runFunctions() {
  //cout << increaseByTen(0) << endl;

  int x = 9;

  cout << duplicateNum(x) << endl;

  int y = 1;

  cout << recurseToGoal(y) << endl;

  return 0;

}


