//============================================================================
// Name        : 3-9.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Airplane{
public:
	string mfr;
	string model;
	int tailNum;
	int capacity;
	void memberFunction();
	static int numberOfPlanes;
	static int totalCapacity;
	static int numberOfBoeings;
	static void xyz();

};

// outside any function
	 int Airplane::numberOfPlanes;
	 int Airplane::totalCapacity;
	 int Airplane::numberOfBoeings;

	void Airplane::memberFunction()
	{

	}

	void Airplane::xyz()
	{
		numberOfPlanes=55;

	};



int main() {
	int numberOfPlanes = 0;
	Airplane::xyz();
	Airplane p1;
	Airplane::numberOfPlanes++;
	numberOfPlanes--;
	Airplane p2;
	Airplane::numberOfPlanes++;
	Airplane p3;
	Airplane::numberOfPlanes++;

	cout << Airplane::numberOfPlanes << endl;

// here
	Airplane * p;
	p = &p1;
	cout << p << endl;
	int * ip;
	ip = &p1.capacity;
	cout << ip << endl;
	return 0;
}
