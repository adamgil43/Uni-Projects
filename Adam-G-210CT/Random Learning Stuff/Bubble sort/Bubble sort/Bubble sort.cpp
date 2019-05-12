// Bubble sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int *bubble_sort(int seq[], int length)
{
	int temp;
	int count = 0;
	int swapN = 0;
	bool swap = true;
	while (swap == true)
	{
		swap = false;
		for (int i = 0; i < length - 1; i++)
		{
			count++;
			if (seq[i] > seq[i + 1])
			{
				swapN++;
				swap = true;
				temp = seq[i + 1];
				seq[i + 1] = seq[i];
				seq[i] = temp;
			}
			cout << "[";
			for (int i = 0; i < length; i++)
			{
				if (i == length - 1)
				{
					cout << seq[i];
				}
				else
				{
					cout << seq[i] << ", ";
				}
			}
			cout << "]\n";

		}
	}
	cout << swapN;
	return seq;
}

int main()
{
	int sequence[10] = { 2,7,9,4,1,5,3,6,0,8 };
	int *newSeq = bubble_sort(sequence, 10);
	cin.get();
	return 0;
}

