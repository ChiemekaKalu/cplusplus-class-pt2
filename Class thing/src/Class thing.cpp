//============================================================================
// Name        : Class.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "IceCream.h"
using namespace std;

int main() {

	IceCream obj1;
	cout << obj1.getFlavor() << endl;
	obj1.pickFlavor("Chocolate");
	cout << obj1.getFlavor() << endl;

	IceCream obj2;
	string newToppings[2] = {"peanuts", "hot fudge"};
	obj2.addTopping(newToppings, 2);
	obj2.printToppings();


	IceCream obj3("strawberry"); // This uses our overloaded constructor that accepts a string

	cout << obj3.getFlavor();
	obj3.eat();
	cout << "You pick a flavor: ";
	string userFlavor;
	getline(cin, userFlavor);
	obj3.pickFlavor(userFlavor);

	IceCream * obj4;
	obj4 = new IceCream("Chocolate"); // Dynamnic Ice Cream with overloaded constructor
	obj4->addTopping("vegan gummy worms", 4);
	obj4->printToppings();








	return 0;
}
