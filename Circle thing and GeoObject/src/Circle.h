#include <iostream>
using namespace std;


#ifndef xyz
#define cyz

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

#endif
