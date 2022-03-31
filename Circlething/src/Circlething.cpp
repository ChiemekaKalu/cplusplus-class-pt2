//============================================================================
// Name        : Circlething.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Circle
{
private:
	float radius;
	float diameter;
	float circumference;
	float area;
public:
// Member Functions V
void setRadius(float r)
{
	radius = r;

}
void doTheCalculations()
{
	diameter = 2*radius;
	circumference = 3.14 * diameter;
	area = 3.14 * radius * radius;
}
float getArea()
{
	return area;
}

Circle()
{
	cout << "in constructor" << endl;
	radius = 0;
	diameter = 0;
	circumference = 0;
	area = 0;
}

};

// Getters get  things from private places getArea
// Getters are also known as accessors
// Setters set the private things setRadius
// Setters are also known as mutators
// Member function also known as methods

int main() {

	Circle c1;
	c1.setRadius(2); // Objectname.membername
	Circle c2;
	c2.setRadius (43.4);
	c1.doTheCalculations();
	c2.doTheCalculations();
	float a = c1.getArea();
	cout << a << endl;


	// Case 3 from the other stuff
		Circle * p; // New Circle pointer
		p = new Circle; // Dynamic circle
		p->setRadius(6); // Dereferencing of p to access the new circle

	// Case 5 from the other thing
		Circle * pa[100]; // 100 Circle pointers
		pa[0] = new Circle;
		pa[0]->setRadius(7);
		delete pa[0];





	return 0;
}
