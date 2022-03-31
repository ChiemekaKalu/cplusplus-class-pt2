/*
 * IceCream.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: chiemekakalu
 *
 *
 *
 *
 */

#include "IceCream.h"

IceCream::IceCream()
{

	flavor = "vanilla";
	temp = 0.0f;
	quantity = 0;
	cupcone = BOTH;

}

void IceCream::pickFlavor(string s)
{

	flavor = s;
}

void IceCream::addScoop()
{
	quantity++;
}

string IceCream::getFlavor()
{
	return flavor;
}


void IceCream::melt()
{
	temp += 5.0f;
	quantity--;
}

void IceCream::eat()
{
	quantity = 0;

}

void IceCream::addTopping(string tarr[], const int SIZE)
{
	for (int i = 0; i < 5; i++)
	{
		toppings[i] = "";
	}
	for (int i = 0; i < SIZE; i++)
	{
		toppings[i] = tarr[i];
	}
}


void IceCream::removeTopping(string tarr[], const int SIZE)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (toppings[i] == tarr[j])
			{
				toppings[i] = "";
			}
		}
	}
}

void IceCream::setCupCone(cob cs2)
{
	cupcone = cs2;

}

cob IceCream::getCupCone()
{

	return cupcone;
}


void IceCream::printToppings()
{
	for (int i = 0; i < 5; i++)
	{
		cout << toppings[i] << endl;

	}

}

IceCream::IceCream(string f)
{

	flavor = f;
	temp = 0.0f;
	quantity = 0;
	cupcone = BOTH;

}

void IceCream::addTopping(string t, int i)
{
	toppings[i] = t;
}





