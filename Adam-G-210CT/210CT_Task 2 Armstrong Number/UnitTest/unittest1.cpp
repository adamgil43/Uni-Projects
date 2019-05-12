#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\210CT_Task 2\armstrong.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(TestArmstrong)
	{
	public:
		
		TEST_METHOD(TestTrue)
		{
			// TODO: Your test code here
			Assert::AreEqual(armstrong(371), 371);
			Assert::AreEqual(armstrong(153), 153);
			Assert::AreEqual(armstrong(370), 370);
			Assert::AreEqual(armstrong(407), 407);
		}
		TEST_METHOD(TestFalse)
		{
			Assert::AreNotEqual(armstrong(1233), 1233);
			Assert::AreNotEqual(armstrong(1633), 1633);
			Assert::AreNotEqual(armstrong(372), 371);
			Assert::AreNotEqual(armstrong(2000), 2000);
		}
		TEST_METHOD(WrongInput)
		{
			Assert::IsFalse(checkInt("Hello"));
			Assert::IsFalse(checkInt("9823o"));
			Assert::IsFalse(checkInt("-0"));
		}
	};
}