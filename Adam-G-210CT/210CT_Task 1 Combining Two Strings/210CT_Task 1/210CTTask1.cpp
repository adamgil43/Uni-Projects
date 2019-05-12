// 210CTTask1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "combiningStrings.h"
using namespace std;

int main()
{
	string word1;
	string word2;
	getline(cin, word1);
	getline(cin, word2);
	string newWord = combineStrings(word1, word2);
	cout << newWord;
	cin.get();
	cin.get();
	return 0;
}