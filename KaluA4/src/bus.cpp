#include "bus.hpp"


string Bus::getBusID()
{

	return BusID;
}

string Bus::getManufacturer(){

	return manufacturer;
}

int Bus::getCapacity(){

	return capacity;
}

int Bus::getMileage()
{
	return mileage;

}

char Bus::getStatus(){

	return status;
}

void Bus::setStatus(char s)
{

	status = s;
}

void Bus::setBusID(string id)
{
	BusID = id;

}

void Bus::setManufacturer(string m)
{

	manufacturer = m;
}

void Bus::setCapacity(int c)
{

	capacity = c;
}

void Bus::setMileage(int m)
{
	mileage = m;
}


// string getBusID();
/*
 *
 * class Bus
{
private:
    string BusID;
    string manufacturer;
    int capacity;
    int mileage;
    char status;
public:

    static int numberOfBus;

   string getBusID()
    {
        return BusID;
    }
   string getManufacturer()
    {
        return manufacturer;
    }
   int getCapacity()
    {
        return capacity;
    }
    int getMileage()
    {
        return mileage;
    }
    char getStatus()
    {
        return status;
    }

    void setStatus(char s)
    {
        status = s;
    }

    void setBusID(string id)
    {
        BusID = id;
    }
    void setManufacturer(string m)
    {
        manufacturer = m;
    }
    void setCapacity(int c)
    {
        capacity = c;
    }
    void setMileage(int m)
    {
        mileage = m;
    }

};
 *
 */
