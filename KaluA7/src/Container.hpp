/*
 * Container.hpp
 *
 *  Created on: May 2, 2022
 *      Author: chiemekakalu
 */

#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_



#include <iostream>
using namespace std;

string ElementDNE = "Element does not exist";
string OutOfBounds = "Element requested is out of bounds and doesn't exist";
template <class Key, class ValueType>
class Container {
	private:
	public:
	int Size;
	int count;

	Key  * keyarray;
	ValueType * valuearray;

	Container(int containerSIZE)
	{
		Size = containerSIZE;
		keyarray = new Key[Size];
		valuearray = new ValueType[Size];
		count = 0;
	}

	~Container()
	{
		delete [] keyarray;
		delete [] valuearray;
	}

	Key key(int index)
	{
		if(index >= count){

			throw(ElementDNE);
		}else
		{
			return keyarray[index];
		}
	}

	ValueType data(int index)
	{
		if(index >= count) 				// If the index the user wants to retrieve is the same or greater than the amount of objects
		{								// pushed back (count), then it should throw the exception
			throw(ElementDNE);
			}
			else
			{
			return valuearray[index];
			}
	}


	bool push_back(Key key, ValueType value)
	{
	 	if(count < Size)
	 	{
	 		keyarray[count] = key;
	 		valuearray[count] = value;
	 		count++;
	 		return true;
	 	}
	 	else
	 	{
	 		return false;
	 	}
	 }

	int max_size()
	{
		return Size;
	}

	int size()
	{
		return count;
	}

	bool retrieve_by_key(Key key, ValueType &value)
	{
		for(int i = 0; i < count; i++)
		{
			if(keyarray[i] == key)
			{
				value = valuearray[i];
				return true;
			}
		}
		return false;
	}

	ValueType operator[](int index)
	{
		if(index >= count)
		{
			throw(OutOfBounds);
		}
		else
		{
			return valuearray[index];
		}

	}

};


#endif /* CONTAINER_HPP_ */
