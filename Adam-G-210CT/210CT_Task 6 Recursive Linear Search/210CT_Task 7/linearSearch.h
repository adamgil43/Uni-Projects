#pragma once
#include <vector>
using namespace std;

/*
Recursive linearSearch for finding a number in an array or vector
*/
int linearSearch(vector<int> numbers, int element, int i)
{
	i = i - 1;//prevents out of range 
	if (i < 0)//end of array, means it's not in the list
	{
		return 0;
	}
	else if (numbers[i] == element)//if its found it, hurray! Return 1.
	{
		return 1;
	}
	else {
		return linearSearch(numbers, element, i--); //if list is no 0, recursivley go through the list until it is or element is found
	}
}