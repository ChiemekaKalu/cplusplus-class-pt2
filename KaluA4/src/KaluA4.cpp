//============================================================================
// Name        : KaluA4.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "bus.hpp"
#include "functions.hpp"
#include <fstream>


const int busArraySize = 50;





int Bus::numberOfBus;



int main(){


    // Bus ID 5 characters
    // Manufacturer 10 characters
    // Capacity 3 characters
    // Mileage 7 mileage
    // 1 Status

    ifstream inFile;
	inFile.open("/Users/chiemekakalu/Downloads/a4data.txt", ios::in);

    cout << "Opening file" << endl;

    if(!inFile.is_open())
	{
		cout << "open failure" << endl;
		exit (1);
	}

    cout << "File opened" << endl;

    Bus busArray[busArraySize];


    int i = 0;
    string BigString = "";
    string temp = "";
    getline(inFile, BigString);
    while(!inFile.eof()){

    	temp = BigString.substr(0,5);
    	busArray[i].setBusID(temp);

    	temp = BigString.substr(5,10);
    	busArray[i].setManufacturer(temp);

    	temp = BigString.substr(15, 3);
    	busArray[i].setCapacity(stoi(temp));

    	temp = BigString.substr(18, 7);
    	busArray[i].setMileage(stoi(temp));

    	busArray[i].setStatus(BigString[25]);

    	Bus::numberOfBus++;
        i++;
        getline(inFile, BigString);
    }






    string userEntry = "";
    cout << "Enter transaction code (D = display, L = list a bus, C = Change, X = exit" << endl;
    getline(cin, userEntry);
    string entrySubString;

    while(userEntry != "X")
    {
    	entrySubString = userEntry.substr(0,1);
    	if(entrySubString == "D")
    	{
    		displayCH();
    		for(int i = 0; i < 10; i++)
    		{
    			cout << busArray[i].getBusID();
    			cout << "     ";
    			cout << busArray[i].getManufacturer();
    			cout << "     ";
    			cout << busArray[i].getCapacity();
    			cout << "      ";
    			cout << busArray[i].getMileage();
    			cout << "       ";
    			cout << busArray[i].getStatus();
    			cout << endl;
    		}
    		userEntry = "";
    	    cout << "Enter transaction code (D = display, L = list a bus, C = Change, X = exit" << endl;
    	    getline(cin, userEntry);
    	}
    	else if(entrySubString == "L")
    	{
            int busdex = 0;
    		string busIDsearch = "";
    		busIDsearch = userEntry.substr(2, 5);

//    		Bus * bussearchpointer;
//    		bussearchpointer = busArray;

            if(busIDSearch(busArray, busIDsearch, busdex))
            {
                displayCH();
                cout << busArray[busdex].getBusID();
                cout << "     ";
                cout << busArray[busdex].getManufacturer();
                cout << "     ";
                cout << busArray[busdex].getCapacity();
                cout << "      ";
                cout << busArray[busdex].getMileage();
                cout << "       ";
                cout << busArray[busdex].getStatus();
                cout << endl;
                cout << "Enter transaction code (D = display, L = list a bus, C = Change, X = exit" << endl;
                getline(cin, userEntry);
                continue;
            }
            else
            {
                cout << "Bus not found" << endl;
                cout << "Enter transaction code (D = display, L = list a bus, C = Change, X = exit" << endl;
                getline(cin, userEntry);
                continue;
            }
            }
            else if(entrySubString == "C")
            {

                string busIDsearch = "";
                busIDsearch = userEntry.substr(2, 5);
                int busdex = 0;
                if(busIDSearch(busArray, busIDsearch, busdex))
                {
                    displayCH();
                    cout << busArray[busdex].getBusID();
                    cout << "     ";
                    cout << busArray[busdex].getManufacturer();
                    cout << "     ";
                    cout << busArray[busdex].getCapacity();
                    cout << "      ";
                    cout << busArray[busdex].getMileage();
                    cout << "       ";
                    cout << busArray[busdex].getStatus();
                    cout << endl;
                    cout << "Enter new status" << endl;
                    getline(cin, userEntry);
                    busArray[busdex].setStatus(userEntry[0]);
                    cout << "Changed" << endl;
                    cout << "Enter transaction code (D = display, L = list a bus, C = Change, X = exit" << endl;
            	    getline(cin, userEntry);
                }
                else
                {
                    cout << "Bus not found" << endl;
                    cout << "Enter transaction code (D = display, L = list a bus, C = Change, X = exit" << endl;
                    getline(cin, userEntry);
                    continue;
                }
            }


    	}

    cout << "Goodbye!" << endl;
	return 0;

    }


