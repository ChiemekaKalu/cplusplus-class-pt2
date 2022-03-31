//============================================================================
// Name        : Classlength.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Airplane
{
// Members
// Public or Private
private:
	string manufacturer;
	string model;
	int tailNumber;
public:
	string airline;
	int numPass;
	string seat[100];

	//member functions

	void increaseCapacity()
	{
		numPass = numPass + 1;
		cout << tailNumber << endl;
	}


};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Airplane p1;
	p1.airline = "United";
	cout << p1.numPass << endl;
//	p1.tailNumber = p1.tailNumber + 1; Would not work because its a private member

	p1.increaseCapacity();


	return 0;
}
