#include "functions.hpp"


void displayCH()
{

	cout << "******************************************************************************************" << endl;

	cout << "BUSID " << "BUS MANUFACTURER " << "BUS CAPACITY " << "BUS Mileage " << "BUS STATUS " << endl;

	cout << "******************************************************************************************" << endl;

}

bool busIDSearch(Bus busArray[], string query, int &busIndex)
{

    for(int i = 0; i < 50; i++)
    {
        if(busArray[i].getBusID() == query)
        {
            busIndex = i;
            return true;
        }
    }
    return false;
}

void displayEverything(Bus busArray[])
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
}
