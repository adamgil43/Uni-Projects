// Binary Search.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "BinSearch4.h"
int main()
{
	int sequence[20000];
	for (int i = 0; i < 20000; i++)
	{
		sequence[i] = (i + 1);
	}
	int len = sizeof(sequence)/sizeof(sequence[0]);
	int guess = binarySearch(sequence, len, 0);
	if (guess == -1)
	{
		cout << "You're number was not found";
	}
	else
	{
		cout << "I have found your number " << guess << "!\n";
	}
	cin.get();
	cin.get();
	return 0;
}