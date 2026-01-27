#include <iostream>

using namespace std;

void runExceptions() {
  int age;
  cin >> age;

  try {
    if(age >= 18){
      cout << "You are old enough to enter the club." << endl;
    } else {
      throw(age);
    }
  } catch (int age) {
      cout << "You are not old enough to enter the club." << endl;
  }
}