/*
 * bus.hpp
 *
 *  Created on: Mar 20, 2022
 *      Author: chiemekakalu
 */

#ifndef BUS_HPP_
#define BUS_HPP_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MaintHist
{
public:
	string maintDate;
	string maintType;
	string maintMechanic;

};

class Bus
{
private:
    string BusID;
    string manufacturer;
    int capacity;
    int mileage;
    char status;
public:

    MaintHist * history;
    int numMH;


   static int numberOfBus;

   string getBusID();
   string getManufacturer();
   int getCapacity();
   int getMileage();
   char getStatus();
   void setStatus(char);
   void setBusID(string);
   void setManufacturer(string );
   void setCapacity(int);
   void setMileage(int);
   Bus();
   ~Bus();

   bool operator==(Bus);
   bool operator>(Bus);
   void operator=(Bus&);


};




#endif /* BUS_HPP_ */
