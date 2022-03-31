//============================================================================
// Name        : 2-28.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream inFile;
	inFile.open("a2data.input", ios::in);
	if(inFile.is_open())
	{
		cout << "open failure" << endl;
		exit (1);
	}

	string input;
	getline(inFile, input);
	cout << "->" << input << "<-" << endl;

	string name;
	float pay;
	float taxRate;
	name = input.substr (0, 25);
	cout << "-> " << name << "<-" << endl;
	pay = stof(input.substr(25, 6));
	taxRate = stof(input.substr (30, 3));
	cout << pay << " " << pay + 1 << endl;


	char inputA[34];
	inFile.read(inputA, 34); // 25 name, 6 pay,  3 taxrate
	char nameA [26];
	char payA[7];
	char taxRateA[4];
	int i, j;
	for (i = 0; i < 25; i++)
	{
		nameA[i] = inputA[i];

	}

	inFile.close();
	return 0;
}



