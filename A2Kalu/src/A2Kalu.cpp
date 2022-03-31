//============================================================================
// Name        : A2Kalu.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 2
//============================================================================

#include <iostream>
using namespace std;

class Employee {
private:
	string employeeName;
	float hours;
	float rate;
	float regularPay;
	float overtimePay;
	float totalpay;
public: // This where the member functions going to go
	void setName(string s){

		employeeName = s;

	}
	void setHours(float h){

		hours = h;
	}
	void setRate(float r){

		rate = r;
	}
	string getName(){

		return employeeName;
	}
	float getHours(){

		return hours;

	}
	float getRate(){

		return rate;
	}
	float getPay(){

		return regularPay;
	}
    float getOvertimePay(){

        return overtimePay;
    }
    float getTotalPay(){

        return totalpay;
    }

    void calculatePay(){

        if(hours <= 40){
            regularPay = hours * rate;
            totalpay = regularPay;
        }
        else{
            regularPay = 40 * rate;
            overtimePay = (hours - 40) * (rate * 1.5);
            totalpay = regularPay + overtimePay;
        }

    }


	Employee(){

        employeeName = "";
        hours = 0;
        rate = 0;
        regularPay = 0;
        overtimePay = 0;
        totalpay = 0;

    }

};


int main() {

    string currentlyentering = "";

    Employee * e[100];
    int employeesentered = 0;
    cout << "ENTER ""STOP"" TO STOP" << endl;
    int i = 0;
    string nameOfEmployee;
    string hoursWorked;
    string rate;


    while (currentlyentering != "STOP")
    {
    	string nameOfEmployee = "";
    	string hoursWorked = "";
    	string rate = "";

    	e[i] = new Employee();
        cout << "Enter the name of the employee: ";
        getline(cin, nameOfEmployee);
        e[i]->setName(nameOfEmployee);
        cout << "Enter the hours worked: ";
        getline(cin, hoursWorked);
        e[i]->setHours(stof(hoursWorked));
        cout << "Enter the rate: ";
        getline(cin, rate);
        e[i]->setRate(stof(rate));
        e[i]->calculatePay();
        employeesentered++;
        cout << "Enter another employee? (ENTER STOP or anything else):";
        getline(cin, currentlyentering);
        i++;
    }




    for (int i = 0; i < employeesentered; i++)
    {
    	cout << "---------------------------------------------";
    	cout << endl;
    	cout << "Name: " << e[i]->getName() << endl;
    	cout << "Hours: " << e[i]->getHours() << endl;
    	cout << "Rate: " << e[i]->getRate() << endl;
    	cout << "Regular Pay: " << e[i]->getPay() << endl;
    	cout << "Overtime Pay: " << e[i]->getOvertimePay() << endl;
    	cout << "Total Pay: " << e[i]->getTotalPay() << endl;
    	cout << "---------------------------------------------";
    	cout << endl;

    }

    float totaltotalpay = 0;

    for (int i = 0; i < employeesentered; i++)
    {

    	totaltotalpay += e[i]->getTotalPay();
    }


    cout << "Total payroll: " << totaltotalpay << endl;

	cout << "Thanks for using my program";



	return 0;
}
