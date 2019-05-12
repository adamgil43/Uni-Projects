#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "linearSearch.h"

int main()
{
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
	if (result != 0)
	{
		cout << "The number " << element << " is the list.\n";
	}
	else
	{
		cout << "The number " << element << " is not in the list.\n";
	}
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

/*
int max_value = 1000;
ofstream outputFile;
outputFile.open("Tnumbers.txt");
for (int i = 1; i < 1000; i++)
{
int rand_int = (rand() % max_value);
outputFile << rand_int << " ";
}
outputFile.close();
cout << endl;

*/