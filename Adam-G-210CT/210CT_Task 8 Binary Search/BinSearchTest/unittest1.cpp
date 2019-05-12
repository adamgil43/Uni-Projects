#include "stdafx.h"
#include "CppUnitTest.h"
#include "Unit test data.h"
#include "../210CT_Task 8/BinSearch4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinSearchTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int sequence[20000];
		TEST_METHOD(TestMethod1)
		{
			for (int i = 0; i < 20000; i++)
			{
				sequence[i] = i + 1;
			}
			int length = sizeof(sequence) / sizeof(sequence[0]);
			int guess = binSearch(10000, sequence, length, 0);
			int guess1 = binSearch(5000, sequence, length, 0);
			int guess2 = binSearch(3356, sequence, length, 0);
			int guess3 = binSearch(1, sequence, length, 0);
			int guess4 = binSearch(20000, sequence, length, 0);
			int guess5 = binSearch(-1, sequence, length, 0);
			int guess6 = binSearch(200001, sequence, length, 0);
			Assert::AreEqual(guess, 1);
			Assert::AreEqual(guess1, 2);
			Assert::AreEqual(guess2, 12);
			Assert::AreEqual(guess3, 14);
			Assert::AreEqual(guess4, 15);
			Assert::AreEqual(guess5, -1);
			Assert::AreEqual(guess6, -1);
		}

	};
}