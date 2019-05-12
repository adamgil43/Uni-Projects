#pragma once
#include <string>
#include <iostream>
#include <string>
using namespace std;

/*
Purpose of this program is to understand how algorithms work
A function that takes two inputs and then combines them
*/
string combineStrings(string word1, string word2)
{
	//find out the lengths of the word
	int j = word1.length();
	int k = word2.length();
	string newWord; //initialise new word
	if (j > k || j == k){ //check which word is longer
		for (int i = 0; i < k; i++){
			newWord += word1[i];
			newWord += word2[i];
		}
		for (int i = k; i < j; i++){
			newWord += word1[i];
		}
	}
	if (k > j){
		for (int i = 0; i < j; i++){
			newWord += word1[i];
			newWord += word2[i];
		}
		for (int i = j; i < k; i++){
			newWord += word2[i];
		}
	}
	return newWord;
}
