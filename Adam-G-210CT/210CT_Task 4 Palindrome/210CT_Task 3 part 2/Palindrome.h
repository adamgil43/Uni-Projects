#pragma once
#include <vector>
using namespace std;


/*
Function to test if a list of integers is a palindrome;
that is, when it's reveresed it looks like the same list.
*/
bool checkIfPalindrom(vector<int> pal)
{
	int length = pal.size();
	vector<int> reverse;
	for (int i = 0; i < length; i++)
	{
		reverse.push_back(pal[length - 1 - i]);
	}
	for (int i = 0; i < length / 2; i++)
	{
		if (reverse[i] != pal[i])
		{
			return false;
		}
	}


	return true;
}