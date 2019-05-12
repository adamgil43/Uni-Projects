// ArmstrongsNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "armstrong.h"
using namespace std;

int main()
{
	string userNum;
	cout << "Please enter a positive number ";
	cin >> userNum;
	//While loop to check if user input is valid
	while (!checkInt(userNum))
	{
		cout << "That is not a positive integer\n";
		cout << "Please enter a postive integer\n";
		cin >> userNum;
	}

	int intUserNumb = stoi(userNum);
	//checks if number is armstrong
	int check = checkArm(intUserNumb, armstrong(intUserNumb));
	if (check == true)
	{
		cout << "The number " << intUserNumb << " is an Armstrong Number.";
		cin.get();
	}
	else
	{
		cout << "The number " << intUserNumb << " is not an Armstrong Number";
		cin.get();
	}
	cin.get();
	return 0;
}
