// Insertion Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int *insertion_sort(int seq[], int length)
{
	int key = 0;
	int j = 0;
	int move = 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		key = seq[i];
		j = i;
		count++;
		while (j > 0 && seq[j - 1] > key)
		{
			count++;
			seq[j] = seq[j - 1];
			j = j - 1;
			move++;
		}
		seq[j] = key;
	}
	cout << move << endl;
	cout << count;
	return seq;
}

int main()
{
	int sequence[10] = { 2, 7, 9, 4, 1, 5, 3, 6, 0 ,8 };
	int *newSeq = insertion_sort(sequence, 10);
	cout << endl;
	cin.get();
	return 0;
}