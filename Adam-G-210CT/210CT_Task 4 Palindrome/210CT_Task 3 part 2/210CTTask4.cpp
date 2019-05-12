// 210CTTask3part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
	vector<int> palindrome = { 1,1,'i',2,3,2,'i',1,1 };
	bool check;
	check = checkIfPalindrom(palindrome);
	cout << endl;
	cout << check;
	cin.get();
	return 0;
}