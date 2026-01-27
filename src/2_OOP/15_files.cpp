#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void runFiles(){
    ofstream ToWriteFile("fileTest.txt");

    ToWriteFile << "Test text to file." << endl;

    ToWriteFile.close();

    string MyText;

    ifstream ToReadFile("fileTest.txt");

    while(getline(ToReadFile, MyText)){
        cout << MyText;
    }

    ToReadFile.close();
}