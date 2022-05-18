//============================================================================
// Name        : KaluA8.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "classes.hpp"

int main(){

	// Opening the file
	ifstream inFile;
	inFile.open("/Users/chiemekakalu/Downloads/a8data.txt", ios::in);
    cout << "Opening file" << endl;
    if(!inFile.is_open())
	{
		cout << "open failure" << endl;
		exit (1);
	}
    cout << "File opened" << endl;



	Vehicle * vehicles[100];
	for(int i = 0; i < 100; i++)
	{
		vehicles[i] = nullptr;
	}
	string input;
	// Position 0: B = Bus, M = MiniBus, L = LightRail
	int vehicleCount = 0;
	getline(inFile, input);
	while(!inFile.eof())
	{
		if(input[0] == 'B')
		{
			vehicles[vehicleCount] = new Bus(input);
			vehicleCount++;
		}
		else if(input[0] == 'M')
		{
			vehicles[vehicleCount] = new MiniBus(input);
			vehicleCount++;
		}
		else if(input[0] == 'L')
		{
			vehicles[vehicleCount] = new LightRail(input);
			vehicleCount++;
		}

		getline(inFile, input);
	}

	cout << endl;

	for(int i = 0; i < vehicleCount; i++)
	{
		vehicles[i]->virtualDisplayFunction();
		cout << endl;
	}

	int index = 0;
	string query = "";

	cout << "Enter vehicle ID to search: ";
	getline(cin, query);

	while(query != "00000")
	{
		if(idSearch(vehicles, query, index))
		{
			cout << "Vehicle found at index: " << index << endl;
			vehicles[index]->checkMaintenance();
		}
		else
		{
			cout << "Vehicle not found" << endl;
		}
		cout << "Enter vehicle ID to search: ";
		getline(cin, query);
	}

	for(int i = 0; i < vehicleCount; i++)
		{
			vehicles[i]->virtualDisplayFunction();
			cout << endl;
		}


	return 0;
}
