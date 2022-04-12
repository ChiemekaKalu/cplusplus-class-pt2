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

Bus::Bus(){

	history = new MaintHist[25];
	numMH = 0;

}
Bus::~Bus(){

	delete [] history;

}

bool Bus::operator==(Bus rhs)
{
	if(this->numMH == rhs.numMH)
	{

		return true;
	}
	else
	{
		return false;
	}

}

bool Bus::operator>(Bus rhs)
{
	if(this->numMH > rhs.numMH)
	{

		return true;
	}
	else
	{
		return false;
	}

}


void Bus::operator=(Bus& rhs)
{

	this->manufacturer = rhs.manufacturer;
	this->capacity = rhs.capacity;
	this->mileage = rhs.mileage;
	rhs.status = 'n';
}
