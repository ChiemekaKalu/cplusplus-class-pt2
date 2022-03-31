//============================================================================
// Name        : Cstring.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{

	char a[6];
	a[0] = 'h';
	a[1] = 'e';
	a[2] = 'l';
	a[3] = 'l';
	a[4] = 'o';
	a[5] = 0;

	// Making the end with a null char
	// Makes this a "cstring" or a "null-terminated" string
	//



	cout << "--->" << a << "<---" << endl;

	char * p;
	p = new char[10];
	p[0] = 'h';
	p[1] = 'e';
	p[2] = 'l';
	p[3] = 'l';
	p[4] = 'o';
	p[5] = '\0';

	cout << "--->" << p << "<---" << endl;



	// Stringname = char array name; C string to string conversion
	// C string to numeric conversion atoi, atot, atod.







	return 0;
}
