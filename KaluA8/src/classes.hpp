/*
 * classes.hpp
 *
 *  Created on: May 11, 2022
 *      Author: chiemekakalu
 */

#ifndef CLASSES_HPP_
#define CLASSES_HPP_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle 
{
private:
    string VehicleID;
    string manufacturer;
    string dateEnteredService;
    int capacity;
    char status;  // A = active, I = inactive, M = maintenance
public:
    Vehicle();
    Vehicle(string);
    //Getters 
    string getVehicleID();
    string getManufacturer();
    string getDateEnteredService();
    int getCapacity();
    char getStatus();
    //Setters 
    void setVehicleID(string);
    void setManufacturer(string);
    void setDateEnteredService(string);
    void setCapacity(int);
    void setStatus(char);
    void displayCommonMembers();
    virtual void virtualDisplayFunction();
    virtual void checkMaintenance();
};

bool idSearch(Vehicle * vehiclearray[], string searchID, int &index);

class Bus: public Vehicle 
{
public:
    int mileageSinceInspection;
    string tireSize;
    int fuelTankSize;
    Bus();
    Bus(string);
    virtual void virtualDisplayFunction();
    virtual void checkMaintenance();
};

class MiniBus: public Vehicle
{
    public:
        int mileageSinceInspection;
        int upTime;
        char fuelType; // 'F' for fossil fuel, 'E' for electric
        MiniBus();
        MiniBus(string);
        virtual void virtualDisplayFunction();
        virtual void checkMaintenance();
};

class LightRail : public Vehicle
{
    public:
        int upTime;
        string motorType;
        char wheelType;
        LightRail();
        LightRail(string);
        virtual void virtualDisplayFunction();
        virtual void checkMaintenance();
};






#endif /* CLASSES_HPP_ */
