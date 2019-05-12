#pragma once
#include "../210CT_Task 10 Temp/BinSearchTree.h"

BinTreeNode* makeTree(int list[7], int length)
{
	BinTreeNode* t;
	for (int i = 0; i < length; i++)
	{
		if (i == 0)
		{
			t = tree_insert(0, list[i]);
		}
		else
			tree_insert(t, list[i]);
	}
	return t;
}