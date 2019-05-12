// Selection Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int *selectSort(int seq[], int length)
{
	int temp;
	int smallest;
	int count = 0;
	int compare = 0;
	for (int i = 0; i < length - 1; i++)
	{
		smallest = i;
		count++;
		for (int j = i + 1; j < length; j++)
		{
			if (seq[j] < seq[smallest])
			{
				compare++;
				smallest = j;
			}
			else
			{
				compare++;
			}
		}
		temp = seq[i];
		seq[i] = seq[smallest];
		seq[smallest] = temp;
	}
	cout << "Count " << count;
	cout << "compare" << compare++;
	return seq;
}

int main()
{
	int sequence[10] = { 2,7,9,4,1,5,3,6,0,8 };
	int *newSeq = selectSort(sequence, 10);
	cin.get();
    return 0;
}

