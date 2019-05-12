#include "stdafx.h"
#include "CppUnitTest.h"
#include "../210CT_Task 1/combiningStrings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestFullWords)
		{
			string newWord = "HTehlelroe"; //Hello There
			string newWord2 = "DTaiyme"; //Day Time DTaiyme
			string newWord3 = "AGdialmmour"; //Adam Gilmour
			Assert::AreEqual(combineStrings("Hello", "There"), newWord);
			Assert::AreEqual(combineStrings("Day", "Time"), newWord2);
			Assert::AreEqual(combineStrings("Adam", "Gilmour"), newWord3);
		}
		TEST_METHOD(SpacedWords)
		{
			string newWord4 = "HAedlalmo Me"; //Hello Me, Adam
			string newWord5 = "URpisgihdtes iDdoew nUp"; //Upside Down, Rightside Up
			string newWord6 = "SSkuyn  aanndd  SMeoaon"; //Sky and Sea, Sun and Moon
			Assert::AreEqual(combineStrings("Hello Me", "Adam"), newWord4);
			Assert::AreEqual(combineStrings("Upside Down", "Rightside Up"), newWord5);
			Assert::AreEqual(combineStrings("Sky and Sea", "Sun and Moon"), newWord6);
		}
		TEST_METHOD(SpaceAtBegining)
		{
			string newWord7 = " Hello"; // " ", "Hello"
			Assert::AreEqual(combineStrings(" ", "Hello"), newWord7);
		}
	};
}