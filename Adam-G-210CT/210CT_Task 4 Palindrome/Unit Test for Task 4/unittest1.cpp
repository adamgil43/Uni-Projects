#include "stdafx.h"
#include "CppUnitTest.h"
#include "../210CT_Task 3 part 2/Palindrome.h"
#include <vector>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforTask4
{		
	TEST_CLASS(TestforTrues)
	{
	public:
		vector<int> P1 = { 1,1,2,2,1,1 };
		vector<int> P2 = { 2,2,3,3,2,2, };
		vector<int> P3 = { 1,2,3,2,1 };
		vector<int> P4 = { 7,8,9,9,8,7 };
		vector<int> P5 = { 1,2,3,4,5 };
		vector<int> P6 = { 1,1,2,2,3,3,2,2,1,1,1 };
		vector<int> P7 = { 0,0,0,1,1,0 };
		vector<int> P8 = { 8,9,10,9,8,1 };
		vector<int> P9 = { 'a','a','a','b','a','a','a' };
		vector<int> P10 = { 'i','a','i','a','i','z' };
		TEST_METHOD(IsPalindrome)
		{
			// TODO: Your test code here
			Assert::IsTrue(checkIfPalindrom(P1));
			Assert::IsTrue(checkIfPalindrom(P2));
			Assert::IsTrue(checkIfPalindrom(P3));
			Assert::IsTrue(checkIfPalindrom(P4));
			Assert::IsTrue(checkIfPalindrom(P9));

		}
		TEST_METHOD(IsNOTPalindrome)
		{
			Assert::IsFalse(checkIfPalindrom(P5));
			Assert::IsFalse(checkIfPalindrom(P6));
			Assert::IsFalse(checkIfPalindrom(P7));
			Assert::IsFalse(checkIfPalindrom(P8));
			Assert::IsFalse(checkIfPalindrom(P10));
		}

	};
}