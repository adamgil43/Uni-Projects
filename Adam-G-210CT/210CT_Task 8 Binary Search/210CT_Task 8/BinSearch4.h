#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int maxNum = 20000;
int minNum = 0;
int answer;

string checkInput(string input)
{
	if (input == "Y" || input == "y" || input == "L" || input == "l" || input == "h" || input == "H") return input;
	else
	{
		cout << "Please enter Y, H or L \n";
		cin >> input;
		return checkInput(input);
	}
}
/*
Binary search for finding if a number is with the list
Uses user input to find out.
*/
int binarySearch(int arr[], int length, int count)
{
	int mid = length/2;
	int number = arr[mid-1];
	count++;
	string userAnswer;
	cout << "Is your number " << number << "? (Enter Y, H or L)\n";
	cin >> userAnswer;
	string check = checkInput(userAnswer);
	if (count > 15)
	{
		return -1;
	}
	if (number < 2 || number > 20000)
	{
		if (check == "Y" || check == "y") return number;
		else return -1;
	}
	if (check == "Y" || check == "y") return number;
	if (check == "L" || check == "l")
	{
		return binarySearch(arr, length / 2, count);
	}
	if (check == "H" || check == "h")
	{
		return binarySearch(arr + mid + 1, length - (mid + 1), count);
	}
	else
	{
		return binarySearch(arr, (mid * 2), count);
	}
}
/*
Binary search for unit testing
No user input required.
Exactly the same as above, but with no user validation.
*/


int binSearch(int number, int arr[], int length, int count)
{
	int mid = length / 2;
	int midNumber = arr[mid - 1];
	count++;
	if (number <= 0 || number > 20000)
	{
		return -1;
	}
	if (number == midNumber)
	{
		return count;
	}
	if (number < midNumber)
	{
		return binSearch(number, arr, length / 2, count);
	}
	if (number > midNumber)
	{
		return binSearch(number, arr + mid + 1, length - (mid + 1), count);
	}
	else
		return -1;
}