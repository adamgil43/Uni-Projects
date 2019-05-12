#include "stdafx.h"
#include "CppUnitTest.h"
#include "../210CT_Task 3/MultiplyingPols.h"
#include "testData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace UnitTest1
{		
	TEST_CLASS(FirstPolynomail)
	{
	public:
		int P1[3] = { 3,1,9 };
		int P2[4] = { 2,1,2,1 };
		int *res = multiplyPols(P1, P2, 3, 4);
		TEST_METHOD(TestFirstPoly)
		{
			Assert::AreEqual(test(res, 0), 6);
			Assert::AreEqual(test(res, 1), 5);
			Assert::AreEqual(test(res, 2), 25)
		}
		TEST_METHOD(WrongInput1)
		{
			Assert::IsFalse(checkIfInt("Hello"));
			Assert::IsFalse(checkIfInt("-093424"));
		}
	};
	TEST_CLASS(SecondPolynomail)
	{
	public:
		int P1[4] = { 2,8,2,9 };
		int P2[3] = { 3,5,7 };
		int *res = multiplyPols(P1, P2, 4, 5);
		TEST_METHOD(TestSecondPoly)
		{
			Assert::AreEqual(test(res, 0), 6);
			Assert::AreEqual(test(res, 1), 34);
			Assert::AreEqual(test(res, 2), 60);
		}
		TEST_METHOD(WrongInput)
		{
			Assert::IsFalse(checkIfInt("dfss"));
			Assert::IsFalse(checkIfInt("-035"));
		}
	};
}