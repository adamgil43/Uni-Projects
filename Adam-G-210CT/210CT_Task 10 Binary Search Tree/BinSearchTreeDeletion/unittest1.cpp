#include "stdafx.h"
#include "CppUnitTest.h"
#include "../210CT_Task 10 Temp/BinSearchTree.h"
#include "testData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace BinSearchTreeDeletion
{
	TEST_CLASS(DeleteNodesZeroChild)
	{
	public:
		int listLength = 7;
		int list[7] = { 20, 15, 30, 10, 19, 25, 35 };
		BinTreeNode* tree = makeTree(list, listLength);
		TEST_METHOD(Pass_1_NoChildren)
		{
			int numberToDestroy = 10;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
		}
		TEST_METHOD(Pass_2_NoChildren)
		{
			int numberToDestroy = 19;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
			Assert::IsTrue(checkifTrue);
			// TODO: Your test code here
		}
		TEST_METHOD(Pass_3_NoChildren)
		{
			int numberToDestroy = 25;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
			Assert::IsTrue(checkifTrue);
			// TODO: Your test code here
		}
		TEST_METHOD(Pass_4_NoChildren)
		{
			int numberToDestroy = 35;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
			Assert::IsTrue(checkifTrue);
			// TODO: Your test code here
		}

	};
	TEST_CLASS(DeleteNodesOneChild)
	{
	public:
		int listLength = 5;
		int list[5] = { 20, 15, 30, 10, 25 };
		BinTreeNode* tree = makeTree(list, listLength);
		TEST_METHOD(Pass_1_OneChild)
		{
			int numberToDestroy = 30;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
		}
		TEST_METHOD(Pass_2_OneChild)
		{
			int numberToDestroy = 15;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
		}
	};
	TEST_CLASS(DeleteNodesTwoChild)
	{
	public:
		int listLength = 7;
		int list[7] = { 20, 15, 30, 10, 19, 25, 35 };
		BinTreeNode* tree = makeTree(list, listLength);
		TEST_METHOD(Pass_1_TwoChild)
		{
			int numberToDestroy = 15;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
		}
		TEST_METHOD(Pass_2_TwoChild)
		{
			int numberToDestroy = 30;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
		}
		TEST_METHOD(Pass_3_TwoChild)
		{
			int numberToDestroy = 20;
			BinTreeNode* deleteTree = deleteNode(tree, numberToDestroy);
			Assert::IsTrue(checkifTrue);
		}

	};
	TEST_CLASS(NotInList)
	{
	public:
		int listLength = 7;
		int list[7] = { 20, 15, 30, 10, 19, 25, 35 };
		BinTreeNode* tree = makeTree(list, listLength);
		TEST_METHOD(Pass_1_NotInList)
		{
			int thingToDestroy = 'a';
			BinTreeNode* deleteTree = deleteNode(tree, thingToDestroy);
			Assert::IsTrue(checkifTrue);
		}
		TEST_METHOD(Pass_2_NotInList)
		{
			int thingToDestroy = -9;
			BinTreeNode* deleteTree = deleteNode(tree, thingToDestroy);
			Assert::IsTrue(checkifTrue);
		}
		TEST_METHOD(Pass_3_NotInList)
		{
			int thingToDestroy = 2149345;
			BinTreeNode* deleteTree = deleteNode(tree, thingToDestroy);
			Assert::IsTrue(checkifTrue);
		}
	};
}