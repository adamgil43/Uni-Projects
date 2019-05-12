// UnitTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <gtest\gtest.h>
using namespace std;



int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


