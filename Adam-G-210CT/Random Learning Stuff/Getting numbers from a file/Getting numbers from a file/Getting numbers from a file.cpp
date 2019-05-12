// Getting numbers from a file.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int linearSearch(vector<int> numbers, int element, int i)
{
	i = i - 1;
	if (i < 0)
	{
		return -1;
	}
	else if (numbers[i] == element)
	{
		return 1;
	}
	else {
		return linearSearch(numbers, element, i);
	}
}

int main()
{
	int max_value = INT_MAX/1000;
	ofstream outputFile;
	outputFile.open("Tnumbers.txt");
	for (int i = 1; i < (INT_MAX/1000); i++)
	{
		int rand_int = (rand() % max_value);
		outputFile << rand_int << " ";
	}
	outputFile.close();
	cout << endl;
    return 0;
}

/*
ofstream outputFile;
outputFile.open("Tnumbers.txt");
for (int i = 1; i < 101; i++)
{
outputFile << i << endl;
}
outputFile.close();
*/

/*
vector<int>numbers;
int number;
ifstream File;
int element;
cout << "Enter a number";
cin >> element;
File.open("Tnumbers.txt");
if (File.is_open())
{
while (File >> number) {
numbers.push_back(number);
File.get();
}
}
File.close();
int result = linearSearch(numbers, element, numbers.size());
if (result > 0)
{
cout << "The number " << element << " is the list.";
}
else
{
cout << "The number " << element << " is not in the list.";
}
*/