// Learningnewcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int *insertionSort(int myArr[], int length)
{
	int j;
	for (int i = 0; i < length; i++) {
		int key = myArr[i];
		j = i;
		while (j > 0 && myArr[j-1] < key)
		{
			myArr[j] = myArr[j - 1];
			j--;
		}
		myArr[j] = key;
	}
	return myArr;
}

int main()
{
	int myArray[8] = { 1,10,23144,242324,23124,124124,12414,948345 };
	int length = 8;
	cout << "The unsorted list is: \n";
	cout << "{";
	for (int i = 0; i < length; i++)
	{
		if (i == (length-1))
		{
			cout << myArray[i] << "}";
		}
		else
			cout << myArray[i] << ", ";
	}
	cout << endl;
	cout << "The sorted list is: \n";
	int *res = insertionSort(myArray, length);
	cout << "{";
	for (int i = length-1; i >= 0; i--)
	{
		if (i == 0)
			cout << res[i] << "}";
		else
			cout << res[i] << ", ";
	}
	cin.get();
	return 0;
}

