#include <iostream>  
#include <string>

using namespace std;

void runLoops() {    
	//Switch 
	int day = 4;
	switch (day) {
		case 6:
			cout << "Today is Saturday";
			break;
		case 7:
			cout << "Today is Sunday";
			break;
		default:
			cout << "Looking forward to the Weekend";
	}

	//Do While
	int i = 10;
	do {
		cout << "i is " << i << "\n";
		i++;
	} while (i < 5);

	//While
	int countdown = 3;
	while (countdown > 0) {
		cout << countdown << "\n";
		countdown--;
	}
	cout << "Happy New Year!!\n";

	//For loop
	for (int i = 1; i <= 10; i = i + 2) {
  		cout << i << "\n";
	}	

	//For each loop
	int numbersList[5] = {10, 20, 30, 40, 50};

	for(int num : numbersList){
		cout << num << endl; 
	}

	//Break
	i = 0;
	while (i < 10) {
		cout << i << "\n";
		i++;
		if (i == 4) {
			break;
		}
	}

	//Continue
	i = 0;
	while (i < 10) {
		if (i == 4) {
			i++;
			continue;
		}
		cout << i << "\n";
		i++;
	}
}