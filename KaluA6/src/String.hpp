/*
 * String.hpp
 *
 *  Created on: Apr 17, 2022
 *      Author: chiemekakalu
 */


#ifndef STRING_HPP_
#define STRING_HPP_

#include <iostream>
#include <string>
using namespace std;

class String
{
private:
    int length;
public:
    char * string;
    String();
    void operator=(const char[]);
    String(const String&);
    String operator=(String);
    ~String();
    String(const char[]);
    char& operator[](int);
    bool operator==(String);
    friend ostream& operator<<(ostream&, String);
    int getLength();

};








#endif /* STRING_HPP_ */
