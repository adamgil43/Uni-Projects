// Binary Search.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int maxNum = 20000;
int minNum = 1;
int answer;

int binarySearch(int arr[], int length)
{
	int mid = length / 2;
	int number = arr[mid];
	string userAnswer;
	if (number < 1 || number > 20000)
	{
		return -1;
	}
	cout << "Is your number " << number << "? (Enter Y, H or L)\n";
	cin >> userAnswer;
	if (userAnswer == "Y" || userAnswer == "y")
	{
		return number;
	}
	if (userAnswer == "L" || userAnswer == "l")
	{
		return binarySearch(arr, mid);
	}
	if (userAnswer == "H" || userAnswer == "h")
	{
		return binarySearch(arr + mid + 1, length - (mid + 1));
	}
	else
	{
		return binarySearch(arr, (mid * 2));
	}
}

int main()
{
	int sequence[20000];
	for (int i = 0; i < 20000; i++)
	{
		sequence[i] = i+1;
	}
	int len = sizeof(sequence) / sizeof(sequence[0]);
	int guess = binarySearch(sequence, len);
	if (guess == -1)
	{
		cout << "You're number is not in the list ";
	}
	cin.get();
    return 0;
}