#include "stdafx.h"
#include "CppUnitTest.h"
#include "../210CT_Task 7/linearSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLinearSearch
{		
	TEST_CLASS(ArrayTest1)
	{
	public:
		TEST_METHOD(FoundAllTrue)
		{
			vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < arr.size(); i++)
			{
				int result = linearSearch(arr, (i+1), arr.size());
				Assert::IsTrue(result);
			}
			// TODO: Your test code here
		}
		TEST_METHOD(NotFoundTrue)
		{
			vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < arr.size() / 2; i++)
			{
				int result = linearSearch(arr, (i + 11), arr.size());
				Assert::IsFalse(result);
			}
		}

	};
}