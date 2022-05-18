/*
 * classes.cpp
 *
 *  Created on: May 11, 2022
 *      Author: chiemekakalu
 */

#include "classes.hpp"

//VEHICLE CONSTRUCTORS
Vehicle::Vehicle()
{
    cout << "In Vehicle Constructor" << endl;
}

Vehicle::Vehicle(string input)
{

    VehicleID = input.substr(0,5);
    manufacturer = input.substr(5,15);
    dateEnteredService = input.substr(20,8);
    capacity = stoi(input.substr(28,3));
    status = input.at(31);
}

//GETTERS

string Vehicle::getVehicleID()
{
    return VehicleID;
}

string Vehicle::getManufacturer()
{
    return manufacturer;
}

string Vehicle::getDateEnteredService()
{
    return dateEnteredService;
}

int Vehicle::getCapacity()
{
    return capacity;
}

char Vehicle::getStatus()
{
    return status;
}

// SETTERS

void Vehicle::setVehicleID(string VehicleID)
{
    this->VehicleID = VehicleID;
}

void Vehicle::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Vehicle::setDateEnteredService(string dateEnteredService)
{
    this->dateEnteredService = dateEnteredService;
}

void Vehicle::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void Vehicle::setStatus(char status)
{
    this->status = status;
}

// Constructors for Bus

Bus::Bus()
{
    cout << "In Bus Constructor" << endl;
}

Bus::Bus(string input) : Vehicle(input)
{
    this->mileageSinceInspection = stoi(input.substr(32,6));
    this->tireSize = input.substr(38,9);
    this->fuelTankSize = stoi(input.substr(47,3));
}
\
// Constructors for MiniBus

MiniBus::MiniBus()
{
    cout << "In MiniBus Constructor" << endl;
}

MiniBus::MiniBus(string input) : Vehicle(input)
{
    this->mileageSinceInspection = stoi(input.substr(32,6));
    this->upTime = stoi(input.substr(38,4));
    this->fuelType = input.at(42);
}

// Constructors for LightRail

LightRail::LightRail()
{
    cout << "In LightRail Constructor" << endl;
}

LightRail::LightRail(string input) : Vehicle(input)
{
    this->upTime = stoi(input.substr(32,3));
    this->motorType = input.at(36);
    this->wheelType = input.at(37);
}


// Display Function

void Vehicle::displayCommonMembers()
{
    cout << "Vehicle ID: " << this->VehicleID << endl;
    cout << "Manufacturer: " << this->manufacturer << endl;
    cout << "Date Entered Service: " << this->dateEnteredService << endl;
    cout << "Capacity: " << this->capacity << endl;
    cout << "Status: " << this->status << endl;
}

// Virtual Display Functions

void Vehicle::virtualDisplayFunction()
{
    cout << "In Vehicle Virtual Display Function" << endl;
}

void Bus::virtualDisplayFunction()
{
    this->displayCommonMembers();
    cout << "Mileage Since Inspection: " << this->mileageSinceInspection << endl;
    cout << "Tire Size: " << this->tireSize << endl;
    cout << "Fuel Tank Size: " << this->fuelTankSize << endl;
}

void MiniBus::virtualDisplayFunction()
{
    this->displayCommonMembers();
    cout << "Mileage Since Inspection: " << this->mileageSinceInspection << endl;
    cout << "Up Time: " << this->upTime << endl;
    cout << "Fuel Type: " << this->fuelType << endl;
}

void LightRail::virtualDisplayFunction()
{
    this->displayCommonMembers();
    cout << "Up Time: " << this->upTime << endl;
    cout << "Motor Type: " << this->motorType << endl;
    cout << "Wheel Type: " << this->wheelType << endl;
}

// Virtual Maitenance Functions

void Vehicle::checkMaintenance()
{
    cout << "In Vehicle Virtual Maitenance Function" << endl;
}

void Bus::checkMaintenance()
{
    if(this->mileageSinceInspection >= 15000)
    {
        cout << "Mileage Since Inspection is greater than 15000, entering service." << endl;
        this->setStatus('M');
    }
    else
    {
        cout << "Mileage Since Inspection is less than 15000. Vehicle does not need maitanence" << endl;
    }
}

void LightRail::checkMaintenance()
{
    if(this->upTime >= 1000)
    {
        cout << "Vehicle uptime is greater than 1000 hours. Vehicle needs maitanecence." << endl;
        this->setStatus('M');
    }
    else
    {
        cout << "Vehicle uptime is less than 1000 hours. Vehicle does not need maitanence." << endl;
    }
}

void MiniBus::checkMaintenance()
{
    if(this->fuelType == 'E')
    {
        if(this->upTime > 1000)
        {
            cout << "Vehicle uptime is greater than 1000 hours, entering service." << endl;
            this->setStatus('M');
        }

    }
    else
    {
        if(this->mileageSinceInspection > 15000)
        {
            cout << "Mileage Since Inspection is greater than 15000, entering service." << endl;
            this->setStatus('M');
        }
    }

    cout << "Vehicle does not need maitanence." << endl;

}



//Random Search I needed

bool idSearch(Vehicle * vehiclearray[], string searchID, int &index)
{
    for(int i = 0; i < 18; i++)
    {
        if(vehiclearray[i]->getVehicleID() == searchID)
        {
            index = i;
            return true;
        }
    }
    return false;
}

// This did not work as I thought it would since I was passing in a pointer array but it takes pointer to the array