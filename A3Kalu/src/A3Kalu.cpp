
// Cs2 Assignment 3


#include <fstream>
#include "ageCalc.h"
#include "student.h"

int studentarraysize = 100;

int main() {
    char parsearray[52];
    char firstNameC[11];
    char middleName[11];
    char lastName[21];
    char studentID[10];
    char age[4];


    ifstream inFile;
	inFile.open("/Users/chiemekakalu/Downloads/a2data.input", ios::in);
	if(!inFile.is_open())
	{
		cout << "open failure" << endl;
		exit (1);
	}


    student * students[studentarraysize];


    for(int i = 0; i <= studentarraysize; i++){

        students[i] = nullptr;
    }

    int currentstudent = 0;


    inFile.read(parsearray, 52);

    while(!inFile.eof())
        {

            students[currentstudent] = new student;

            string temp = "";

            for(int i = 0; i < 10; i++)
                 {
                      firstNameC[i] = parsearray[i];
                 }

            firstNameC[10] = '\0';

            temp = firstNameC;

            students[currentstudent]->firstName = temp;


           for(int i = 0; i < 10; i++)
                {
                    middleName[i] = parsearray[i+10];
                }
                middleName[10] = '\0';

                temp = middleName;

                students[currentstudent]->middleIntial = temp[0];

                for(int i = 0; i < 20; i++)
                {
                    lastName[i] = parsearray[i+20];
                }
                lastName[20] = '\0';

                temp = lastName;
                students[currentstudent]->lastName = temp;

                for(int i = 0; i < 10; i++)
                {
                    studentID[i] = parsearray[i+41];
                }
                studentID[9] = '\0';

                temp = studentID;
                students[currentstudent]->studentID = temp;

                students[currentstudent]->campusCode = parsearray[40];

                for(int i = 0; i < 4; i++)
                {
                    age[i] = parsearray[i+50];
                }
                age[3] = '\0';

                students[currentstudent]->age = atoi(age);

                currentstudent++;
                inFile.read(parsearray, 52);
            }






    cout << "FirstName";
    cout << " ";
    cout << "MiddleInitial";
    cout << " ";
    cout << "LastName";
    cout << "  ";
    cout << "IDCode";
    cout << " ";
    cout << "CampusCode";
    cout << " ";
    cout << "Age";
    cout << endl;
    cout << "=================================================";
    cout << endl;

    int reader = 0;
    while(students[reader] != nullptr){

    	cout << students[reader]->firstName;

    	cout << " ";

    	cout << students[reader]->middleIntial;

    	cout << "  ";

    	cout << students[reader]->lastName;

    	cout << " ";

    	cout << students[reader]->studentID;

    	cout << " ";

    	cout << students[reader]->campusCode;

    	cout << " ";

    	cout << students[reader]->age;

    	cout << " ";

    	cout << endl;

    	reader++;
    }

    cout << "=================================================";


      cout << endl;
      cout << endl;



      student * youngestStudent;
      cout << "The average age is " << ageCalc(students,youngestStudent) << "." << endl;
      cout << "The youngest student is " << youngestStudent->firstName << "and he is " << youngestStudent->age << " years old." << endl;

      cout << endl;




    cout << "Closing File and cleaning up memory..." << endl;
    inFile.close();

    int deleter = 0;
    while (students[deleter] != nullptr)
    {
    	delete students[deleter];
    	deleter++;
    }
    cout << endl;


    cout << "File closed and memory cleaned. Goodbye!" << endl;

    cout << endl;

    cout << "                             ------> banana <------" << endl;

    return 0;
}




