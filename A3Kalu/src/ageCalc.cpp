#include "ageCalc.h"

int ageCalc(student * a[], student * & b)
{
    // Student Average Age
    int i = 0;
    int sum = 0;
    int count = 0;
    while(a[i] != nullptr)
    {
        sum += a[i]->age;
        count++;
        i++;
    }

    // Youngest Age Calculator
    int j = 0;
    int youngestAge = a[j]->age;
    int indextracker = 0;

    while(a[j] != nullptr)
    {
        if(a[j]->age < youngestAge)
        {
            youngestAge = a[j]->age;
            indextracker = j;
        }
        j++;

        b = a[indextracker];
    }

    return sum/count;
}
