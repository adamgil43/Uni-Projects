#include "stdafx.h"
#include "CppUnitTest.h"
#include "Graph.h"
#include "../210_CT Task 11a Basic Graph/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnweightedUndirectedListTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int V = 6;
		Graph* newGraph = makeGraph(V);
		TEST_METHOD(IsInGraph)
		{
			Assert::AreEqual(checkGraph(newGraph, 1, 1, V), 5);
			Assert::AreEqual(checkGraph(newGraph, 1, 2, V), 4);
			Assert::AreEqual(checkGraph(newGraph, 1, 3, V), 3);
			Assert::AreEqual(checkGraph(newGraph, 2, 1, V), 5);
			Assert::AreEqual(checkGraph(newGraph, 2, 2, V), 4);
			Assert::AreEqual(checkGraph(newGraph, 2, 3, V), 3);
			Assert::AreEqual(checkGraph(newGraph, 3, 1, V), 5);
			Assert::AreEqual(checkGraph(newGraph, 3, 2, V), 2);
			Assert::AreEqual(checkGraph(newGraph, 3, 3, V), 1);
			Assert::AreEqual(checkGraph(newGraph, 4, 1, V), 5);
			Assert::AreEqual(checkGraph(newGraph, 4, 2, V), 2);
			Assert::AreEqual(checkGraph(newGraph, 4, 3, V), 1);
			Assert::AreEqual(checkGraph(newGraph, 5, 1, V), 4);
			Assert::AreEqual(checkGraph(newGraph, 5, 2, V), 3);
			Assert::AreEqual(checkGraph(newGraph, 5, 3, V), 2);
			Assert::AreEqual(checkGraph(newGraph, 5, 4, V), 1);
			// TODO: Your test code here
		}
		TEST_METHOD(NotInGraph)
		{
			Assert::AreEqual(checkGraph(newGraph, 10, 2, V), -1);
			Assert::AreEqual(checkGraph(newGraph, 10, 1, V), -1);
			Assert::AreEqual(checkGraph(newGraph, 10, 3, V), -1);
			Assert::AreEqual(checkGraph(newGraph, 10, 4, V), -1);
			Assert::AreEqual(checkGraph(newGraph, 4, 10, V), -1);

		}
	};
}