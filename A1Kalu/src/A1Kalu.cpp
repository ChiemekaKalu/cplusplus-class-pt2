
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void dynAlloc (int, int * &); // Done
void insertionSort (int *, int, int *); // Working on it
void displayArray (int *, int); // Done
int linearSearch (int *, int, int, int &); // Done
int binarySearch (int *, int, int, int &); // Done

int main() {

	int IterationCounter = 0;
	int& linearSearchIterations = IterationCounter; // Variable for the functions
	int& binarySearchIterations = IterationCounter; // Variable for the functions
	int LinearSearchValue = 0; // Variable for the functions
	int BinarySearchValue = 0; // Variable for the functions
	int searching = 0;

	// Declare the pointers
	int * unsortedarray;
	int * sortedarray;

	// Dynamic Allocation of the arrays
	dynAlloc(100, unsortedarray);
	dynAlloc(100, sortedarray);


	// Random seeding
	srand(time(0));
	for(int i = 0; i <= 100; i++)
	{
		unsortedarray[i] = 1 + (rand() % 50);
	}

	// Print array1
	displayArray(unsortedarray, 100);

	// Sort array 2
	insertionSort(unsortedarray, 100, sortedarray);

	cout << endl;
	cout << endl;
	cout << endl;

	// Display array2
	displayArray(sortedarray, 100);

	cout << endl;
	cout << endl;

	// Searching

	cout << "Would you like to search? Enter -1 to end the search or any other number for Yes" << endl;
	cin >> searching;

	while((searching != -1))
	{

		if((searching != -1))
		{
			cout << "What value would you like to search for ?" << endl;
			cin >> LinearSearchValue;
			cout << "Invoking linear search" << endl;

			if(linearSearch(sortedarray,100,LinearSearchValue,linearSearchIterations) != -1)
			{

				cout << "Your Value is at index " << linearSearch(sortedarray, 100, LinearSearchValue,linearSearchIterations) << endl;
				cout << "It took " << linearSearchIterations << " Iterations" << endl;

			}
			else if(linearSearch(sortedarray,100,LinearSearchValue,linearSearchIterations) == -1)
			{
				cout << "Search failed." << endl;
				cout << "Iterations:" << linearSearchIterations << endl;

			}


			cout << "What value would you like to search for ? Now using binary search" << endl;
			cin >> BinarySearchValue;

			if(binarySearch(sortedarray,100,BinarySearchValue,binarySearchIterations) != -1)
			{

				cout << "Your Value is at index " << binarySearch(sortedarray, 100, BinarySearchValue,binarySearchIterations) << endl;
				cout << "It took " << binarySearchIterations << " Iterations" << endl;;

			}
			else if(binarySearch(sortedarray,100,BinarySearchValue,binarySearchIterations) == -1)
			{
				cout << "Search failed." << endl;
				cout << "Iterations:" << binarySearchIterations << endl;

			}


		}

		cout << "Would you like to continue searching? Enter -1 for no." << endl;
		cin >> searching;

	}


	cout << "Thanks for using my program. Goodbye!" << endl;
	return 0;

}

void dynAlloc (int arraysize, int * &a) // Works
{

	a = new int[arraysize];
	return;
}

void displayArray(int * aa, int a) // Works
{
	for(int i = 0; i < a; i++){
		if(i % 5 == 0){ cout << endl; }
		cout << aa[i] << " ";
	}
}

void insertionSort (int * unsortedarray, int arraysize, int * sortedarray) // WIP
{
	for (int i = 0; i < arraysize; i++)
	{
		sortedarray[i] = unsortedarray[i];

	}

	int i = 1;

	while (i < arraysize)
	{
		int j = i;

		while ((j > 0) && (sortedarray[j-1] > sortedarray[j]))
		{
			int temp = sortedarray[j];
			sortedarray[j] = sortedarray[j-1];
			sortedarray[j-1] = temp;
			j--;
		}
		i++;
	}

}


int binarySearch (int * searcharray, int arraysize , int searchval, int& iterations) // To my knowledge this works
{
	bool found = false;
	int low = 0;
	int high = arraysize - 1;
	int mid = 0;
	int index = 0;
	while (low <= high && found == false)
	{
		mid = (low + high) / 2;

		if (searcharray[mid] < searchval)
		{
			low = mid + 1;
		}
		else if(searcharray[mid] > searchval)
		{
			high = mid - 1;

		}
		else
		{
			found = true;
		}
		iterations++;
	}
	if(found == false)
	{
		index = -1;
	}
	else
	{
		index = mid;
	}
	return index;
}



int linearSearch(int * searcharray, int arraysize , int searchval, int& iterations) // Works
{
    int i = 0;
    int found = 0;

    while (i < arraysize && found == 0)
    {
        if (searcharray[i] == searchval)
        {
            found = 1;
        }
        else
        {
            i++;
        }
    }

    iterations = i;

   if (found == 1)
    {
        return i;
    }
   else
    {
        return -1;
    }
}


