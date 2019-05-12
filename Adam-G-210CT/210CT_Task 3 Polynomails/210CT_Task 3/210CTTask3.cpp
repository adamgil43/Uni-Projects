// 210CTTask3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MultiplyingPols.h"
using namespace std;

int main() {
	int FirstDeg, SecDeg, numbers;
	cout << "Please enter the degrees of your first polynomail\n";
	while (!(cin >> FirstDeg) || FirstDeg < 0)
	{
		cout << "must be a positive number:\n";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> FirstDeg;
	}
	cout << "\nPlease enter the degrees of your second polynomail\n";
	cin >> SecDeg;
	int *P1 = new int(FirstDeg + 1);
	int *P2 = new int(SecDeg + 1);
	cout << "\nPlease enter the coeffiecients for your first polynomail\n";
	cout << "You need to enter " << FirstDeg + 1 << " numbers, one at a time\n";
	for (int i = 0; i < (FirstDeg + 1); i++)
	{
		cin >> numbers;
		P1[i] = numbers;
	}
	cout << "\nPlease enter the coeffiecients for your second polynomail\n";
	cout << "You need to enter " << SecDeg + 1 << " numbers, one at a time\n";
	for (int i = 0; i < (SecDeg + 1); i++)
	{
		cin >> numbers;
		P2[i] = numbers;
	}
	int *res = multiplyPols(P1, P2, FirstDeg+1, SecDeg+1);
	cout << "\nYou're multiplied polynomail is\n";

	cin.get();
	return 0;
}