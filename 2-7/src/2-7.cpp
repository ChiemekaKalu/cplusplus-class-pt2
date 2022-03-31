//============================================================================
// Name        : 2-7.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Feb 7 Notes" << endl;

		cout << endl;
		cout << endl;


	// Individual ints using pointer array

	int * pa[100];
	int i;
	for (i = 0; i <100; i++){

		pa[i] = new int;
	}

	*pa[37] = 99; // Dereferences the pointer @ element 37 and makes that new int value 99

	// Sum up all the ints

	int sum = 0;
	for (i = 0; i<100; i++)
	{
		sum = sum + *pa[i];
	}

	cout << sum;




	return 0;

}


