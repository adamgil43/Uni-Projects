#pragma once
#include <string>

/* Function to multiply polynomails*/
int *multiplyPols(int Poly1[], int Poly2[], int m, int n)
{
	int size = (m)+(n); //Takes the size of the first poly and second and adds them together to get the length of the 3rd
	int *res = new int[size];
	for (int i = 0; i < size; i++)
	{
		res[i] = 0;
	}
	//Nested for loop used because you're multiplying
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i + j] = res[i + j] + Poly1[i] * Poly2[j];
		}
	}
	return res;
}

//Check if user input is valid
bool checkIfInt(std::string userInput)
{
	int length = userInput.length();
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(userInput[i]))
		{
			return false;
		}
	}
	return true;
}