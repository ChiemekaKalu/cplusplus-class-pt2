#include "String.hpp"

string OutOfBounds = "Error. Out of bounds. Try a number below 100";

int size = 100;


// Constructs a String object with a default value of "" and length 0, creates new char array
String::String()
{
    length = 0;
    string = new char[size];
    string[0] = '\0';
}


// Constructs a String object with whatever value is passed in as a char array, creates new char array
void String::operator=(const char str[])
{
	length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        string[i] = str[i];
    }

    string[length] = '\0';
};



String::String(const String& str)
{
	this->length = str.length;
	this->string = new char[length];

    for(int i = 0; i < str.length; i++)
    {
        this->string[i] = str.string[i];
    }    

};

int String::getLength()
{
    return length;
};

String String::operator=(String str)
{
    this->length = str.length;

    for(int i = 0; i < str.length; i++)
    {
        this->string[i] = str.string[i];
    }    

    this->string[length] = '\0';

    return *this;

};

// Works
String::~String()
{
	// cout << "Destructor working" << endl;
    delete [] string;

};

String::String(const char str[])
{
    length = strlen(str);
    string = new char[100];
    string[0] = '\0';

    for(int i = 0; i < length; i++)
    {
        string[i] = str[i];
    }

    while(string[length] != '\0')
        {
            length++;
        }

    string[length] = '\0';

};

char& String::operator[] (int index)
{
	if(index >= 100)
	{
		throw(OutOfBounds);
	}
    return string[index];
};

bool String::operator==(String str)
{
    if(length != str.length)
    {
        return false;
    }

    for(int i = 0; i < length; i++)
    {
        if(string[i] != str.string[i])
        {
            return false;
        }
    }

    return true;
};




