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


    displayEverything(busArray);

    cout << endl;



    string userEntry = "";
    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
    getline(cin, userEntry);
    string entrySubString;

    while(userEntry != "X")
    {
    	entrySubString = userEntry.substr(0,1);
    	if(entrySubString == "D")
    	{
    		displayCH();
    		for(int i = 0; i < Bus::numberOfBus; i++)
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
            cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
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

                if(busArray[busdex].numMH == 0){

                	cout << "No maitanence history to display" << endl;
                }else
                {
                	cout << "Start of maintenance history" << endl;
                	for(int i = 0; i < busArray[busdex].numMH; i++)
                	{
                		cout << "History element "  << i << "-" << busArray[busdex].history[i].maintDate << " , " << busArray[busdex].history[i].maintType << " , " << busArray[busdex].history[i].maintMechanic << endl;
                	}
                }

                cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                getline(cin, userEntry);
                continue;
            }
            else
            {
                cout << "Bus not found" << endl;
                cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                getline(cin, userEntry);
                continue;
            }
            }
            else if(entrySubString == "C")
            {
                int busdex = 0;
                int busdex2 = 0;
                string busIDsearch = "";
                string busIDsearch2 = "";

                cout << "Enter bus ID" << endl;
                getline(cin, busIDsearch);
                if(busIDSearch(busArray, busIDsearch, busdex) == false)
                {
                    cout << "Bus not found" << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;
                }else{
                    cout << "Bus 1 found" << endl;
                }
                cout << "Enter second bus ID" << endl;
                getline(cin, busIDsearch2);
                if(busIDSearch(busArray, busIDsearch2, busdex2) == false)
                {
                    cout << "Bus not found" << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;
                }else{
                	cout << "Bus 2 found" << endl;
                }

                if(busArray[busdex].numMH > busArray[busdex2].numMH)
                {

                    cout << "Bus " << busArray[busdex].getBusID() << " has more maitanence history than bus " << busArray[busdex2].getBusID() << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;

                }else
                {

                    cout << "Bus " << busArray[busdex].getBusID() << " does not have more maitanence history than bus " << busArray[busdex2].getBusID() << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;
                }

                cout << "Checking for equal maitanence history" << endl;
                if(busArray[busdex].numMH == busArray[busdex2].numMH)
                {
                    cout << busArray[busdex].getBusID() << " has equal history to " << busArray[busdex2].getBusID() << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;
                }
                else
                {
                    cout << "The two busses do not have equal history" << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;
                }
            }else if (entrySubString == "M")
            {
                int busdex = 0;
    		    string busIDsearch = "";
                cout << "Enter bus ID" << endl;
                getline(cin, busIDsearch);
                if(busIDSearch(busArray, busIDsearch, busdex))
                {
                    cout << "Beginning maitanence record" << endl;
                    cout << "Enter maitenance date" << endl;
                    getline(cin, userEntry);
                    busArray[busdex].history->maintDate = userEntry;
                    cout << "Enter maitenance type" << endl;
                    getline(cin, userEntry);
                    busArray[busdex].history->maintType = userEntry;
                    cout << "Enter maitenance mechanic" << endl;
                    getline(cin, userEntry);
                    busArray[busdex].history->maintMechanic = userEntry;
                    cout << "Maintenance added" << endl;
                    busArray[busdex].numMH++;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                }
                else
                {
                    cout << "Bus not found" << endl;
                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    continue;
                }

            }else if (entrySubString == "N")
            {
                int busdex = 0;
                int currentBus = Bus::numberOfBus;
                string busIDsearchToSearch = "";
                string newBusID;

                cout << "Enter bus ID for the new bus" << endl;
                getline(cin, newBusID);

                cout << "Enter bus ID for existing bus" << endl;
                getline(cin, busIDsearchToSearch);

                if(busIDSearch(busArray, busIDsearchToSearch, busdex))
                {

                    busArray[currentBus] = busArray[busdex];
                    busArray[currentBus].setBusID(newBusID);
                    busArray[currentBus].setStatus('n');

                    cout << "Bus " << busArray[currentBus].getBusID() << " has been created" << endl;

                    cout << "Enter transaction code (D = display, M to add maitanence, L = list a bus, C = Change, N to add new bus, X = exit," << endl;
                    getline(cin, userEntry);
                    Bus::numberOfBus++;
                    continue;

                }else
                {

                    cout << "existing bus not found" << endl;
                }



            }

    	}



    cout << "Goodbye!" << endl;
	return 0;

    }


