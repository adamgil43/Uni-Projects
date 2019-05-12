
#include "stdafx.h"
#include "BinSearchTree.h"

int main(int argc, char *argv[])
{
	BinTreeNode* t;
	int list[7] = { 20, 15, 30, 10, 19, 25, 35 };
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
		{
			t = tree_insert(0, list[i]);
		}
		else
			tree_insert(t, list[i]);
	}
	in_order(t);
	std::cout << "\n";
	BinTreeNode* newTree = deleteNode(t, 30);
	in_order(newTree);
	return 0;
}

