//============================================================================
// Name        : KaluA6.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "String.hpp"

ostream& operator << (ostream &os, String str)
{
	for(int i = 0; i < str.length; i++)
	{
		os << str.string[i];
	}
	return os;
}


int main() {

	// Test for string assignment using literal
	String a;

	a = "abcdef";

	cout << "String a is equal to: " << a << " with length " << a.getLength() << endl;

	// Test for string assignment using string

	String b;

	b = a;

	cout << "String b is equal to: " << b << " with length " << b.getLength() << endl;

	String x = b = a;

	cout << "String x is equal to b equal to a and x = " << x << " with a length of " << x.getLength() << endl;

	// Testing [] Overload

	// Replacement should work now

	char c = a[0];    // Should be equal to 'a'

	cout << "a[0] ---> " << c << endl;

	String toBeReplaced = "ABC";

	cout << "String replacement test. String to be replaced == " << toBeReplaced << endl;

	String replacement = "DEF";

	cout << "String for replacement characters == " << replacement << endl;

	cout << "Replacing first character of 1st string with 2nd string" << endl;

	toBeReplaced[0] = replacement[0];

	cout << "Replaced string is equal to " << toBeReplaced << endl;

	// Testing == Overload

	String cc = "ABC";
	String d = "ABC";

	if(cc == d)
	{

		cout << "Comparison is working when strings are equal" << endl;
	}
	else
	{

		cout << "Comparison isn't working" << endl;
	}

	String ee = "ABCD";
	String ff = "abc";

	if(ee == d)
	{

		cout << "Comparison isn't working on the not equal" << endl;
	}
	else
	{

		cout << "Comparison is also working when they aren't equal" << endl;
	}

	// Other shit to test goes below here




	return 0;
}
