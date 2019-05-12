#pragma once  
#include <string>  
#include <iostream>  
#include <cmath>  
/* Function to calculate the value of the number when you take their digits
and then raise them to the power of 3 and then add them*/
int armstrong(int integer)
{
	//I used an iterative function because they are much more efficient  
	//If this was going to be a larger number, it would take longer to do a recursive function  
	int digit;
	int total = 0;
	while (integer != 0)
	{
		digit = integer % 10;
		total += digit * digit * digit;
		integer /= 10;
	}
	return total;//base case  
}
//function to compare if the number is an armstrong number  
bool checkArm(int number, int armstrong)
{
	if (number == armstrong) return true;
	else return false;
}
//check if user has entered valid input.  
bool checkInt(std::string testNum)
{
	int length = testNum.length();
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(testNum[i])) return false;
	}
	return true;
}