/*
 * IceCream.h
 *
 *  Created on: Feb 16, 2022
 *      Author: chiemekakalu
 */

#ifndef ICECREAM_H_
#define ICECREAM_H_
#include <string>
#include <iostream>
using namespace std;

enum cob {
	CUP, CONE, BOTH

};


class IceCream {
private:
	// attributes
	string flavor;
	float temp;
	string toppings[5];
	int quantity;
	cob cupcone;

public:
	IceCream(); // Constructor
	IceCream(string); // Constructor overload
	void melt();
	void pickFlavor(string);
	void addScoop();
	void eat();
	void addTopping(string[], const int);
	void throwAway();
	void removeTopping(string[], const int);
	string getFlavor();
	void setCupCone(cob);
	cob getCupCone();
	void printToppings();

// Overloaded methods
	void addTopping(string, int);


};

#endif /* ICECREAM_H_ */
