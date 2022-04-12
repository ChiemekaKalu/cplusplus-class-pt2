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

