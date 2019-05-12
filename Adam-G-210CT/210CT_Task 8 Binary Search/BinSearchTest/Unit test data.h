#pragma once

int *newArr()
{
	int myArr[20000];
	for (int i = 0; i < 20000; i++)
	{
		myArr[i] = i + 1;
	}
	return myArr;
}

/*
Take the number 100;
100 will be in the list;
check number and loop untill it is found.

*/